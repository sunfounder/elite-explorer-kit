.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

El diodo emisor de luz semiconductor (LED) es un tipo de componente que puede convertir energía eléctrica en energía luminosa a través de uniones PN. Según la longitud de onda, puede clasificarse en diodo láser, diodo emisor de luz infrarroja y diodo emisor de luz visible, que generalmente se conoce como LED.

El diodo tiene conductividad unidireccional, por lo que el flujo de corriente será como indica la flecha en el símbolo del circuito. Solo puedes proporcionar energía positiva al ánodo y negativa al cátodo. Así, el LED se encenderá.

.. image:: img/led_symbol.png

Un LED tiene dos pines. El más largo es el ánodo, y el más corto, el cátodo. Presta atención a no conectarlos inversamente. Hay una caída de voltaje fija hacia adelante en el LED, por lo que no puede conectarse directamente al circuito porque la tensión de alimentación puede superar esta caída y causar que el LED se queme. El voltaje directo del LED rojo, amarillo y verde es de 1.8 V y el del blanco es de 2.6 V. La mayoría de los LEDs pueden soportar una corriente máxima de 20 mA, por lo que necesitamos conectar una resistencia limitadora de corriente en serie.

La fórmula del valor de la resistencia es la siguiente:

    R = (Vsupply – VD)/I

**R** representa el valor de la resistencia limitadora de corriente, **Vsupply** la tensión de alimentación, **VD** la caída de voltaje y **I** la corriente de trabajo del LED.

Aquí tienes una introducción detallada del LED: |link_led_wiki|.


**Ejemplo**


* :ref:`basic_led` (Basic Project)
* :ref:`basic_relay` (Basic Project)
* :ref:`fun_light_array` (Fun Project)
* :ref:`fun_smart_fan` (Fun Project)
