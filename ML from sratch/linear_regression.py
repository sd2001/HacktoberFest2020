import numpy as np

class LinearRegression:

    def __init__(self, lr = 0.001, n_itters = 1000):
        self.lr = lr
        self.n_itters = n_itters
        self.weights = None
        self.bias = None

    def fit(self, X, y):
        n_samples, n_features = X.shape
        self.weights = np.zeros(n_features)
        self.bias = 0
        

    def predict(self, X):
        pass
