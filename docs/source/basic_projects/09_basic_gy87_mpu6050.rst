.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_gy87_mpu6050:

MPU6050
==========================


Descripción general
--------------------------

En este tutorial, aprenderás a conectar el módulo IMU GY-87 con un Arduino Uno, centrándote en el sensor MPU6050. Cubriremos la inicialización del MPU6050 y la visualización de sus datos de acelerómetro, giroscopio y temperatura en el Monitor Serial. Esta lección es esencial para proyectos que necesitan detección de movimiento y temperatura, como robótica, dispositivos controlados por gestos e instalaciones de arte interactivo.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-

Cableado
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>

Diagrama esquemático
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Código
-----------

.. note::

    * Puedes abrir el archivo ``09-gy87_mpu6050.ino`` en la ruta de ``elite-explorer-kit-main\basic_project\09-gy87_mpu6050`` directamente.
    * O copiar este código en el IDE de Arduino.

.. note:: 
    Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit MPU6050"** e instálala. 

.. literalinclude:: /_code/09_basic_gy87_mpu6050.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_mpu6050.ino


Análisis del código
------------------------

#. Incluir bibliotecas

   Se incluyen las bibliotecas ``Adafruit_MPU6050``, ``Adafruit_Sensor`` y ``Wire`` para la interfaz y comunicación del sensor.

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. Inicializar el objeto del sensor

   Se crea un objeto de la clase Adafruit_MPU6050 para representar el sensor MPU6050.

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. Función de configuración

   Inicializa la comunicación serial y llama a la función para inicializar el sensor MPU6050.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. Función de bucle

   Llama repetidamente a la función para imprimir los datos del MPU6050 con un retraso de 500 milisegundos entre cada llamada.

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. Función para inicializar el MPU6050

   Verifica si el MPU6050 está conectado, establece los rangos del acelerómetro y el giroscopio, y configura el ancho de banda del filtro.

   .. code-block:: arduino

      void initializeMPU6050() {
        // Verifica si se detecta el sensor MPU6050
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1)
            ;  // Detener si no se encuentra el sensor
        }
        Serial.println("MPU6050 Found!");
      
        // establecer el rango del acelerómetro a +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      
        // establecer el rango del giroscopio a +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      
        // establecer el ancho de banda del filtro a 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      
        Serial.println("");
        delay(100);
      }

#. Función para imprimir los datos del MPU6050

   Lee e imprime los datos de aceleración, giroscopio y temperatura del MPU6050 en el Monitor Serial.

   .. code-block:: arduino

      void printMPU6050() {
      
        Serial.println();
        Serial.println("MPU6050 ------------");
      
        /* Obtener nuevos eventos de sensor con las lecturas */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
      
        /* Imprimir los valores */
        Serial.print("Acceleration X: ");
        Serial.print(a.acceleration.x);
        Serial.print(", Y: ");
        Serial.print(a.acceleration.y);
        Serial.print(", Z: ");
        Serial.print(a.acceleration.z);
        Serial.println(" m/s^2");
      
        Serial.print("Rotation X: ");
        Serial.print(g.gyro.x);
        Serial.print(", Y: ");
        Serial.print(g.gyro.y);
        Serial.print(", Z: ");
        Serial.print(g.gyro.z);
        Serial.println(" rad/s");
      
        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.println(" degC");
      
        Serial.println("MPU6050 ------------");
        Serial.println();
      }
