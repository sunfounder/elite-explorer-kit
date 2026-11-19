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


Calibración
----------------------

Antes de leer los datos del sensor, calibra el IMU para que las mediciones sean precisas.

#. Instala la biblioteca **SunFounder_IMU**: abre el Administrador de Bibliotecas de Arduino, busca **"SunFounder_IMU"** y haz clic en **INSTALL**. La imagen de abajo muestra la entrada una vez instalada.

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. Abre el archivo ``09-imu_calibration.ino`` en la ruta ``elite-explorer-kit-main\basic_project\09-imu_calibration`` y súbelo a tu placa.

#. Abre el Monitor Serial y configura la velocidad en baudios en **115200** y el fin de línea en **Both NL & CR**.

#. Realiza la calibración de seis caras siguiendo las indicaciones del Monitor Serial:

   * Envía cualquier carácter para empezar. El Monitor Serial mostrará entonces la primera orientación.
   * Coloca el módulo en las seis orientaciones en el orden indicado: Z arriba, Z abajo, X arriba, X abajo, Y arriba e Y abajo.
   * Mantén el módulo completamente quieto durante cada medición y vuelve a enviar cualquier carácter para medir la orientación actual y pasar a la siguiente.

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. Al terminar la sexta orientación, el Monitor Serial imprime las constantes de calibración. Copia las seis líneas:

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   Los valores de arriba son solo un ejemplo; los tuyos son propios de tu módulo.

#. Abre el proyecto ``09-imu`` y su pestaña ``calibration_data.h``, y sustituye los seis arrays por los valores que copiaste.

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. Sube ``09-imu.ino`` a tu placa Arduino Uno R4. El Monitor Serial imprimirá continuamente los datos del acelerómetro, el giroscopio, el magnetómetro y el barómetro.

   .. image:: img/imu_reading.png