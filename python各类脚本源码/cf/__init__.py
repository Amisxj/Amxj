# __init__.py 为初始化加载文件
# 导入图片
from airscript.screen import FindImages
# 导入上下环境
from airscript.system import R

# 导入ui界面
from .res.ui import draw
# 导入yolo模型
from airscript.screen import yolo_v5

# 导入时间
import time
# 导入滑动
from airscript.action import slide
# 导入点击
from airscript.action import click
# 导入-屏幕检索库
# 找色
from airscript.screen import FindColors
# 比色
from airscript.screen import CompareColors
# 找图
from airscript.screen import FindImages
# 文字识别
from airscript.screen import Ocr

# 加载模型
yolo = yolo_v5("cf:1.1")


#获取图片信息
a = R(__file__).res("/img/开始游戏.png")
b = R(__file__).res("/img/界面.png")
c = R(__file__).res("/img/弹出.png")



# spear是枪，litter是小怪，boss是大怪，ability是技能，jump是跳跃
direct = None
jump = None
ability = None
spear = None
litter = None
boss = None
方向 = "方向"
跳跃 = "跳跃"
技能 = "技能"
枪口 = "枪口"
小怪 = "小怪"
大怪 = "大怪"

#坐标信息
spear_x = None
spear_y = None
litter_x = None
litter_y = None 
boss_x = None
boss_y = None




#绘制模型
def find(a,b):
    print(a)
    if a and b != "小怪" and b != "大怪":
        draw.add_rect(a.label + str(a.prob), 600000, a.x, a.y, a.w, a.h)
        print("找到了"+b)
    elif a and (b == "小怪" or b == "大怪"):
        draw.add_rect(a.label + str(a.prob), 300, a.x, a.y, a.w, a.h)
    else :
        pass  #print("找不到"+b)

#判断是否出现图片
def img(imgtext):
    if imgtext !=None and imgtext["confidence"]>=0.8:
        return True
    else:
        print("图片未出现")
        return False

#获取坐标并点击
def dianji(ps) :
    temp = ps.get('result')
    click(temp)

#等待图片出现10s
def wait(ph) :
    time_start = time.time()
    time_end = 0
    time_wait = time_end - time_start
    content = FindImages(ph).find()
    while time_wait<20 or img(content)=="False":
        content = FindImages(ph).find()
        if img(content):
            # 输入找图结果的属性
            print("中心坐标为:x=%d,y=%d" % (content['result'][0], content['result'][1]))
            print("范围:", content["rectangle"])
            print("准确度:", content["confidence"])
            dianji(content)
            return True
        else:
            print("等待出现")
        time_end = time.time()
        time_wait = time_end - time_start
        time.sleep(1)
        print(str(int(time_wait))+"秒")

# 开始游戏
wait(a)
time.sleep(10)
print("等待10秒后执行")
# 关闭弹窗页面
wait(b)

print("等待5秒")
time.sleep(5)


box = yolo.find_all()
print("模型类型：")
print(box)
for button in box:
    if button.label == "方向":
        direct = button   
    elif button.label == "跳跃":
        jump = button
    elif button.label == "技能":
        ability = button
    elif button.label == "枪口":
        spear = button
    else:
        print("找不到")
    if spear is not None:
        spear_x = spear.x + spear.w/2
        spear_y = spear.y + spear.h/2



# 找到方向、跳跃、技能、枪口的固定坐标位置并绘制
# 绘制基本按钮
print(direct)
print("找按钮方向")
find(direct,方向)
find(jump,跳跃)
find(ability,技能)
find(spear,枪口)

#移动到指定位置
slide(340,664,340,510,10000)


print("寻找怪物")
#寻找到怪物
while True:
    box = yolo.find_all()
    for temp in box:
        if temp.label == "小怪" and temp.prob>0.6:
            litter = temp
        elif temp.label == "boss" and temp.prob>0.6:
            boss = temp           
    find(litter,小怪)
    find(boss,大怪)
    if spear !=None and litter!=None:
        litter_x = litter.x + litter.w/2
        litter_y = litter.y + litter.w/2
        slide(spear_x,spear_y,litter_x,litter_y,300)


