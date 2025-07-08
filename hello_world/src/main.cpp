#include <Arduino.h>
#include <ArduTFLite.h>
#include "float_model_data.h"

//Available memory for tensors of 2kb
constexpr int tensorArenaSize = 2000;
alignas(16) byte tensorArena[tensorArenaSize];

float x = 0.0;  //Input value to use in inference

void setup() {
  Serial.begin(115200);
  while (!Serial);  //Waiting for serial port opening

  //Model initialization using the variables set before
  if (!modelInit(sine_model_tflite, tensorArena, tensorArenaSize)) {
    while (true);  //If initialization fails, program will stop
  }
}

void loop() {
  //Define the input and run inference with the value
  if (modelSetInput(x, 0) && modelRunInference()) {
    float y_pred = modelGetOutput(0);  //Inference output
    float y_true = sin(x);             //Actual sin(x) value
    Serial.printf("x: %.2f | model: %.4f | sin(x): %.4f\n", x, y_pred, y_true);
  }

  //Increment x by 0.1 to iterate and reset after 2π (~6.28)
  x += 0.1;
  if (x > 6.28) x = 0.0;
  delay(5000);  // Wait 5 seconds between inferences
}