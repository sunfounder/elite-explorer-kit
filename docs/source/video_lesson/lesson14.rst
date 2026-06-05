课程 14：从串口监视器读取用户输入
====================================================

本课程演示如何使用 Arduino 创建用户交互程序，重点是通过串口监视器获取用户输入并根据输入执行不同的操作。以下是您将学习的内容的简要概述：

1. **通过串口监视器获取用户输入简介** ：介绍从 Arduino 串口监视器读取用户输入的概念，这对于交互项目至关重要。
2. **设置串行通信** ：关于在 Arduino 代码中设置串行通信的详细说明，使用 Serial.begin(9600) 初始化串口监视器。
3. **读取不同的数据类型** ：关于如何从用户读取各种数据类型的逐步指导：整数：使用 Serial.parseInt() 读取整数值。浮点数：使用 Serial.parseFloat() 读取浮点数。字符串：使用 Serial.readString() 读取字符串。
4. **使用 While 循环等待用户输入** ：解释如何实现 while 循环以等待用户输入，确保程序在用户输入所需数据之前不会继续执行。
5. **串行输入的错误处理** ：关于处理与错误数据类型相关的错误的技巧，并确保串口监视器设置为"无行结束符"，以防止额外字符被读取为输入。
6. **实际应用和示例代码** ：一个示例项目，其中要求用户输入一个数字、一个浮点数和一个字符串，演示如何有效捕获和使用这些输入。提供的代码展示了如何请求输入、等待输入，然后读取和处理输入。
7. **课后作业** ：创建一个程序，要求用户为 LED 输入亮度级别（0 到 255 之间），然后相应地设置 LED 亮度。



**视频**

.. raw:: html

    <iframe width="100%"
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef"
        title="YouTube video player"
        frameborder="0"
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
        allowfullscreen>
    </iframe>
