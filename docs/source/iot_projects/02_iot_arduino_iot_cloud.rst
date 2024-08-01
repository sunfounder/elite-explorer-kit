.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de Expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y Compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_arduino_cloud:

Arduino IoT Cloud
===========================

Este ejemplo demuestra el código para comunicarse con el Arduino IoT Cloud. Su propósito es conectar al Arduino IoT Cloud e interactuar con variables en la nube. Aquí, enviamos los valores de temperatura leídos del sensor DHT11 al Arduino IoT Cloud, permitiéndonos monitorizarlo desde la nube.

.. image:: img/02_cloud.png

**Componentes Requeridos**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - Ítems en este Kit
        - Enlace
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

También puedes comprarlos por separado desde los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Introducción del Componente
        - Enlace de Compra

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**Conexiones**

.. image:: img/02_arduino_iot_cloud_bb.png
    :width: 90%
    :align: center

.. raw:: html
    
    <br/>

**Esquemático**

.. image:: img/02_arduino_iot_cloud_schematic.png
  :width: 40%
  :align: center


**Instalar Arduino Create Agent**

1. Visita la dirección https://create.arduino.cc/getting-started/plugin/welcome.

2. Haz clic en START.

  .. image:: img/02_install_agent_2.png
     :width: 95%

3. Elige la versión que se ajuste a tu ordenador, y se descargará un paquete de instalación.

  .. image:: img/02_install_agent_3.png
     :width: 95%

4. Instala el agente.

  .. image:: img/02_install_agent_4.png
    :width: 85%

5. Después de la instalación, vuelve a tu navegador, y verás la siguiente interfaz.

  .. image:: img/02_install_agent_5.png
     :width: 95%

6. Haz clic en NEXT, y luego puedes ir al editor web.

  .. image:: img/02_install_agent_6.png
     :width: 95%

**Usar Arduino IoT Cloud**

1. Primero, necesitas iniciar sesión o registrarte en Arduino.

  https://login.arduino.cc/login

2. Una vez que hayas iniciado sesión, haz clic en IoT Cloud en la esquina superior derecha.

   .. image:: img/02_iot_cloud_2.png

3. Crea un nuevo "thing".

   .. image:: img/02_iot_cloud_3.png
  
4. Asocia tu dispositivo.

   .. image:: img/02_iot_cloud_4.png

5. Configura un nuevo dispositivo.

   .. image:: img/02_iot_cloud_5.png

6. Elige tu placa Arduino.

   .. image:: img/02_iot_cloud_6.png

7. Espera un momento, y tu UNO R4 WiFi será detectado. Continúa haciendo clic en configurar.

   .. image:: img/02_iot_cloud_7.png

8. Dale un nombre a tu dispositivo.

  .. image:: img/02_iot_cloud_8.png

9. Haz que tu dispositivo esté listo para IoT, y recuerda guardar la clave secreta.

  .. image:: img/02_iot_cloud_9.png

10. Espera unos minutos.

  .. image:: img/02_iot_cloud_10.png

.. 5. Selecciona Arduino UNO R4 WiFi.

.. .. image:: img/sp231016_164654.png

11. Configura el WiFi.

  .. image:: img/02_iot_cloud_11.png

12. Aquí necesitarás ingresar tu contraseña de WiFi y la clave secreta.

  .. image:: img/02_iot_cloud_12.png

13. Agrega una variable.

  .. image:: img/02_iot_cloud_13.png

14. Aquí, queremos mostrar la temperatura en IoT Cloud, así que configuramos una variable de tipo float de solo lectura.

  .. image:: img/02_iot_cloud_14.png

15. Después de completar, ve al sketch.

  .. image:: img/02_iot_cloud_15.png

16. Abre el editor completo.

  .. image:: img/02_iot_cloud_16.png

17. Haz clic en Libraries en el lado derecho, luego en Library Manager.

  .. image:: img/02_iot_cloud_17.png

18. Busca la librería del sensor DHT y selecciónala.

  .. image:: img/02_iot_cloud_18.png

19. Ahora, necesitamos editar el código. Puedes ver que el editor ya ha preparado el código relacionado con IoT Cloud para ti. Solo necesitas agregar la funcionalidad específica que necesitas. En este ejemplo, agregamos código para leer la temperatura usando el sensor DHT11.

  .. code-block::
      :emphasize-lines: 1,2,3,22,23,24,32,55,56
  
      // DHT sensor library - Version: Latest 
      #include <DHT.h>
      #include <DHT_U.h>
  
      /* 
      Sketch generated by the Arduino IoT Cloud Thing "Untitled"
      https://create.arduino.cc/cloud/things/260edac8-34f9-4e2e-9214-ba0c20994220 
  
      Arduino IoT Cloud Variables description
  
      The following variables are automatically generated and updated when changes are made to the Thing
  
      float temperature;
  
      Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
      which are called when their values are changed from the Dashboard.
      These functions are generated with the Thing and added at the end of this sketch.
      */
  
      #include "thingProperties.h"
  
      #define DHTPIN 11     
      #define DHTTYPE DHT11 
      DHT dht(DHTPIN, DHTTYPE);
  
      void setup() {
          // Initialize serial and wait for port to open:
          Serial.begin(9600);
          // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
          delay(1500); 
  
          dht.begin();
  
          // Defined in thingProperties.h
          initProperties();
  
          // Connect to Arduino IoT Cloud
          ArduinoCloud.begin(ArduinoIoTPreferredConnection);
          
          /*
              The following function allows you to obtain more information
              related to the state of network and IoT Cloud connection and errors
              the higher number the more granular information you’ll get.
              The default is 0 (only errors).
              Maximum is 4
          */
          setDebugMessageLevel(2);
          ArduinoCloud.printDebugInfo();
      }
  
      void loop() {
          ArduinoCloud.update();
          // Your code here 
          
          float temp = dht.readTemperature();  
          temperature = temp;
          
      }
 
20. Sube el código. Puede que se te pida actualizar; sigue las indicaciones para completar.

  .. image:: img/02_iot_cloud_20.png

21. Regresa a IoT Cloud.

  .. image:: img/02_iot_cloud_21.png

22. Haz clic en el menú en la esquina superior izquierda.

  .. image:: img/02_iot_cloud_22.png

23. Haz clic en el panel.

  .. image:: img/02_iot_cloud_23.png

24. Crea un panel.

  .. image:: img/02_iot_cloud_24.png

25. Hay muchos widgets disponibles; aquí, elegimos un widget de valor para mostrar la temperatura.

  .. image:: img/02_iot_cloud_25.png

26. Después de hacer clic, aparecerá una interfaz de configuración de widget, donde puedes conectar el widget a la variable de nube que creaste anteriormente.

  .. image:: img/02_iot_cloud_26.png

27. Ahora, puedes ver las lecturas del sensor en Arduino IoT Cloud.

  .. image:: img/02_iot_cloud_27.png

**¿Cómo funciona?**

Después de configurar IoT Cloud (configuración del dispositivo, configuración de red, creación de variables en la nube), noterás que el sketch en la nube se actualiza automáticamente. Por lo tanto, la mayor parte del código ya está escrita para ti.

Abre el editor, y verás que este sketch contiene cuatro archivos:

``main.ino``: Usado para inicializar el Arduino y realizar las tareas principales del bucle. Adicionalmente, incluye la lógica para conectar y comunicarse con el Arduino IoT Cloud.

``thingProperties.h``: Este archivo se usa para definir variables y funciones en Arduino IoT Cloud. Contiene declaraciones de variables en la nube y sus funciones de callback asociadas. En el código proporcionado, se usa para inicializar propiedades en la nube (por ejemplo, la variable temperatura) y conectarse a Arduino IoT Cloud.

``Secret``: Usado para almacenar información sensible o privada, como contraseñas de WiFi o claves API. Esta información sensible típicamente no se expone directamente en el código, sino que se almacena en el archivo Secret para mejorar la seguridad.

``ReadMe.adoc``: Contiene la documentación del proyecto u otra información relevante para una mejor comprensión y uso del proyecto. Este archivo usualmente no contiene código ejecutable, sino más bien información descriptiva y documentación.

Necesitamos agregar algo de código para el sensor DHT11. Este código es idéntico al que usarías en tu IDE local. La única diferencia es que necesitas asignar el valor leído del DHT11 a la variable en la nube ``temperature``.

(note: Nunca deberías modificar ``thingProperties.h`` y ``Secret``. Estos serán modificados cuando hagas cambios usando el editor Thing.)
