import torch
from torch.utils.data import Dataset
import os
import numpy as np
import pandas as pd

class xy(Dataset):#制作dataset函数的子类，用于制作nn.py的数据处理模块
    def __init__(self, data_path):#传入文件路径
        self.data_path = data_path

        assert os.path.exists(self.data_path), "data_path does not exist"#判断文件路径是否存在
        df = pd.read_csv(self.data_path,names=['x','y'])#读取csv文件

        #//抽象数据合法化(定义一个字典，将抽象数据转化成普通数据)
        #//d={"A":0,"B":1,"C":2}
        #//df["y"]=df["y"].map(d)

        #//区分数据
        #//data = df.iloc[:, :1]  #行、列
        #//label = df.iloc[:, 1:] 

        #//标准化数据
        #//df =(df -np.mean(df))/np.std(df)#标准差标准化
        #//df = (df - df.min()) / (df.max() - df.min())#最小-最大归一化

        #将数据转换为numpy后转为tensor
        self.data =torch.from_numpy(np.array(df['x'], dtype="float32"))
        self.label=torch.from_numpy(np.array(df['y'], dtype="float32"))

        self.data_len = len(self.data)#数据长度
        print("数据长度：",self.data_len)

#pytorch规定重写
    def __len__(self):
        return self.data_len

    def __getitem__(self, index):
        #将数据转换为列表
        self.data = list(self.data)
        self.label = list(self.label)
        
        return self.data[index], self.label[index]
        