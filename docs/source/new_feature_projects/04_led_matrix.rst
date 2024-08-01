.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _new_led_matrix:

Matriz LED de 12x8
========================================

El Arduino UNO R4 WiFi viene con una matriz LED integrada de 12x8 que se puede programar para mostrar una variedad de gráficos, animaciones, actuar como una interfaz o incluso facilitar experiencias de juego.

.. image:: img/unor4wifi.webp
    :width: 60%

En esta guía, proporcionamos un ejemplo sencillo para ayudarte a mostrar tu patrón deseado en la matriz LED.

Cómo almacenar datos de la matriz LED en Arduino
-------------------------------------------------------

Para utilizar la matriz LED, necesitarás la biblioteca ``Arduino_LED_Matrix``, que se instala junto con el núcleo Renesas.

La biblioteca de la matriz LED para el UNO R4 WiFi funciona creando y cargando fotogramas en un búfer para mostrarlos. Un fotograma, también conocido como "image", representa lo que se muestra actualmente en la matriz. En una animación compuesta por varias imágenes, cada image se considera un fotograma.

Para controlar la matriz LED de 12x8 en el UNO R4 WiFi, se requiere un mínimo de 96 bits de espacio de memoria. La biblioteca ofrece dos enfoques para esto.

**Un enfoque utiliza una matriz bidimensional**, con ceros y unos para representar si el LED correspondiente está apagado o encendido. Cada número corresponde a un LED en la matriz LED. La siguiente matriz ilustra un patrón en forma de corazón.

.. code-block:: arduino
   
   // Usa una matriz bidimensional para representar una matriz LED de 12x8.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**Otro enfoque emplea una matriz de enteros de 32 bits** para mantener el estado de la matriz LED. Este método es más compacto pero ligeramente más complejo. Cada ``unsigned long`` almacena 32 bits. Por lo tanto, para una matriz LED de 12x8, que contiene 96 LEDs, necesitarás al menos tres variables ``unsigned long``.

1. Cada ``unsigned long`` contiene 32 bits, y puedes pensar en estos bits como el estado de una parte específica en una matriz LED.
2. Estas variables ``unsigned long`` forman una matriz que encapsula el estado completo de la matriz LED.

Aquí hay un fragmento de código que utiliza tres variables `unsigned long` para representar una matriz LED de 12x8.

.. code-block:: arduino

   // Usa una matriz de enteros de 32 bits para almacenar la matriz LED.
   unsigned long frame[] = {
     0x3184a444, // Estado de los primeros 32 LEDs
     0x42081100, // Estado de los siguientes 32 LEDs
     0xa0040000  // Estado de los últimos 32 LEDs
   };

Para visualizar mejor los estados de los LEDs, estos valores se pueden convertir en forma binaria, donde cada bit representa secuencialmente el estado de cada LED de izquierda a derecha y de arriba a abajo. Un 0 indica apagado y un 1 indica encendido.

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

Mostrar patrón en la matriz LED
-----------------------------------------

Una vez que tu patrón esté listo, el siguiente paso es transmitir estos datos a la matriz LED de 12x8. Esto generalmente implica invocar funciones de la biblioteca y pasar la matriz o variables que contienen los estados de los LEDs a estas funciones.

1. Usando una matriz bidimensional

   Para mostrar el patrón almacenado en una matriz 2D, puedes usar el siguiente código:
   
   .. code-block:: arduino
   
      #include <Arduino_LED_Matrix.h>
   
      ArduinoLEDMatrix matrix;
   
      // Matriz 2D predefinida
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };
   
      void setup() {
        // Inicializar la matriz LED
        matrix.begin();
      }
   
      void loop() {
        // Mostrar el patrón en la matriz LED
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }
   
   En este código, utilizamos la función ``matrix.renderBitmap(frame, 8, 12);`` para mostrar la matriz LED. Aquí, 8 y 12 representan respectivamente las filas y columnas de la matriz LED.

2. Usando una matriz de enteros de 32 bits
   
   Para mostrar el patrón almacenado en una matriz de ``unsigned long``, utiliza el siguiente código:
   
   .. code-block:: arduino
   
      #include "Arduino_LED_Matrix.h"
      
      ArduinoLEDMatrix matrix;
      
      void setup() {
        matrix.begin();
      }
      
      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };
        
      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }
   
   En este caso, necesitamos utilizar la función ``matrix.loadFrame(heart)`` para mostrar el patrón en la matriz LED.


Editor de Matriz LED de Arduino
-----------------------------------------

Recomiendo utilizar una matriz ``unsigned long`` para almacenar el estado de la matriz LED, ya que ahorra memoria en el Arduino. Aunque este método puede no ser muy intuitivo, puedes usar el |link_led_matrix_editor| como ayuda, lo que te ayudará a generar una matriz ``unsigned long``.

Con el |link_led_matrix_editor| y la biblioteca ``Arduino_LED_Matrix``, puedes crear íconos o animaciones de manera conveniente y mostrarlas en la placa UNO R4 WiFi. Todo lo que tienes que hacer es dibujar, descargar el archivo ``.h`` y llamar a la función ``matrix.play()`` en tu boceto para construir fácilmente tu próximo proyecto.



#. Abre el Editor de Matriz LED

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. Dibuja tu patrón en el lienzo central

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. Establece el intervalo de fotogramas en milisegundos

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. Puedes crear un nuevo fotograma en blanco o copiar y crear un nuevo fotograma a partir del fotograma actual.

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. Exporta el archivo de encabezado ``.h``

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   Después de hacer clic en OK, recibirás un archivo llamado ``animation.h``.


Mostrar Animaciones
-----------------------------------------

En los pasos anteriores, obtuvimos un archivo ``.h`` que almacena una serie de fotogramas junto con sus duraciones. A continuación, vamos a mostrarlos en la matriz LED.

#. Primero, crea un boceto. Puedes abrir el archivo ``04-led_matrix.ino`` ubicado en la ruta ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, o copiar este código en el **Arduino IDE**.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/f3712371-7c3d-4a4b-bd98-f74fe43269ed/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Si estás utilizando el código de la ruta ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, encontrarás una pestaña llamada ``animation.h`` en el Arduino IDE. Ábrela y reemplaza el código existente con el archivo .h que obtuviste del sitio web.

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. Si has creado tu propio boceto, necesitas copiar el archivo ``.h`` obtenido de la página web al mismo directorio del boceto.

#. Después de configurar tu código preferido en el Arduino IDE y cargarlo en tu Arduino UNO R4 WiFi, tu matriz LED debería mostrar el patrón que definiste.

   .. raw:: html
   
      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         Your browser does not support the video tag.
      </video>

   ¡Felicidades! Has programado con éxito la matriz LED de 12x8 de tu Arduino UNO R4 WiFi.


**Referencia**

- |link_r4_led|

**Más Proyectos**

* :ref:`fun_snake` (Fun Project)



