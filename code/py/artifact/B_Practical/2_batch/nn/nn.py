import os
import sys
import numpy as np
from data_loader import titanic
from torch.utils.data import DataLoader

import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
# from sklearn.metrics import accuracy_score    scikit - learn 库提供了各种机器学习相关的工具和算法
# from sklearn.metrics import confusion_matrix
# from sklearn.metrics import classification_report
from tqdm import tqdm

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

#todo 超参数设置
in_dim = 7
hidden1 = 32
hidden2 = 16
out_dim = 1
batchsize = 16

lr = 0.0005
epochs = 30
loss_f =nn.BCELoss()
threshold = 0.5 #阈值，用于二分类问题

datapath = "artifact/B_Practical/data/Titanic_data.csv"
save_path = os.path.join(os.getcwd(), "artifact/B_Practical/2_batch/epochsaves")
if os.path.exists(save_path) is False: os.makedirs(save_path)

#todo 数据集加载  
# 加载数据    #!create batch
custom_dataset = titanic("artifact/B_Practical/data/Titanic_data.csv")
# 划分训练集、验证集和测试集
train_size = int(len(custom_dataset) * 0.7)
val_size = int(len(custom_dataset) * 0.2)
test_size = len(custom_dataset) - train_size - val_size
train_dataset, val_dataset, test_dataset = torch.utils.data.random_split(custom_dataset, [train_size, val_size, test_size])
# 创建数据加载器
train_loader = DataLoader(train_dataset, batch_size=batchsize, shuffle=True)
val_loader = DataLoader(val_dataset, batch_size=batchsize, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=batchsize, shuffle=True)
print("数据加载完成!")
print(f"训练集大小：{len(train_dataset)}    验证集大小：{len(val_dataset)}    测试集大小：{len(test_dataset)}")

#todo 定义神经网络模型  
class NN(nn.Module):
    def __init__(self, in_dim, hidden1, hidden2, out_dim):
        super(NN, self).__init__()
        self.fc1 = nn.Linear(in_dim , hidden1)
        self.fc2 = nn.Linear(hidden1, hidden2)
        self.fc3 = nn.Linear(hidden2, out_dim)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = torch.sigmoid(self.fc3(x))
        return x

def infer(model, dataset, device):  #!use test and val
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for datas in dataset:
            data, label = datas
            data, label = data.to(device), label.to(device)
            outputs = model(data)
            # 使用阈值判断预测结果，并调整形状
            predicted_y = (outputs.squeeze() > threshold).long()
            # 确保标签的维度与预测结果一致
            label = label.squeeze().long()
            correct += (predicted_y == label).sum().item()
            total += label.size(0)
    accuracy = correct / total
    return accuracy

#todo 训练模型
def main(lr, epochs):       #!use train batch to train
    model = NN(in_dim, hidden1, hidden2, out_dim).to(device) 
    
    pg = [p for p in model.parameters() if p.requires_grad] #判断参数是否可迭代
    optimizer = optim.Adam(pg, lr=lr) #传入参数  #optimizer = optim.Adam(model.parameters(), lr=lr)
    
    overall_pbar = tqdm(total=epochs, desc="训练中", ncols=100, colour='green')#进度条
    
    for epoch in range(epochs):
        model.train()
        acc_num =torch.zeros(1).to(device)
        sample_num =0
        #train_bar= tqdm(train_loader,desc=f"Epoch {epoch + 1}/{epochs}", ncols=100, colour='green')
        for batch in train_loader:
            data, label = batch
            label = label.squeeze(-1)
            sample_num+=data.shape[0]
            
            optimizer.zero_grad()
            outputs = model(data.to(device)).squeeze(-1) 
            pred_label = (outputs > threshold).long()
            acc_num += torch.eq(pred_label, label.to(device)).sum()  
            loss = loss_f(outputs, label.float().to(device))
            loss.backward()
            optimizer.step()
            
        train_acc = acc_num.item()/sample_num
        val_acc = infer(model, val_loader, device)
        overall_pbar.set_postfix(epoch=epoch+1,loss=loss.item(), val_acc=val_acc)
        #print(f"第{epoch+1}轮训练完成，损失为：{loss.item()}    训练准确率为：{train_acc}   验证准确率为：{val_acc}")
        
        torch.save(model.state_dict(), os.path.join(save_path, f"model_{epoch+1}.pth"))
        train_acc = 0
        val_acc = 0
        
        overall_pbar.update(1)

    overall_pbar.close()
    test_acc = infer(model, test_loader, device)
    print("模型训练完成！")
    print(f"测试准确率：{test_acc}")
    
    """
    with torch.no_grad():
        correct = 0
        total = 0
        for batch in tqdm(val_loader):
            inputs, labels = batch
            inputs = inputs.to(device)
    """

if __name__ == "__main__":  
    main(lr, epochs)