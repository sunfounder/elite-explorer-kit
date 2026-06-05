课程 17：从串口监视器控制多个 LED
=========================================================

本课程演示如何使用 Arduino 创建用户控制的 LED 系统，用户可以通过串口监视器输入来打开和关闭不同的 LED。以下是您将学习的内容的简要概述：

1. **回顾之前的课后作业** ：回顾课程 16 的作业，其中涉及制作一个包含三个 LED（红色、黄色和绿色）的电路，并根据用户输入控制它们。
2. **搭建电路** ：关于如何正确将三个 LED 及其限流电阻连接到 Arduino 的详细说明。每个 LED 的长脚（阳极）连接到一个数字引脚，短脚（阴极）通过电阻连接到地。
3. **编写代码** ：逐步编码指导：定义每个 LED 的引脚，设置串口监视器以接收用户输入，使用 if 语句打开指定的 LED 并确保所有其他 LED 关闭，将用户输入转换为小写以处理不同的大小写情况。
4. **调试技巧** ：关于排查常见问题的指导，例如缺少分号、花括号不正确，以及确保在打开新 LED 时所有其他 LED 都已正确关闭。
5. **实际应用** ：使用 if 语句处理用户输入并根据输入控制多个输出（LED）的示例。
6. **课后作业** ：通过要求用户同时输入 LED 颜色和所需亮度来扩展项目。

**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/Ai7uqYHt_Yc?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
