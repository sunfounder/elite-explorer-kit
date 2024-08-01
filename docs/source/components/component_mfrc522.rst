.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_mfrc522:

Módulo MFRC522
=====================

**RFID**

La identificación por radiofrecuencia (RFID) se refiere a tecnologías que implican el uso de comunicación inalámbrica entre un objeto (o etiqueta) y un dispositivo de interrogación (o lector) para rastrear e identificar automáticamente dichos objetos. El rango de transmisión de la etiqueta está limitado a varios metros desde el lector. No es necesario que haya una línea de visión clara entre el lector y la etiqueta.

La mayoría de las etiquetas contienen al menos un circuito integrado (IC) y una antena. El microchip almacena información y es responsable de gestionar la comunicación de radiofrecuencia (RF) con el lector. Las etiquetas pasivas no tienen una fuente de energía independiente y dependen de una señal electromagnética externa, proporcionada por el lector, para alimentar sus operaciones. Las etiquetas activas contienen una fuente de energía independiente, como una batería. Por lo tanto, pueden tener capacidades de procesamiento y transmisión aumentadas y un mayor rango.

.. image:: img/mfrc522.png

**MFRC522**

El MFRC522 es un tipo de chip integrado de lectura y escritura de tarjetas. Se utiliza comúnmente en la radio a 13.56MHz. Lanzado por la compañía NXP, es un chip de tarjeta sin contacto de bajo voltaje, bajo costo y tamaño pequeño, una excelente opción para instrumentos inteligentes y dispositivos portátiles.

El MF RC522 utiliza un concepto avanzado de modulación y demodulación que se presenta completamente en todos los tipos de métodos y protocolos de comunicación sin contacto pasiva a 13.56MHz. Además, soporta el algoritmo de cifrado rápido CRYPTO1 para verificar productos MIFARE. El MFRC522 también admite comunicación sin contacto de alta velocidad de la serie MIFARE, con una velocidad de transmisión de datos bidireccional de hasta 424kbit/s. Como nuevo miembro de la serie de lectores altamente integrados a 13.56MHz, el MF RC522 es muy similar al existente MF RC500 y MF RC530, pero también existen grandes diferencias. Se comunica con la máquina host a través de una manera serial que necesita menos cableado. Puedes elegir entre el modo SPI, I2C y UART serial (similar a RS232), lo que ayuda a reducir la conexión, ahorrar espacio en la placa PCB (tamaño más pequeño) y reducir el costo.

**Ejemplo**


* :ref:`basic_mfrc522` (Basic Project)
* :ref:`fun_access` (Fun Project)