.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Módulo IMU GY-87
==========================

El módulo GY-87 está equipado con tres chips sensores: MPU6050, QMC5883L y BMP180, cada uno ofreciendo capacidades únicas. El MPU6050 combina un giroscopio y un acelerómetro para el seguimiento de movimientos, el QMC5883L sirve como magnetómetro para la detección direccional, y el BMP180 se utiliza para medir la presión barométrica y la temperatura. Estos pueden ser integrados utilizando el protocolo I2C para una comunicación efectiva con un Arduino.

Estos sensores están diseñados para una integración sin problemas a través del protocolo I2C, asegurando una comunicación eficiente con plataformas como Arduino. Cada sensor en el módulo GY-87 es accesible a través de direcciones I2C únicas: el MPU6050 se accede en 0x68, el QMC5883L en 0x0D, y el BMP180 en 0x77.

Tutoriales individuales para cada chip sensor:

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l

.. raw:: html

   <br/>

**Código para el módulo GY-87**

Si deseas usar estos tres chips simultáneamente, aquí tienes un ejemplo simple:

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


.. note::

    * Puedes abrir el archivo ``09-gy87.ino`` en la ruta ``elite-explorer-kit-main\basic_project\09-gy87`` directamente.
    * O copiar este código en el IDE de Arduino.

.. note:: 
    Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino. 
    
        - Busca **"Adafruit MPU6050"** e instálala.

          Al instalar cada biblioteca, asegúrate de seleccionar la instalación de todas las dependencias.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Busca **"Adafruit Unified Sensor"** e instálala.
        - Busca **"QMC5883LCompass"** e instálala.
        - Busca **"Adafruit BMP085 Library"** e instálala.

.. literalinclude:: /_code/09_basic_gy87.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87.ino

.. note::
   Los magnetómetros deben calibrarse(:ref:`basic_gy87_calibrate`) antes de que puedan usarse como brújulas, y deben mantenerse nivelados durante su uso y **alejados de objetos de hierro, materiales magnetizados y cables que transportan corriente**.


Después de que el código se haya subido exitosamente a tu Arduino Uno R4, el Monitor Serial cobrará vida, imprimiendo continuamente los datos del sensor del módulo IMU GY-87. Este módulo incorpora tres sensores individuales: el MPU6050 para lecturas de acelerómetro y giroscopio, el QMC5883L para lecturas de magnetómetro, y el BMP180 para lecturas de presión barométrica y temperatura.
