

>编辑作者：Seer Technical Support
>编辑时间：2020 年 10 月 09 日
>联系邮箱：[support@seer-group.com](mailto:support@seer-group.com)
>文档版本：v1.0.0
# charger

## 一、充电桩的安装方式

充电桩的正确安装方式只有两种：

1.背靠墙壁（可以不用固定）

2.使用膨胀螺栓固定在地面上（推荐方式）

正确放置示意图：

![图片](https://uploader.shimo.im/f/nEXATZ8Lk2Io7h0l.png!thumbnail)![图片](https://uploader.shimo.im/f/S51loIBcPToVChv4.png!thumbnail)

背靠墙壁放置法（临时使用）                                膨胀螺栓固定法（推荐方法）

错误放置示意图：

![图片](https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1156948800,579516193&fm=26&gp=0.jpg)**充电桩未可靠固定**

![图片](https://uploader.shimo.im/f/sgGOjHVr9hwpmmtk.png!thumbnail)

充电桩未可靠固定

3.充电桩要与AMB处于同一平面上

正确情况：

![图片](https://uploader.shimo.im/f/7GRJhw6t2VogZxnT.png!thumbnail)


错误情况：

![图片](https://uploader.shimo.im/f/IVt9FsXdTtYIvHOE.png!thumbnail)


## 二、AMB 自动充电

**适用机器人类型: AMB**

**使用前提：充电桩正常通电(需使用官方 AMB 充电桩)****且按照要求放置在环境中**

备注：AMB 充电激光均在机器人前方

### 2.1 配置方法

1.建立地图，将充电桩扫描进地图内，如下图：

![图片](https://uploader.shimo.im/f/g4BeIaO1tgstvaGf.png!thumbnail)

红框中为充电桩

2.遥控 AMB，使 AMB 的充电机构，正对 AMB 充电桩的充电口，使用 Roboshop 按照 0.02m/s 的速度手动控制 AMB 前进（**注意要将【参数配置】-【安全性】中的 ManualBlock 参数配置为 false**，否则机器人可能会被阻挡，从而停止运动）使 AMB 充电机构插入 AMB 充电桩，若  Roboshop 中显示电池电流为正值，说明 AMB 开始充电。**（若因地面不平整的原因，导致 AMB 无法插入 AMB 充电桩，需要更换到平整地面，或者，调整充电桩地脚，使 AMB 能够顺滑无阻力的插入充电桩）。**

![图片](https://uploader.shimo.im/f/5jnH6mkO6eH7m9Zl.png!thumbnail)

3.将鼠标悬停在代表机器人的蓝色矩形上，右键点击，选择“标记特殊工作站”，将会出现充电点 ChargePoint；对于AMB机器人，注意CP点的朝向务必与机器人进入充电桩的方向一致；![图片](https://uploader.shimo.im/f/rHakIJenbDsYQl94.png!thumbnail)

4.选择充电点的识别模型文件为：amb.charger**（如果不选择，则为无识别的路径导航方式充电）**![图片](https://uploader.shimo.im/f/rrC6Bz97hI4qbVZg.png!thumbnail)

5.控制机器人后退，后退到距离 CP 点 1m 的位置附近时，将鼠标悬停在代表机器人的蓝色矩形上，右键点击，标记站点，会出现一个 LM 点，此时，可以将**【参数配置】-【安全性】**中的 ManualBlock 参数改回**true；**![图片](https://uploader.shimo.im/f/cf93DJ2Bvy4QLQsl.png!thumbnail)

6.将 LM 点与 CP 点进行连接，并且配置好 LM -> CP 点的机器人行走 direction 和 CP -> LM 点的机器人行走 direction；进入充电点为**正走**，导航方式为路径导航；退出充电点为**倒走**，导航方式为路径导航；LM2至CP1之间连线一定要**直连**；

![图片](https://uploader.shimo.im/f/crwJ4ux958oVyO8m.png!thumbnail)

![图片](https://uploader.shimo.im/f/twG71eMrHqAYPfw2.png!thumbnail)

7.将 LM2 设置为 CP1 的前置点，如下图：

![图片](https://uploader.shimo.im/f/InDyfoVdpJIPgmO2.png!thumbnail)

8.将配置的充电点和前置点与地图中的其他站点相连，形成机器人可达的线路，如下图：![图片](https://uploader.shimo.im/f/NaWjzQMVj8Evchxn.png!thumbnail)

9.保存并推送地图至机器人，使用路径导航至 CP1 点，即可进行自动充电。![图片](https://uploader.shimo.im/f/Pvo3wCR7lWMx9kQ2.png!thumbnail)

### 2.2 错误示例

![图片](https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1156948800,579516193&fm=26&gp=0.jpg)前置点距离过远

![图片](https://images-cdn.shimo.im/YeqURPeyus4pQ9Jb/image.png!thumbnail)


![图片](https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1156948800,579516193&fm=26&gp=0.jpg)前置点不在充电点正前方

![图片](https://images-cdn.shimo.im/jSdZdcTnVr8212ih/image.png!thumbnail)


![图片](https://ss1.bdstatic.com/70cFvXSh_Q1YnxGkpoWK1HF6hhy/it/u=1156948800,579516193&fm=26&gp=0.jpg)前置点与充电点之间的线路不是直线

![图片](https://images-cdn.shimo.im/bZ8yJp4JZ4QdQCeq/image.png!thumbnail)


## 附录：

## 一、自动充电桩参数配置说明（以 AMB 为例）

**该附录内容仅针对接受过培训的技术人员或集成商客户**

1. 充电桩 2D 图纸
![图片](https://uploader.shimo.im/f/niGfGlBcKkECcFhO.png!thumbnail)


充电桩上反光条的宽度建议为 15~20cm 左右，高度建议大于等于 5cm，反光条中心位置的离地高度要与机器人激光雷达离地高度相近。

1. 充电桩识别文件

**注：如果充电桩上没有反光条，则无法进行识别充电（请使用路径导航至固定位置进行充电），本节内容可忽略。**

#### 2.2.1 查看已有充电桩识别文件

点击 Roboshop 中的【识别文件】标签即可切换至机器人识别文件管理，首先点击“全部拉取”按钮跟机器人同步所有识别文件（绿色勾代表文件已同步）：

![图片](https://uploader.shimo.im/f/K3E5us9pqPwjLxs6.png!thumbnail)

然后选择 charger 中的 amb 即为 AMB 充电桩的识别文件，如下图：

![图片](https://uploader.shimo.im/f/IUk9iyyQlnAWcfw5.png!thumbnail)


**参数说明：**

**minwidth**：充电桩上反光条的最小宽度

**maxwidth**：充电桩上反光条的最大宽度

**注：机器人会同激光雷达检测宽度大于 minwidth 且小于 maxwidth 的反光条，从而确定充电桩位置**

**dx**：充电极片，相对于充电桩坐标系原点，在 x 轴上的偏移量，标准 AMB 充电桩为 0.025 左右

**dy**：充电极片，相对于充电桩坐标系原点，在 y 轴上的偏移量，标准 AMB 充电桩为 0

**注：充电桩坐标系原点即为反光条的中心，Z 轴不需要考虑**

![图片](https://uploader.shimo.im/f/owLkRTXvp60kXhfQ.png!thumbnail)

下图指示了 dx 的含义：

![图片](https://uploader.shimo.im/f/ynDz3b3x0hYEk3wU.png!thumbnail)


设计充电桩时，dy 最好为 0，即在充电桩正视图中，充电机构中心与反光板中心位于一条垂线上，如下图：

![图片](https://uploader.shimo.im/f/gppYTtme6SwlFd4w.png!thumbnail)


#### 2.2.2 新建充电桩识别文件

若要新建识别文件，请右键点击已有的充电桩识别文件，选择复制并添加，如下图：

![图片](https://uploader.shimo.im/f/jA1ZQs3GH9YJzpvl.png!thumbnail)


可以对新识别文件重命名或者设置参数，如下图：

![图片](https://uploader.shimo.im/f/iAHOll6UDlkn9AQj.png!thumbnail)


编辑完后，右键新的充电识别文件，选择推送即可将识别文件推送至机器人中，如下图：

![图片](https://uploader.shimo.im/f/txx0SYWItbM35a4t.png!thumbnail)


出现绿色勾说明推送成功：

![图片](https://uploader.shimo.im/f/FRGK7bntSfQYRLRm.png!thumbnail)


此时点击【地图与控制】标签切换回地图编辑界面，启用地图编辑，选择 CP 点，即可更换 CP 点的识别文件，如下图选择了刚才新添加的 new_charger 识别文件：

![图片](https://uploader.shimo.im/f/VqwR2ljN7vMMRbrh.png!thumbnail)


最后，保存地图文件并推送至机器人。至此，新建充电桩识别文件并配置使用新识别文件的操作结束，机器人将能识别新的充电桩进行充电。

1. 机器人模型中关于充电机构的配置

点击 Roboshop【机器人模型】标签切换至机器人模型编辑界面，选中 charger 即可看到机器人充电机构：

![图片](https://uploader.shimo.im/f/BEih2pLbFQU9dgcp.png!thumbnail)


通过属性窗口来修改充电机构的参数配置：设备名、位置等。

![图片](https://uploader.shimo.im/f/tol284jDDe0yVSpd.png!thumbnail)


**"x"**、**"y"**为设置充电机构的位置。请务必根据机器人坐标系（右手坐标系），按照实际情况进行准确填写（一般情况下 "x" 就是车头的距离，"y" 为 0）。

**注意：当实际充电时，如果发现机器人停止运动后充电机构过于插入充电桩或者未完全插入充电桩，可以微调 "x" 的数值，使得机器人的充电机构正确的插入充电桩。（减小 "x" 将使机器人更远离充电桩，增大 "x" 将使机器人更进入充电桩）**

#### **2.3.1 充电 DO 控制**

**预置条件**：所要控制的充电 DO 必须装配有充电回路继电器。若无该继电器或不需要控制该充电 DO 时，将 switchDO 设置为 -1 即可。

**"switchDO"**：用于在充电时控制是否打开充电 DO 或打开对应 id 的充电 DO ，不开启时该数值填写为 -1 。例如：在充电时需要打开充电 DO3，则该数值应该填写为 3 。

**"openDODist"**：表示在自动模式下，当机器人和充电桩距离小于该参数时，会将充电 DO 打开。例如：设置该数值为 1 和 switchDO 为 7 时，在充电距离小于 1 m 的时候，会打开充电 DO7；当这个值配置为 0 时，将会启用新逻辑：通过看是否有 DI 被配置成 "openCharge"，如果有，  那就导航直到有一个符合要求的 DI 被触发后停下，之后再将充电 DO 打开。特别注意：如果不存在硬件 DO，而是使用虚拟 DO 进行控制，需要在模型文件中 DO 列中添加一个 DO

**"disableByEMC"**：拍急停是否关闭充电 DO ，勾选则为拍急停断开充电 DO ，反之将充电 DO 置于打开状态。

#### 2.3.2 注意事项

若 switchDO 设为 -1，则参数 "openDODist"、"disableByEMC" 是不会被触发的。

若配置了充电 DO ，那么机器人在自动模式下，自动运行到充电桩 openDODist 范围内，会将 DO 打开，出了这个区域内，则会自动关闭 DO 。

若机器人正在充电，在自动模式下，退出充电点时，也会自动将充电 DO 关闭再运动。

若要使用该功能，请确认 openDODist 是否合适（该参数设置过大，会导致过早打开 DO ，充电片带电；该参数设置过小，会导致机器人已经与充电桩接触，但还未开始充电）。

# 
## 二、自动充电桩参数配置说明（以地牛为例）

### 2.1 配置充电桩

地牛的激光平面不同于标准AMB车型，因此地牛在自动识别充电桩时，需要将反光条张贴在地牛的激光平面内（如图2.1.1所示），同时应保证反光条的中心与充电桩中心垂直对齐（间图2.1.2）。如中心未对齐，则会导致电池极片对不齐，此时可根据实际情况调整反光条位置或充电桩位置。此外，可以并排粘贴两张反光条，来确保识别效果（见图2.1.3）。

![图片](https://uploader.shimo.im/f/jyXmREJ6A8J5gnou.png!thumbnail)

**图2.1.1 反光条应在激光检测面内**

![图片](https://uploader.shimo.im/f/daBl7JlAzpPI6JOG.png!thumbnail)

**图2.1.2 垂直对齐**

![图片](https://uploader.shimo.im/f/WP85woUmBJyOjIeZ.jpeg!thumbnail)

**图2.1.3 并排粘贴的反光条**

**注意事项：**

1. 充电桩间的最小间隔距离：考虑到当两反光条之间的距离太近时，地牛的自动识别会出现误识别情况，现规定两充电桩（反光条）之间的最小距离不得小于1.16米；
2. 激光最大识别距离：地牛的激光与贴在墙面上的反光条之间的距离不得大于1m，如超出1m，可能会出现“recognize charger failed”的警告，此时应适当缩小识别距离。
### 2.2 配置识别文件

**dx**：充电极片，相对于充电桩坐标系原点，在 x 轴上的偏移量，需要手动测量；

**dy**：充电极片，相对于充电桩坐标系原点，在 y 轴上的偏移量，默认量为0。

地牛充电时要着重配置**dx**的数值，配置方法如下：

1. 在手动模式下控制地牛前进进入充电点，在正常充电状态下，量取地牛前端充电极片到反光条所在平面（墙面）的距离**X**（**注意：此时充电极片应处于收缩最紧状态**）；

![图片](https://uploader.shimo.im/f/OR36QJW6d41q11lU.png!thumbnail)

**图2.2.1 X的定义**

1. 由于模型文件中的充电模块有一半体积在车体外侧，因此最终的**dx**值不应大于**X**-10。

![图片](https://uploader.shimo.im/f/3QGEwrXUnDVLHHoi.png!thumbnail)

**图 2.2.2**

### 2.3 其他注意事项

1. 地牛的自动充电口在机器人前方，因此进入充电点时为正走，退出充电点时为倒走；

![图片](https://uploader.shimo.im/f/6wdsUdN4awBtUWXT.png!thumbnail)

**图2.3.1 正确的路径设置**

1. 考虑到地牛的车型较长，转弯半径较大，因此在规划cp点、前置点以及充电路径时，应尽可能预留出车体运动的空间；
2. 如在充电时出现”虚拟激光被阻挡“的报错，可在充电点上添加Di区域，关掉相应的Di接口；或在路径设置上，将“virtualLaser”勾选为“false”（如图2.3.1所示）。
# pallet

## FM830-GI 图漾相机

本公司选用的图漾相机型号为FM830-GI，主要用于地面障碍物检测以及栈板识别。本文主要对相机的使用适配和相关注意事项作简要的说明。

### 一、相机模型文件配置

使用图漾FM830相机时，将其与主控USB口连接后可上电运行，在Roboshop上需要配置如下：![图片](https://uploader.shimo.im/f/Bffe0Hg9X0VcSNNq.png!thumbnail)

其中PercipioID是相机的唯一ID码，在相机机身后面白色标签上。如果安装两个以上830时，需要正确填写相机进行区分，如果只安装一个830时，可以设置为空，则程序会默认连接当前的相机。

![图片](https://uploader.shimo.im/f/wX38ydiYwlmDHn8t.jpg!thumbnail)

**如果相机是用于识别栈板进行货物叉取的话，勾选onlyForPalletDetection**

### 二、栈板识别功能注意事项

默认当前只能识别左右对称的栈板，即中间孔的尺寸是一致的。在使用栈板识别功能前，需要在识别文件选项配置pallet相关参数，分别为：

pallet_width:栈板宽度

pallet_height:栈板高度

pocket_width:中间孔宽度

pocket_height:中间空高度

pocket_spacing:中间腿宽度

栈板高度指栈板支撑柱的高度，不包括支撑柱之间连接物体的高度，栈板的厚度(栈板高度减去中间孔高度)要大于3cm以上，小于3cm可能会识别不到

如下图所示：

![图片](https://uploader.shimo.im/f/UWXELBDG9ZGhXxUA.jpg!thumbnail)

栈板摆放时栈板和机器人之间坐标系的偏差角一般小于20度，栈板中心和叉车中心的垂直机器人方向距离小于栈板的宽度，超过则无法识别。栈板距离相机一般大于1m，小于3m。

### 三、栈板识别叉车运动参数说明

参数配置中：

RecQRCode_AheadDist， 识别规划前置距离

RecQRCode_BackLength， 识别规划后置距离

RecQRCode_PathSpeed， 识别路径的行驶速度


# shelf

## 介绍

### 1.1 顶升模块模型文件简介

具有顶升模块的机器人通常作业方式为：钻入到货架底部顶起货架，运送到位之后放下货架。

顶升模块在机器人模型文件中对应于 jack_type 现在有四种类型：

* 0 代表没有顶升模块；
* 1 代表不带随动的顶升模块；
* 2 代表类 Kiva 车的可随动的顶升模块；
* 3 代表用户自定义的顶升模块；
* 4 代表牵引顶升机构。

当 Jack_type 为 1, 2, 3 类别时，动作序列为：

* 动作 1：识别货架（可选）。
* 动作 2：移动到货架底部。
* 动作 3：利用 PGV 进行二次位置校准(可选) 。
* 动作 4：顶升。

其中，当 Jack_type 为 3 时候，因为是用户控制顶升模块，因此 Robokit 将不会检验顶升状态（如是否上升到位 是否下降到位），完成动作 2 或者动作 3 后，这时候访问任务状态，将直接返回已完成。

当 Jack_type 为 4 时，作为牵引的顶升机构，动作序列为：

* 动作 1：识别货架（可取消）
* 动作 2：顶升
* 动作 3：移动到货架底部
* 动作 4：利用 PGV 进行二次位置校准(可取消)
### 1.2 注意事项

1.目前执行机构为 Jack 的顶升机器人，只支持顶升模块中心与机器人里程中心重合的情况（随动顶升机器人、AMB 配合顶升模块都是符合这个限制的）。

2.货架设计原则（现成货架需要满足的基本要求，不满足则货架需要改造或重新设计）：

(a).原则 1：一般情况下，货架是有四条腿，要求四腿形成一个矩形，假设四条腿对角线连接交点为 O，如图 1(a) 货架坐标系示意图所示；其中 X 轴正方向伸出侧为机器人进入货架底部的那一侧。

(b).原则 2：确定机器人钻入的方向，并在此方向的两条腿上贴上 5CM 宽的 3M 反光条，反光条的材质推荐使用钻石级（Diamond Grade 4090 或者 983-10），不要使用在交通应用里使用的反光板，例如 3990。其中，贴反光条的两条腿如图标注，我们建立货架坐标系如图 1(a) 中所示。需要保证两个反光条的中点和货架中点重合，误差要小于顶升对位的需求。

(c).原则 3：货架设计的其他部分都要求成轴对称的形式，包含：和顶升机构配合的限位孔、货架腿上支撑的货架部分。

(d.)原则 4：货架内侧宽度要比机器人最大宽度宽 20cm，也就是左右各冗余 10cm 的钻货架调整空间。

(e).原则 5：货架高度要求，根据顶升模块的行程确定。

3.建议：机器人顶起货架后，要求激光外露，不能看到两条货架腿。

![图片](https://uploader.shimo.im/f/nEAEoZKUIQAe0A8B.png!thumbnail)![图片](https://uploader.shimo.im/f/WivuxW0sojYEMzS6.png!thumbnail)

(a) 货架坐标系示意图****(b) 机器人坐标系示意图

**图 1.  (a) 货架坐标系示意图; (b) 机器人坐标系示意图**

顶升机器人顶起货架时，机器人里程中心、顶升机构中心、货架中心需要三点重合。

4.货架摆放位置说明。

由于为了减小误识别的情况，使用激光识别料架时要求货架的前面两条腿中心距离和前置识别点的距离小于 2m，中心点到识别位置激光的连线和车体的角度偏差小于 10°, 料架本身的角度和识别时的 AGV 的角度偏差小于 20°.

5.识别精度说明。

在使用激光识别货架方法时，可选用带反光板和不带反光板两种，使用反光板的识别精度会高于不带反光板的精度。

带反光板：x, y 方向的精度高于 ±2cm, 角度精度高于 2°.

不带反光板：x, y 方向精度高于 ±3cm, 角度精度高于 2.5°.

## 二、带货架识别的顶升任务教程

现有货架，只要满足设计原则里的硬性要求，机器人利用粘贴反光条的形式对客户货架进行很小的改造，就可以实现机器人对货架的识别与定位，从而可以钻入货架底部，为顶升货架做好准备。

### 2.1 货架尺寸需要满足的要求

根据所选机器人车体尺寸的不同，货架的尺寸也有不同，目前货架只支持矩形。

尺寸需求如下：

#### 2.1.1货架宽度的需求

对于不需要随动功能：货架内侧宽度要比机器人最大宽度宽 20cm, 也就是左右各冗余 10cm 的钻货架调整空间。

对于需要随动功能：架内侧宽度要比机器人宽度和长度都大 20cm, 也就是左右各冗余 10cm。使AGV在货架底部能够无阻挡的转动。

#### 2.1.2货架高度的需求

货架高度要求：根据顶升模块的行程确定。不能低于机器人高度，高于机器人高度加顶升最大量程的高度。

#### 2.1.3货架腿宽度的需求

如果是识别模式，货架腿宽度要大于3 cm。非识别对货架腿的宽度没有要求

### 2.2 增加货架识别准确的改造

可直接购买 3M 汽车反光胶贴（要求详见1.2（b）部分），一般宽度为 5CM, 反光条宽度不能小于 5CM, 如下图所示：

![图片](https://uploader.shimo.im/f/0YcXtilLreUHc0Jb.png!thumbnail)

**反光贴**

剪取 5CM 长的两块（即得到两块 5CM*5CM 的反光胶贴），贴于货架腿上：

1.高度方向：要求反光条中心与激光扫描平面对齐。

2.宽度方向：要求反光条内侧与货架腿内侧平齐，如图所示。

![图片](https://uploader.shimo.im/f/YrmCN3mLDZIo4IYT.png!thumbnail)

**贴好反光贴的货架**

### 2.3 货架的其他需求

货架和机器人摩擦力要足够大，防止机器人急停时，货架和机器人相对滑动。

货架内部最好没有反射面，防止激光出现噪点。

## **三、**机器人货架描述文件配置说明

### 3.1 介绍

因为工厂中可能存在各种各样的满足机器人钻入要求的货架，机器人在不同的任务中，也可能被指定钻入不同的货架，因此我们需要对机器人要钻入的各种货架进行描述，货架描述文件的后缀名为 .shelf, 存放于 Robokit/resources/objects/shelf/ 目录下。在 Roboshop 识别文件中货架标签下编辑。

### 3.2 配置说明

打开 Roboshop 软件，点击【识别文件】标签页进入配置界面，选择一个【shelf】文件，在右侧的属性窗进行货架描述文件的参数配置。如下图所示：

![图片](https://uploader.shimo.im/f/8mCQqU7Vpcpz02xH.png!thumbnail)

**货架描述文件编辑界面**

其中，【属性窗口】的各个参数释义如下：

设备名：货架型号名，同一个场景中，可能存在不同型号的货架，一般该描述文件名即为设备名，例如： s0002.shelf

**注：如需修改设备名，请【另存为】后修改文件名称后，选择【shelf】模块，使用【加载】功能载入修改后的货架描述文件，进行推送即可。**

width: 改造后，钻入方向上，两个货架腿的外侧宽度。这里的宽度，是指改造后，两块反光条的最外侧宽度。

length: 垂直于钻入方向的两个货架腿的最外侧宽度。

leg_width: 反光条宽度，若选用标准 3M 汽车反光贴，即为 0.05（米）。

align_depth: 前置线路为“倒走”，也就是机器人钻入货架底部后，机器人坐标系 x 轴正方向与货架 x 轴正方向重合时（参考[图 1](https://shimo.im/docs/7036d117f33a4593#anchor-maz1)货架坐标系示意图及机器人坐标系示意图），机器人停下的位置和货架前腿之间的距离，开放出来配置，主要是便于实施时候调整。

anti_align_depth: 前置线路为“正走”，也就是机器人钻入货架底部后，机器人坐标系 x 轴正方形和货架 x 轴正方向差 180 度（参考[图 1](https://shimo.im/docs/7036d117f33a4593#anchor-maz1)货架坐标系示意图及机器人坐标系示意图），机器人停下的位置和货架前腿之间的距离，开放出来配置，主要是便于实施时候调整。

outer_width: 因为存在货架顶部，比货架腿形成的矩形要大的情况，因此有这个参数；这个宽度的方向和参数[width](https://shimo.im/docs/7036d117f33a4593#anchor-dd8f)****是同向的。

outer_length:  因为存在货架顶部，比货架腿形成的矩形要大的情况，因此有这个参数；

这个长度的方向和参数[ length](https://shimo.im/docs/7036d117f33a4593#anchor-6889)是同向的。注意为了防止反光条的噪声，outer_length 至少需要比 length 大 5cm.

extra_dist: 激光抠出区域的宽度

leg_type: 货架腿类型，方形（cube）和圆柱形（cylinder）可选，暂时不起作用。

其中，识别钻货架相关的参数有 "width", "leg_width",  "align_depth", "anti_align_depth". AGV 顶起货物后形状变化的相关的参数有 "outer_width",  "outer_length". 扣除激光点的区域相关的参数有 "extra_dist", "leg_width", "width", "length".

货架描述文件的参数与真实货架的关系如图 2, 3 所示。黄色区域 AGV 顶起货架后，形状变化的轮廓，红色为激光扣除区域。

![图片](https://uploader.shimo.im/f/s1EG6x60Kk0jFXxk.png!thumbnail)

**图 2. 货架描述文件与真实货架的关系**

![图片](https://images-cdn.shimo.im/jRJsI4vP5kAF0yqG/image.png!thumbnail)

**图 3. 货架的描述文件与实物的关系**

"align_depth" 和 "anti_align_depth" 的作用是用来校准 AGV 钻入的深度，如图 3 所示，AGV 识别钻入货架的距离由这两个参数确定。

"align_depth" 是 AGV 在倒走时钻入的深度。

"anti_align_depth" 是 AGV 在正走时钻入的深度。

另外还有一个前置距离在配置参数中为 "D_GoWithJack_AheadDist", 钻入深度和前置距离之和为 AGV 钻入货架时直线的行走距离。

![图片](https://uploader.shimo.im/f/6mjrSaz42wQxsYnk.png!thumbnail)

**图 3. AGV 识别后的运动轨迹**

### 3.3 推送并同步货架描述文件

1.配置完货架描述文件后，点击【全部保存】右击该文件，如下图所示：

![图片](https://uploader.shimo.im/f/ZVG3F87J1fECOGby.png!thumbnail)

2.右击配置完成的文件，点击【推送 ↑ 】按钮进行推送和同步操作，如下图所示：

![图片](https://uploader.shimo.im/f/ChVJ8Yu51WY1EVqh.png!thumbnail)

3.也可点击【全部保存】后，点击【全部推送】进行整个【识别文件】的推送和同步操作，如下图所示。

## **四、Roboshop 任务配置流程**

### **4.1 预置条件**

请构建好地图并上传机器人并重定位正确。

### **4.2 标定任务**

1.将货架摆放到日常工作位置。

2.这步中识别和非识别两种模式配置会不同。

(a).识别模式：地图中添加工作站，工作站的位置需要比货架实际可能摆放的位置靠后一点。

(b).非识别模式：通过 Robosohp 的手控功能 W, A, S, D 控制机器人钻入货架底部，在该机器人上右键选择【标记工作站】，如下图所示：

![图片](https://uploader.shimo.im/f/3JAaC9crbeoc1SXv.png!thumbnail)

3.配置工作站：识别和非识别的配置内容是相同的。进入【地图编辑】界面，点击刚才标记添加的工作站，查看工作站的类型选为 ActionPoint，执行对象为顶升机构，因此选择 jack, 识别的模型文件即为[ ](https://shimo.im/docs/7036d117f33a4593#anchor-fIhk)[第三章](https://shimo.im/docs/7036d117f33a4593#anchor-fIhk)****节中介绍的 .shelf 文件，如下图所示：

![图片](https://uploader.shimo.im/f/prYaOeH72cEsKS0a.png!thumbnail)

**配置工作站**

4.设置工作站前置点， 要求机器人在前置点时，激光距离货架反光条最少 0.5 米，前置点朝向需要根据实际工况进行设置，原则是机器人在这点进行识别货架并钻货架的任务时，需要激光朝向货架腿。

典型情况是，LM3 到 AP4 为正走时，LM3 的朝要和 AP4 的朝向一致，如下图所示：

![图片](https://uploader.shimo.im/f/PVZlmxMgKrw224zw.png!thumbnail)

**从前置站到工作站为正走时的路线**

LM3 到 AP4 为倒走时（即为识别完成后，转身 180 度，再倒退进入货架，LM3 的朝向与上一种情况相反），如下图所示，同时该图中，由于机器人钻入货架后，再出来的时候为了避免机器人原地转动，我们把工作点的朝向也改为了机器人倒走时候的车头朝向。

![图片](https://uploader.shimo.im/f/oUCBUHlIXwMbOvBV.png!thumbnail)

**从前置站到工作站为倒走时的路线**

**注意事项：**

**1.LM3 到 AP4 及 AP4 到 LM3，需要将线路属性中的 ObsExpansion 设置为 0，避免钻货架过程中机器人停障。**

**2.无论机器人正向进入货架，还是倒走进入货架，机器人钻货架任务结束后，激光头都必须露出货架（防止搬送货架过程中激光看到货架腿）。**

### 4.3 下发任务

机器人可能会存在以下几种任务：

* Load 货架（顶升）。
* Unload 货架（下降）。
* Wait（钻入并等待）。
* Height (顶升调节到某个高度，目前只有 SeerJack 采用这个功能)。

执行任务时，先点击【路径导航】，然后选中【工作点】，选择【执行动作】，若选择【路径导航】，机器人只会根据地图上的线路进行路径导航并到达 AP 点。

![图片](https://uploader.shimo.im/f/AdHarIoZlLMP14SX.png!thumbnail)**执行动作到 AP 点**

会跳出对话框，根据机器人的任务不同，我们需要进行不同的勾选和选择：

![图片](https://uploader.shimo.im/f/zkylu5xu9eolMUFc.png!thumbnail)

**执行动作的选项界面**

1.需要识别货架所在位置，并钻入货架顶升起来，需要勾选 Recognize，点击 Load.

2.不需要识别货架所在位置，开环的钻入到一个固定位置上，并顶升起来，不需要勾选 Recognize，直接点击 Load.

3.需要识别位置上有没有货架，并放置货架，勾选 Recognisze，点击 Unload，若有货架占用的话，会报错；不需要识别，直接开环放置，不用勾选 Recognisze，直接点击 Unload.

4.需要点击 Wait 的情况比较少,若勾选了 Recognize，再点击 Wait，机器人就会识别货架位置，钻入货架底部，然后结束任务，不会动作顶升模块；若不勾选 Recognize，直接点击 Wait，机器人就会固定路径导航到工作站，然后结束任务，不会动作顶升。

5.总结：

(a).勾选 Recognize，会使机器人识别出货架位置，自主规划路径进入货架底部；

(b).不勾选 Recognize，机器人直接根据线路，固定路径导航到该 AP 点；

(c).Load Unload Wait 指示的是机器人到点之后的动作，Load 指示顶升升起，Unload 指示顶升放下，Wait 指示不动作。

(d).勾选了 use_pgv，前提是机器人装备了 PGV 传感器，机器人将钻入货架底部后，根据 PGV 的识别结果，调整姿态

**注：勾选 Recognize，却不存在货架，会导致机器人识别不到，停在原地。**

## 五、程序设计简要说明

钻货架任务，对应于机器人动作 GoWithJack.

主要有两个事情需要注意：

1.机器人顶起货架后，会自动根据描述文件，抠掉货架腿的区域（防止行走时候被阻挡） (扣除范围由 length, width,  outer_width,  out_length,  extra_dist_, leg_width_ 决定）。

2.当机器人放下货架时，会把上述 1、2 设置的内容复原，也就是不抠除特定区域，恢复机器人原有大小。

当机器身上有货物后，其运行参数也会发生变化具体参数如下：

```
"loadedParameters": {
        "MoveFactory": {
            "Load_MaxSpeed": 1.5,
            "Load_MaxAcc": 0.5,
            "Load_MaxDec": 0.5,
            "Load_MaxRotAcc": 60,
            "Load_MaxRotDec": 60,
            "Load_MaxManualAcc": 0.5,
            "Load_MaxManualDec": 0.5,
            "Load_Load_MaxManualRotAcc": 60,
            "MaxManualRotDec": 60,
            "Load_ObsDecDist": 5,
            "Load_ObsStopDist": 1,
            "Load_ObsExpansion": 0.15,
            "Load_StopAcc": 2,
            "Load_StopRotAcc": 150
        }
    },
    "unloadedParameters": {
        "MoveFactory": {
            "MaxSpeed": 2,
            "MaxAcc": 1,
            "MaxDec": 1,
            "MaxRotAcc": 90,
            "MaxRotDec": 120,
            "MaxManualAcc": 1,
            "MaxManualDec": 3,
            "MaxManualRotAcc": 120,
            "MaxManualRotDec": 180,
            "ObsDecDist": 5,
            "ObsStopDist": 1,
            "ObsExpansion": 0.1,
            "StopAcc": 2,
            "StopRotAcc": 150
        }
    }
```
所以，使用机器人时，尽量不要使用 roboshop 手控中的顶升，因为这个并不会对上述 1、2、3 有任何操作。有可能出现手控放下了，因为之前是任务顶起的，所以机器人还把自己尺寸设置很大，导致比较容易停障的情况。
**注：使用任务操作、使用任务操作、使用任务操作**

## **六、多种货架的使用方法**

### 6.1 Roboshop Pro 准备：

在 Roboshop 的安装目录，找到以下文件：

![图片](https://uploader.shimo.im/f/cudgAS8BGOcvf8sD.png!thumbnail)

**定义多个货架名称得文件**

在框出来的区域，加入新的货架类型，这样，重启 Roboshop 后，就能够在 ActionPoint 的类型中选择它了。

![图片](https://uploader.shimo.im/f/uFdPDDlxSLQguq7W.png!thumbnail)

**定义多个货架的位置**

### 6.2 Robokit 准备：

#### 6.2.1 Robokit 3.0 版本和 Roboshop 2.1.2.4 版本之前的操作方式

1.需要在 Robokit/resources/objects/shelf/ 目录下同样添加同名称的识别文件，具体操作方法如下：

(a).打开 Roboshop 进入【首页】，找到需要进行描述文件修改的机器人的 IP 地址，点击机器人图标上的设置按钮：

![图片](https://uploader.shimo.im/f/Ps0HxKvJwEsg60Nr.png!thumbnail)

(b).打开【高级配置】界面后，选择【机器人文件】并打开【Robokit Objects】目录：

![图片](https://uploader.shimo.im/f/WrGbF9ZHgPVWoitn.png!thumbnail)

(c).进入【shelf】目录，并选择 S0002.shelf 文件，点击【下载选中文件】将文件下载至本地：

![图片](https://uploader.shimo.im/f/113D6jI2L9oV876V.png!thumbnail)

(d).将下载至本地的 s0002.shelf 文件的内容参考根据实际情况进行修改。

货架描述文件是文本文件，可以用记事本等软件打开，进行直接修改编辑。

```
{
	"class": "shelf",  #货架名称，无需修改
	"type": "s0002",   #货架编号
	"width": 0.8,  #货架腿外侧的宽度，与“识别相关”
	"length": 0.6,  #货架腿外侧之间的长度
	"leg_type": "cube",  #货架腿是正方形还是圆形
	"leg_width": 0.05,  #货架腿宽度，与“识别相关”
	"align_depth" : 0.39,  #自动识别下，倒走钻入的深度
	"anti_align_depth": 0.27, #自动识别下，正走钻入的深度
	"outer_width":0.86,  #用于碰撞检测的宽度
	"outer_length":0.9,  #用于碰撞检测的长度
	"extra_dist" : 0.1   #用于扣除货架腿区域的膨胀余量
}
```
(e).将修改好的 .shelf 文件上传机器人，在【高级配置】→【机器人文件】→【Robokit Objects】→【shelf】界面点击【上传文件到指定目录】，选择并打开：

![图片](https://uploader.shimo.im/f/LIJDyCjhGq4EECB3.png!thumbnail)

(f).上传成功后，【shelf】列表中会出现所上传的文件：

![图片](https://uploader.shimo.im/f/IrGS0rjjDWmhuSbU.png!thumbnail)



#### 6.2.2 Robokit 3.0 版本和 Roboshop 2.1.2.4 版本之后的操作方式

需要在识别文件夹下目录下同样添加同名称的识别文件，具体操作方法如下：

1. 打开 Roboshop 进入【首页】，找到需要进行描述文件修改的机器人 IP 地址，进入【地图与编辑】界面，选择【识别文件】标签页，打开【shelf】目录：

![图片](https://uploader.shimo.im/f/USDXKXWfdJyM7oIn.png!thumbnail)

**识别文件界面**

2. 在左侧 shelf 目录下，选中任意一个文件，右击选择【复制并添加】：

![图片](https://uploader.shimo.im/f/9Q09ucgDELISgZbt.png!thumbnail)

**新建识别文件操作说明**

3.点击新添加的识别文件，在右侧的属性窗口进行参数的配置：

![图片](https://uploader.shimo.im/f/TvOsEvm4CqIn7iem.png!thumbnail)

**新建识别文件的参数配置**

4.编辑完成后，点击【全部保存】，再点击【全部推送】，提示【推送识别文件成功】：

![图片](https://uploader.shimo.im/f/2BMWLZl5XnFw44Oe.png!thumbnail)

**新建识别文件推送同步操作**

## 

# tag

## **一、Introduction**

在目前使用二维码进行货物识别定位时，选取的相机型号为 ，在使用二维码进行定位时，需要注意二维码的选取，目前支持的 AprilTag 种类有 16h5，25h7 以及 36h11，每一种二维码的数量分别为 30，242 和 587 个。![图片](https://uploader.shimo.im/f/mtTSAcuFDMMsimWc.png!thumbnail)

**左边是 16h5，左边是 36h11**

如上图所示，其中字母 h 前面的数字代表的是在每一种 tag 里的模块数量，例如 16h5 指的是包含了 16 (4*4) 个模块（在 C 的范围里，黑色和白色颜色块），36h11 中是包含了 36 个模块。而字母后面的数字指的是同一种类的 tag，不同 ID 之间的 Hamming 距离。16h5 指的是该种类不同 ID 的 tag 之间的 Hamming 距离为 5，36h11 的不同 ID 之间的 Hamming 距离为 11。

16h5 相比于 36h11 的优势在于相同尺寸时分辨率更低，因此可被观测距离更远，但同时缺点是更容易被误识别，因此需要根据需要选择不同种类的 tag。

## 二、camera模型文件配置

将Realsense与SRC核心控制器上USB 3.0连接。

需要在模型文件配置中拖入相机，然后在相机类型里选择 realsense。根据实际安装效果，输入相机在机器人坐标系中的位置 x 、y 以及 z，如下图所示：

![图片](https://uploader.shimo.im/f/mNqF1MtJHx4o8tdV.png!thumbnail)


## **三、realsense识别文件配置说明**

### **3.1 介绍**

实际使用二维码时，通常将两个二维码对称贴在目标物体上，识别的位置为两个二维码的中点，因此需要指定二维码与目标物体之间的空间关系。将坐标关系描述记录在描述文件，后缀名为.tag，存放于 Robokit /resource/objects/tag/目录下，或在 Roboshop 识别文件中“tag”标签下编辑。

### 3.2 配置说明

打开 Roboshop 软件，点击【识别文件】标签页进入配置界面，选择一个【tag】文件，在右侧的属性窗进行货架描述文件的参数配置。如下图所示：

![图片](https://uploader.shimo.im/f/KNvxDSBVRyrK3WMd.png!thumbnail)

**tag描述文件编辑界面**

其中，【属性窗口】的各个参数释义如下

X_Dis：二维码中心在货架坐标系中x方向的坐标；

Y_Dis：二维码中心在货架坐标系中y方向的坐标；

Z_Dis：二维码中心在货架坐标系中z方向的坐标；

goodsWidth：货架宽度；

goodsLength：货架长度；

tagDistance：两二维码中心的水平距离（默认在同一高度）；

tagSize：二维码大小；

Tagtype：二维码种类。

**备注：当默认二维码对称贴于货架前端两侧时，X_Dis的值为货架长度的相反数（负值），Y_Dis的值为0， Z_Dis的值为二维码中心****的离地高度。**

![图片](https://uploader.shimo.im/f/uxXtfEIO3dGuXrUk.png!thumbnail)

**tag的描述文件与实物的关系**


## 四、精度以及使用说明

### 4.1 最大识别距离

对于二维码识别而言，识别的位置精度随着距离增加而减小，在二维码离相机超过最大识别距离时，就无法识别到二维码。

![图片](https://uploader.shimo.im/f/GR4PTZ7dvPIsc9ua.png!thumbnail)

对于 AprilTag 而言，其中每个模块的大小为：S=t/r，其中 t 是二维码的大小，r 是模块的在 x 方向的数量。而在像素坐标系里，需要识别出每个 tag，每个模块至少为 5*5 个像素， 因此最大观测距离可以近似表示为：D=f*t/u，其中 f 为相机的焦距，t 为 tag 的实际尺寸，u 为二维码的最小像素数量。因此如果二维码的尺寸为 10cm*10cm，假设相机的焦距为 1075，对于不同种类的二维码的最大观测距离分别为：


|种类|最少像素|Tag宽度|最大观测距离|
|:----:|:----|:----:|:----|:----:|:----|:----:|:----|
|16h5|30|6*6（s）|3.58m|
|25h7|35|7*7   (s)|3.07m|
|36h11|40|8*8   (s)|2.69m|

### 4.2 识别精度

识别二维码的定位精度与许多因素相关，包括二维码和相机的距离，角度以及光照影响，假设在足够的光照条件下，可以看到识别定位的误差随着距离和角度增大的关系如下图

![图片](https://uploader.shimo.im/f/Fs4YQmZi3Qw80JDK.png!thumbnail)

总体而言识别的误差随着距离和角度的增大开始变大，具体分析可以参考论文（Accuracy analysis of marker-based 3D visual localization）。

**注：在通常比较好的情况下，相机的 Z 方向垂直于二维码平面，相机距离二维码 2m 以内时，测量出的位置在垂直方向的精度小于 2cm，水平方向的精度小于 1.5cm。**

### 4.3 使用说明

将两个二维码对称贴在待识别物体表面，如下图所示：

![图片](https://uploader.shimo.im/f/ZRtLfUHlO5QgGMZH.jpg!thumbnail)

二维码需要粘贴平整，其中二维码应垂直正确贴在目标物体表面，二维码最好保持横平竖直贴放，即有数字和 id 的需要朝下水平放置，方向如下：

![图片](https://uploader.shimo.im/f/ncEBtHjZQ2IPaWgJ.png!thumbnail)


**可以参考 Seer 顶升/钻货架教程，在 AP 点设置描述文件，然后选择执行机构。下发任务后，机器人就会开始识别执行任务。**




## 


