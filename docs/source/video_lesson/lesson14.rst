.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

LECCIÓN 14: Leer la Entrada del Usuario Desde el Monitor Serial
====================================================================

Esta lección demuestra cómo crear un programa interactivo utilizando el Arduino, enfocándose en obtener la entrada del usuario a través del monitor serial y realizar diferentes operaciones basadas en la entrada. Aquí tienes un breve resumen de lo que aprenderás:

1. **Introducción a la Entrada del Usuario a Través del Monitor Serial**: Una introducción al concepto de leer la entrada del usuario desde el monitor serial de Arduino, esencial para proyectos interactivos.
2. **Configuración de la Comunicación Serial**: Instrucciones detalladas sobre cómo configurar la comunicación serial en el código de Arduino, utilizando Serial.begin(9600) para inicializar el monitor serial.
3. **Leer Diferentes Tipos de Datos**: Guía paso a paso sobre cómo leer varios tipos de datos del usuario:
   - **Enteros**: Usando Serial.parseInt() para leer valores enteros.
   - **Flotantes**: Usando Serial.parseFloat() para leer números de punto flotante.
   - **Cadenas**: Usando Serial.readString() para leer cadenas de texto.
4. **Implementar un Bucle While para Esperar la Entrada del Usuario**: Explicación de cómo implementar un bucle while para esperar la entrada del usuario, asegurando que el programa no proceda hasta que el usuario haya ingresado los datos requeridos.
5. **Manejo de Errores con Entrada Serial**: Consejos sobre cómo manejar errores relacionados con tipos de datos incorrectos y asegurarse de que el monitor serial esté configurado en 'No line ending' para evitar que se lean caracteres adicionales como entrada.
6. **Aplicación Práctica y Código de Ejemplo**: Un proyecto de ejemplo donde se pide al usuario un número, un flotante y una cadena, demostrando cómo capturar y usar estas entradas de manera efectiva. El código proporcionado muestra cómo pedir la entrada, esperar por ella, y luego leer y procesar la entrada.
7. **Tarea**: Crear un programa que pida al usuario un nivel de brillo (entre 0 y 255) para un LED y luego ajuste el brillo del LED en consecuencia.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef" title="Reproductor de video de YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

