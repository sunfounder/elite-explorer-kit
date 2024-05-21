.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _i2c_sacnner:

Wie scannt und erkennt man I2C-Adressen?
==============================================

Dieses Tutorial nimmt das Scannen der I2C-Adresse des GY-87-Moduls als Beispiel und leitet Sie an, wie Sie I2C-Adressen erkennen können.

Verdrahtung
---------------

Verbinden Sie den SCL des GY-87-Moduls mit dem SCL des UNO R4 und verbinden Sie den SDA des GY-87-Moduls mit dem SDA des UNO R4.

Eine andere Möglichkeit besteht darin, den SCL des GY-87-Moduls mit A5 des UNO R4 zu verbinden und den SDA des GY-87-Moduls mit A4 des UNO R4 zu verbinden.

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

Code hochladen
-----------------

Kopieren Sie den untenstehenden Code in Ihre Arduino IDE und laden Sie dann den Code hoch.


.. code-block:: arduino

   #include <Wire.h>
   
   // Set I2C bus to use: Wire, Wire1, etc.
   #define WIRE Wire
   
   void setup() {
     WIRE.begin();
   
     Serial.begin(9600);
     while (!Serial)
       delay(10);
     Serial.println("\nI2C Scanner");
   
     // Enable bypass Mode for mpu6050
     Wire.beginTransmission(0x68);
     Wire.write(0x37);
     Wire.write(0x02);
     Wire.endTransmission();
   
     Wire.beginTransmission(0x68);
     Wire.write(0x6A);
     Wire.write(0x00);
     Wire.endTransmission();
   
     // Disable Sleep Mode
     Wire.beginTransmission(0x68);
     Wire.write(0x6B);
     Wire.write(0x00);
     Wire.endTransmission();
   }
   
   
   void loop() {
     byte error, address;
     int nDevices;
   
     Serial.println("Scanning...");
   
     nDevices = 0;
     for (address = 1; address < 127; address++) {
       // The i2c_scanner uses the return value of
       // the Write.endTransmisstion to see if
       // a device did acknowledge to the address.
       WIRE.beginTransmission(address);
       error = WIRE.endTransmission();
   
       if (error == 0) {
         Serial.print("I2C device found at address 0x");
         if (address < 16)
           Serial.print("0");
         Serial.print(address, HEX);
         Serial.println("  !");
   
         nDevices++;
       } else if (error == 4) {
         Serial.print("Unknown error at address 0x");
         if (address < 16)
           Serial.print("0");
         Serial.println(address, HEX);
       }
     }
     if (nDevices == 0)
       Serial.println("No I2C devices found\n");
     else
       Serial.println("done\n");
   
     delay(5000);  // wait 5 seconds for next scan
   }


Nachdem Sie den Code hochgeladen haben, öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein. Überprüfen Sie die Ausgabe im seriellen Monitor.

Dies sind die erkannten I2C-Adressen. Sie können sich auf relevante Informationen beziehen, um zu bestimmen, welche Chips diesen Adressen entsprechen. In diesem Fall steht ``0x68`` für MPU6050 und ``0x77`` für BMP180. Die Adresse ``0x1E`` ist für QMC5883L, und gelegentlich (aufgrund unterschiedlicher Produktionschargen) kann die Adresse von QMC5883L auch ``0x0D`` sein.

.. image:: img/gy87-i2c.png
    :width: 100%
