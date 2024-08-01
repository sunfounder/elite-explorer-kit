.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Tierra
* **VCC**: Suministro de voltaje, 5V.
* **SDA**: Línea de datos seriales. Conectar a VCC a través de una resistencia pullup.
* **SCL**: Línea de reloj serial. Conectar a VCC a través de una resistencia pullup.

Como todos sabemos, aunque las pantallas LCD y algunas otras enriquecen enormemente la interacción hombre-máquina, comparten una debilidad común. Cuando se conectan a un controlador, se ocupan múltiples IOs del controlador, que no tiene tantos puertos externos. Además, restringe otras funciones del controlador.

Por lo tanto, se desarrolló el LCD1602 con un módulo I2C para resolver este problema. El módulo I2C tiene un chip I2C PCF8574 incorporado que convierte los datos seriales I2C en datos paralelos para la pantalla LCD.

* |link_pcf8574_datasheet|

**Dirección I2C**

La dirección predeterminada es básicamente 0x27, en algunos casos puede ser 0x3F.

Tomando como ejemplo la dirección predeterminada de 0x27, la dirección del dispositivo se puede modificar cortocircuitando las almohadillas A0/A1/A2; en el estado predeterminado, A0/A1/A2 es 1, y si la almohadilla está en cortocircuito, A0/A1/A2 es 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Retroiluminación/Contraste**

La retroiluminación se puede habilitar con un capuchón de puente, desconecte el capuchón de puente para deshabilitar la retroiluminación. El potenciómetro azul en la parte posterior se utiliza para ajustar el contraste (la relación de brillo entre el blanco más brillante y el negro más oscuro).

.. image:: img/back_lcd1602.jpg

* **Capuchón de Puente**: La retroiluminación se puede habilitar con este capuchón, desconéctelo para deshabilitar la retroiluminación.
* **Potenciómetro**: Se utiliza para ajustar el contraste (la claridad del texto mostrado), que aumenta en dirección de las agujas del reloj y disminuye en dirección contraria.

**Ejemplo**

* :ref:`basic_i2c_lcd1602` (Basic Project)
* :ref:`basic_ultrasonic_sensor` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`fun_guess_number` (Fun Project)
* :ref:`iot_Bluetooth_lcd` (IoT Project)
