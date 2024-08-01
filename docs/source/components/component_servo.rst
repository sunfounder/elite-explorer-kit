.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_servo:

Servo
=======

.. image:: img/servo.png
    :align: center

Un servo está generalmente compuesto por las siguientes partes: carcasa, eje, sistema de engranajes, potenciómetro, motor DC y placa integrada.

Funciona de la siguiente manera: El microcontrolador envía señales PWM al servo, y luego la placa integrada en el servo recibe las señales a través del pin de señal y controla el motor interno para girar. Como resultado, el motor impulsa el sistema de engranajes y luego mueve el eje después de la desaceleración. El eje y el potenciómetro del servo están conectados entre sí. Cuando el eje gira, mueve el potenciómetro, por lo que el potenciómetro envía una señal de voltaje a la placa integrada. Luego, la placa determina la dirección y velocidad de rotación según la posición actual, para que pueda detenerse exactamente en la posición definida y mantenerse allí.

.. image:: img/servo_internal.png
    :align: center

El ángulo está determinado por la duración de un pulso que se aplica al cable de control. Esto se llama Modulación por Ancho de Pulso (PWM). El servo espera recibir un pulso cada 20 ms. La longitud del pulso determinará cuánto gira el motor. Por ejemplo, un pulso de 1.5 ms hará que el motor gire a la posición de 90 grados (posición neutral).
Cuando se envía un pulso a un servo que es menor a 1.5 ms, el servo gira a una posición y mantiene su eje de salida algunos grados en sentido antihorario desde el punto neutral. Cuando el pulso es más ancho que 1.5 ms ocurre lo contrario. El ancho mínimo y máximo del pulso que hará que el servo gire a una posición válida son funciones de cada servo. Generalmente, el pulso mínimo será de aproximadamente 0.5 ms y el pulso máximo será de 2.5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center


**Ejemplo**

* :ref:`basic_servo` (Basic Project)
* :ref:`fun_smart_can` (Fun Project)
