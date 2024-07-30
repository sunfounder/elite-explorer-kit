.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 19 : Mélanger les couleurs avec une LED RGB
=================================================

Cette leçon montre comment créer un système LED RGB contrôlé par l'utilisateur à l'aide de l'Arduino, où l'utilisateur peut choisir différentes couleurs en fonction des entrées via le moniteur série. Voici un bref aperçu de ce que vous allez apprendre :

1. **Revue des devoirs précédents** : Récapitulatif de l'exercice de la leçon 18, qui consistait à contrôler une LED RGB pour produire diverses couleurs en mélangeant les lumières rouge, verte et bleue.
2. **Configuration du circuit** : Instructions détaillées sur la manière de connecter correctement une LED RGB et ses résistances limitant le courant à l'Arduino. Chaque canal de couleur (rouge, vert, bleu) est connecté à une broche numérique (broches 9, 10 et 11), et la cathode commune (grande patte) est connectée à la masse.
3. **Écriture du code** : Instructions de codage étape par étape pour :
   - Définir les broches pour chaque canal de couleur de la LED RGB.
   - Configurer le moniteur série pour les entrées utilisateur.
   - Utiliser des commandes analogWrite pour ajuster la luminosité de chaque canal de couleur afin de mélanger différentes couleurs.
   - Convertir les entrées utilisateur en minuscules pour gérer différents cas.
   - Gérer diverses entrées utilisateur pour produire des couleurs spécifiques (rouge, vert, bleu, cyan, magenta, jaune, orange, blanc) en mélangeant correctement les valeurs RGB.
4. **Conseils de débogage** : Conseils pour résoudre les problèmes courants tels que :
   - S'assurer de la bonne capitalisation et de la syntaxe dans le code.
   - Vérifier les points-virgules manquants et les accolades incorrectes.
   - Ajuster les valeurs RGB pour obtenir la bonne sortie de couleur en modifiant les niveaux de luminosité.
5. **Applications pratiques** : Exemples de mélange de couleurs à l'aide des valeurs RGB pour produire une large gamme de couleurs.
6. **Devoirs** : Faire clignoter la LED RGB dans une séquence de rouge, vert, bleu, attendre une seconde, et répéter cette séquence 25 fois. S'assurer que le programme s'arrête après 25 cycles. Créer une courte vidéo de la solution, la poster sur YouTube, et faire un lien vers la leçon pour examen.

**Vidéo**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

