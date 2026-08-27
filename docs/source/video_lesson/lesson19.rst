.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

LECCIÓN 19: Mezclando colores con un LED RGB
================================================

Esta lección muestra cómo crear un sistema de LED RGB controlado por el usuario usando el Arduino, donde el usuario puede elegir diferentes colores según la entrada a través del monitor serial. Aquí tienes un breve resumen de lo que aprenderás:

1. **Revisión de la Tarea Anterior**: Recapitulación de la tarea de la Lección 18, que consistía en controlar un LED RGB para producir varios colores mezclando luces rojas, verdes y azules.
2. **Configuración del Circuito**: Instrucciones detalladas sobre cómo conectar correctamente un LED RGB y sus resistencias limitadoras de corriente al Arduino. Cada canal de color (rojo, verde, azul) se conecta a un pin digital (pines 9, 10 y 11), y el cátodo común (pata larga) se conecta a tierra.
3. **Escritura del Código**: Instrucciones paso a paso para: Definir los pines para cada canal de color del LED RGB. Configurar el monitor serial para la entrada del usuario. Usar comandos de escritura analógica para ajustar el brillo de cada canal de color y mezclar diferentes colores. Convertir la entrada del usuario a minúsculas para manejar diferentes casos. Manejar varias entradas del usuario para producir colores específicos (rojo, verde, azul, cian, magenta, amarillo, naranja, blanco) mezclando adecuadamente los valores RGB.
4. **Consejos de Depuración**: Orientación sobre cómo solucionar problemas comunes tales como: Asegurar la capitalización y sintaxis correctas en el código. Verificar la falta de puntos y comas y llaves incorrectas. Ajustar los valores RGB para obtener la salida de color correcta ajustando los niveles de brillo.
5. **Aplicaciones Prácticas**: Ejemplos de mezcla de colores usando valores RGB para producir una amplia gama de colores.
6. **Tarea**: Hacer parpadear el LED RGB en una secuencia de rojo, verde, azul, esperar un segundo y repetir esta secuencia 25 veces. Asegúrate de que el programa se detenga después de 25 ciclos. Crea un breve video de la solución, publícalo en YouTube y enlázalo a la lección para su revisión.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

