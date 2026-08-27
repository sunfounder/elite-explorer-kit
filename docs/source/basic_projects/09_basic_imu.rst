.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_imu:

Módulo IMU (10 ejes)
==========================

.. note:: Diferentes versiones de este kit pueden usar diferentes módulos IMU. Selecciona el tutorial apropiado según la versión del kit que tengas. Si tienes un módulo IMU de 10 ejes, consulta este tutorial. Si tienes un módulo GY-87, consulta :ref:`basic_gy87`.

El módulo IMU (Unidad de Medición Inercial) de 10 ejes combina múltiples sensores para proporcionar datos completos de movimiento y entorno. Integra un sensor de presión barométrica (SPL06_001) para la medición de altitud, un sensor de movimiento de 6 ejes (SH3001) para aceleración y rotación, y un magnetómetro de 3 ejes (QMC6310) para el rumbo de la brújula. Este sofisticado módulo es ideal para robótica, sistemas de navegación y aplicaciones de seguimiento de movimiento.





Circuito Fritzing
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


Instalar la biblioteca
---------------------------------

Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino.

   - Busca **"SunFounder_IMU"** e instálala


      .. image:: img/09-add_lib_tip_imu.png



Calibración
----------------------

Antes de usar el módulo IMU, se recomienda realizar la calibración para garantizar la precisión de los datos del sensor. Los siguientes son los pasos de calibración:

* Abre el archivo ``09-imu_calibration.ino`` en la ruta ``elite-explorer-kit-main\basic_project\09-imu_calibration`` directamente.

Después de ejecutar este código, abre el Monitor Serial y verás la salida de datos del sensor. Generalmente tiene el siguiente formato:

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

Copia estos datos.

Ejecutar el código
----------------------


Abre el archivo ``09-imu.ino`` en la ruta ``elite-explorer-kit-main\basic_project\09-imu`` directamente.

Ve a la página ``calibration_data.h`` en el proyecto, pega los datos que acabas de copiar en el archivo ``calibration_data.h``, reemplazando los datos originales.

.. image:: img/imu_cali_data.png
   :width: 80%

Vuelve a la página ``09-imu.ino`` y sube el código a tu placa Arduino Uno R4.

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

Después de que el código se haya subido exitosamente a tu Arduino Uno R4, el Monitor Serial cobrará vida, imprimiendo continuamente los datos del sensor del módulo IMU de 10 ejes.

.. image:: img/imu_reading.png