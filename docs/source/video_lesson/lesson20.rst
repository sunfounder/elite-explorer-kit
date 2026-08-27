.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

LECCIÓN 20: Bucles For en Arduino
=====================================

Esta lección muestra cómo crear un sistema de LED RGB controlado por el usuario usando el Arduino, donde el usuario puede especificar el número de parpadeos a través del monitor serial. Aquí tienes un breve resumen de lo que aprenderás:

1. **Revisión de la Tarea Anterior**: Recapitulación de la tarea de la Lección 19, que consistía en hacer parpadear un LED RGB en una secuencia rojo-verde-azul durante 25 ciclos.
2. **Configuración del Circuito**: Instrucciones detalladas sobre cómo conectar correctamente un LED RGB y sus resistencias limitadoras de corriente al Arduino. Cada canal de color (rojo, verde, azul) se conecta a un pin digital PWM (pines 9, 10 y 11), y el cátodo común (pata larga) se conecta a tierra.
3. **Escritura del Código**: Instrucciones paso a paso para: Definir los pines para cada canal de color del LED RGB. Configurar el monitor serial para la entrada del usuario. Usar comandos de escritura analógica para controlar el brillo de cada canal de color. Implementar un bucle for para controlar el número de ciclos de parpadeo basado en la entrada del usuario. Asegurarse de que el programa se detenga después del número especificado de parpadeos.
4. **Consejos de Depuración**: Orientación sobre cómo solucionar problemas comunes tales como: Corregir errores de sintaxis en el código. Asegurarse de que el programa se repita el número correcto de veces. Manejar correctamente la entrada del usuario y detener el programa después de los ciclos especificados.
5. **Aplicaciones Prácticas**: Ejemplos de uso de bucles for para repetir una secuencia de acciones un número especificado de veces.
6. **Tarea**: Repetir la secuencia de parpadeos un número especificado de veces por el usuario sin usar un bucle for. Asegurarse de que el programa se detenga después del número especificado de parpadeos.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/CZh8QB26jjU?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

