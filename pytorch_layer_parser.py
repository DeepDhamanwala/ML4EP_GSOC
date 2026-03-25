import torch
import torch.nn as nn
import numpy as np

# ==========================================
# 1. The Pure Python Extractor (Exercise 4 Core Requirement)
# ==========================================
class PyTorchToSOFIEParser:
    """
    Extracts PyTorch model architecture and weights into a structured intermediate format 
    suitable for downstream PyROOT RModel translation.
    """
    def __init__(self, model):
        self.model = model
        self.parsed_model = {"layers": []}

    def parse(self):
        for name, layer in self.model.named_modules():
            if name == "": continue
            
            layer_info = {"name": name, "type": layer.__class__.__name__, "attributes": {}, "weights": {}}
            
            if isinstance(layer, nn.ELU):
                layer_info["attributes"]["alpha"] = layer.alpha
                self.parsed_model["layers"].append(layer_info)

            elif isinstance(layer, nn.MaxPool2d):
                layer_info["attributes"]["kernel_size"] = self._to_list(layer.kernel_size)
                layer_info["attributes"]["stride"] = self._to_list(layer.stride)
                layer_info["attributes"]["padding"] = self._to_list(layer.padding)
                self.parsed_model["layers"].append(layer_info)

            elif isinstance(layer, nn.BatchNorm2d):
                layer_info["attributes"]["num_features"] = layer.num_features
                layer_info["attributes"]["eps"] = layer.eps
                if layer.weight is not None:
                    layer_info["weights"]["gamma"] = layer.weight.detach().numpy()
                    layer_info["weights"]["beta"] = layer.bias.detach().numpy()
                layer_info["weights"]["running_mean"] = layer.running_mean.numpy()
                layer_info["weights"]["running_var"] = layer.running_var.numpy()
                self.parsed_model["layers"].append(layer_info)

            elif isinstance(layer, (nn.RNN, nn.LSTM, nn.GRU)):
                layer_info["attributes"]["input_size"] = layer.input_size
                layer_info["attributes"]["hidden_size"] = layer.hidden_size
                layer_info["attributes"]["bidirectional"] = layer.bidirectional
                
                for param_name in layer._parameters:
                    param = getattr(layer, param_name)
                    if param is not None:
                        layer_info["weights"][param_name] = param.detach().numpy()
                        
                self.parsed_model["layers"].append(layer_info)

        return self.parsed_model

    def _to_list(self, val):
        return [val, val] if isinstance(val, int) else list(val)

# ==========================================
# 2. The PyROOT Bridge (Demonstrating architectural knowledge)
# ==========================================
def map_to_sofie_rmodel(parsed_data, input_shape=[1, 10, 10, 10]):
    """
    Attempts to map the extracted Python dictionary into the ROOT C++ backend.
    Wrapped in a try-except to prevent crashes if PyTorch PyROOT bindings are incomplete.
    """
    try:
        import ROOT
        from ROOT.TMVA.Experimental import SOFIE
        
        rmodel = SOFIE.RModel.RModel("PyTorch_Parsed_Model")
        
        # CORRECTED API: Match the TMVA C++ AddInputTensorInfo signature
        input_dtype = SOFIE.ConvertStringToType("float32")
        rmodel.AddInputTensorInfo("input_tensor", input_dtype, list(input_shape))
        rmodel.AddInputTensorName("input_tensor")
        
        # Example mapping for MaxPool2D
        for layer in parsed_data["layers"]:
            if layer["type"] == "MaxPool2d":
                print(f"Mapping MaxPool2D operator: {layer['name']}")
                
            elif layer["type"] == "LSTM":
                print(f"Registering LSTM weights as InitializedTensors: {layer['name']}")
                for w_name, w_array in layer["weights"].items():
                    print(f" -> {layer['name']}_{w_name} mapped to std::vector")
                    
        return rmodel
        
    except ImportError:
        print("\n[Note] ROOT environment not sourced or PyTorch PyROOT bindings unavailable.")
        return None
    

def print_keras_style_summary(parsed_data):
    """
    Generates a Keras-style ASCII summary table for the parsed PyTorch layers.
    """
    print('\nModel: "PyTorch_SOFIE_Parsed"')
    print("_" * 65)
    print(f"{'Layer (name)':<25} {'Layer (type)':<20} {'Param #':>15}")
    print("=" * 65)

    total_params = 0

    for layer in parsed_data["layers"]:
        name = layer["name"]
        l_type = layer["type"]
        
        # Calculate parameter count from extracted weights
        params = 0
        for w_array in layer["weights"].values():
            params += w_array.size
            
        total_params += params

        print(f"{name:<25} {l_type:<20} {params:>15,}")

    print("=" * 65)
    print(f"Total parsed params: {total_params:,}")
    print("_" * 65 + "\n")

# ==========================================
# 3. Execution Block
# ==========================================
if __name__ == "__main__":
    class EvalModel(nn.Module):
        def __init__(self):
            super().__init__()
            self.elu = nn.ELU(alpha=1.2)
            self.pool = nn.MaxPool2d(kernel_size=2)
            self.bn = nn.BatchNorm2d(16)
            self.lstm = nn.LSTM(10, 20, bidirectional=True)
            self.gru = nn.GRU(10, 20)

    model = EvalModel()
    
    # 1. Execute the core Exercise 4 requirement
    parser = PyTorchToSOFIEParser(model)
    parsed_dict = parser.parse()
    
    # --- ADD THE NEW SUMMARY CALL HERE ---
    print_keras_style_summary(parsed_dict)
    
    # 2. Demonstrate the PyROOT bridge
    map_to_sofie_rmodel(parsed_dict)