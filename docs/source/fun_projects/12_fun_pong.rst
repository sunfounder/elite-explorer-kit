.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_pong:

JUEGO - Pong
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/12_fun_pong.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este es un simple juego de Pong diseñado usando una pantalla OLED y una placa Arduino.
En el juego de Pong, los jugadores compiten contra la computadora, controlando una pala vertical para devolver una pelota que rebota. 
El objetivo es evitar que la pelota pase el borde de la pala del jugador, de lo contrario, el oponente anote.

La mecánica del juego se puede dividir en las siguientes partes:

1. Movimiento de la pelota: La pelota se mueve a lo largo de su dirección actual a una velocidad establecida. Cada vez que la pelota choca con una pala, su velocidad aumenta, haciendo el juego más desafiante.

2. Movimiento de la pala: Utilizada para bloquear el movimiento de la pelota, la pala puede moverse hacia arriba o hacia abajo. Los jugadores controlan su propia pala usando botones, mientras que la pala de la computadora sigue automáticamente la posición de la pelota.

3. Puntuación: Cada vez que la pelota pasa más allá del borde izquierdo o derecho de la pantalla, el jugador correspondiente o la CPU anoten.

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_power`
        - \-


**Cableado**

.. note::
    Para proteger la batería del :ref:`cpn_power`, cárgala completamente antes de usarla por primera vez.

.. image:: img/12_pong_bb.png
    :width: 100%
    :align: center


**Esquema**

.. image:: img/12_pong_schematic.png
    :width: 100%
    :align: center

**Código**

.. note::

    * Puedes abrir el archivo ``12_pong_oled.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project\12_pong_oled`` directamente.
    * O copiar este código en Arduino IDE.

.. note::
   Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit SSD1306"** y **"Adafruit GFX"** e instálalas.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/86dbb549-d425-4f42-8b5b-28d486e3f7f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**¿Cómo funciona?**

La estructura del programa se puede dividir en las siguientes cinco partes:

1. Importar bibliotecas necesarias: Usadas para controlar la pantalla OLED y leer entradas de botones.

2. Definir constantes y variables globales:

   Definiciones para el ancho y la altura de la pantalla OLED.
   Definiciones para los botones y pines de reinicio de la OLED.
   Posición, velocidad, tamaño y dirección de la pelota y las palas.
   Puntuaciones para el jugador y la CPU.

3. Inicialización:

   Inicializa la comunicación serie, la pantalla OLED y muestra la interfaz inicial.
   Configura los botones como entradas y conecta resistencias pull-up.
   Dibuja el campo de juego.

4. Bucle principal:

   Lee los estados de los botones.
   Mueve la pelota según la tasa de refresco establecida.
   Detecta colisiones entre la pelota y las palas o las paredes, ajustando la dirección y velocidad de la pelota en consecuencia.
   Actualiza la pantalla con las puntuaciones basadas en los eventos de puntuación.
   Refresca las posiciones de las palas.

5. Funciones adicionales:

   ``crossesPlayerPaddle`` y ``crossesCpuPaddle`` - Usadas para detectar si la pelota colisiona con la pala del jugador o de la CPU.
   
   ``drawCourt`` - Dibuja el campo de juego en la pantalla OLED.

   ``displayScore`` - Muestra las puntuaciones del jugador y la CPU en la pantalla.

