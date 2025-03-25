import os
import sys
import numpy as np
from data_loader import titanic
from torch.utils.data import DataLoader

import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
from tqdm import tqdm

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# 超参数设置
in_dim = 7
hidden1 = 32
hidden2 = 16
out_dim = 1
batchsize = 16

lr = 0.0005
epochs = 30
loss_f = nn.BCELoss()
threshold = 0.5

datapath = "artifact/a3_waystokeep/2_batch/titanic/Titanic_data.csv"
save_path = os.path.join(os.getcwd(), "artifact/a3_waystokeep/2_batch/epochsaves")
os.makedirs(save_path, exist_ok=True)

# 数据集加载
custom_dataset = titanic(datapath)
train_size = int(len(custom_dataset) * 0.7)
val_size = int(len(custom_dataset) * 0.2)
test_size = len(custom_dataset) - train_size - val_size
train_dataset, val_dataset, test_dataset = torch.utils.data.random_split(custom_dataset, [train_size, val_size, test_size])

train_loader = DataLoader(train_dataset, batch_size=batchsize, shuffle=True)
val_loader = DataLoader(val_dataset, batch_size=batchsize, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=batchsize, shuffle=True)

print(f"训练集大小：{len(train_dataset)} 验证集大小：{len(val_dataset)} 测试集大小：{len(test_dataset)}")

# 定义模型
class NN(nn.Module):
    def __init__(self, in_dim, hidden1, hidden2, out_dim):
        super(NN, self).__init__()
        self.fc1 = nn.Linear(in_dim, hidden1)
        self.fc2 = nn.Linear(hidden1, hidden2)
        self.fc3 = nn.Linear(hidden2, out_dim)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        return torch.sigmoid(self.fc3(x))

def infer(model, dataset, device):
    model.eval()
    correct = 0
    with torch.no_grad():
        for data, label in dataset:
            data, label = data.to(device), label.to(device)
            outputs = model(data).squeeze()
            predicted = (outputs > threshold).long()
            correct += predicted.eq(label.squeeze().long()).sum().item()
    return correct / len(dataset.dataset)

# 修改后的训练函数
def main(lr, epochs):
    model = NN(in_dim, hidden1, hidden2, out_dim).to(device)
    optimizer = optim.Adam(model.parameters(), lr=lr)
    
    with tqdm(total=epochs, desc="整体进度", unit="epoch", ncols=100, colour='green') as pbar:
        for epoch in range(epochs):
            # 训练阶段
            model.train()
            train_correct = 0
            for data, label in train_loader:
                data, label = data.to(device), label.squeeze().to(device)
                
                optimizer.zero_grad()
                outputs = model(data).squeeze()
                loss = loss_f(outputs, label.float())
                
                loss.backward()
                optimizer.step()
                
                train_correct += ((outputs > threshold).long() == label).sum().item()

            # 验证阶段
            val_acc = infer(model, val_loader, device)
            train_acc = train_correct / len(train_dataset)
            
            # 更新进度条描述
            pbar.set_postfix({
                "损失": f"{loss.item():.4f}",
                "训练精度": f"{train_acc:.2%}",
                "验证精度": f"{val_acc:.2%}"
            })
            pbar.update(1)
            
            # 保存模型
            torch.save(model.state_dict(), os.path.join(save_path, f"model_{epoch+1}.pth"))

    # 最终测试
    test_acc = infer(model, test_loader, device)
    print(f"\n测试精度：{test_acc:.2%}")

if __name__ == "__main__":
    main(lr, epochs)