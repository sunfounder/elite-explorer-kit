.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete más en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_i2c_lcd1602:

LCD1602 I2C
==========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

Descripción general
-----------------------

En esta lección, aprenderás sobre las pantallas de cristal líquido (LCD) con una interfaz I2C. Estos tipos de LCD se utilizan ampliamente en una variedad de dispositivos electrónicos, como relojes digitales, microondas, tableros de automóviles e incluso equipos industriales. La interfaz I2C simplifica el cableado y las conexiones, haciéndolo más conveniente y eficiente tanto para aficionados como para profesionales.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Conexión
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

Diagrama esquemático
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``14-i2c_lcd.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\14-i2c_lcd``.
    * O copia este código en Arduino IDE.

.. note:: 
    Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"LiquidCrystal I2C"** e instálala. 

.. literalinclude:: /_code/14_basic_i2c_lcd.ino
   :language: cpp
   :linenos:
   :caption: 14-i2c_lcd.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Después de cargar el código exitosamente en el Arduino, la pantalla de cristal líquido (LCD) mostrará el mensaje "Hello world!" en su primera línea y "LCD Tutorial" en su segunda línea.

.. note::
    Si el LCD no muestra ningún carácter después de cargar el código, puedes ajustar el contraste girando el potenciómetro en el módulo I2C hasta que el LCD funcione correctamente.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd_2.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Análisis del código
------------------------

1. Inclusión de la biblioteca e inicialización del LCD:
   Se incluye la biblioteca LiquidCrystal I2C para proporcionar funciones y métodos para la interfaz del LCD. Luego, se crea un objeto LCD utilizando la clase LiquidCrystal_I2C, especificando la dirección I2C, el número de columnas y el número de filas.

   .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"LiquidCrystal I2C"** e instálala.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Función de configuración:
   La función ``setup()`` se ejecuta una vez cuando se inicia el Arduino. En esta función, se inicializa el LCD, se limpia y se enciende la retroiluminación. Luego, se muestran dos mensajes en el LCD.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // inicializa el LCD
        lcd.clear();      // limpia la pantalla del LCD
        lcd.backlight();  // asegura que la retroiluminación esté encendida
      
        // Imprime un mensaje en ambas líneas del LCD.
        lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
        lcd.print("LCD Tutorial");
      }