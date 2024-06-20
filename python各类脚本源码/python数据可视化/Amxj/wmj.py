# 导入matplotlib和numpy的第三方库
import matplotlib.pyplot as plt
import numpy as np
# 设置中文字体和解决负号显示问题
plt.rcParams['font.sans-serif']=[u'simHei']
plt.rcParams['axes.unicode_minus']=False
# 加载国民经济核算季度数据的.npz 文件
data = np.load("国民经济核算季度数据.npz", allow_pickle=True)
# 打印数据的列名
print(data.f.columns)
# 创建用于存储第一季度相关数据的列表
# 散点图：
plt.xticks(range(0,70,4),data.f.values[range(0,70,4),1],rotation=45) #设置横坐标刻度的位置和标签
#假设第一列是时间索引，第三、四、五列分别是第一、二、三产业的生产总值
plt.scatter(data.f.values[:, 0], data.f.values[:, 3], color="b", marker="p",label="第一产业生产总值")
plt.scatter(data.f.values[:, 0], data.f.values[:, 4], color="y", marker="*",label="第二产业生产总值")
plt.scatter(data.f.values[:, 0], data.f.values[:, 5], color="g", marker=",",label="第三产业生产总值")
plt.legend(loc="best")  #添加图例，并设置位置为最佳
#设置图表的标题和坐标轴标签
plt.title("2000-2017年各产业生产总值散点图")
plt.xlabel("时间")
plt.ylabel("生产总值(亿元)")
plt.show()      #显示散点图

plt.bar("第一产业生产总值", sum(data.f.values[:, 3]),label="第一产业生产总值")
plt.bar("第二产业生产总值", sum(data.f.values[:, 4]),label="第二产业生产总值")
plt.bar("第三产业生产总值", sum(data.f.values[:, 5]),label="第三产业生产总值")
plt.title("2000-2017 年各产业生产总值直方图")
plt.ylabel("生产总值（亿元）")
# 将图例放在右上角
plt.legend(loc="upper left")
# 显示直方图
plt.show()
# 计算三个产业生产总值的总和并存储到 total 列表
total=[]
total.append(sum(data.f.values[:, 3]))
total.append(sum(data.f.values[:, 4]))
total.append(sum(data.f.values[:, 5]))
# 定义标签
labels=["第一产业生产总值","第二产业生产总值","第三产业生产总值"]
# 绘制饼图
# plt.pie(total, labels=labels)
plt.pie(total, labels=labels, autopct='%1.1f%%', startangle=140)
plt.title("2000-2017 年各产业生产总值饼图")
# 将图例放在左中
plt.legend(loc="lower right")
# 显示饼图
plt.show()