.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_power:

Módulo de Fuente de Alimentación
=====================================

.. note::
    Para proteger la batería del :ref:`cpn_power`, por favor cárguela completamente antes de usarla por primera vez.

Cuando necesitamos una gran corriente para alimentar un componente, esto puede interferir gravemente con el funcionamiento normal de la placa Arduino UNO. Por lo tanto, proporcionamos energía separada para el componente con este módulo para que funcione de manera segura y estable.

Puedes simplemente conectarlo en la placa de pruebas para suministrar energía. Proporciona un voltaje de 3.3V y 5V, y puedes conectar cualquiera de ellos mediante un puente incluido.

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**Características y especificaciones**

* Entrada de carga: USB Tipo-C, 5V
* Voltaje de salida: 5V, 3.3V (ajustable mediante puentes: 0V, 3.3V y 5V)
* Corriente de salida: 5V/1.5A, 3.3V/1A
* Interruptor ON-OFF disponible
* Dos canales independientes
* Salida USB (Tipo-A) disponible
* Batería: Batería de ion de litio 14500 de 3.7V, 500mAh
* Dimensiones: 52mm x 32mm x 24mm (L x A x H)

**Ejemplo**

* :ref:`basic_motor` (Basic Project)
* :ref:`basic_pump` (Basic Project)
* :ref:`basic_stepper_motor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`fun_access` (Fun Project)
* :ref:`fun_pong` (Fun Project)

