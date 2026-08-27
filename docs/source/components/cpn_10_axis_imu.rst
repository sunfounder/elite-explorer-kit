.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _cpn_10_axis_imu:

Módulo IMU 10 ejes
============================

.. image:: img/10_axis.png
    :align: center
    :width: 40%

El módulo IMU de 10 ejes es un módulo de alta precisión de 10 ejes (10DOF) capaz de medir la aceleración, la velocidad angular y la intensidad del campo magnético en tres ejes: x, y y z. Está compuesto por tres sensores principales: SH3001, QMC6310 y SPL06_001, y se comunica mediante el protocolo I2C.

Este módulo se basa en tres sensores:

1. **SH3001**: Es un acelerómetro y giroscopio de 6 ejes que puede medir la aceleración y la velocidad angular en los tres ejes x, y y z.
2. **QMC6310**: Es una brújula digital de 3 ejes que puede medir la intensidad del campo magnético en los tres ejes x, y y z.
3. **SPL06_001**: Es un sensor barométrico de temperatura y presión que puede medir la presión atmosférica y la temperatura.

El SH3001 mide la aceleración y la velocidad angular en los tres ejes x, y y z. El QMC6310 mide la intensidad del campo magnético en los tres ejes x, y y z. El SPL06_001 mide la presión atmosférica y la temperatura. Los datos de estos sensores se combinan para proporcionar información precisa sobre la orientación del módulo en el espacio.

El módulo IMU de 10 ejes se usa comúnmente en aplicaciones como drones, robótica y otros proyectos que requieren información precisa de orientación. Es compatible con las placas Arduino y puede integrarse fácilmente con ellas mediante el protocolo de comunicación I2C.