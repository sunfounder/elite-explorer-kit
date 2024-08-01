.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_ultrasonic:

Módulo Ultrasónico
=====================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Un módulo sensor ultrasónico es un instrumento que mide la distancia a un objeto utilizando ondas de sonido ultrasónicas. Tiene dos sondas. Una para enviar ondas ultrasónicas y la otra para recibirlas y transformar el tiempo de envío y recepción en una distancia, detectando así la distancia entre el dispositivo y un obstáculo. En la práctica, es realmente conveniente y funcional.

Proporciona una función de medición sin contacto de 2 cm a 400 cm, y la precisión de rango puede llegar a 3 mm. Puede asegurar que la señal sea estable dentro de 5 m, y la señal se debilita gradualmente después de 5 m, hasta desaparecer en la posición de 7 m.

El módulo incluye transmisores ultrasónicos, receptor y circuito de control. Los principios básicos son los siguientes:

#. Usa un flip-flop IO para procesar una señal de alto nivel de al menos 10us.

#. El módulo envía automáticamente ocho señales de 40khz y detecta si hay una señal de pulso de retorno.

#. Si la señal regresa, pasando el nivel alto, la duración de salida alta del IO es el tiempo desde la transmisión de la onda ultrasónica hasta su retorno. Aquí, la distancia de prueba = (tiempo alto x velocidad del sonido (340 m / s) / 2.

El diagrama de tiempos se muestra a continuación.

.. image:: img/ultrasonic228.png

Solo necesitas suministrar un breve pulso de 10us para la entrada del disparador para 
comenzar el rango, y luego el módulo enviará una ráfaga de 8 ciclos de ultrasonido a 
40 kHz y elevará su eco. Puedes calcular el rango a través del intervalo de tiempo 
entre el envío de la señal de disparo y la recepción de la señal de eco.

Fórmula: us / 58 = centímetros o us / 148 = pulgadas; o: el rango = tiempo de nivel 
alto * velocidad (340M/S) / 2; se sugiere usar un ciclo de medición superior a 60ms 
para evitar colisiones de señal entre la señal de disparo y la señal de eco.

**Ejemplo**

* :ref:`basic_ultrasonic_sensor` (Basic Project)
* :ref:`fun_smart_can` (Fun Project)
