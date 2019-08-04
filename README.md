# StenisGate
import pandas as pd
import numpy as np
import sklearn
from sklearn import linear_model
from sklearn.utils import shuffle
data = pd.read_csv("student-mat.csv",sep=";")
#data = data[["G1","G2","G3","studytime","failures","absences"]]
data = data[["G1","G2","G3","studytime","absences","failures"]]
predict ="G3"
datax=np.array(data.drop([predict],1));#drop函数默认删除行，列需要加axis = 1
targety=np.array(data[predict])

x_train,x_test,y_train,y_test = sklearn.model_selection.train_test_split(datax,targety,test_size=0.1)
'''print(x_train)
print(x_test);print(y_train)
print(y_test)'''
linear = linear_model.LinearRegression()
linear.fit(x_train,y_train)
print(linear.score(x_test,y_test))

print('coef_:')
print(linear.coef_)
print('intercept_')
print(linear.intercept_)

prediction = linear.predict(x_test)

for i in range(len(prediction)):
    print(prediction[i])
    print(["G1","G3","studytime","absences","failures"])
    print(x_test[i])
    print("G2")
    print(y_test[i])
    print('\n')
