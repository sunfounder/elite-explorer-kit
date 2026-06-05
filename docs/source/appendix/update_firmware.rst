.. _update_firmware:

更新UNO R4 WiFi板上的无线电模块固件
==============================================================

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. 使用USB线将UNO R4 WiFi板连接到计算机。
2. 如果您正在运行Arduino IDE的串口监视器或串口绘图器，请关闭它们。

   您可以通过点击串口监视器选项卡上出现的X图标来关闭它：

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. 从Arduino IDE菜单中选择Tools > Firmware Updater。
   将打开"Firmware Updater"对话框。

   .. image:: img/update_firmware_1.png
         :width: 70%

4. 在"Firmware Updater"对话框中，从"Select Board"菜单中选择UNO R4 WiFi。
5. 点击"CHECK UPDATES"按钮。
   对话框中将会出现一个"INSTALL"按钮。

   .. image:: img/update_firmware_2.png
         :width: 85%

6. 点击"INSTALL"按钮。
   将开始"Installing firmware"过程，如对话框底部附近的消息所示。

   .. image:: img/update_firmware_3.png
         :width: 85%

7. 等待固件更新过程成功完成，如对话框中的消息所示：
   Firmware successfully installed.

   .. image:: img/update_firmware_4.png
         :width: 85%

8. 点击对话框中的X图标。
   对话框将关闭。
9. 从计算机上拔下UNO R4 WiFi板的USB线。
10. 再次使用USB线将UNO R4 WiFi板连接到计算机。


**参考**

- |link_update_firmware|