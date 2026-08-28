.. _basic_imu:

IMU 模块 (10 轴)
==========================

.. note:: 该套件的不同版本可能使用不同的 IMU 模块。请根据您所拥有的套件版本选择相应的教程。如果您拥有 10 轴 IMU 模块，请参阅本教程。如果您拥有 GY-87 模块，请参阅 :ref:`basic_gy87` 课程。

10 轴 IMU（惯性测量单元）模块集成了多个传感器，提供全面的运动和环境数据。它集成了用于高度测量的气压传感器（SPL06_001）、用于加速度和旋转的 6 轴运动传感器（SH3001）以及用于罗盘航向的 3 轴磁力计（QMC6310）。这款精密的模块非常适合机器人、导航系统和运动追踪应用。





Fritzing 电路
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


安装库
---------------------------------

要安装库，请使用 Arduino 库管理器。

   - 搜索 **"SunFounder_IMU"** 并安装


      .. image:: img/09-add_lib_tip_imu.png



校准
----------------------

在使用 IMU 模块之前，建议进行校准以确保传感器数据的准确性。以下是校准步骤：

* 直接打开 ``elite-explorer-kit-main\basic_project\09-imu_calibration`` 路径下的 ``09-imu_calibration.ino`` 文件。

运行此代码后，打开串口监视器，您将看到传感器数据输出。通常格式如下：

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

复制此数据。

运行代码
----------------------


直接打开 ``elite-explorer-kit-main\basic_project\09-imu`` 路径下的 ``09-imu.ino`` 文件。

转到项目中的 ``calibration_data.h`` 页面，将刚复制的数据粘贴到 ``calibration_data.h`` 文件中，替换原有数据。

.. image:: img/imu_cali_data.png
   :width: 80%

切回 ``09-imu.ino`` 页面，将代码上传到您的 Arduino Uno R4 板。

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

代码成功上传到您的 Arduino Uno R4 后，串口监视器将开始运行，持续打印来自 10 轴 IMU 模块的传感器数据。

.. image:: img/imu_reading.png
