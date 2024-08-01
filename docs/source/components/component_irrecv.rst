.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_ir_receiver:

Receptor Infrarrojo
=================================

Receptor IR
----------------------------

.. image:: img/infrared-receiver_01.png
    :width: 60%

* S: Salida de señal
* +: VCC
* -: GND

Un receptor infrarrojo es un componente que recibe señales infrarrojas y puede recibir rayos infrarrojos de manera independiente y emitir señales compatibles con el nivel TTL. Es similar en tamaño a un transistor encapsulado en plástico normal y es adecuado para todo tipo de control remoto infrarrojo y transmisión infrarroja.

El SL838 es un pequeño receptor para sistemas de control remoto infrarrojo. Contiene un fotodiodo de alta velocidad y alta sensibilidad y un preamplificador, y está encapsulado con resina epoxi para formar un filtro infrarrojo. Su principal ventaja es que tiene una función fiable incluso en un entorno perturbado.

La comunicación por infrarrojos, o IR, es una tecnología de comunicación inalámbrica popular, de bajo costo y fácil de usar. La luz infrarroja tiene una longitud de onda ligeramente más larga que la luz visible, por lo que es imperceptible para el ojo humano, ideal para la comunicación inalámbrica. Un esquema de modulación común para la comunicación por infrarrojos es la modulación de 38KHz.

* Puede usarse para control remoto
* Amplio voltaje de funcionamiento: 2.7~5V
* Filtro interno para la frecuencia PCM 
* Compatibilidad con TTL y CMOS
* Gran capacidad antiinterferencias
* Cumplimiento RoHS

Control Remoto
-------------------------

.. image:: img/infrared-receiver_02.jpeg
    :width: 70%

Este es un control remoto inalámbrico infrarrojo mini y delgado con 21 botones funcionales y una distancia de transmisión de hasta 8 metros, que es adecuado para operar una amplia gama de dispositivos en la habitación de un niño.

* Tamaño: 85x39x6mm
* Rango de control remoto: 8-10m
* Batería: pila de litio y manganeso tipo botón de 3V
* Frecuencia portadora de infrarrojos: 38KHz
* Material de la superficie: PET de 0.125mm
* Vida útil: más de 20,000 usos


**Ejemplo**

* :ref:`basic_irrecv` (Basic Project)
* :ref:`fun_guess_number` (Fun Project)