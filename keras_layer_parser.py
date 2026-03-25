import os
#suppressing TensorFlow logging clutter
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2' 
import tensorflow as tf

def extract_keras_layer_info(model):
    """
    Parses a Keras model and extracts attributes and weights for SOFIE IR translation
    specifically targeting layers: LSTM, GRU, and Conv2DTranspose
    """
    parsed_layers = {}
    
    for layer in model.layers:
        layer_info = {"type": layer.__class__.__name__}
        
        # 1. LSTM
        if isinstance(layer, tf.keras.layers.LSTM):
            layer_info["units"] = layer.units
            layer_info["activation"] = layer.activation.__name__
            layer_info["recurrent_activation"] = layer.recurrent_activation.__name__
            layer_info["return_sequences"] = layer.return_sequences
            
            # Keras stores LSTM weights as [kernel, recurrent_kernel, bias]
            weights = layer.get_weights()
            if len(weights) == 3:
                layer_info["weights_kernel"] = weights[0]
                layer_info["weights_recurrent"] = weights[1]
                layer_info["weights_bias"] = weights[2]

        # 2. GRU
        elif isinstance(layer, tf.keras.layers.GRU):
            layer_info["units"] = layer.units
            layer_info["activation"] = layer.activation.__name__
            layer_info["return_sequences"] = layer.return_sequences
            
            weights = layer.get_weights()
            if len(weights) == 3:
                layer_info["weights_kernel"] = weights[0]
                layer_info["weights_recurrent"] = weights[1]
                layer_info["weights_bias"] = weights[2]

        # 3. Conv2DTranspose
        elif isinstance(layer, tf.keras.layers.Conv2DTranspose):
            layer_info["filters"] = layer.filters
            layer_info["kernel_size"] = layer.kernel_size
            layer_info["strides"] = layer.strides
            layer_info["padding"] = layer.padding
            
            weights = layer.get_weights()
            if len(weights) >= 1:
                layer_info["weights_kernel"] = weights[0]
            if len(weights) == 2:
                layer_info["weights_bias"] = weights[1]

        else:
            continue
            
        parsed_layers[layer.name] = layer_info
        
    return parsed_layers

#running sample test
def run_tests():
    print("Running SOFIE Keras Parser Tests")
    
    # creating a dummy model containing the requested bonus layers
    inputs = tf.keras.Input(shape=(10, 32))
    
    # adding LSTM and GRU
    x = tf.keras.layers.LSTM(16, return_sequences=True, name="test_lstm")(inputs)
    x = tf.keras.layers.GRU(8, return_sequences=False, name="test_gru")(x)
    
    # adding a Conv2DTranspose requires reshaping to 4D first
    x = tf.keras.layers.Reshape((2, 2, 2))(x)
    outputs = tf.keras.layers.Conv2DTranspose(filters=4, kernel_size=(3,3), name="test_conv2d_trans")(x)
    
    model = tf.keras.Model(inputs=inputs, outputs=outputs)
    
    # run extraction parser
    extracted_data = extract_keras_layer_info(model)
    
    for layer_name, data in extracted_data.items():
        print(f"\n[Parsed Layer]: {layer_name} ({data['type']})")
        for key, val in data.items():
            if key == "type": continue
            if hasattr(val, 'shape'):
                print(f"  - {key}: Numpy Array with shape {val.shape}")
            else:
                print(f"  - {key}: {val}")
                
    print("\n keras test completed")

if __name__ == "__main__":
    run_tests()
