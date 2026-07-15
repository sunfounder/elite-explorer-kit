.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_escape:

JUEGO - Escape
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/11_fun_escape_square.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este juego se llama "Escape".
El objetivo del jugador es inclinar el sensor MPU6050 para mover un píxel en la matriz de LED e intentar maniobrarlo a través de una apertura en el borde de la matriz (la salida).

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
    *   - :ref:`cpn_gy87`
        - \-


**Cableado**

.. image:: img/11_escape_bb.png
    :width: 80%
    :align: center


**Esquema**

.. image:: img/11_escape_schematic.png
   :width: 70%
   :align: center


**Código**

.. note::

    * Puedes abrir el archivo ``11_escape_square.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project\11_escape_square`` directamente.
    * O copiar este código en Arduino IDE.

.. note::
   Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit MPU6050"** e instálala.

.. literalinclude:: /_code/11_fun_escape.ino
   :language: cpp
   :linenos:
   :caption: 11_escape_square.ino

**¿Cómo funciona?**

Aquí hay una explicación detallada del código:

1. Importación de bibliotecas y variables globales:

   Se importan bibliotecas como la de la matriz LED, Wire (para comunicación I2C), MPU6050 (sensor de movimiento) y ``Adafruit_Sensor``.
   Inicialización de objetos MPU6050 y matriz LED.
   Definición de variables globales como pixelX y pixelY (posición del píxel), gapStart y side (posición inicial del hueco y lado), nivel (dificultad del juego), y más.

2. ``setup()``:

   Inicializa la matriz LED y dibuja la matriz con el hueco.
   Inicializa la comunicación serie y verifica si el sensor MPU6050 se inicia correctamente, configurando su rango de aceleración a 2g.

3. ``loop()``:

   Actualiza periódicamente la posición del píxel según las lecturas del sensor MPU6050.
   Mueve periódicamente la posición del hueco.
   Carga el nuevo diseño del píxel y lo renderiza en la matriz LED.
   Verifica si el píxel ha pasado por el hueco.
   Si ha pasado, espera 1.5 segundos para mostrar el éxito, aumenta la dificultad del juego y restablece la posición del píxel.

4. Otras funciones:

   * ``drawSquareWithGap()``: Dibuja un borde de 8x8 y crea un hueco dentro de él.
   * ``createGap()``: Crea un hueco de longitud 2 en el lado especificado.
   * ``moveGap()``: Mueve la posición del hueco según el lado actual y gapStart, cambiando el lado cuando sea necesario.
   * ``movePixelBasedOnMPU()``: Lee los datos de aceleración del MPU6050. Mueve la posición del píxel según los datos de aceleración (restableciendo si el píxel se sale de los límites o entra en las paredes).
   * ``resetPixel()``: Restablece la posición del píxel al centro de la matriz.
   * ``checkPixelPosition()``: Verifica si el píxel está en el hueco. Si es así, aumenta el nivel de dificultad del juego y establece el indicador de paso en verdadero.

