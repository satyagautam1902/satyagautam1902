import tensorflow as tf
from matplotlib import pyplot as plt
import numpy as np

objects = tf.keras.datasets.mnist
(training_images, training_labels),(test_image,test_labels)= objects.load_data()

for i in range (9):
  #define subplot
  plt.subplot(330+i+1)
  #plot row pixel data
  plt.imshow(training_images[i])
  
  print(training_images.shape)
print(training_images[0])

training_images=training_images/255.0
test_image=test_image/255.0

model=tf.keras.models.Sequential([tf.keras.layers.Flatten(input_shape=(28,28)),
                                  tf.keras.layers.Dense(120,activation='relu'),
                                  tf.keras.layers.Dense(10,activation=tf.nn.softmax)])

model.compile(optimizer = tf.optimizers.Adam(),
              loss = 'sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(training_images,training_labels,epochs=5)

print(model.evaluate(test_image,test_labels))

plt.imshow(test_image[18])
prediction=model.predict(test_image)
print(np.argmax(prediction[18]))
