.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_plant_monitor:

Monitor de Plantas
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/08_fun_plant_monitor.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este proyecto riega automáticamente las plantas activando una bomba de agua cuando la humedad del suelo cae por debajo de un umbral específico.
Además, muestra la temperatura, la humedad y la humedad del suelo en una pantalla LCD, proporcionando a los usuarios información sobre el entorno de crecimiento de la planta.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|
    *   - :ref:`cpn_power`
        - \-

**Cableado**

.. note::
    Para proteger la batería del :ref:`cpn_power`, cárgala completamente antes de usarla por primera vez.

.. image:: img/08_plant_monitor_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Esquema**

.. image:: img/08_plant_monitor_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**Código**

.. note::

    * Puedes abrir el archivo ``08_plant_monitor.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project\08_plant_monitor`` directamente.
    * O copiar este código en Arduino IDE.

.. note::
   Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"DHT sensor library"** y **"LiquidCrystal I2C"** e instálalas.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/a9d6c9c7-0d7f-4dc2-84b6-9dbda15c89ae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**¿Cómo funciona?**

Aquí tienes una explicación detallada del código:

1. Inclusión de bibliotecas y definición de constantes/variables:

   Importa las bibliotecas ``Wire.h``, ``LiquidCrystal_I2C.h`` y ``DHT.h``.
   Define números de pines y otros parámetros relacionados con el DHT11, el sensor de humedad del suelo y la bomba de agua.

2. ``setup()``:

   Inicializa los modos de los pines relacionados con el sensor de humedad del suelo y la bomba de agua.
   Apaga la bomba de agua inicialmente.
   Inicializa la pantalla LCD y enciende la luz de fondo.
   Inicia el sensor DHT.

3. ``loop()``:

   Lee la humedad y la temperatura del sensor DHT.
   Lee la humedad del suelo del sensor de humedad del suelo.
   Muestra los valores de temperatura y humedad en la pantalla LCD, luego limpia la pantalla y muestra el valor de humedad del suelo.
   Determina si activar la bomba de agua en función de la humedad del suelo. Si la humedad del suelo es inferior a 500 (un umbral configurable), activa la bomba de agua durante 1 segundo.

