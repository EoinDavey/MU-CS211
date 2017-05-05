import numpy as np
from sklearn import linear_model

inputData = np.loadtxt("input.csv",delimiter=',')
inputData = inputData[:,1:]

best = 10000.0 
chosen = 0

for k in range(0,487):
    trainInput = inputData[:, range(0,k) + range(k+1,487)]
    yInput = inputData[:,k]

    regr = linear_model.LinearRegression()

    regr.fit(trainInput, yInput)

    score = np.mean((regr.predict(trainInput) - yInput) ** 2)
    if score < best:
        best = score
        chosen = k

print chosen

trainInput = inputData[:, range(0,chosen) + range(chosen+1,487)]
yInput = inputData[:,chosen]

regr = linear_model.LinearRegression()

regr.fit(trainInput, yInput)

size = regr.coef_.size
for i in range(0,chosen):
    print '%.32f,' % regr.coef_[i]
print '0,'
for i in range(chosen,size):
    print '%.32f,' % regr.coef_[i]
