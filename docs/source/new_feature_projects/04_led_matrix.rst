.. _new_led_matrix:

12x8 LED 矩阵
========================================

Arduino UNO R4 WiFi 配有一个集成的 12x8 LED 矩阵，可以通过编程显示各种图形、动画、充当界面，甚至促进游戏体验。

.. image:: img/unor4wifi.webp
    :width: 60%

在本指南中，我们提供一个简单的示例来帮助您在 LED 矩阵上显示所需的图案。

如何在 Arduino 中存储 LED 矩阵数据
-----------------------------------------

要使用 LED 矩阵，您需要 ``Arduino_LED_Matrix`` 库，该库与 Renesas 核心一起安装。

UNO R4 WiFi 的 LED 矩阵库通过创建和加载帧到缓冲区来显示它们。一个帧，也称为"图像"，表示当前在矩阵上显示的内容。在由多个图像组成的动画中，每个图像被视为一帧。

要控制 UNO R4 WiFi 上的 12x8 LED 矩阵，至少需要 96 位内存空间。该库提供了两种方法。

**一种方法使用二维数组** ，用 0 和 1 表示相应的 LED 是否熄灭或点亮。每个数字对应 LED 矩阵上的一个 LED。以下数组展示了一个心形图案。

.. code-block:: arduino

   // Use a two-dimensional array to represent a 12x8 LED matrix.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**另一种方法使用 32 位整数数组** 来维护 LED 矩阵状态。这种方法更紧凑但稍微复杂一些。每个 ``unsigned long`` 存储 32 位。因此，对于一个包含 96 个 LED 的 12x8 LED 矩阵，您至少需要三个 ``unsigned long`` 变量。

1. 每个 ``unsigned long`` 包含 32 位，您可以将这些位视为 LED 矩阵中某一部分的状态。
2. 这些 ``unsigned long`` 变量形成一个数组，封装了完整的 LED 矩阵状态。

以下是一个使用三个 `unsigned long` 变量表示 12x8 LED 矩阵的代码片段。

.. code-block:: arduino

   // Use an array of 32-bit integers to store the LED matrix.
   unsigned long frame[] = {
     0x3184a444, // State of the first 32 LEDs
     0x42081100, // State of the next 32 LEDs
     0xa0040000  // State of the last 32 LEDs
   };

为了更好地可视化 LED 状态，这些值可以转换为二进制形式，其中每个位依次从左到右、从上到下表示每个 LED 状态。0 表示熄灭，1 表示点亮。

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

在 LED 矩阵上显示图案
-----------------------------------------

图案准备好后，下一步是将此数据传输到 12x8 LED 矩阵。这通常涉及调用库函数并将包含 LED 状态的数组或变量传递给这些函数。

1. 使用二维数组

   要显示存储在 2D 数组中的图案，您可以使用以下代码：

   .. code-block:: arduino

      #include <Arduino_LED_Matrix.h>

      ArduinoLEDMatrix matrix;

      // Pre-defined 2D array
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };

      void setup() {
        // Initialize LED matrix
        matrix.begin();
      }

      void loop() {
        // Display pattern on the LED matrix
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }

   在这段代码中，我们使用 ``matrix.renderBitmap(frame, 8, 12);`` 函数来显示 LED 矩阵。这里，8 和 12 分别代表 LED 矩阵的行和列。

2. 使用 32 位整数数组

   要显示存储在 ``unsigned long`` 数组中的图案，请使用以下代码：

   .. code-block:: arduino

      #include "Arduino_LED_Matrix.h"

      ArduinoLEDMatrix matrix;

      void setup() {
        matrix.begin();
      }

      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };

      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }

   在这种情况下，我们需要使用 ``matrix.loadFrame(heart)`` 函数在 LED 矩阵上显示图案。


Arduino LED 矩阵编辑器
-----------------------------------------

我建议使用 ``unsigned long`` 数组来存储 LED 矩阵的状态，因为它可以节省 Arduino 上的内存。虽然这种方法可能不是很直观，但您可以使用 |link_led_matrix_editor| 作为辅助工具，它可以帮助您生成 ``unsigned long`` 数组。

借助 |link_led_matrix_editor| 和 ``Arduino_LED_Matrix`` 库，您可以方便地创建图标或动画，并在 UNO R4 WiFi 板上显示它们。您只需绘制、下载 ``.h`` 文件，并在您的 sketch 中调用 ``matrix.play()`` 函数，即可轻松构建您的下一个项目。



#. 打开 LED 矩阵编辑器

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. 在中央画布上绘制您的图案

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. 以毫秒为单位设置帧间隔

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. 您可以创建一个新的空白帧，或从当前帧复制并创建一个新帧。

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. 导出 ``.h`` 头文件

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   点击确定后，您将收到一个名为 ``animation.h`` 的文件。


显示动画
-----------------------------------------

在前面的步骤中，我们获得了一个 ``.h`` 文件，其中存储了一系列帧及其持续时间。接下来，让我们在 LED 矩阵上显示它们。

#. 首先，创建一个 sketch。您可以打开位于路径 ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` 下的 ``04-led_matrix.ino`` 文件，或将此代码复制到 **Arduino IDE** 中。

.. literalinclude:: /_code/04_led_matrix.ino
   :language: cpp
   :linenos:
   :caption: 04-led_matrix.ino


#. 如果您使用的是来自 ``elite-explorer-kit-main\r4_new_feature\04-led_matrix`` 路径的代码，您会在 Arduino IDE 中找到一个名为 ``animation.h`` 的选项卡。打开它，并用您从网站获取的 .h 文件替换现有代码。

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. 如果您创建了自己的 sketch，则需要将从网页获得的 ``.h`` 文件复制到 sketch 的同一目录中。

#. 在 Arduino IDE 中设置好您喜欢的代码并将其上传到您的 Arduino UNO R4 WiFi 后，您的 LED 矩阵现在应该显示您定义的图案。

   .. raw:: html

      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         Your browser does not support the video tag.
      </video>

   恭喜！您已成功编程了 Arduino UNO R4 WiFi 的 12x8 LED 矩阵！


**参考**

- |link_r4_led|

**更多项目**

* :ref:`fun_snake` （趣味项目）
