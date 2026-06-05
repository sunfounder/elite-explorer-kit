课程 19：用 RGB LED 混合颜色
==========================================

本课程演示如何使用 Arduino 创建用户控制的 RGB LED 系统，用户可以通过串口监视器输入选择不同的颜色。以下是您将学习的内容的简要概述：

1. **回顾之前的课后作业** ：回顾课程 18 的作业，其中涉及控制 RGB LED，通过混合红、绿、蓝光来产生各种颜色。
2. **搭建电路** ：关于如何正确将 RGB LED 及其限流电阻连接到 Arduino 的详细说明。每个颜色通道（红、绿、蓝）连接到一个数字引脚（引脚 9、10 和 11），公共阴极（长脚）连接到地。
3. **编写代码** ：逐步编码指导：定义 RGB LED 每个颜色通道的引脚，设置串口监视器以接收用户输入，使用模拟写入命令调整每个颜色通道的亮度以混合不同的颜色，将用户输入转换为小写以处理不同的大小写情况，处理各种用户输入以通过适当混合 RGB 值产生特定颜色（红色、绿色、蓝色、青色、品红色、黄色、橙色、白色）。
4. **调试技巧** ：关于排查常见问题的指导：确保代码中的大小写和语法正确，检查缺少的分号和不正确的花括号，通过调整亮度级别调整 RGB 值以获得正确的颜色输出。
5. **实际应用** ：使用 RGB 值混合颜色以产生广泛颜色范围的示例。
6. **课后作业** ：让 RGB LED 按红、绿、蓝顺序闪烁，等待一秒钟，然后重复此序列 25 次。确保程序在 25 次循环后停止。制作解决方案的短视频，发布到 YouTube，并链接回本课程以供评审。

**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
