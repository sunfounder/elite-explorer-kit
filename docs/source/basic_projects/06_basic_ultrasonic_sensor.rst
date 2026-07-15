.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_ultrasonic_sensor:

Ultrasonido
==========================

Descripción general
-----------------------

Cuando estás retrocediendo, verás la distancia entre el coche y los obstáculos circundantes para evitar colisiones. El dispositivo para detectar la distancia es un sensor ultrasónico. En este experimento, aprenderás cómo la onda ultrasónica detecta la distancia.

Componentes necesarios
---------------------------

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


Cableado
----------------------

.. image:: img/06-ultrasonic_module_bb.png
    :align: center
    :width: 100%

.. raw:: html

    <br/>

Diagrama esquemático
-----------------------

.. image:: img/06_ultrasonic_schematic.png
    :align: center
    :width: 100%


Código
-----------

.. note::

    * Puedes abrir el archivo ``06-ultrasonic.ino`` en la ruta ``elite-explorer-kit-main\basic_project\06-ultrasonic`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/06_basic_ultrasonic_sensor.ino
   :language: cpp
   :linenos:
   :caption: 06-ultrasonic.ino
    
.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/06_basic_ultrasonic_sensor.mp4"  type="video/mp4">
      Tu navegador no soporta la etiqueta de video.
   </video>

Análisis del código
------------------------

**1. Inicializa el sensor ultrasónico y el LCD1602**

    .. code-block:: arduino
    
       #include <LiquidCrystal_I2C.h>
       
       LiquidCrystal_I2C lcd(0x27, 16, 2);  // inicializa el objeto de pantalla de cristal líquido con la dirección I2C 0x27, 16 columnas y 2 filas
       
       // Define los números de pin para el sensor ultrasónico
       const int echoPin = 3;
       const int trigPin = 4;
       
       void setup() {
         pinMode(echoPin, INPUT);               // Establecer el pin de eco como entrada
         pinMode(trigPin, OUTPUT);              // Establecer el pin de disparo como salida
       
         lcd.init();       // inicializa el LCD
         lcd.clear();      // limpia la pantalla LCD
         lcd.backlight();  // Asegúrate de que la luz de fondo esté encendida
       
       }

**2. Muestra la distancia en el LCD1602**

    .. code-block:: arduino
    
       void loop() {
         float distance = readDistance();  // Llama a la función para leer los datos del sensor y obtener la distancia
       
         lcd.setCursor(0, 0);         // Coloca el cursor en la Línea 1, Columna 1. Desde aquí se mostrarán los caracteres
         lcd.print("Distance:");      // Imprime Distance: en el LCD
         lcd.setCursor(0, 1);         // Coloca el cursor en la Línea 1, Columna 0
         lcd.print("               ");  // Aquí es para dejar algunos espacios después de los caracteres para borrar los caracteres anteriores que aún pueden quedar.
         lcd.setCursor(7, 1);         // Coloca el cursor en la Línea 1, Columna 7
         lcd.print(distance);         // imprime en el LCD el valor de la distancia convertida del tiempo entre el envío y la recepción del ping.
         lcd.setCursor(14, 1);        // Coloca el cursor en la Línea 1, Columna 14
         lcd.print("cm");             // imprime la unidad "cm"
       
         delay(800);                       // Retraso de 800 milisegundos antes de repetir el bucle
       }

**3. Convierte el tiempo en distancia**

    .. code-block:: arduino

        float readDistance(){// ...}

    Aquí, "PING" se refiere al proceso donde el sensor ultrasónico envía un pulso ultrasónico (o "ping") y luego espera su eco.
    
    El PING se activa mediante un pulso ALTO de 2 o más microsegundos. (Da un breve pulso BAJO antes para asegurar un pulso ALTO limpio).

    .. code-block:: arduino

        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW); 

    El pin de eco se utiliza para leer la señal de PING, un pulso ALTO cuya duración es el tiempo (en microsegundos) desde el envío del ping hasta la recepción del eco del objeto. Usamos la siguiente función para obtener la duración.

    .. code-block:: arduino

        pulseIn(echoPin, HIGH);

    La velocidad del sonido es de 340 m/s o 29 microsegundos por centímetro.

    Esto da la distancia recorrida por el ping, de ida y vuelta, por lo que dividimos por 2 para obtener la distancia del obstáculo.

    .. code-block:: arduino

        float distance = pulseIn(echoPin, HIGH) / 29.00 / 2;     // Fórmula: (340m/s * 1us) / 2
