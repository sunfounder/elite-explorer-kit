.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_ws2812:

Tira de LEDs RGB WS2812 de 8 LEDs
====================================

.. image:: img/ws2812b.png

La tira de LEDs RGB WS2812 de 8 LEDs está compuesta por 8 LEDs RGB. Solo se requiere un 
pin para controlar todos los LEDs. Cada LED RGB tiene un chip WS2812, que puede ser 
controlado de forma independiente. Puede realizar una visualización de brillo de 256 niveles 
y una visualización de color verdadero completo de 16,777,216 colores. Al mismo tiempo, el 
píxel contiene una señal de enclavamiento de datos de interfaz digital inteligente, un 
circuito de conducción de amplificación de conformación de señal y un circuito de 
conformación de señal incorporado para garantizar de manera efectiva la consistencia de 
altura de color del punto de luz del píxel.

Es flexible, puede acoplarse, doblarse y cortarse a voluntad, y la parte posterior está equipada con cinta adhesiva, que puede fijarse en superficies irregulares a voluntad y puede instalarse en un espacio estrecho.

**Características**

* Voltaje de trabajo: DC5V
* IC: Un IC controla un LED RGB
* Consumo: 0.3w por LED
* Temperatura de trabajo: -15-50
* Color: RGB de color completo
* Tipo de RGB: 5050RGB (IC WS2812B incorporado)
* Espesor de la tira de luz: 2mm
* Cada LED puede ser controlado individualmente

**Introducción al WS2812B**

* |link_ws2812b_datasheet|

WS2812B es una fuente de luz LED de control inteligente en la que el circuito de control y el chip RGB están integrados en un paquete de componentes 5050. Internamente incluye un puerto de datos de interfaz digital inteligente de enclavamiento y un circuito de amplificación de conformación de señal. También incluye un oscilador interno de precisión y una parte de control de corriente constante programable de 12V, asegurando de manera efectiva la consistencia de color del punto de luz del píxel.

El protocolo de transferencia de datos utiliza un modo de comunicación NZR único. Después de que el píxel se reinicia, el puerto DIN recibe datos del controlador, el primer píxel recoge los datos iniciales de 24 bits y luego los envía al enclavamiento de datos interno, los otros datos que son conformados por el circuito de amplificación de conformación de señal interna se envían al siguiente píxel en cascada a través del puerto DO. Después de la transmisión de cada píxel, la señal se reduce en 24 bits. El píxel adopta tecnología de transmisión de auto conformación, lo que hace que el número de píxeles en cascada no esté limitado por la transmisión de señal, solo depende de la velocidad de transmisión de señal.

LED con bajo voltaje de conducción, protección ambiental y ahorro de energía, alto brillo, gran ángulo de dispersión, buena consistencia, bajo consumo, larga vida útil y otras ventajas. El chip de control integrado en el LED hace que el circuito sea más simple, de pequeño volumen y de instalación conveniente.
.. Example
.. -------------------

.. :ref:`RGB LED Strip`

**Ejemplo**

* :ref:`basic_ws2812` (Basic Project)
* :ref:`iot_cheerlights` (IoT Project)
