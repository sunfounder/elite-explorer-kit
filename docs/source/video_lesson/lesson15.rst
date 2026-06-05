课程 15：基于串口监视器的用户输入控制 LED
====================================================================

本课程演示如何使用 Arduino 创建用户交互程序，重点是通过串口监视器获取用户输入并根据输入执行不同的操作。以下是您将学习的内容的简要概述：

1. **回顾之前的课后作业** ：回顾课程 14 的作业，其中涉及通过从串口监视器获取用户输入来控制 LED 的亮度。
2. **搭建电路** ：关于如何正确连接 LED 和电阻到 Arduino 的说明，确保每个元件都正确配置用于实验。
3. **编写代码** ：逐步编码指导，从串口监视器读取用户输入并使用它调整 LED 的亮度。这包括数学计算，将用户输入转换为 Arduino 可用于控制 LED 亮度的值。
4. **指数缩放** ：解释如何使用指数缩放，确保 LED 的感知亮度在用户输入范围内平滑增加。
5. **调试技巧** ：关于排查常见问题的指导，例如读数不正确或影响 LED 亮度的输出错误。
6. **课后作业** ：创建一个程序，要求用户为 LED 输入亮度级别（0 到 10 之间），然后相应地设置 LED 亮度。

**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/d-Ma3u7GngA?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
