import torch
from torch.utils.data import Dataset
import os
import pandas as pd
import numpy as np

class titanic(Dataset):
    def __init__(self, data_path):
        super(titanic, self).__init__()
        self.data_path = data_path

        assert os.path.exists(self.data_path), "data_path does not exist"
        
        # 正确读取 CSV 文件（假设文件有标题行）
        df = pd.read_csv(self.data_path, header=0)
        
        # 处理分类变量
        df["Sex"] = df["Sex"].map({"male": 1, "female": 0})
        df["Embarked"] = df["Embarked"].fillna("S")  # 直接赋值
        df["Embarked"] = df["Embarked"].map({"S": 0, "C": 1, "Q": 2})
        
        # 删除无关列
        df = df.drop(["Name", "Ticket", "Cabin"], axis=1)
        
        # 处理 Age 列的缺失值
        df['Age'] = pd.to_numeric(df['Age'], errors='coerce')
        df['Age'] = df['Age'].fillna(df['Age'].median()) 
        
        # 确保 Pclass 是数值类型
        df["Pclass"] = pd.to_numeric(df["Pclass"], errors="coerce")
        
        # 分离特征和标签
        data = df.drop(["PassengerId", "Survived"], axis=1)  # 特征列
        label = df["Survived"]  # 标签列
        
        # 标准化
        data = (data - data.mean()) / data.std()
        
        # 转换为 PyTorch 张量
        self.data = torch.from_numpy(data.values.astype(np.float32))
        self.label = torch.from_numpy(label.values.astype(np.int64))
        
        print(f"数据形状：{self.data.shape}")
        print(f"使用特征列：{data.columns.tolist()}")

    def __len__(self):
        return len(self.label)
    
    def __getitem__(self, index):
        return self.data[index], self.label[index]