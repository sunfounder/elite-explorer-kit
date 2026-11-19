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


校准
----------------------

在读取传感器数据之前，先对 IMU 进行校准，让测量结果更准确。

#. 安装 **SunFounder_IMU** 库：打开 Arduino 库管理器，搜索 **"SunFounder_IMU"**，然后点击 **INSTALL**。下图为安装完成后的界面。

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. 打开 ``elite-explorer-kit-main\basic_project\09-imu_calibration`` 路径下的 ``09-imu_calibration.ino`` 文件，并将它上传到开发板。

#. 打开串口监视器，将波特率设为 **115200**，行尾符设为 **Both NL & CR**。

#. 按串口监视器中的提示完成六面校准：

   * 发送任意字符开始校准，串口监视器会显示第一个朝向。
   * 按提示把模块依次摆成六个朝向：Z 朝上、Z 朝下、X 朝上、X 朝下、Y 朝上、Y 朝下。
   * 每次测量时保持模块完全静止，然后再次发送任意字符测量当前朝向，再进入下一个朝向。

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. 六个朝向测量完成后，串口监视器会打印校准常量。复制这六行：

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   以上数值仅为示例，实际数值只属于你自己的模块。

#. 打开 ``09-imu`` 项目及其中的 ``calibration_data.h`` 标签页，用刚复制的数值替换这六个数组。

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. 将 ``09-imu.ino`` 上传到 Arduino Uno R4 开发板，串口监视器会持续输出加速度计、陀螺仪、磁力计和气压计的数据。

   .. image:: img/imu_reading.png
