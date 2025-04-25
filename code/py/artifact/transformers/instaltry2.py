
try:
    import tf_keras
except ImportError:
    raise ImportError(f"'tf_keras' could not be resolved. Please install it by 'pip install tf-keras'.")
    
from transformers import pipeline

# pipeline() 会下载并缓存一个用于情感分析的预训练模型和分词器。
classifier = pipeline("sentiment-analysis")

# 在目标文本上使用 classifier
classifier("We are very happy to show you the 🤗 Transformers library.")