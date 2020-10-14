import streamlit as st
import cv2 
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from PIL import Image
import urllib.request
from streamlit_drawable_canvas import st_canvas
import time

html_temp = '''
    <div style = "background-color: rgba(25,25,112,0.06); padding-bottom: 20px; padding-top: 20px; padding-left: 5px; padding-right: 5px">
    <center><h1>Handwritten Digit Recognition</h1></center>
    
    </div>
    '''
st.markdown(html_temp, unsafe_allow_html=True)
html_temp = '''
    <div>
    <h2></h2>
    <center><h3>Please upload Image for Classification</h3></center>
    </div>
    '''
st.set_option('deprecation.showfileUploaderEncoding', False)
st.markdown(html_temp, unsafe_allow_html=True)
opt = st.selectbox("How do you want to upload the image for classification?\n", ('Please Select', 'Upload image via link', 'Upload image from device', 'Draw the Digit!'))
if opt == 'Upload image from device':
    file = st.file_uploader('Select', type = ['jpg', 'png', 'jpeg'])
    st.set_option('deprecation.showfileUploaderEncoding', False)
    if file is not None:
        image = Image.open(file)

elif opt == 'Upload image via link':
  
  try:
    img = st.text_input('Enter the Image Address')
    image = Image.open(urllib.request.urlopen(img))
    
  except:
    if st.button('Submit'):
      show = st.error("Please Enter a valid Image Address!")
      time.sleep(4)
      show.empty()

elif opt == 'Draw the Digit!':
  b_width = st.slider('Brush Width: ',1,50,10)
  drawing_mode = st.checkbox("Draw",True)
  image_data = st_canvas(b_width, '#000', '#EEE', height=200,width=300, drawing_mode=drawing_mode, key="canvas")
  try:
    cv2.imwrite("test.jpg",image_data)
    image = Image.open("test.jpg")
  except:
    pass
try:
  if image is not None:
    st.image(image, width = 300, caption = 'Uploaded Image')
    if st.button('Predict'):
      mnist=tf.keras.datasets.mnist     #importing the dataset form mnist
      (x_train, y_train), (x_test, y_test) = mnist.load_data()     
      #normalizing the data
      x_train = tf.keras.utils.normalize(x_train, axis=1)
      x_test = tf.keras.utils.normalize(x_test, axis=1)
      #defining the model with an input layer, two hidden layers and an output layer
      model=tf.keras.models.Sequential([
          tf.keras.layers.Flatten(input_shape=(28,28)),   
          tf.keras.layers.Dense(units=128,activation=tf.nn.relu),   
          tf.keras.layers.Dense(units=128,activation=tf.nn.relu),   
          tf.keras.layers.Dense(units=10,activation=tf.nn.softmax)
      ])
      
      model.compile(optimizer='adam',loss='sparse_categorical_crossentropy',metrics=['accuracy'])
      model.fit(x_train,y_train,epochs=5)
      loss,accuracy=model.evaluate(x_test,y_test)
      model.save('digits.model')
      image = np.array(image.resize((28, 28), Image.ANTIALIAS))
      image = np.array(image, dtype='uint8' )
      image = image[:,:,0]
      image = np.invert(np.array([image]))
      prediction = model.predict(image)
      st.success('Hey! The uploaded digit has been predicted as {} with Accuracy {:.3f}'.format(np.argmax(prediction),accuracy))

except:
  pass
