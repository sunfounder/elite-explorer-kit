.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_potentiometer:

Potenciómetro
=================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

El potenciómetro es un componente resistivo con 3 terminales y su valor de resistencia puede ajustarse según una variación regular.

Los potenciómetros vienen en varias formas, tamaños y valores, pero todos tienen en común lo siguiente:

* Tienen tres terminales (o puntos de conexión).
* Tienen una perilla, tornillo o deslizador que se puede mover para variar la resistencia entre el terminal central y cualquiera de los terminales exteriores.
* La resistencia entre el terminal central y cualquiera de los terminales exteriores varía de 0 Ω a la resistencia máxima del potenciómetro a medida que se mueve la perilla, el tornillo o el deslizador.

Aquí está el símbolo del circuito del potenciómetro.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Las funciones del potenciómetro en el circuito son las siguientes:

#. Sirviendo como divisor de voltaje

    El potenciómetro es una resistencia ajustable continuamente. Cuando ajustas el eje o la manija deslizante del potenciómetro, el contacto móvil se desliza sobre la resistencia. En este punto, se puede generar un voltaje dependiendo del voltaje aplicado al potenciómetro y del ángulo al que se ha rotado el brazo móvil o el recorrido que ha hecho.

#. Sirviendo como reóstato

    Cuando el potenciómetro se usa como reóstato, conecta el pin central y uno de los otros 2 pines en el circuito. Así, puedes obtener un valor de resistencia que cambia de manera suave y continua dentro del recorrido del contacto móvil.

#. Sirviendo como controlador de corriente

    Cuando el potenciómetro actúa como controlador de corriente, el terminal de contacto deslizante debe estar conectado como uno de los terminales de salida.

Si deseas saber más sobre el potenciómetro, consulta: |link_potentiometer_wiki|.

**Ejemplo**

* :ref:`basic_potentiometer` (Basic Project)
* :ref:`fun_hue` (Fun Project)

