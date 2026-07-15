.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_guess_number:

JUEGO - Adivina el Número
==============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/10_fun_guess_game.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Adivina el Número es un juego de fiesta entretenido en el que tú y tus amigos se turnan para introducir un número (0~99). 
El rango se estrecha con cada número ingresado hasta que un jugador adivina correctamente la respuesta. 
El jugador que adivina correctamente es declarado el perdedor y se le aplica una penalización. 
Por ejemplo, si el número secreto es 51, que los jugadores no pueden ver, y el jugador 1 ingresa 50, 
el rango de números cambia a 50~99. Si el jugador 2 ingresa 70, el rango de números se convierte en 50~70. 
Si el jugador 3 ingresa 51, es el desafortunado. 
En este juego, utilizamos un Controlador Remoto IR para ingresar números y una pantalla LCD para mostrar los resultados.

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
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|


**Cableado**

.. image:: img/10_guess_number_bb.png
    :width: 90%
    :align: center


**Esquema**

.. image:: img/10_guess_number_schematic.png
   :width: 100%
   :align: center

**Código**

.. note::

    * Puedes abrir el archivo ``10_guess_number.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project\10_guess_number`` directamente.
    * O copiar este código en Arduino IDE.

.. note::
   Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"IRremote"** y **"LiquidCrystal I2C"** e instálalas.

.. literalinclude:: /_code/10_fun_guess_number.ino
   :language: cpp
   :linenos:
   :caption: 10_guess_number.ino

**¿Cómo funciona?**

1. Importación de bibliotecas y definición de variables globales:

   Se importan tres bibliotecas: ``Wire`` para la comunicación I2C, ``LiquidCrystal_I2C`` para controlar la pantalla LCD y ``IRremote`` para recibir señales del control remoto infrarrojo.
   Se definen varias variables globales para almacenar el estado y configuraciones del juego.

2. ``setup()`` 

   Inicializa la pantalla LCD y enciende la retroiluminación.
   Inicializa la comunicación serie con una velocidad de 9600 baudios.
   Inicia el receptor infrarrojo.
   Llama a la función ``initNewValue()`` para establecer el estado inicial del juego.

3. ``loop()`` 

   Comprueba si se recibe una señal del control remoto infrarrojo.
   Decodifica la señal infrarroja recibida.
   Actualiza el estado del juego o realiza acciones correspondientes basadas en el valor decodificado (número o comando).

4. ``initNewValue()`` 

   Utiliza ``analogRead`` para inicializar la semilla de número aleatorio, asegurando que se generen números aleatorios diferentes cada vez.
   Genera un número aleatorio entre 0 y 98 como el número afortunado (el número que los jugadores deben adivinar).
   Restablece los límites superior e inferior.
   Muestra un mensaje de bienvenida en la pantalla LCD.
   Restablece el número ingresado.

5. ``detectPoint()`` 

   Comprueba la relación entre el número ingresado por el jugador y el número afortunado.
   Si el número ingresado es mayor que el número afortunado, actualiza el límite superior.
   Si el número ingresado es menor que el número afortunado, actualiza el límite inferior.
   Si el jugador ingresa el número correcto, restablece la entrada y devuelve verdadero.

6. ``lcdShowInput()`` 

   Muestra el número ingresado por el jugador y los límites superior e inferior actuales en la pantalla LCD.
   Si el jugador adivina correctamente, muestra un mensaje de éxito y pausa durante 5 segundos antes de reiniciar el juego.

