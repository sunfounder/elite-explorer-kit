GY-87 IMU Modul
==========================

Das GY-87 Modul ist mit drei Sensorchips ausgestattet: MPU6050, QMC5883L und BMP180, die jeweils einzigartige Fähigkeiten bieten. Der MPU6050 kombiniert ein Gyroskop und einen Beschleunigungsmesser zur Bewegungsverfolgung, der QMC5883L dient als Magnetometer zur Richtungserkennung und der BMP180 wird zur Messung des barometrischen Drucks und der Temperatur verwendet. Diese können über das I2C-Protokoll für eine effektive Kommunikation mit einem Arduino verbunden werden.

Diese Sensoren sind für eine nahtlose Integration über das I2C-Protokoll konzipiert, was eine effiziente Kommunikation mit Plattformen wie Arduino gewährleistet. Jeder Sensor im GY-87 Modul ist über einzigartige I2C-Adressen zugänglich: MPU6050 unter 0x68, QMC5883L unter 0x0D und BMP180 unter 0x77.


Einzeltutorials für jeden Sensorchip:

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l


.. raw:: html

   <br/>

.. **Code für das GY-87 Modul**

Wenn Sie diese drei Chips gleichzeitig verwenden möchten, finden Sie hier ein einfaches Beispiel:


.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


.. note::

    * Sie können die Datei ``09-gy87.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\09-gy87`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note:: 
    Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager. 
    
        - Suchen Sie nach **„Adafruit MPU6050“** und installieren Sie

          Bei der Installation jeder Bibliothek stellen Sie bitte sicher, dass die Installation aller Abhängigkeiten ausgewählt wird.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Suchen Sie nach **„Adafruit Unified Sensor“** und installieren Sie
        - Suchen Sie nach **„QMC5883LCompass“** und installieren Sie
        - Suchen Sie nach **„Adafruit BMP085 Library“** und installieren Sie

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/efd14082-486b-47eb-9533-8d36a36d2d88/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. note::
   Magnetometer müssen kalibriert werden (:ref:`basic_gy87_calibrate`), bevor sie als Kompass verwendet werden können, und müssen waagerecht gehalten und **fern von Eisenobjekten, magnetisierten Materialien und stromführenden Drähten** gehalten werden.

Nachdem der Code erfolgreich auf Ihrem Arduino Uno R4 hochgeladen wurde, wird der Serielle Monitor aktiv und druckt kontinuierlich Sensordaten vom GY-87 IMU-Modul aus. Dieses Modul beinhaltet drei einzelne Sensoren: den MPU6050 für Beschleunigungs- und Gyroskopdaten, den QMC5883L für Magnetometerdaten und den BMP180 für barometrische Druck- und Temperaturdaten.
