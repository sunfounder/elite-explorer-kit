.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_buzzer:

Zumbador
==========

.. image:: img/buzzer1.png
    :width: 50%
    :align: center

Como tipo de zumbador electrónico con una estructura integrada, los zumbadores, que son alimentados por corriente continua, se utilizan ampliamente en computadoras, impresoras, fotocopiadoras, alarmas, juguetes electrónicos, dispositivos electrónicos automotrices, teléfonos, temporizadores y otros productos electrónicos o dispositivos de voz.

Los zumbadores pueden clasificarse como activos y pasivos (ver la siguiente image). Gira el zumbador de manera que sus pines queden hacia arriba, y el zumbador con una placa de circuito verde es un zumbador pasivo, mientras que el que está encerrado con una cinta negra es uno activo.

.. image:: img/buzzer2.png
    :width: 60%
    :align: center

La diferencia entre un zumbador activo y uno pasivo:

Un zumbador activo tiene una fuente de oscilación incorporada, por lo que emitirá sonidos cuando esté electrificado. Pero un zumbador pasivo no tiene tal fuente, por lo que no emitirá pitidos si se utilizan señales de corriente continua; en su lugar, necesitas usar ondas cuadradas cuya frecuencia esté entre 2K y 5K para activarlo. El zumbador activo suele ser más caro que el pasivo debido a los múltiples circuitos de oscilación integrados.

El siguiente es el símbolo eléctrico de un zumbador. Tiene dos pines con polos positivo y negativo. Con un + en la superficie se representa el ánodo y el otro es el cátodo.

.. image:: img/buzzer_symbol.png
    :width: 150

Puedes verificar los pines del zumbador, el más largo es el ánodo y el más corto es el cátodo. Por favor, no los mezcles al conectarlos, de lo contrario, el zumbador no emitirá sonido.

|link_buzzer_wiki|

**Ejemplo**

* :ref:`basic_active_buzzer` (Basic Project)
* :ref:`basic_passive_buzzer` (Basic Project)
* :ref:`fun_access` (Fun Project)
