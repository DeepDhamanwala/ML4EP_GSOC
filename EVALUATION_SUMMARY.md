# GSoC 2026 SOFIE Evaluation - Keras & PyTorch Parsers

**Candidate:** Deep Dhamanwala
**Branch:** `gsoc26-sofie-evaluation`

## Environment Setup (Exercises 1 & 2)
* Built ROOT from source via CMake with `-Dtmva-sofie=ON` and `-Dtmva-pymva=ON`.
* Verified the Deep Learning and CNN TMVA classification tutorials.

## Exercise 3: SOFIE Parsers Verification
* Successfully generated `.onnx` and Keras/PyTorch dummy models.
* Ran `TMVA_SOFIE_ONNX.C`, `TMVA_SOFIE_Keras.C`, and `TMVA_SOFIE_PyTorch.C` macros to generate the C++ Intermediate Representation (`.hxx`) files.

## Exercise 4: PyTorch Parser Implementation
* **File:** `pytorch_layer_parser.py`
* Developed a Python-side parsing script to introspect PyTorch models using `named_modules()`.
* Implemented extraction logic for attributes, running statistics, and weight matrices (converting to numpy arrays for C++ transfer) for:
  * `ELU`, `MaxPool2d`, `BatchNorm2d`
  * `RNN`, `LSTM`, `GRU`
* Included a built-in unit testing function to verify extraction shapes.

## Exercise 5: [BONUS] Keras Parser Enhancements
* **File:** `keras_layer_parser.py`
* Extended the logic to target the Keras Keras ops/layers.
* Implemented extraction for:
  * `LSTM` (kernel, recurrent_kernel, bias)
  * `GRU`
  * `Conv2DTranspose`
* Included a dedicated dummy model test to validate weight extraction.
