.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_smart_fan:

Ventilador Inteligente
==========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/06_fun_smartfan.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este proyecto con Arduino ajusta automáticamente la velocidad del ventilador para mantener 
la temperatura dentro de un rango adecuado. Además, los usuarios pueden ingresar al modo manual a través de un botón para operar el ventilador a máxima velocidad.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-

**Cableado**

.. note::
    Para proteger el Power Pack del :ref:`cpn_power`, cárgalo completamente antes de usarlo por primera vez.

.. image:: img/06_smart_fan_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Esquema**

.. image:: img/06_smart_fan_schematic.png
   :width: 80%
   :align: center

**Código**

.. note::

    * Puedes abrir el archivo ``06_smart_fan.ino`` bajo la ruta ``elite-explorer-kit-main\fun_project\06_smart_fan`` directamente.
    * O copia este código en Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ba484912-14d6-4125-83a0-73a107904144/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**¿Cómo funciona?**

Aquí hay una explicación paso a paso del código:

1. Definiciones de constantes y variables:

   Usa ``#define`` para definir los pines para varias conexiones de hardware.
   ``TEMP_THRESHOLD`` se define como 25°C, que es el umbral de temperatura para iniciar el ventilador.
   ``manualMode``: Una variable booleana que indica si está en modo manual.

2. ``setup()``:

   Configura el modo para los pines relevantes (salida, entrada, entrada con pull-up).
   Inicialmente está configurado en modo automático, por lo que ``LED_AUTO`` está encendido mientras ``LED_MANUAL`` está apagado.

3. ``loop()``:

   Monitorea el estado del botón. Cuando el botón se presiona, cambia el modo y cambia el estado del LED.
   En modo manual, el ventilador opera a máxima velocidad.
   En modo automático, el código primero lee el valor de voltaje del sensor de temperatura y lo convierte en un valor de temperatura.
   Si la temperatura supera el umbral, la velocidad del ventilador se ajusta en función de la temperatura.

4. ``voltageToTemperature()``:

   Esta es una función auxiliar utilizada para convertir el valor de voltaje del sensor de temperatura en un valor de temperatura (en Celsius).
   La función utiliza la fórmula estándar para un termistor para estimar la temperatura.
   El valor de retorno está en grados Celsius.

