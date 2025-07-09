# 📦 Edge AI Deployment with PlatformIO and TensorFlow Lite Micro

This repository contains a complete example of deploying a quantized TensorFlow Lite model to a microcontroller using [PlatformIO](https://platformio.org/) and the [ArduTFLite](https://github.com/spaziochirale/ArduTFLite) library. 

---

## Repository Structure

- `Model_generation/`: Contains Python scripts to train and convert a TensorFlow/Keras model to a `.tflite` file using quantization.
- `platformio_project/`: PlatformIO-based firmware project that embeds the `.tflite` model, performs inference, and prints results via serial.

---

## 1. Model Creation

Inside the `Model_generation/` folder:

- A basic ML sine model is trained using TensorFlow.
- The model is converted to a quantized TensorFlow Lite format.
- The `.tflite` file must be transformed into a C array using `xxd -i`, preparing it for inclusion in the microcontroller firmware.

---

## 2. PlatformIO Project

Inside the `platformio_project/` folder:

- The `platformio.ini` file defines the board, platform, framework (Arduino), required libraries, and build flags.
- The `src/` directory contains:
  - The main firmware code using the ArduTFLite library to load the model and run inference.
  - The model C array header file generated from the quantized `.tflite` model.

---

## 3. Deployment Workflow

- Initialize the project using PlatformIO and install dependencies via `lib_deps` in the config file.
- Upload the firmware to the microcontroller via USB using PlatformIO's CLI.
- Use PlatformIO's built-in serial monitor to observe inference results in real time.

---

## 4. Requirements

- Visual Studio Code with the PlatformIO extension installed.
- Python (for training the model).
- A supported microcontroller board (e.g., Arduino Nano 33 BLE Sense).

---
