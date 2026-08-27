.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 17 : Contrôler plusieurs LED depuis le moniteur série
=====================================================================

Cette leçon montre comment créer un système de contrôle des LED avec l'Arduino, où l'utilisateur peut allumer et éteindre différentes LED en fonction des entrées du moniteur série. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revue des devoirs précédents** : Récapitulatif de l'exercice de la leçon 16, qui consistait à créer un circuit avec trois LED (rouge, jaune et verte) et à les contrôler en fonction des entrées utilisateur.
2. **Configuration du circuit** : Instructions détaillées sur la manière de connecter correctement trois LED et leurs résistances limitant le courant à l'Arduino. La patte longue (anode) de chaque LED est connectée à une broche numérique, et la patte courte (cathode) est connectée à la terre via une résistance.
3. **Écriture du code** : Instructions de codage étape par étape pour :
   - Définir les broches pour chaque LED,
   - Configurer le moniteur série pour les entrées utilisateur,
   - Utiliser des instructions if pour allumer la LED spécifiée et s'assurer que toutes les autres LED sont éteintes,
   - Convertir les entrées utilisateur en minuscules pour gérer différents cas.
4. **Conseils de débogage** : Conseils pour résoudre les problèmes courants tels que les points-virgules manquants, les accolades incorrectes et s'assurer que toutes les LED sont correctement éteintes lorsqu'une nouvelle LED est allumée.
5. **Applications pratiques** : Exemples d'utilisation des instructions if pour gérer les entrées utilisateur et contrôler plusieurs sorties (LED) en fonction de ces entrées.
6. **Devoirs** : Étendre le projet en demandant à l'utilisateur à la fois la couleur de la LED et la luminosité souhaitée.

**Vidéo**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/Ai7uqYHt_Yc?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

