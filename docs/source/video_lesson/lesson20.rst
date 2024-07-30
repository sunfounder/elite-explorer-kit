.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 20 : Les boucles For dans Arduino
============================================

Cette leçon montre comment créer un système LED RGB contrôlé par l'utilisateur à l'aide de l'Arduino, où l'utilisateur peut spécifier le nombre de clignotements via le moniteur série. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revue des devoirs précédents** : Récapitulatif de l'exercice de la leçon 19, qui consistait à faire clignoter une LED RGB dans une séquence rouge-vert-bleu pendant 25 cycles.
2. **Configuration du circuit** : Instructions détaillées sur la manière de connecter correctement une LED RGB et ses résistances limitant le courant à l'Arduino. Chaque canal de couleur (rouge, vert, bleu) est connecté à une broche PWM (broches 9, 10 et 11), et la cathode commune (longue patte) est connectée à la masse.
3. **Écriture du code** : Instructions de codage étape par étape pour :
   - Définir les broches pour chaque canal de couleur de la LED RGB.
   - Configurer le moniteur série pour les entrées utilisateur.
   - Utiliser les commandes analogWrite pour contrôler la luminosité de chaque canal de couleur.
   - Implémenter une boucle for pour contrôler le nombre de cycles de clignotement en fonction de l'entrée utilisateur.
   - S'assurer que le programme s'arrête après le nombre de clignotements spécifié.
4. **Conseils de débogage** : Conseils pour résoudre les problèmes courants tels que :
   - Correction des erreurs de syntaxe dans le code.
   - S'assurer que le programme boucle le bon nombre de fois.
   - Gérer correctement les entrées utilisateur et arrêter le programme après les cycles spécifiés.
5. **Applications pratiques** : Exemples d'utilisation des boucles for pour répéter une séquence d'actions un nombre spécifié de fois.
6. **Devoirs** : Répéter la séquence de clignotement un nombre de fois spécifié par l'utilisateur sans utiliser de boucle for. S'assurer que le programme s'arrête après le nombre de clignotements spécifié.

**Vidéo**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/CZh8QB26jjU?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

