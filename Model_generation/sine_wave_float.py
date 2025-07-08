import numpy as np
import tensorflow as tf
import os

#Generate training data
x_train = np.linspace(0, 2 * np.pi, 1000, dtype=np.float32)
y_train = np.sin(x_train)

#Define simple neural network model
model = tf.keras.Sequential([
    tf.keras.layers.Input(shape=(1,)),
    tf.keras.layers.Dense(16, activation='relu'),
    tf.keras.layers.Dense(16, activation='relu'),
    tf.keras.layers.Dense(1)
])

#Compile model
model.compile(optimizer='adam', loss='mse')

#Train the model
model.fit(x_train, y_train, epochs=100, verbose=0)

#Create a TensorFlow Lite converter
converter = tf.lite.TFLiteConverter.from_keras_model(model)

#Convert the model to TensorFlow Lite
tflite_model = converter.convert()

#Save the converted TensorFlow Lite model to a file
with open("sine_model_float.tflite", "wb") as f:
    f.write(tflite_model)

