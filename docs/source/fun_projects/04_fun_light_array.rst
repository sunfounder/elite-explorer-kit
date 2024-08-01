.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_light_array:

Array Sensible a la Luz
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/04_fun_lightarray.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este programa convierte las lecturas de una fotorresistencia en un número correspondiente de luces LED iluminadas, creando un simple indicador de brillo de luz.

**Componentes necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

También puedes comprarlos por separado desde los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|


**Cableado**

.. image:: img/04_light_sensitive_array_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Esquema**

.. image:: img/04_light_sensitive_array_schematic.png
   :width: 60%

**Código**

.. note::

    * Puedes abrir el archivo ``04_light_sensitive_array.ino`` bajo la ruta ``elite-explorer-kit-main\fun_project\04_light_sensitive_array`` directamente.
    * O copia este código en Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9da7af57-c002-41a0-bc84-372e91885d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**¿Cómo funciona?**

Aquí hay una explicación paso a paso del código:

1. Definiciones de Constantes y Variables:

   ``NbrLEDs``: Define la presencia de 8 LEDs.
   ``ledPins[]``: Los LEDs están conectados a los pines 5 a 12 de Arduino.
   ``photocellPin``: La fotorresistencia está conectada al pin A0 de Arduino.
   ``sensorValue``: Esta variable almacena el valor leído de la fotorresistencia.
   ``ledLevel``: Esta variable almacena el número de LEDs basados en la conversión de sensorValue.

2. ``setup()``:

   Configura los pines 5 a 12 como salida para controlar los LEDs.

3. ``loop()``:

   Lee el valor analógico de la fotorresistencia desde el pin A0, típicamente en un rango de 0 a 1023.
   Usa la función map para mapear el valor de la fotorresistencia desde el rango 300-1023 al rango 0-8.
   Esto significa que si la lectura de la fotorresistencia es 300, no se encenderá ningún LED; si la lectura es 1023 o superior, se encenderán los 8 LEDs.
   
   El siguiente bucle for verifica cada LED. Si su índice es menor que ledLevel, el LED se encenderá; de lo contrario, se apagará.

