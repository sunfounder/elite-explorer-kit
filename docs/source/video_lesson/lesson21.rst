.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 21 : Comprendre les boucles While
========================================

Cette leçon montre comment utiliser les boucles while dans Arduino pour créer un système de clignotement de LED RGB contrôlé par l'utilisateur basé sur des entrées via le moniteur série. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revue des devoirs précédents** : Récapitulatif de l'exercice de la leçon 20, qui consistait à faire clignoter une LED RGB dans une séquence rouge-vert-bleu un nombre de fois spécifié par l'utilisateur en utilisant une boucle while au lieu d'une boucle for.
2. **Configuration du circuit** : Instructions détaillées sur la manière de connecter correctement une LED RGB et ses résistances limitant le courant à l'Arduino. Chaque canal de couleur (rouge, vert, bleu) est connecté à une broche PWM (broches 9, 10 et 11), et la cathode commune (longue patte) est connectée à la masse.
3. **Écriture du code** : Instructions de codage étape par étape pour :
   - Définir les broches pour chaque canal de couleur de la LED RGB.
   - Configurer le moniteur série pour les entrées utilisateur.
   - Utiliser les commandes digitalWrite pour contrôler l'état marche/arrêt de chaque canal de couleur.
   - Implémenter une boucle while pour contrôler le nombre de cycles de clignotement en fonction de l'entrée utilisateur.
   - S'assurer que le programme s'arrête après le nombre de clignotements spécifié.
4. **Conseils de débogage** : Conseils pour résoudre les problèmes courants tels que :
   - Correction des erreurs de syntaxe dans le code.
   - S'assurer que le programme boucle le bon nombre de fois.
   - Gérer correctement les entrées utilisateur et arrêter le programme après les cycles spécifiés.
   - Initialiser et incrémenter correctement les compteurs de boucle.
5. **Applications pratiques** : Exemples d'utilisation des boucles while pour répéter une séquence d'actions un nombre spécifié de fois. La leçon met l'accent sur l'importance d'obtenir des entrées utilisateur pour contrôler le comportement du programme et de gérer correctement le compteur de boucle.
6. **Tests et débogage** : Importance de tester le code sous différentes conditions pour garantir sa fiabilité.
7. **Devoirs** : Répéter la séquence de clignotement un nombre de fois spécifié par l'utilisateur sans utiliser de boucle for. S'assurer que le programme s'arrête après le nombre de clignotements spécifié.

**Vidéo**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/Cw_i7l_RFVE?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

