.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

LECCIÓN 17: Controlar Múltiples LEDs desde el Monitor Serial
==================================================================

Esta lección muestra cómo crear un sistema de control de LEDs utilizando el Arduino, donde el usuario puede encender y apagar diferentes LEDs en función de la entrada a través del monitor serial. Aquí tienes un breve resumen de lo que aprenderás:

1. **Revisión de la Tarea Anterior**: Recapitulación de la tarea de la Lección 16, que consistía en hacer un circuito con tres LEDs (rojo, amarillo y verde) y controlarlos en función de la entrada del usuario.
2. **Configuración del Circuito**: Instrucciones detalladas sobre cómo conectar correctamente tres LEDs y sus resistencias limitadoras de corriente al Arduino. La pata larga (ánodo) de cada LED está conectada a un pin digital, y la pata corta (cátodo) está conectada a tierra a través de una resistencia.
3. **Escritura del Código**: Instrucciones paso a paso para:Definir los pines para cada LED,Configurar el monitor serial para la entrada del usuario,Usar declaraciones if para encender el LED especificado y asegurarse de que todos los demás LEDs estén apagados,Convertir la entrada del usuario a minúsculas para manejar diferentes casos.
4. **Consejos de Depuración**: Orientación sobre cómo solucionar problemas comunes como la falta de punto y coma, llaves incorrectas y asegurarse de que todos los LEDs estén apagados correctamente cuando se encienda un nuevo LED.
5. **Aplicaciones Prácticas**: Ejemplos de cómo usar declaraciones if para manejar la entrada del usuario y controlar múltiples salidas (LEDs) en función de esa entrada.
6. **Tarea**: Ampliar el proyecto pidiendo al usuario tanto el color del LED como el brillo deseado.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/Ai7uqYHt_Yc?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

