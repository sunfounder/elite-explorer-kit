.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_oled:

Módulo de Pantalla OLED
==========================

.. image:: img/oled.png
    :width: 300
    :align: center

Introducción
---------------------------
Un módulo de pantalla OLED (Diodo Orgánico Emisor de Luz) es un dispositivo que puede mostrar texto, gráficos e imágenes en una pantalla delgada y flexible utilizando materiales orgánicos que emiten luz cuando se aplica corriente eléctrica.

La principal ventaja de una pantalla OLED es que emite su propia luz y no necesita otra fuente de retroiluminación. Debido a esto, las pantallas OLED a menudo tienen mejor contraste, brillo y ángulos de visión en comparación con las pantallas LCD.

Otra característica importante de las pantallas OLED son los niveles de negro profundo. Dado que cada píxel emite su propia luz en una pantalla OLED, para producir el color negro, el píxel individual puede apagarse.

Debido al menor consumo de energía (solo los píxeles que están iluminados consumen corriente), las pantallas OLED también son populares en dispositivos operados por batería como relojes inteligentes, rastreadores de salud y otros dispositivos portátiles.

Principio
---------------------------
Un módulo de pantalla OLED consiste en un panel OLED y un chip controlador OLED montado en la parte trasera del módulo. El panel OLED está compuesto por muchos pequeños píxeles que pueden producir diferentes colores de luz. Cada píxel consiste en varias capas de materiales orgánicos intercalados entre dos electrodos (ánodo y cátodo). Cuando la corriente eléctrica fluye a través de los electrodos, los materiales orgánicos emiten luz de diferentes longitudes de onda dependiendo de su composición.

El chip controlador OLED es un chip que puede controlar los píxeles del panel OLED utilizando un protocolo de comunicación serial llamado I2C (Circuito Inter-Integrado).

El chip controlador OLED convierte las señales del Arduino en comandos para el panel OLED. El Arduino puede enviar datos al chip controlador OLED utilizando una biblioteca que puede controlar el protocolo I2C. Una de esas bibliotecas es la biblioteca Adafruit SSD1306. Con esta biblioteca, puedes inicializar el módulo de pantalla OLED, ajustar el nivel de brillo, imprimir texto, gráficos o imágenes, etc.

**Ejemplo**


* :ref:`basic_oled` (Basic Project)
* :ref:`fun_pong` (Fun Project)
* :ref:`iot_weathertime_screen` (IoT Project)