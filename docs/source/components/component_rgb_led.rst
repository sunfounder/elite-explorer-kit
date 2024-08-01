.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_rgb_led:

LED RGB
=========

.. image:: img/rgb_led.png
    :width: 100

Los LEDs RGB emiten luz en varios colores. Un LED RGB agrupa tres LEDs de rojo, verde y azul en una carcasa de plástico transparente o semitransparente. Puede mostrar varios colores cambiando el voltaje de entrada de los tres pines y superponiéndolos, lo que, según las estadísticas, puede crear 16,777,216 colores diferentes.

.. image:: img/rgb_light.png
    :width: 600

Los LEDs RGB pueden categorizarse en ánodo común y cátodo común. En este kit, se utiliza el segundo. El **cátodo común** significa conectar los cátodos de los tres LEDs. Después de conectarlo con GND y enchufar los tres pines, el LED mostrará el color correspondiente.

Su símbolo de circuito se muestra en la figura.

.. image:: img/rgb_symbol.png
    :width: 300

Un LED RGB tiene 4 pines: el más largo es GND; los otros son Rojo, Verde y Azul. Toca su carcasa de plástico y encontrarás un corte. El pin más cercano al corte es el primer pin, marcado como Rojo, luego GND, Verde y Azul en ese orden.

.. image:: img/rgb_pin.jpg
    :width: 200


**Ejemplo**

* :ref:`basic_rgb_led` (Basic Project)
* :ref:`fun_hue` (Fun Project)
