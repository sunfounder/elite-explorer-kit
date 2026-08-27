.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 13 : LED réglable contrôlée par un potentiomètre
=======================================================

Cette leçon démontre comment créer une LED réglable contrôlée par un potentiomètre en utilisant un Arduino, en s'appuyant sur les leçons précédentes concernant la lecture des valeurs analogiques et le contrôle des sorties via PWM. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revoir les devoirs précédents** : Récapitulatif de l'exercice de la leçon 12, qui consistait à utiliser un potentiomètre pour contrôler la luminosité d'une LED.
2. **Mise en place du circuit** : Instructions détaillées sur la façon de connecter correctement un potentiomètre et une LED à l'Arduino, en s'assurant que chaque composant est configuré correctement pour l'expérience.
3. **Écriture du code** : Instructions de codage pas à pas pour lire la valeur analogique du potentiomètre et l'utiliser pour ajuster la luminosité de la LED via PWM. Cela inclut des calculs mathématiques pour traduire la résistance variable du potentiomètre en une valeur de tension que l'Arduino peut utiliser pour contrôler la LED.
4. **Conseils de débogage** : Conseils pour résoudre les problèmes courants tels que des lectures incorrectes du potentiomètre ou des erreurs dans la sortie PWM affectant la luminosité de la LED.
5. **Devoirs** : Étendre le projet de la leçon en expérimentant avec différentes mappages des lectures du potentiomètre à la luminosité de la LED pour comprendre la mise à l'échelle linéaire par rapport à l'échelle exponentielle et ses impacts perceptuels sur la gradation de la LED.

**Vidéo**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/PXf51k0alGU?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

