.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _i2c_sacnner:

¿Cómo escanear y detectar direcciones I2C?
==============================================

Este tutorial toma como ejemplo el escaneo de la dirección I2C del módulo gy-87 y te guía sobre cómo detectar direcciones I2C.

Cableado
---------------

Conecta el SCL del módulo GY-87 al SCL del UNO R4, y conecta el SDA del módulo GY-87 al SDA del UNO R4.

Otra forma es conectar el SCL del módulo GY-87 al A5 del UNO R4, y conectar el SDA del módulo GY-87 al A4 del UNO R4.

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

Subir el código
--------------------

Copia el código a continuación en tu IDE de Arduino y luego sube el código.

.. code-block:: arduino

   #include <Wire.h>
   
   // Configurar bus I2C a utilizar: Wire, Wire1, etc.
   #define WIRE Wire
   
   void setup() {
     WIRE.begin();
   
     Serial.begin(9600);
     while (!Serial)
       delay(10);
     Serial.println("\nI2C Scanner");
   
     // Habilitar modo bypass para mpu6050
     Wire.beginTransmission(0x68);
     Wire.write(0x37);
     Wire.write(0x02);
     Wire.endTransmission();
   
     Wire.beginTransmission(0x68);
     Wire.write(0x6A);
     Wire.write(0x00);
     Wire.endTransmission();
   
     // Deshabilitar modo de suspensión
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
       // El escáner I2C utiliza el valor de retorno de
       // Write.endTransmission para ver si
       // un dispositivo respondió a la dirección.
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


Después de subir el código, abre el monitor serial y configura la velocidad de baudios a 9600. Verifica la salida en el monitor serial.

Estas son las direcciones I2C detectadas. Puedes referirte a la información relevante para determinar qué chips corresponden a estas direcciones. En este caso, ``0x68`` es para MPU6050 y ``0x77`` es para BMP180. La dirección ``0x1E`` es para QMC5883L, y ocasionalmente (debido a diferentes lotes de producción) la dirección de QMC5883L también puede ser ``0x0D``.

.. image:: img/gy87-i2c.png
    :width: 100%