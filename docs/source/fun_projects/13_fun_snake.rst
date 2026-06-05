.. _fun_snake:

游戏 - 贪吃蛇
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

此示例使用 R4 Wifi 板在 8x12 LED 矩阵上实现了经典的贪吃蛇游戏。
玩家使用双轴摇杆控制蛇的方向。

**所需元件**

在这个项目中，我们需要以下元件。

购买整套套件会更方便，以下是链接：

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - 名称
        - 套件所含项目
        - 链接
    *   - Elite Explorer 套件
        - 300+
        - |link_Elite_Explorer_kit|

您也可以从下面的链接单独购买。

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - 元件介绍
        - 购买链接

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**接线**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**原理图**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**代码**

.. note::

    * 您可以直接打开路径 ``elite-explorer-kit-main\fun_project\13_snake`` 下的 ``13_snake.ino`` 文件。
    * 或者将这段代码复制到 Arduino IDE 中。

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/df370ec5-d1b5-4ae7-b3b9-e97e0eb9a872/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**工作原理**

以下是代码的详细说明：

1. 变量定义和初始化

   导入 ``Arduino_LED_Matrix`` 库用于 LED 矩阵操作。
   matrix 是 LED 矩阵的一个实例。
   ``frame`` 和 ``flatFrame`` 是用于存储和处理屏幕上像素信息的数组。
   蛇表示为一个 ``Point`` 结构体数组，其中每个点具有 x 和 y 坐标。
   food 表示食物的位置。
   ``direction`` 是蛇当前的移动方向。

2. ``setup()``

   将摇杆的 X 轴和 Y 轴初始化为输入。
   启动 LED 矩阵。
   将蛇的起始位置初始化在屏幕中心。
   随机生成食物的初始位置。

3. ``loop()``

   根据摇杆的读数确定蛇的方向。
   移动蛇。
   检查蛇头是否与食物碰撞。
   如果是，蛇身增长，并在新位置生成新的食物。
   检查蛇是否与自身碰撞。如果是，重置游戏。
   在 LED 矩阵上绘制当前游戏状态（蛇和食物的位置）。
   添加延迟以控制游戏速度。

4. ``moveSnake()``

   将蛇的每个部分移动到前一部分的位置，从尾部开始向头部移动。
   根据蛇的方向移动蛇头。

5. ``generateFood()``

   生成所有可能的食物位置。
   检查每个位置是否与蛇的任何部分重叠。如果不重叠，则该位置被视为可能的食物位置。
   随机选择一个可能的食物位置。

6. ``drawFrame()``

   清除当前帧。
   在帧上绘制蛇和食物。
   将二维帧数组展平为一维数组（flatFrame）并将其加载到 LED 矩阵上。
