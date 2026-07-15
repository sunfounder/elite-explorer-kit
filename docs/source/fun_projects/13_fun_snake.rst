.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_snake:

JUEGO - Snake
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este ejemplo implementa el clásico juego de Snake en una matriz de LED de 8x12 utilizando la placa R4 Wifi.
Los jugadores controlan la dirección de la serpiente usando un joystick de doble eje.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Cableado**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**Esquema**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**Código**

.. note::

    * Puedes abrir el archivo ``13_snake.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project\13_snake`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/13_fun_snake.ino
   :language: cpp
   :linenos:
   :caption: 13_snake.ino


**¿Cómo funciona?**

Aquí tienes una explicación detallada del código:

1. Definición e Inicialización de Variables

   Importa la biblioteca ``Arduino_LED_Matrix`` para las operaciones con la matriz de LED.
   matrix es una instancia de la matriz de LED.
   ``frame`` y ``flatFrame`` son matrices utilizadas para almacenar y procesar la información de los píxeles en la pantalla.
   La serpiente se representa como una matriz de estructuras ``Point``, donde cada punto tiene una coordenada x y una y.
   food representa la posición de la comida.
   ``direction`` es la dirección de movimiento actual de la serpiente.

2. ``setup()`` 

   Inicializa los ejes X e Y del joystick como entradas.
   Inicia la matriz de LED.
   Inicializa la posición inicial de la serpiente en el centro de la pantalla.
   Genera la posición inicial de la comida de manera aleatoria.

3. ``loop()`` 

   Determina la dirección de la serpiente basándose en las lecturas del joystick.
   Mueve la serpiente.
   Verifica si la cabeza de la serpiente colisiona con la comida. 
   Si es así, la serpiente crece y se genera nueva comida en una nueva ubicación.
   Verifica si la serpiente colisiona consigo misma. Si es así, reinicia el juego.
   Dibuja el estado actual del juego (posiciones de la serpiente y la comida) en la matriz de LED.
   Agrega un retraso para controlar la velocidad del juego.

4. ``moveSnake()`` 

   Mueve cada parte de la serpiente a la posición de la parte anterior, comenzando desde la cola y moviéndose hacia la cabeza.
   Mueve la cabeza de la serpiente basándose en su dirección.

5. ``generateFood()`` 

   Genera todas las posibles posiciones de comida.
   Verifica si cada posición se superpone con alguna parte de la serpiente. Si no se superpone, la posición se considera una ubicación posible para la comida.
   Selecciona aleatoriamente una ubicación posible para la comida.

6. ``drawFrame()`` 

   Limpia el marco actual.
   Dibuja la serpiente y la comida en el marco.
   Aplana la matriz bidimensional del marco en una matriz unidimensional (flatFrame) y la carga en la matriz de LED.

