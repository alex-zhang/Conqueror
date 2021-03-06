#STCode Format 

    STCode 全称SmartCode 是一个和QRCode类似，但应用场合不同的图像编码定义。他比QRCode有。

## 原则特性
+ STCode 编码图形十分简洁（这是前提，因为这样他才叫STCode的）
+ 整个图形由色块构成，白色表达空白色，其他颜色视为有效颜色，当然这会有阈值来控制
+ 整个图形是要求是正方形，且边的色块数量为奇数
+ 图形的中间会有个识别区，识别区域是个3x3的色块构成，要求中心那个色块是空白色块（中心色块），其中四边上有且仅有一空白色块（基准色块）。 识别区图案是整个
图形中具有唯一性的图案，在识别区域的任何其他地方不允许出现和识别区一致的图形。
+ 识别区以外的地方为数据区使用有效色块表达1，空白色块表达0， 外层数据区的层数这里不做约束
+ 数据区从基准色块 相连的数据色块开始，顺时针方表达数据。
+ 数据区的数据格式： b(4) 随机mask + b(8) index + b(4) flag
+ 一个画布里面可以包含多个STCode但要求是两个STcode相隔的距离最小是二者中间色块宽度最大的那个（这是一个建议不是标准）

![](STCode.png)