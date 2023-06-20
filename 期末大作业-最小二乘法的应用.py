import numpy as np
import pandas as pd
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt

# 对数据集中的样本属性进行分割，制作X和Y矩阵
def feature_label_split(pd_data):
    row_cnt = pd_data.shape[0]
    column_cnt = len(pd_data.iloc[0, 0].split())

    X = np.empty((row_cnt, column_cnt - 1))
    Y = np.empty((row_cnt, 1))
    for i in range(0, row_cnt):
        row_array = pd_data.iloc[i, 0].split()
        X[i] = np.array(row_array[0:-1])
        Y[i] = np.array(row_array[-1])

    return X, Y


# 主函数
if __name__ == "__main__":
    # 读取训练集和测试集文件
    train_data = pd.read_csv("boston_house.train", header=None)
    test_data = pd.read_csv("boston_house.test", header=None)


    # 对训练集和测试集进行X，Y分离
    train_X, train_Y = feature_label_split(train_data)
    test_X, test_Y = feature_label_split(test_data)


    # 使用最小二乘法求解线性回归
    ones = np.ones((train_X.shape[0], 1))
    X = np.concatenate((ones, train_X), axis=1)  # 添加常数项
    W = np.linalg.inv(X.T @ X) @ X.T @ train_Y  # 最小二乘法求解参数


    # 模型评估, 对测试集进行预测
    ones = np.ones((test_X.shape[0], 1))
    X_test = np.concatenate((ones, test_X), axis=1)  # 添加常数项
    test_pred = X_test @ W
    mse = mean_squared_error(test_Y, test_pred)
    print("均方误差", mse)


    # 对测试集上的标注值与预测值进行可视化呈现
    t = np.arange(len(test_pred))
    # mpl.rcParams['font.sans-serif'] = [u'simHei']
    # mpl.rcParams['axes.unicode_minus'] = False
    plt.figure(facecolor='w')
    plt.plot(t, test_Y, color='red', lw=2, label=u'True Value')
    plt.plot(t, test_pred, color='royalblue', lw=2, label=u'Estimated')
    plt.legend(loc='best')
    plt.title(u'Boston house price', fontsize=18)
    plt.xlabel(u'case id', fontsize=15)
    plt.ylabel(u'house price', fontsize=15)
    plt.grid()
    plt.show()

