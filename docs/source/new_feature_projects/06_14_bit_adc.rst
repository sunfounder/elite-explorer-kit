.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _new_adc:

Convertidor Analógico-Digital (ADC) (hasta 14 bits)
=======================================================

En los proyectos electrónicos contemporáneos, leer y procesar señales analógicas con precisión es esencial. Los Convertidores Analógico-Digital (ADC) transforman señales analógicas en digitales para su manejo por microcontroladores. El Arduino Uno R4 ha visto avances significativos en esta área, gracias a su procesador más potente. Mientras que la generación anterior, el Arduino Uno R3, tenía una resolución máxima de 10 bits, la resolución ADC del Arduino Uno R4 es ahora de 14 bits. Esta mejora permite obtener valores más precisos de las señales analógicas, mejorando la refinación y precisión en la recolección y procesamiento de datos.

Configurar la resolución del ADC
-------------------------------------

La resolución estándar en la placa Arduino está configurada a 10 bits (0-1023). El UNO R4 WiFi admite hasta una resolución de 14 bits (0-16383), proporcionando valores más precisos de las señales analógicas. Para actualizar la resolución, solo necesitas usar el comando ``analogReadResolution()``.

.. code-block:: arduino

   void setup() {
     // abrir una conexión serial
     Serial.begin(9600);
   }
   
   void loop() {
     // leer la entrada en A0 con la resolución predeterminada (10 bits)
     // y enviarla a través de la conexión serial
     analogReadResolution(10);
     Serial.print("ADC 10-bit (default) : ");
     Serial.print(analogRead(A0));
   
     // cambiar la resolución a 12 bits y leer A0
     analogReadResolution(12);
     Serial.print(", 12-bit : ");
     Serial.print(analogRead(A0));
   
     // cambiar la resolución a 14 bits y leer A0
     analogReadResolution(14);
     Serial.print(", 16-bit : ");
     Serial.print(analogRead(A0));
   
     // cambiar la resolución a 8 bits y leer A0
     analogReadResolution(8);
     Serial.print(", 8-bit : ");
     Serial.println(analogRead(A0));
   
     // un pequeño retraso para no saturar el Monitor Serial
     delay(100);
   }

notes y advertencias
---------------------

Al configurar la resolución del ADC, considera los siguientes puntos:

1. **Límites de capacidad del hardware**: Si configuras el valor de ``analogReadResolution()`` más alto que las capacidades de la placa, el Arduino solo informará a su resolución más alta, rellenando los bits adicionales con ceros. Por ejemplo, usar el Uno R4 con ``analogReadResolution(16)`` dará un número aproximado de 16 bits, con los primeros 14 bits conteniendo la lectura real del ADC y los últimos 2 bits rellenos con ceros.

2. **Configuraciones de menor resolución**: Si configuras el valor de ``analogReadResolution()`` más bajo que las capacidades de la placa, los bits menos significativos adicionales leídos del ADC serán descartados. Esto te permite trabajar con un rango simplificado si tu aplicación no requiere la resolución completa.

Entender estas consideraciones te ayudará a utilizar eficazmente las capacidades del ADC del Arduino Uno R4, asegurando un rendimiento y precisión óptimos para tu aplicación específica.


**Referencia**
- |link_analogReadResolution|
- |link_r4_minima_adc|
- |link_r4_wifi_adc|







