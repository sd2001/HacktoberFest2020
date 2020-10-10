import streamlit as st
import pandas as pd
import numpy as np
from sklearn import metrics
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_boston
from sklearn.linear_model import LinearRegression
from sklearn.tree import DecisionTreeRegressor 

boston = load_boston()
df = pd.DataFrame(boston.data)
df.columns = boston.feature_names
df['PRICE'] = boston.target
X = df.drop(['PRICE'], axis = 1)
y = df['PRICE']
html_temp = '''
    <div style = "background-color: rgba(25,25,112,0.06); padding-bottom: 30px; padding-top: 20px; padding-left: 5px; padding-right: 5px">
    <center><h1>Boston Housing Prices</h1></center>
    
    </div>
    '''
st.markdown(html_temp, unsafe_allow_html=True)

st.sidebar.header('Enter Features for Prediction')
crim = st.sidebar.number_input('Per capita crime rate by town: ')
zn = st.sidebar.number_input('Proportion of residential land zoned for lots over 25,000 sq.ft: ')
indus = st.sidebar.number_input('Proportion of non-retail business acres per town: ')
chas = st.sidebar.radio('Charles River dummy variable: ',(0,1))
nox = st.sidebar.number_input('Nitric oxides concentration (parts per 10 million): ')
rm = st.sidebar.number_input('Average number of rooms per dwelling: ')
age = st.sidebar.slider('Proportion of owner-occupied units built prior to 1940: ',1,100,20)
dis = st.sidebar.number_input('Weighted distances to five Boston employment centres: ')
rad = st.sidebar.slider('Index of accessibility to radial highways: ',1,25,5)
tax = st.sidebar.slider('Full-value property-tax rate per 10,000 USD: ',100,1000,250)
ptratio = st.sidebar.number_input('Pupil-teacher ratio by town: ')
b = st.sidebar.number_input('Proportion of blacks by town: ')
lstat = st.sidebar.number_input('Lower status of the population: ')
input = np.array([[crim, zn, indus, chas, nox, rm, age, dis, rad, tax, ptratio, b, lstat]])
html_temp = '''
    <div>
    <h2></h2>
    <center><h3>Select your Regression Model</h3></center>
    </div>
    '''
st.set_option('deprecation.showfileUploaderEncoding', False)
st.markdown(html_temp, unsafe_allow_html=True)
opt = st.selectbox("Which Model do you want for Regression?\n", ('Please Select', 'Linear Regressor', 'Decision Trees'))
if opt == 'Linear Regressor':
  Linear_regressor = LinearRegression()
  Linear_regressor.fit(X, y)
  if st.button('Predict'):
    st.info('Estimated Price: $ {:.3f}'.format(Linear_regressor.predict(input)[0]))

elif opt == 'Decision Trees':
  DT_regressor = DecisionTreeRegressor(random_state = 0)  
  DT_regressor.fit(X, y)
  if st.button('Predict'):
    st.info('Estimated Price: $ {:.3f}'.format(DT_regressor.predict(input)[0]))