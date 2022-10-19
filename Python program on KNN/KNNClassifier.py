from sklearn.neighbors import KNeighborsClassifier
from sklearn.datasets import load_iris
from sklearn.neural_network import MLPClassifier
from sklearn.preprocessing import StandardScaler

iris = load_iris()
x = iris.data
y = iris.target

# -------------------------------------------

# KNN Classifier

# knn = KNeighborsClassifier(n_neighbors=3)
# knn.fit(x, y)
#
# test = [[5, 5, 3, 2]]
# result = knn.predict(test)
# print(result)

# -------------------------------------------

# MLP Classifier

# x1 = [[0, 0, ], [0, 1], [1, 0], [1, 1]]
# y1 = [0, 0, 0, 1]
#
# mlp = MLPClassifier(solver='lbfgs', hidden_layer_sizes=(5, 2), random_state=1)
# mlp.fit(x1, y1)
# test1 = [[2, 2]]
# print(mlp.predict(test1))
#
# print(mlp.coefs_[0])
# print(mlp.coefs_[1])

# -------------------------------------------

test2 = [[5, 5, 3, 2]]
scalar = StandardScaler()
scalar.fit(x)
x = scalar.transform(x)
test2 = scalar.transform(test2)
print(test2)

mlp = MLPClassifier(solver='lbfgs', hidden_layer_sizes=(10, 5), random_state=1, max_iter=100)
mlp.fit(x, y)
print(mlp.predict(test2))

# -------------------------------------------
