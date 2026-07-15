.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete más en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

Descripción general
----------------------

En esta lección, aprenderás sobre las pantallas OLED utilizando el controlador SSD1306. Las pantallas OLED (Diodos Orgánicos Emisores de Luz) se usan ampliamente en diversos dispositivos electrónicos como relojes inteligentes, teléfonos móviles e incluso televisores. El SSD1306 es un controlador de pantalla gráfica de matriz de puntos OLED/PLED con un solo chip CMOS. Ofrece una salida visual nítida y clara a través de diodos basados en material orgánico que emiten luz cuando pasa una corriente eléctrica.

En el código proporcionado, una pantalla OLED se conecta a una placa Arduino a través del protocolo I2C. El código usa la biblioteca Adafruit SSD1306 para controlar la pantalla. El programa cubre varias funcionalidades, tales como:

1. Mostrar texto: Se imprime "Hello world!" en la pantalla.
2. Texto invertido: Se muestra el texto "Hello world!" en un esquema de colores invertidos.
3. Tamaño de fuente: Se muestra el texto "Hello!" con un tamaño de fuente aumentado.
4. Visualización numérica: Se muestran los números 123456789.
5. Caracteres ASCII: Se muestra un conjunto de caracteres ASCII.
6. Desplazamiento: El texto se desplaza horizontalmente a través de la pantalla.
7. Visualización de bitmap: Se muestra una image bitmap predefinida en la pantalla OLED.

Esta pantalla OLED se puede usar en multitud de aplicaciones, incluyendo relojes digitales, mini consolas de juegos, pantallas de información, y más. Ofrece una excelente manera de proporcionar una interfaz de usuario en dispositivos compactos y portátiles.


Componentes necesarios
----------------------------

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

Conexión
----------------------

.. image:: img/15-oled_bb.png
    :align: center

Diagrama esquemático
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

Código
---------------

.. note::

    * Puedes abrir el archivo ``15-oled.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\15-oled``.
    * O copia este código en Arduino IDE.

    .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"Adafruit SSD1306"** y **"Adafruit GFX"** e instálalas. 

.. literalinclude:: /_code/15_basic_oled.ino
   :language: cpp
   :linenos:
   :caption: 15-oled.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>


Análisis del código
------------------------

1. **Inclusión de la biblioteca y definiciones iniciales**:
   Se incluyen las bibliotecas necesarias para la interfaz con el OLED. Posteriormente, se proporcionan las definiciones sobre las dimensiones del OLED y la dirección I2C.

   - **Adafruit SSD1306**: Esta biblioteca está diseñada para ayudar con la interfaz de la pantalla OLED SSD1306. Proporciona métodos para inicializar la pantalla, controlar sus configuraciones y mostrar contenido.
   - **Biblioteca Adafruit GFX**: Esta es una biblioteca gráfica central para mostrar texto, producir colores, dibujar formas, etc., en varias pantallas, incluidas las OLED.

   .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"Adafruit SSD1306"** y **"Adafruit GFX"** e instálalas. 

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // Ancho de la pantalla OLED, en píxeles
      #define SCREEN_HEIGHT 64  // Altura de la pantalla OLED, en píxeles

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Datos Bitmap**:
   Datos Bitmap para mostrar un icono personalizado en la pantalla OLED. Estos datos representan una image en un formato que el OLED puede interpretar.

   Puedes usar esta herramienta en línea llamada |link_image2cpp| que puede convertir tu image en un array. 

   La palabra clave ``PROGMEM`` denote que el array se almacena en la memoria del programa del microcontrolador Arduino. Almacenar datos en la memoria del programa (PROGMEM) en lugar de en la RAM puede ser útil para grandes cantidades de datos, que de otro modo ocuparían demasiado espacio en la RAM.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Función de configuración (Inicialización y pantalla)**:
   La función ``setup()`` inicializa el OLED y muestra una serie de patrones, textos y animaciones.

   .. code-block:: arduino

      void setup() {
         ...  // Inicialización del serial y del objeto OLED
         ...  // Mostrando varios textos, números y animaciones
      }