import os
os.environ["HF_ENDPOINT"] = "https://hf-mirror.com"  # 添加在导入 transformers 之前

from transformers import pipeline

generator = pipeline('text-generation', model='gpt2')
result = generator("Hello, I'm a language model", max_length=100)
print(result)


# 通过系统环境变量永久生效，无需修改代码。

#todo Windows
# 打开环境变量设置：

# 按 Win + S 搜索「环境变量」，选择「编辑系统环境变量」。

# 点击「环境变量」按钮，在「用户变量」或「系统变量」中新建一个变量：

# 变量名：HF_ENDPOINT

# 变量值：https://hf-mirror.com

# Windows 环境变量设置示例

# 重启终端或 IDE
# 配置后需重启终端或开发工具（如 VS Code、PyCharm）使环境变量生效。

#todo Linux/macOS
# 修改 Shell 配置文件
# 打开终端，编辑配置文件（根据 Shell 类型选择）：

# Bash：~/.bashrc 或 ~/.bash_profile

# Zsh：~/.zshrc

# bash
# 复制
# # 添加以下内容到配置文件末尾
# export HF_ENDPOINT="https://hf-mirror.com"
# 使配置生效
# 运行命令加载配置：

# bash
# 复制
# source ~/.bashrc  # 根据实际配置文件选择