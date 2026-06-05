课程 18：使用 Arduino 控制 RGB LED
================================================

本课程演示如何使用 Arduino 控制 RGB LED，通过混合红、绿、蓝三种光来创建不同颜色，建立在之前关于控制 LED 和使用 Arduino 的 PWM 功能的课程基础上。以下是您将学习的内容的简要概述：

1. **回顾之前的课后作业** ：回顾课程 17 的作业，其中涉及创建一个包含三个 LED（红色、黄色和绿色）的电路，并根据用户输入控制它们。
2. **搭建电路** ：关于如何正确将 RGB LED 连接到 Arduino 的详细说明。RGB LED 有四个引脚：一个公共接地端和三个用于红、绿、蓝 LED 的引脚。每个颜色通道需要一个单独的限流电阻，以防止串扰并确保正常运行。
3. **编写代码** ：逐步编码指导：定义 RGB LED 每个颜色通道的引脚，设置串口监视器以接收用户输入，使用数字写入命令打开和关闭每个颜色通道，将用户输入转换为小写以处理不同的大小写情况。
4. **实际应用** ：通过打开红、绿、蓝 LED 的不同组合来控制 RGB LED 产生各种颜色的示例。
5. **课后作业** ：通过要求用户指定颜色来扩展项目，包括红色、绿色、蓝色、青色、品红色、黄色、橙色和白色。

**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/ASHBCGGeEPk?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
