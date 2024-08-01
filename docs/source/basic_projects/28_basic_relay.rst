.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_relay:

Relé
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/relay_uno.html#relay-uno


Descripción general
---------------------

Como sabemos, un relé es un dispositivo que se utiliza para proporcionar conexión entre dos o más puntos o dispositivos en respuesta a la señal de entrada aplicada. En otras palabras, los relés proporcionan aislamiento entre el controlador y el dispositivo, ya que los dispositivos pueden funcionar con CA y CC. Sin embargo, reciben señales de un microcontrolador que funciona con CC, por lo que se necesita un relé para cerrar esa brecha. El relé es extremadamente útil cuando necesitas controlar una gran cantidad de corriente o voltaje con una pequeña señal eléctrica.

Componentes necesarios
-----------------------

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_realy`
        - |link_realy_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_diode`
        - |link_diode_buy| 

Conexión
----------

.. image:: img/28-relay_bb.png
    :align: center
    :width: 90%

Diagrama esquemático
----------------------

Conecta una resistencia de 1K (para limitar la corriente cuando se energiza el transistor) al pin 8 de la placa SunFounder Uno, luego a un transistor NPN cuyo colector está conectado a la bobina de un relé y el emisor a GND; conecta el contacto normalmente abierto del relé a un LED y luego a GND. Por lo tanto, cuando se envía una señal de alto nivel al pin 8, el transistor se energiza, haciendo que la bobina del relé sea conductiva. Luego, su contacto normalmente abierto se cierra y el LED se iluminará. Cuando se envía un nivel bajo al pin 8, el LED permanecerá apagado.

.. image:: img/28_relay_schematic.png

**Función del diodo de rueda libre**: Cuando la entrada de voltaje cambia de Alto (5V) a Bajo (0V), el transistor cambia de saturación (tres condiciones de trabajo: amplificación, saturación y corte) a corte, la corriente en la bobina de repente no tiene por dónde fluir. En este momento, sin el diodo de rueda libre, se generará una fuerza contraelectromotriz (EMF) en los extremos de la bobina, con positivo en la parte inferior y negativo en la parte superior, un voltaje superior a 100V. Este voltaje más el del transistor son lo suficientemente grandes como para quemarlo. Por lo tanto, el diodo de rueda libre es extremadamente importante para descargar este contra-EMF en la dirección de la flecha en la figura anterior, de modo que el voltaje del transistor a GND no sea superior a +5V (+0.7V).

En este experimento, cuando el relé se cierra, el LED se iluminará; cuando el relé se abre, el LED se apagará.


Código
--------

.. note::

    * Puedes abrir el archivo ``28-relay.ino`` en la ruta ``elite-explorer-kit-main\basic_project\28-relay`` directamente.
    * O copiar este código en Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/093cb26d-298d-4b36-b3be-466d813c19a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
  

Ahora, envía una señal de alto nivel y el relé se cerrará y el LED se encenderá; envía una señal de bajo nivel y el relé se abrirá y el LED se apagará. Además, puedes escuchar un tic-tac causado por la apertura del contacto normalmente cerrado y el cierre del contacto normalmente abierto.

Análisis del código
---------------------

.. code-block:: arduino

   void loop() {
     digitalWrite(relayPin, HIGH);  // Enciende el relé
     delay(1000);                   // Espera un segundo
     digitalWrite(relayPin, LOW);   // Apaga el relé
     delay(1000);                   // Espera un segundo
   }

El código en este experimento es simple. Primero, establece relayPin en nivel ALTO y el LED conectado al relé se encenderá. Luego establece relayPin en nivel BAJO y el LED se apagará.
