# 导入必要的库
import os
import sys
import numpy as np
from data_loader import xy
from torch.utils.data import DataLoader
import torch
import torch.nn as nn
import torch.optim as optim
from tqdm import tqdm
import matplotlib.pyplot as plt

# 定义神经网络模型
class NN(nn.Module):
    def __init__(self, in_dim, hidden1, hidden2, out_dim):
        """
        初始化神经网络模型
        :param in_dim: 输入层维度
        :param hidden1: 第一个隐藏层维度
        :param hidden2: 第二个隐藏层维度
        :param out_dim: 输出层维度
        """
        super().__init__()
        # 定义线性层
        self.layer1 = nn.Linear(in_dim, hidden1)
        self.layer2 = nn.Linear(hidden1, hidden2)
        self.layer3 = nn.Linear(hidden2, out_dim)

    def forward(self, x):
        """
        前向传播函数
        :param x: 输入数据
        :return: 模型输出
        """
        x = torch.relu(self.layer1(x))
        x = torch.relu(self.layer2(x))
        x = self.layer3(x)
        return x

# 选择设备（GPU 或 CPU）
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# 加载数据
custom_dataset = xy("artifact/a2_neural/data.txt")
# 划分数据集
train_size = int(len(custom_dataset) * 0.7)
val_size = int(len(custom_dataset) * 0.2)
test_size = len(custom_dataset) - train_size - val_size
train_dataset, val_dataset, test_dataset = torch.utils.data.random_split(custom_dataset, [train_size, val_size, test_size])
# 创建数据加载器
train_loader = DataLoader(train_dataset, batch_size=1, shuffle=True)
val_loader = DataLoader(val_dataset, batch_size=1, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=1, shuffle=True)

print("数据加载完成")
print(f"训练集大小：{len(train_dataset)}")
print(f"验证集大小：{len(val_dataset)}")
print(f"测试集大小：{len(test_dataset)}")

# 推理函数，计算均方误差损失
def infer(model, data_loader, device):
    """
    推理函数，用于评估模型在给定数据集上的性能
    :param model: 神经网络模型
    :param data_loader: 数据加载器
    :param device: 设备(GPU 或 CPU)
    :return: 平均均方误差损失
    """
    model.eval()
    total_loss = 0
    with torch.no_grad():
        for data in data_loader:
            x, y = data
            x = x.to(device)
            y = y.to(device)
            output = model(x)
            # 定义均方误差损失函数
            loss_fn = nn.MSELoss()
            loss = loss_fn(output, y)
            total_loss += loss.item()
    # 计算平均损失
    avg_loss = total_loss / len(data_loader)
    return avg_loss

# 训练函数
def main(lr=0.01, epochs=100):
    """
    主训练函数
    :param lr: 学习率
    :param epochs: 训练轮数
    """
    # 初始化模型
    model = NN(1, 20, 10, 1).to(device)
    # 定义损失函数和优化器
    loss_fn = nn.MSELoss()
    optimizer = optim.Adam(model.parameters(), lr=lr)

    # 创建保存权重的目录
    weight_path = os.path.join(os.getcwd(), "result/weight")
    if not os.path.exists(weight_path):
        os.makedirs(weight_path)

    # 用于记录训练集和验证集的损失
    train_losses = []
    val_losses = []

    # 整体进度条
    overall_pbar = tqdm(total=epochs, desc="训练中", ncols=100)

    # 训练循环
    for epoch in range(epochs):
        model.train()
        total_loss = 0
        sample_num = 0

        for data in train_loader:
            x, y = data
            x = x.to(device)
            y = y.to(device)
            sample_num += x.shape[0]

            # 梯度清零
            optimizer.zero_grad()
            # 前向传播
            output = model(x)
            # 计算损失
            loss = loss_fn(output, y)
            # 反向传播
            loss.backward()
            # 更新参数
            optimizer.step()

            total_loss += loss.item()

        # 计算平均训练损失
        avg_train_loss = total_loss / len(train_loader)
        train_losses.append(avg_train_loss)

        # 计算验证集损失
        val_loss = infer(model, val_loader, device)
        val_losses.append(val_loss)
        print(f"train[loss={avg_train_loss:.3f}] val[loss={val_loss:.3f}]")

        # 保存模型权重
        torch.save(model.state_dict(), os.path.join(weight_path, f"epoch_{epoch + 1}.pth"))

        # 更新整体进度条
        overall_pbar.update(1)

    overall_pbar.close()
    print("训练完成")
    # 计算测试集损失
    test_loss = infer(model, test_loader, device)
    print(f"学习率：{lr}"  f"训练轮数：{epochs}" )
    print(f"训练集损失：{train_losses[-1]:.3f}"   f"验证集损失：{val_losses[-1]:.3f}"   f"测试集损失：{test_loss:.3f}")

    # 可视化训练集和验证集的损失
    plt.figure(figsize=(10, 6))
    plt.plot(range(epochs), train_losses, label='Training Loss')
    plt.plot(range(epochs), val_losses, label='Validation Loss')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.title('Training and Validation Loss')
    plt.legend()
    plt.grid(True)
    plt.show()

    # 绘制 x, y 数据散点图和训练后的函数预测图
    all_x = []
    all_y = []
    all_preds = []
    model.eval()
    with torch.no_grad():
        for dataset in [train_dataset, val_dataset, test_dataset]:
            for data in dataset:
                x, y = data
                all_x.append(x.item())
                all_y.append(y.item())
                x = x.unsqueeze(0).to(device)
                pred = model(x).item()
                all_preds.append(pred)

    plt.figure(figsize=(10, 6))
    plt.scatter(all_x, all_y, label='Original Data', color='blue')
    sorted_indices = np.argsort(all_x)
    all_x = np.array(all_x)[sorted_indices]
    all_preds = np.array(all_preds)[sorted_indices]
    plt.plot(all_x, all_preds, label='Predicted Function', color='red')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('Original Data vs Predicted Function')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    main(lr=0.005, epochs=100)