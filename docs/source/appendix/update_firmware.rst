.. _update_firmware:

Update the radio module firmware on your UNO R4 WiFi board
------------------------------------------------------------------

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. Connect the UNO R4 WiFi board to your computer with the USB cable.
2. If you have the Arduino IDE Serial Monitor or Serial Plotter running, close them.

   You can close Serial Monitor by clicking the X icon that appears on its tab when selected:

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. Select Tools > Firmware Updater from the Arduino IDE menus.
   The "Firmware Updater" dialog will open.

   .. image:: img/update_firmware_1.png
         :width: 70%

4. Select the UNO R4 WiFi from the "Select Board" menu in the "Firmware Updater" dialog.
5. Click the "CHECK UPDATES" button.
   An "INSTALL" button will be added to the dialog.

   .. image:: img/update_firmware_2.png
         :width: 85%

6. Click the "INSTALL" button.
   An "Installing firmware" process will start, as indicated by the message near the bottom of the dialog.

   .. image:: img/update_firmware_3.png
         :width: 85%

7. Wait for the firmware update process to finish successfully, as indicated by the message in the dialog:
   Firmware successfully installed.

   .. image:: img/update_firmware_4.png
         :width: 85%

8. Click the X icon in the dialog.
   The dialog will close.
9. Disconnect the USB cable of the UNO R4 WiFi board from your computer.
10. Connect the UNO R4 WiFi board to your computer with the USB cable again.


**Reference**

- |link_update_firmware|