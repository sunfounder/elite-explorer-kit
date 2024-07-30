.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 18 : Contrôler une LED RGB avec un Arduino
====================================================

Cette leçon montre comment utiliser une LED RGB avec un Arduino pour créer différentes couleurs en combinant les lumières rouge, verte et bleue, en s'appuyant sur les leçons précédentes sur le contrôle des LED et l'utilisation des capacités PWM de l'Arduino. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revue des devoirs précédents** : Récapitulatif de l'exercice de la leçon 17, qui consistait à créer un circuit avec trois LED (rouge, jaune et verte) et à les contrôler en fonction des entrées utilisateur.
2. **Configuration du circuit** : Instructions détaillées sur la manière de connecter correctement une LED RGB à l'Arduino. La LED RGB a quatre pattes : une masse commune et trois pour les LED rouge, verte et bleue. Chaque canal de couleur nécessite une résistance limitant le courant pour éviter les interférences et assurer un bon fonctionnement.
3. **Écriture du code** : Instructions de codage étape par étape pour :
   - Définir les broches pour chaque canal de couleur de la LED RGB.
   - Configurer le moniteur série pour les entrées utilisateur.
   - Utiliser des commandes d'écriture numérique pour allumer et éteindre chaque canal de couleur.
   - Convertir les entrées utilisateur en minuscules pour gérer différents cas.
4. **Applications pratiques** : Exemples de contrôle de la LED RGB pour produire diverses couleurs en allumant différentes combinaisons des LED rouge, verte et bleue.
5. **Devoirs** : Étendre le projet en demandant à l'utilisateur des couleurs spécifiques, y compris rouge, vert, bleu, cyan, magenta, jaune, orange et blanc.

**Vidéo**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/ASHBCGGeEPk?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

