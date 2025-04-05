import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import matplotlib.pyplot as plt

#todo生成数据
# 生成100个y = 2x^2 + x - 6带有偏差的随机数据
np.random.seed(42)
x = np.linspace(-10, 10, 100)
y_true = 2 * x**2 + x - 6
# 添加随机偏差
noise = np.random.normal(0, 3, y_true.shape)
y = y_true + noise

#todo训练数据
# 将数据转换为PyTorch张量
x_tensor = torch.tensor(x, dtype=torch.float32).view(-1, 1)
y_tensor = torch.tensor(y, dtype=torch.float32).view(-1, 1)

#todo 定义神经网络模型
class NeuralNetwork(nn.Module): 
    def __init__(self):
        # 调用父类nn.Module的构造函数
        super(NeuralNetwork, self).__init__()
        # nn.Linear是PyTorch中的线性层，这里创建一个从1个输入到3个输出的线性层
        self.fc1 = nn.Linear(1, 3)
        # 创建一个从3个输入到2个输出的线性层
        self.fc2 = nn.Linear(3, 2)
        # 创建一个从2个输入到1个输出的线性层
        self.fc3 = nn.Linear(2, 1)
        # Sigmoid函数将输入映射到0到1之间
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        # 前向传播函数
        # 首先将输入x通过第一个线性层，然后应用Sigmoid激活函数
        x = self.sigmoid(self.fc1(x))
        # 将上一层的结果通过第二个线性层，再次应用Sigmoid激活函数
        x = self.sigmoid(self.fc2(x))
        # 将第二层的结果通过第三个线性层，得到最终的输出
        x = self.fc3(x)
        # 返回最终的输出
        return x

# 初始化模型
model = NeuralNetwork()

# 定义损失函数和优化器
criterion = nn.MSELoss()        #均方误差损失函数
optimizer = optim.Adam(model.parameters(), lr=0.1) # 学习率为0.1 

#todo 训练模型
num_epochs = 9000          #  训练次数
for epoch in range(num_epochs):
    # 前向传播
    outputs = model(x_tensor)             # 输入数据x_tensor传入模型，得到输出outputs
    loss = criterion(outputs, y_tensor)   # 计算损失：使用损失函数criterion计算输出outputs和目标值y_tensor之间的损失

    # 反向传播和优化
    optimizer.zero_grad()   #  将优化器的梯度缓存清零，以防止梯度累积
    loss.backward()         #  反向传播：计算损失函数的梯度，并存储在模型的参数的.grad属性中
    optimizer.step()        #  更新模型参数：使用优化器根据梯度更新模型的参数

    if (epoch + 1) % 300 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')
# 打印最终参数
print("Final parameters:")
for name, param in model.named_parameters():
    if param.requires_grad:
        print(name, param.data)

#todo 结果预测和可视化
with torch.no_grad():
    predicted = model(x_tensor).numpy()

plt.scatter(x, y, label='Original data')
plt.plot(x, predicted, color='r', label='Fitted line')
plt.legend()
plt.show()