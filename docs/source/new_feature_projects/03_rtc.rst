.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _new_rtc:

Reloj en Tiempo Real (RTC)
========================================

El RTC (Reloj en Tiempo Real) está integrado en el microcontrolador (RA4M1) del UNO R4 WiFi. El RTC es un módulo de reloj autónomo capaz de funcionar incluso cuando la fuente de alimentación principal está desconectada, gracias a una fuente de energía de respaldo como una batería. Esto hace que el RTC sea increíblemente versátil para diversas aplicaciones como la programación de tareas en sistemas de automatización del hogar o la estampación temporal de datos en aplicaciones de registro de datos.

.. note::
    El UNO R4 WiFi tiene un pin VRTC que mantiene la operación del RTC integrado incluso cuando la placa pierde energía. Para utilizar esta característica, aplica un voltaje entre 1.6 y 3.6 V al pin VRTC.


Tareas Repetitivas Programadas
++++++++++++++++++++++++++++++++++++++++++++

En ciertos casos de uso, es posible que necesites ejecutar tareas específicas a intervalos regulares. Para establecer interrupciones periódicas, primero necesitarás inicializar una función de callback periódica. A continuación, se muestra un ejemplo de código Arduino que utiliza una interrupción periódica para hacer parpadear un LED cada 2 segundos.


**Cargar el Código**

Abre el archivo ``03-rtc.ino`` ubicado en ``elite-explorer-kit-main\r4_new_feature\03-rtc``, o pega el siguiente código en tu IDE de Arduino.

.. literalinclude:: /_code/03_rtc.ino
   :language: cpp
   :linenos:
   :caption: 03-rtc.ino


**Explicación del Código**

1. Inicializando Componentes y Bibliotecas

   .. code-block:: arduino
   
     #include "RTC.h"
     volatile bool irqFlag = false;
     bool ledState = false;
     const int led = LED_BUILTIN;
   
     void setup() {
       pinMode(led, OUTPUT);
       Serial.begin(9600);
       RTC.begin();
     }
   
   - ``#include "RTC.h"``: Incluye la biblioteca RTC.
   - ``volatile bool irqFlag = false;``: Declara una bandera booleana volátil. ``volatile`` asegura que la variable pueda ser accedida o modificada de manera segura por una interrupción. Para más detalles sobre ``volatile``, consulta la `documentación de Arduino sobre volatile <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_.
   - ``bool ledState = false;``: Declara una variable booleana para llevar el control del estado del LED.
   - ``const int led = LED_BUILTIN;``: Declara una constante para el pin del LED integrado.
   - ``pinMode(led, OUTPUT);``: Configura el pin del LED como salida.
   - ``Serial.begin(9600);``: Inicializa la comunicación serial a 9600 baudios.
   - ``RTC.begin();``: Inicializa el RTC.

   .. raw:: html
    
        <br/>

2. Configurando el Reloj en Tiempo Real

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: Crea un objeto ``RTCTime`` y lo inicializa con una fecha y hora específicas.
   - ``RTC.setTime(mytime);``: Configura el RTC con la hora inicializada.
   
   Configurando y Verificando el Callback Periódico
   
   .. code-block:: arduino
   
     if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
       Serial.println("ERROR: periodic callback not set");
     }
   
     void loop() {
       if (irqFlag) {
         Serial.println("Timed CallBack");
         ledState = !ledState;
         digitalWrite(led, ledState);
         irqFlag = false;
       }
     }
   
     void periodicCallback() {
       irqFlag = true;
     }
   
   - ``RTC.setPeriodicCallback(...);``: Establece un callback periódico para activarse cada 2 segundos. El periodo puede ser especificado utilizando las siguientes enumeraciones:

      - ``ONCE_EVERY_2_SEC``
      - ``ONCE_EVERY_1_SEC``
      - ``N2_TIMES_EVERY_SEC``
      - ``N4_TIMES_EVERY_SEC``
      - ``N8_TIMES_EVERY_SEC``
      - ``N16_TIMES_EVERY_SEC``
      - ``N32_TIMES_EVERY_SEC``
      - ``N64_TIMES_EVERY_SEC``
      - ``N128_TIMES_EVERY_SEC``
      - ``N256_TIMES_EVERY_SEC``

   - ``void loop() {...}``: Verifica si el callback ha sido activado. Si es así, cambia el estado del LED.
   - ``void periodicCallback() {...}``: La función de callback establece ``irqFlag = true`` cuando se activa.


**Referencia**

- |link_r4_rtc|
