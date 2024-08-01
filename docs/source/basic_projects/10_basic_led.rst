.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_led:

Módulo LED
==========================

Así como imprimir "Hola, mundo" es el primer paso para aprender a programar, usar un programa para encender un LED es la introducción tradicional al aprendizaje de la programación física.

Componentes necesarios
-------------------------

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí tienes el enlace:

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

    *   - INTRODUCCIÓN AL COMPONENTE
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

Conexión
----------------------

.. image:: img/10-led_bb.png
    :align: center
    :width: 60%


Diagrama esquemático
-----------------------

.. image:: img/10_led_schematic.png
    :align: center
    :width: 80%


Código
---------------

.. note::

   * Puedes abrir el archivo ``10-led.ino`` en la ruta ``elite-explorer-kit-main\basic_project\10-led``. 
   * O copiar este código en **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2d23289e-ebd1-49e9-b11f-b1bbc1f192c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/10_basic_led.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Después de cargar el código exitosamente, verás que el LED conectado al pin digital 9 de la placa Arduino comienza a parpadear. El LED se encenderá durante medio segundo y luego se apagará durante otro medio segundo, repitiendo este ciclo continuamente mientras el programa esté en ejecución.

Análisis del código
------------------------

Aquí, conectamos el LED al pin digital 9, por lo que necesitamos declarar una variable ``int`` llamada ``ledPin`` al inicio del programa y asignarle un valor de 9.

.. code-block:: arduino

    const int ledPin = 9;

Ahora, inicializa el pin en la función ``setup()``, donde necesitas configurar el pin en modo ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

En ``loop()``, ``digitalWrite()`` se usa para proporcionar una señal de nivel alto de 5V al pin ``ledPin``, lo que causará una diferencia de voltaje entre los pines del LED y encenderá el LED.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Si la señal de nivel se cambia a LOW, la señal del pin ``ledPin`` volverá a 0 V para apagar el LED.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

Se requiere un intervalo entre encendido y apagado para permitir que las personas vean el cambio, por lo que usamos un código ``delay(1000)`` para que el controlador no haga nada durante 1000 ms.

.. code-block:: arduino

    delay(1000);   
