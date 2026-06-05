课程 20：Arduino 中的 For 循环
=================================
本课程演示如何使用 Arduino 创建用户控制的 RGB LED 系统，用户可以通过串口监视器指定闪烁次数。以下是您将学习的内容的简要概述：

1. **回顾之前的课后作业** ：回顾课程 19 的作业，其中涉及使 RGB LED 按红-绿-蓝顺序闪烁 25 次循环。
2. **搭建电路** ：关于如何正确将 RGB LED 及其限流电阻连接到 Arduino 的详细说明。每个颜色通道（红、绿、蓝）连接到一个 PWM 数字引脚（引脚 9、10 和 11），公共阴极（长脚）连接到地。
3. **编写代码** ：逐步编码指导：定义 RGB LED 每个颜色通道的引脚，设置串口监视器以接收用户输入，使用模拟写入命令控制每个颜色通道的亮度，实现 for 循环以根据用户输入控制闪烁循环次数，确保程序在指定闪烁次数后停止。
4. **调试技巧** ：关于排查常见问题的指导：纠正代码中的语法错误，确保程序循环正确的次数，正确处理用户输入并在指定循环后停止程序。
5. **实际应用** ：使用 for 循环将一系列动作重复指定次数的示例。
6. **课后作业** ：不使用 for 循环，将闪烁序列重复用户指定的次数。确保程序在指定闪烁次数后停止。

**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/CZh8QB26jjU?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
