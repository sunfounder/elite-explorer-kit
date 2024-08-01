.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_humiture_sensor:

Módulo Sensor de Humedad y Temperatura
==========================================

.. https://docs.sunfounder.com/projects/3in1-kit/en/latest/basic_project/ar_dht11.html#ar-dht11

Descripción general
--------------------------

La humedad y la temperatura están estrechamente relacionadas desde la cantidad física misma hasta la vida real de las personas.
La temperatura y la humedad del entorno humano afectarán directamente la función termorreguladora y el efecto de transferencia de calor del cuerpo humano.
Esto afectará aún más la actividad del pensamiento y el estado mental, influyendo así en la eficiencia de nuestro estudio y trabajo.

La temperatura es una de las siete cantidades físicas básicas en el Sistema Internacional de Unidades, que se utiliza para medir el grado de calor y frío de un objeto.
El Celsius es una de las escalas de temperatura más utilizadas en el mundo, expresada por el símbolo "℃".

La humedad es la concentración de vapor de agua presente en el aire.
La humedad relativa del aire se utiliza comúnmente en la vida y se expresa en %HR. La humedad relativa está estrechamente relacionada con la temperatura.
Para un cierto volumen de gas sellado, cuanto mayor sea la temperatura, menor será la humedad relativa, y cuanto menor sea la temperatura, mayor será la humedad relativa.

El dht11, un sensor digital de temperatura y humedad, se proporciona en este kit. Utiliza un sensor de humedad capacitivo y un termistor para medir el aire circundante y emite una señal digital en el pin de datos.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|


Cableado
----------------------

.. image:: img/07-dht11_bb.png
    :align: center

Diagrama esquemático
-----------------------

.. image:: img/07_humiture_schematic.png
    :align: center
    :width: 40%

Código
---------------

.. note::

    * Puedes abrir el archivo ``07-humiture_sensor.ino`` en la ruta ``elite-explorer-kit-main\basic_project\07-humiture_sensor`` directamente.
    * O copiar este código en Arduino IDE.

.. note:: 
    Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"DHT sensor library"** e instálala. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1086b07f-9551-4fa0-a0c0-391a6465ad2e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Después de que el código se cargue correctamente, verás que el Monitor Serial imprime continuamente la temperatura y la humedad, y a medida que el programa se estabiliza, estos dos valores se volverán más precisos.


Análisis del código
------------------------

#. Inclusión de las bibliotecas necesarias y definición de constantes.
   Esta parte del código incluye la biblioteca del sensor DHT y define el número de pin y el tipo de sensor utilizado en este proyecto.

   .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino y busca **"DHT sensor library"** e instálala. 

   .. code-block:: arduino
    
      #include <DHT.h>
      #define DHTPIN 2       // Define el pin utilizado para conectar el sensor
      #define DHTTYPE DHT11  // Define el tipo de sensor

#. Creación del objeto DHT.
   Aquí creamos un objeto DHT usando el número de pin y el tipo de sensor definidos.

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // Crea un objeto DHT

#. Esta función se ejecuta una vez cuando el Arduino se inicia. Inicializamos la comunicación serial y el sensor DHT en esta función.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // Initialize the DHT sensor
      }

#. Bucle principal.
   La función ``loop()`` se ejecuta continuamente después de la función setup. Aquí, leemos los valores de humedad y temperatura, calculamos el índice de calor y imprimimos estos valores en el monitor serial. Si la lectura del sensor falla (devuelve NaN), imprime un mensaje de error.

   .. note::
    
      El |link_heat_index| es una forma de medir qué tan caliente se siente en el exterior combinando la temperatura del aire y la humedad. También se llama "temperatura aparente".

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }
