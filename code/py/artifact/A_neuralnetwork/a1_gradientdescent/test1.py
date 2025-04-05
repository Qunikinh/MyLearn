import numpy as np
import matplotlib.pyplot as plt

# 生成数据
np.random.seed(42)
x = np.linspace(-10, 10, 100)
y_true = 2 * x**2 + x - 6
noise = np.random.normal(0, 3, y_true.shape)  # 偏差
y = y_true + noise

# 将数据转换为列表
x = x.tolist()
y = y.tolist()

# 定义神经网络模型参数
input_size = 1
hidden_size1 = 3
hidden_size2 = 2
output_size = 1

# 初始化权重和偏置
np.random.seed(42)
W1 = np.random.randn(input_size, hidden_size1)
b1 = np.zeros((1, hidden_size1))
W2 = np.random.randn(hidden_size1, hidden_size2)
b2 = np.zeros((1, hidden_size2))
W3 = np.random.randn(hidden_size2, output_size)
b3 = np.zeros((1, output_size))

# 定义 Sigmoid 函数和它的导数
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# 定义损失函数
def mse(y_true, y_pred):
    return sum((yt - yp) ** 2 for yt, yp in zip(y_true, y_pred)) / len(y_true)

# 定义学习率
learning_rate = 0.1

# 训练模型
num_epochs = 10000
for epoch in range(num_epochs):
    # 前向传播
    z1 = [sum(xi * w for xi, w in zip(x, W1[0])) + b1[0][i] for i in range(hidden_size1)]
    a1 = [sigmoid(z) for z in z1]
    z2 = [sum(ai * w for ai, w in zip(a1, W2[i])) + b2[0][i] for i in range(hidden_size2)]
    a2 = [sigmoid(z) for z in z2]
    z3 = [sum(ai * w for ai, w in zip(a2, W3[i])) + b3[0][i] for i in range(output_size)]
    outputs = z3

    # 计算损失
    loss = mse(y, outputs)

    # 反向传播
    output_error = [outputs[i][0] - y[i] for i in range(len(y))]
    output_delta = [error * 1 for error in output_error]  # 因为输出层没有激活函数

    z2_error = [sum(output_delta[j] * W3[j][i] for j in range(output_size)) for i in range(hidden_size2)]
    z2_delta = [error * sigmoid_derivative(a2[i]) for i, error in enumerate(z2_error)]

    z1_error = [sum(z2_delta[j] * W2[j][i] for j in range(hidden_size2)) for i in range(hidden_size1)]
    z1_delta = [error * sigmoid_derivative(a1[i]) for i, error in enumerate(z1_error)]

    # 更新权重和偏置
    for i in range(hidden_size2):
        for j in range(output_size):
            W3[i][j] -= learning_rate * a2[i] * output_delta[j]
    for i in range(output_size):
        b3[0][i] -= learning_rate * output_delta[i]

    for i in range(hidden_size1):
        for j in range(hidden_size2):
            W2[i][j] -= learning_rate * a1[i] * z2_delta[j]
    for i in range(hidden_size2):
        b2[0][i] -= learning_rate * sum(z2_delta[i] for _ in range(hidden_size1))

    for i in range(input_size):
        for j in range(hidden_size1):
            W1[i][j] -= learning_rate * x[i] * z1_delta[j]
    for i in range(hidden_size1):
        b1[0][i] -= learning_rate * sum(z1_delta[i] for _ in range(input_size))

    # 打印损失
    if (epoch + 1) % 1000 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss:.4f}')

# 打印最终参数
print("Final parameters:")
print("W1:", W1)
print("b1:", b1)
print("W2:", W2)
print("b2:", b2)
print("W3:", W3)
print("b3:", b3)

# 结果预测和可视化
predicted = []
for xi in x:
    z1 = [xi * w for w in W1[0]] + b1[0]
    a1 = [sigmoid(z) for z in z1]
    z2 = [sum(ai * w for ai, w in zip(a1, W2[i])) + b2[0][i] for i in range(hidden_size2)]
    a2 = [sigmoid(z) for z in z2]
    z3 = [sum(ai * w for ai, w in zip(a2, W3[i])) + b3[0][i] for i in range(output_size)]
    predicted.append(z3[0])

plt.scatter(x, y, label='Original data')
plt.plot(x, predicted, color='r', label='Fitted line')
plt.legend()
plt.show()
