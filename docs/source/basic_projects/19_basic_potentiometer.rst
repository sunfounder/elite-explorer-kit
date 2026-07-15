.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_potentiometer:

Potenciómetro
===========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_an_led_by_potentiometer_uno.html


Descripción general
-----------------------

En esta lección, veremos cómo cambiar la luminancia de un LED usando un potenciómetro y recibir los datos del potenciómetro en el Monitor Serie para ver cómo cambia su valor.

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
    *   - :ref:`led`
        - |link_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


Conexión
----------------------

.. image:: img/19-potentiometer_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
---------------------------

En este experimento, el potenciómetro se usa como divisor de voltaje, lo que significa conectar dispositivos a sus tres pines. Conecta el pin central del potenciómetro al pin A0 y los otros dos pines a 5V y GND respectivamente. Por lo tanto, el voltaje del potenciómetro es de 0-5V. Gira la perilla del potenciómetro y el voltaje en el pin A0 cambiará. Luego convierte ese voltaje en un valor digital (0-1024) con el convertidor AD en la placa de control. A través de la programación, podemos usar el valor digital convertido para controlar el brillo del LED en la placa de control.

.. image:: img/19_potentiometer_schematic.png
   :align: center
   :width: 70%

Código
---------------

.. note::

    * Puedes abrir el archivo ``19-potentiometer.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\19-potentiometer``.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/19_basic_potentiometer.ino
   :language: cpp
   :linenos:
   :caption: 19-potentiometer.ino

Después de subir el código a la placa Uno, puedes abrir el monitor serie para observar los valores leídos del potenciómetro. A medida que giras la perilla del potenciómetro, el valor leído cambiará en consecuencia. La lectura analógica en bruto del potenciómetro variará de \(0\) a \(1023\). Simultáneamente, el código escala este valor a un rango de \(0\) a \(255\), que también se muestra en el monitor serie. Este valor escalado se usa para controlar el brillo del LED conectado. El LED se volverá más brillante o más tenue según el valor escalado. Vale la pena mencionar que, aunque el rango teórico del potenciómetro es de \(0\) a \(1023\), el rango real puede variar ligeramente debido a las tolerancias del hardware.

Análisis del código
------------------------

#. Inicialización y configuración (definiendo modos de pin e inicializando la comunicación serie)

   Antes de entrar en el bucle, definimos qué pines estamos usando e inicializamos la comunicación serie.

   .. code-block:: arduino

      const int analogPin = 0;  // Pin de entrada analógica conectado al potenciómetro
      const int ledPin = 9;     // Pin de salida digital conectado al LED

      void setup() {
        Serial.begin(9600);  // Inicializar comunicación serie con una tasa de baudios de 9600
      }

#. Lectura de entrada analógica (obteniendo datos del potenciómetro)

   En este segmento, leemos los datos analógicos del potenciómetro y los imprimimos en el monitor serie.

   .. code-block:: arduino

        inputValue = analogRead(analogPin);  // Leer el valor analógico del potenciómetro
        Serial.print("Input: ");             // Imprimir "Input: " en el monitor serie
        Serial.println(inputValue);          // Imprimir el valor de entrada bruto en el monitor serie

#. Mapeo y escalado (convirtiendo datos del potenciómetro)

   Escalamos los datos brutos del potenciómetro, que están en el rango de 0-1023, a un nuevo rango de 0-255.

   ``map(value, fromLow, fromHigh, toLow, toHigh)`` se usa para convertir un número de un rango a otro. Por ejemplo, si el valor está dentro del rango de ``fromLow`` y ``fromHigh``, se convertirá a un valor correspondiente dentro del rango de ``toLow`` y ``toHigh``, manteniendo la proporcionalidad entre los dos rangos.

   En este caso, dado que el pin del LED (pin 9) tiene un rango de 0-255, necesitamos mapear los valores en el rango de 0-1023 para que coincidan con esa misma escala de 0-255.

   .. code-block:: arduino

      outputValue = map(inputValue, 0, 1023, 0, 255);  // Mapear el valor de entrada a un nuevo rango

#. Control del LED y salida serie

   Finalmente, controlamos el brillo del LED basado en el valor escalado e imprimimos el valor escalado para monitoreo.

   .. code-block:: arduino

      Serial.print("Output: ");                        // Imprimir "Output: " en el monitor serie
      Serial.println(outputValue);                     // Imprimir el valor de salida escalado en el monitor serie
      analogWrite(ledPin, outputValue);                // Controlar el brillo del LED basado en el valor escalado
      delay(1000);     