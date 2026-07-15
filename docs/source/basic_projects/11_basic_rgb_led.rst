.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_rgb_led:

LED RGB
==========================

Descripción general
---------------------------

En esta lección, utilizaremos PWM para controlar un LED RGB y hacerlo parpadear en varios colores. Cuando se configuran diferentes valores PWM en los pines R, G y B del LED, su brillo será diferente. Al mezclar los tres colores diferentes, podremos ver que el LED RGB parpadea en distintos colores.

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|

PWM
--------

La modulación por ancho de pulso (PWM, por sus siglas en inglés) es una técnica para obtener resultados analógicos mediante medios digitales. El control digital se utiliza para crear una onda cuadrada, una señal que alterna entre encendido y apagado. Este patrón de encendido-apagado puede simular voltajes entre completamente encendido (5 Voltios) y apagado (0 Voltios) cambiando la proporción del tiempo que la señal permanece encendida frente al tiempo que permanece apagada. La duración del "tiempo encendido" se llama ancho de pulso. Para obtener valores analógicos variables, cambias o modulas ese ancho. Si repites este patrón de encendido-apagado lo suficientemente rápido con algún dispositivo, por ejemplo, un LED, parecerá que la señal es un voltaje constante entre 0 y 5V controlando el brillo del LED. (Consulta la descripción de PWM en el sitio web oficial de Arduino).

En el gráfico a continuación, las líneas verdes representan un período de tiempo regular. Esta duración o período es el inverso de la frecuencia PWM. En otras palabras, con la frecuencia PWM de Arduino en aproximadamente 500Hz, las líneas verdes medirían 2 milisegundos cada una.

.. image:: img/11_rgbled_pwm.jpeg
   :align: center
   :width: 60%


Una llamada a analogWrite() está en una escala de 0 a 255, de modo que analogWrite(255) solicita un ciclo de trabajo del 100% (siempre encendido), y analogWrite(127) es un ciclo de trabajo del 50% (encendido la mitad del tiempo), por ejemplo.

Encontrarás que cuanto menor sea el valor PWM, menor será el valor después de convertirse en voltaje. Luego, el LED se vuelve más tenue en consecuencia. Por lo tanto, podemos controlar el brillo del LED controlando el valor PWM.



Conexión
----------------------

.. image:: img/11-rgb_led_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-----------------------

.. image:: img/11-rgb_led_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``11-rgb_led.ino`` en la ruta ``elite-explorer-kit-main\basic_project\11-rgb_led`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/11_basic_rgb_led.ino
   :language: cpp
   :linenos:
   :caption: 11-rgb_led.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/11_basic_rgb_led.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Una vez que el código se cargue correctamente, observarás que el LED RGB parpadea inicialmente en un patrón circular de rojo, verde y azul. Luego procederá a parpadear en la secuencia de rojo, naranja, amarillo, verde, azul, índigo y púrpura.


Análisis del código
-----------------------

**Configurar el color**

Aquí se utiliza la función ``color()`` para configurar el color del LED RGB. En el código, se configura para parpadear en 7 colores diferentes.

Puedes usar la herramienta de pintura en tu computadora para obtener el valor RGB.

1. Abre la herramienta de pintura en tu computadora y haz clic en Editar colores.

   .. image:: img/11_rgbled_color1.png
      :align: center

2. Selecciona un color, luego podrás ver el valor RGB de este color. Complétalos en el código.
   
   .. note:: 
      Debido a factores de hardware y ambientales, los colores mostrados en las pantallas de las computadoras y los LED RGB pueden variar incluso al usar los mismos valores RGB.

   .. image:: img/11_rgbled_color2.png
      :align: center

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
       void loop() // ejecutar una y otra vez
   
       {
   
         // Colores básicos:
   
         color(255, 0, 0); // encender el LED RGB en rojo
   
         delay(1000); // retrasar 1 segundo
   
         color(0,255, 0); // turn the RGB LED green
   
         delay(1000); // retrasar 1 segundo
   
         color(0, 0, 255); // encender el LED RGB en azul
   
         delay(1000); // retrasar 1 segundo
   
         // Ejemplo de colores mezclados:
   
         color(255,0,252); // turn the RGB LED red
   
         delay(1000); // retrasar 1 segundo
   
         color(237,109,0); // turn the RGB LED orange
   
         delay(1000); // retrasar 1 segundo
   
         color(255,215,0); // turn the RGB LED yellow
   
         ......
   
   
**Función color()**

.. code-block:: arduino

    void color (int red, int green, int blue)
    // la función generadora de color

    {

      analogWrite(redPin, red);

      analogWrite(greenPin, green);

      analogWrite(bluePin, blue);

    }

Define tres variables unsigned char, red, green y blue. Escribe sus valores en ``redPin``, ``greenPin`` y ``bluePin``. Por ejemplo, color(128, 0, 128) escribe 128 en ``redPin``, 0 en ``greenPin`` y 128 en ``bluePin``. El resultado es que el LED parpadea en púrpura.


**analogWrite()**: Escribe un valor analógico (onda PWM) en un pin. No tiene nada que ver con un pin analógico, sino que es solo para pines PWM. No necesitas llamar a ``pinMode()`` para configurar el pin como salida antes de llamar a ``analogWrite()``.
