.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete más en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_7segment:

Pantalla de 7 segmentos
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/7_segment_display_uno.html#segmeng-uno


Descripción general
-------------------

Una pantalla de 7 segmentos es un dispositivo que puede mostrar números y letras. Está compuesta por siete LEDs conectados en paralelo. Se pueden mostrar diferentes letras/números conectando los pines de la pantalla a la fuente de alimentación y activando los pines correspondientes, encendiendo así los segmentos LED correspondientes. En esta lección, aprenderemos cómo mostrar caracteres específicos en ella.

Componentes necesarios
------------------------

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

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN A LOS COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

Conexión
----------------------

.. image:: img/13-7_segment_display_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
------------------------

En este experimento, conecta cada uno de los pines a-g de la pantalla de 7 segmentos a una resistencia limitadora de corriente de 1000 ohmios respectivamente y luego a los pines 4-11. GND se conecta a GND. Mediante programación, podemos establecer uno o varios de los pines 4-11 en nivel alto para encender los LED correspondientes.

.. image:: img/13-7_segment_display_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``13-7_segment.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\13-7_segment``.
    * O copia este código en Arduino IDE.


.. literalinclude:: /_code/13_basic_7_segment.ino
   :language: cpp
   :linenos:
   :caption: 13-7_segment.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/13_basic_7_segment.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Análisis del código
----------------------

El código puede ser un poco largo para este experimento. Pero la sintaxis es simple. Vamos a echarle un vistazo.

**Llamar a la función en loop()**

.. code-block:: arduino

   digital_1(); //mostrar 1 en el display de 7 segmentos

   delay(1000); //esperar un segundo

   digital_2(); //mostrar 2 en el display de 7 segmentos

   delay(1000); //esperar un segundo

   digital_3(); //mostrar 3 en el display de 7 segmentos

   delay(1000); //esperar un segundo

   digital_4(); //mostrar 4 en el display de 7 segmentos


Llamar a estas funciones en loop() permite que el display de 7 segmentos muestre del 0 al F. Las funciones se muestran a continuación. Tomemos ``digital_2()`` como ejemplo:

**Análisis detallado de digital_2()**

.. code-block:: arduino

   void digital_2()  //mostrar 2 en el display de 7 segmentos
   {
     turnOffAllSegments();
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(g, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(d, HIGH);
   }

.. image:: img/13_7segment.jpeg
   :align: center

Primero, necesitamos entender cómo aparece el número **2** en el display de 7 segmentos. Se logra encendiendo los segmentos a, b, d, e y g. En programación, los pines conectados a estos segmentos se establecen en nivel alto mientras que c y f se establecen en nivel bajo. Comenzamos utilizando la función ``turnOffAllSegments()`` para apagar todos los segmentos y luego encender los necesarios.

Después de ejecutar esta parte, el display de 7 segmentos mostrará **2**. De manera similar, la visualización de otros caracteres es la misma. Dado que las letras b y d en mayúsculas, es decir, **B** y **D**, se verían igual que **8** y **0** en el display, se muestran en minúsculas en su lugar.
