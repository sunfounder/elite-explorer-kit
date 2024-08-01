.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_gy87_qmc5883l:

QMC5883L
==========================

Descripción general
--------------------------

En este tutorial, exploraremos el módulo IMU GY-87, centrándonos en su magnetómetro QMC5883L. La primera parte del tutorial te guía a través de la calibración del magnetómetro QMC5883L, esencial para mediciones precisas del campo magnético. Aprenderás cómo cargar un sketch de calibración en Arduino, realizar la calibración en tiempo real y aplicar estos ajustes en tus proyectos. La segunda parte del tutorial cubre la inicialización del MPU6050 (acelerómetro y giroscopio) y el QMC5883L en un Arduino Uno utilizando las bibliotecas Adafruit MPU6050 y QMC5883LCompass. Aprenderás a leer y mostrar datos del sensor en el Monitor Serial, una habilidad fundamental para aplicaciones en navegación, seguimiento de movimiento y detección de orientación.

Componentes necesarios
-------------------------

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
    :width: 90%

.. raw:: html

   <br/>


Diagrama esquemático
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%

Instalar biblioteca
-----------------------

.. note:: 
    Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino. 
    
        - Busca **"Adafruit MPU6050"** e instálala

          Al instalar cada biblioteca, asegúrate de seleccionar la instalación de todas las dependencias.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Busca **"QMC5883LCompass"** e instálala


.. _basic_gy87_calibrate:

Calibrar QMC5883L
-----------------------

.. note::

    * Puedes abrir el archivo ``09-gy87_compass_calibration.ino`` en la ruta de ``elite-explorer-kit-main\basic_project\09-gy87_compass_calibration`` directamente.
    * O copiar este código en el IDE de Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/252c7a58-3a9f-4c66-959e-f45fc19e68aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código, abre el monitor serial. Sigue las instrucciones en el monitor serial para calibrar el QMC5883L. Cuando se te indique mover el sensor, se recomienda utilizar el método de calibración en forma de 8. Alternativamente, simplemente mantén el sensor paralelo al suelo y gíralo en sentido horario o antihorario hasta que el monitor serial indique que la calibración está completa.

.. image:: img/09_calibrate_qmc5883l.png
    :width: 100%
    :align: center

Una vez que se hayan recopilado todos los datos de calibración, el sketch te proporcionará un código que se verá como ``compass.setCalibrationOffsets(-375.00, -179.00, 85.00);`` y ``compass.setCalibrationScales(1.04, 0.96, 1.01);``. Copia este código. Es posible que desees guardarlo para futuras referencias.

Al usar el QMC5883L: Abre el sketch de tu proyecto y pega la línea de código que copiaste directamente debajo de la llamada ``compass.init()``. Así:

.. code:: arduino 

   void initializeQMC5883L() {
   
     compass.init();
   
     // Debes reemplazar el código a continuación según tus resultados de calibración
     compass.setCalibrationOffsets(-375.00, -179.00, 85.00);
     compass.setCalibrationScales(1.04, 0.96, 1.01);
   
   }

Código
---------------------------------------------

.. note::

   Los magnetómetros deben calibrarse(:ref:`basic_gy87_calibrate`) antes de que puedan usarse como brújulas, y deben mantenerse nivelados durante su uso y **mantenerse alejados de objetos de hierro, materiales magnetizados y cables que transportan corriente**.

.. note::

    * Puedes abrir el archivo ``09-gy87_qmc5883l.ino`` en la ruta de ``elite-explorer-kit-main\basic_project\09-gy87_qmc5883l`` directamente.
    * O copiar este código en el IDE de Arduino.
    * Coloca el código obtenido de los pasos de calibración debajo de la línea de código ``compass.init()`` en la función ``initializeQMC5883L()``.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b266a18-ce7b-4330-8c10-c9f4148bb8ec/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Análisis del código
------------------------


#. Incluir bibliotecas e inicializar sensores
   Esta sección incluye las bibliotecas necesarias para los sensores MPU6050 y QMC5883L e inicializa sus objetos.

   .. code-block:: arduino
      
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>

      Adafruit_MPU6050 mpu;
      QMC5883LCompass compass;

#. Función de configuración

   Inicializa la comunicación serial, el sensor MPU6050 y configura el MPU6050 en modo bypass I2C para permitir el acceso directo al magnetómetro QMC5883L. Luego, inicializa el magnetómetro QMC5883L.

   .. code-block:: arduino
      
      void setup() {
        // Inicializa la comunicación serial con una velocidad de 9600 baudios
        Serial.begin(9600);
      
        // Inicializa el sensor MPU6050 (acelerómetro y giroscopio)
        initializeMPU6050();
      
        // Habilita el bypass I2C en el MPU6050 para acceder directamente al magnetómetro QMC5883L
        mpu.setI2CBypass(true);
      
        // Inicializa el sensor magnetómetro QMC5883L
        initializeQMC5883L();
      }

#. Función de bucle

   Lee continuamente los datos del magnetómetro QMC5883L y los imprime en el Monitor Serial.

   .. code-block:: arduino
      
      void loop() {
        printQMC5883L();
        delay(500);
      }

#. Función para inicializar el QMC5883L

   Inicializa y calibra el magnetómetro QMC5883L. Los valores de calibración deben ajustarse según los datos específicos de calibración.(:ref:`basic_gy87_calibrate`)

   .. code-block:: arduino
      
      void initializeQMC5883L() {
        compass.init();
      
        // Debes reemplazar el código a continuación según tus resultados de calibración
        compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
        compass.setCalibrationScales(0.97, 1.02, 1.02);
      }

#. Función para imprimir los datos del QMC5883L

   Esta función lee los valores X, Y, Z y el acimut del magnetómetro, y los imprime en el Monitor Serial.

   .. code-block:: arduino

    void printQMC5883L() {
    
      Serial.println();
      Serial.println("QMC5883L ------------");
    
    	int x, y, z, a;
    	char myArray[3];
    	
    	compass.read();
      
    	x = compass.getX();
    	y = compass.getY();
    	z = compass.getZ();
    	
    	a = compass.getAzimuth();
    
    	compass.getDirection(myArray, a);
      
    	Serial.print("X: ");
    	Serial.print(x);
    
    	Serial.print(" Y: ");
    	Serial.print(y);
    
    	Serial.print(" Z: ");
    	Serial.print(z);
    
    	Serial.print(" Azimuth: ");
    	Serial.print(a);
    
    	Serial.print(" Direction: ");
    	Serial.print(myArray[0]);
    	Serial.print(myArray[1]);
    	Serial.println(myArray[2]);
    
      Serial.println("QMC5883L ------------");
      Serial.println();
    }
