import torch
import torch.nn as nn
import numpy as np

def extract_layer_info(model):
    """
    Parse a PyTorch model and extracts attributes and weights for SOFIE IR translation
    """
    parsed_layers = {}
    
    for name, layer in model.named_modules():
        # Skip the top-level container
        if name == "":
            continue
            
        layer_info = {"type": layer.__class__.__name__}
        
        # 1. ELU
        if isinstance(layer, nn.ELU):
            layer_info["alpha"] = layer.alpha
            
        # 2. MaxPool2D
        elif isinstance(layer, nn.MaxPool2d):
            layer_info["kernel_size"] = layer.kernel_size
            layer_info["stride"] = layer.stride
            layer_info["padding"] = layer.padding
            layer_info["dilation"] = layer.dilation
            layer_info["ceil_mode"] = layer.ceil_mode

        # 3. BatchNorm2D
        elif isinstance(layer, nn.BatchNorm2d):
            layer_info["num_features"] = layer.num_features
            layer_info["eps"] = layer.eps
            layer_info["momentum"] = layer.momentum
            # Extract weights (gamma/beta) and running stats to numpy for C++ transfer
            layer_info["weight"] = layer.weight.detach().numpy() if layer.weight is not None else None
            layer_info["bias"] = layer.bias.detach().numpy() if layer.bias is not None else None
            layer_info["running_mean"] = layer.running_mean.numpy()
            layer_info["running_var"] = layer.running_var.numpy()

        # 4, 5, 6. RNN, LSTM, GRU (The Complex Layers)
        elif isinstance(layer, (nn.RNN, nn.LSTM, nn.GRU)):
            layer_info["input_size"] = layer.input_size
            layer_info["hidden_size"] = layer.hidden_size
            layer_info["num_layers"] = layer.num_layers
            layer_info["batch_first"] = layer.batch_first
            layer_info["bidirectional"] = layer.bidirectional
            
            # Extracting the weight matrices for all layers and directions
            weights = {}
            for attr_name in layer._parameters:
                param = getattr(layer, attr_name)
                if param is not None:
                    weights[attr_name] = param.detach().numpy()
            layer_info["weights"] = weights

        else:
            # If it's a layer we haven't targeted, skip or log
            continue
            
        parsed_layers[name] = layer_info
        
    return parsed_layers

def print_summary_table(extracted_data):
    """
    Parses the flat dictionary and generates a Keras-style ASCII summary table.
    """
    print('\nModel: "PyTorch_Extracted_Sequential"')
    print("_" * 65)
    print(f"{'Layer (name)':<25} {'Layer (type)':<20} {'Param #':>15}")
    print("=" * 65)

    total_params = 0

    for layer_name, data in extracted_data.items():
        l_type = data.get("type", "Unknown")
        params = 0

        # Dynamically find and sum the size of any numpy array in the dictionary
        for key, val in data.items():
            if isinstance(val, np.ndarray):
                params += val.size
            elif key == "weights" and isinstance(val, dict):
                for w_array in val.values():
                    if isinstance(w_array, np.ndarray):
                        params += w_array.size

        total_params += params
        print(f"{layer_name:<25} {l_type:<20} {params:>15,}")

    print("=" * 65)
    print(f"Total params: {total_params:,}")
    print("_" * 65 + "\n")


# unit testing the parser
def run_tests():
    print("--- Running PyTorch Parser Tests ---")
    
    # Create a dummy model containing all requested layers
    class ComplexTestModel(nn.Module):
        def __init__(self):
            super().__init__()
            self.elu = nn.ELU(alpha=1.5)
            self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
            self.bn = nn.BatchNorm2d(num_features=16)
            self.rnn = nn.RNN(input_size=10, hidden_size=20, num_layers=1)
            self.lstm = nn.LSTM(input_size=10, hidden_size=20, num_layers=2, batch_first=True)
            self.gru = nn.GRU(input_size=10, hidden_size=20, bidirectional=True)
            
    model = ComplexTestModel()
    
    # Run our extraction parser
    extracted_data = extract_layer_info(model)
    
    # Print the formatted Keras-style table
    print_summary_table(extracted_data)
    
    print("Test Completed")

if __name__ == "__main__":
    run_tests()
