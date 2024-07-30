.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

LEÇON 14 : Lire les entrées utilisateur depuis le moniteur série
===========================================================================

Cette leçon démontre comment créer un programme interactif utilisant l'Arduino, en se concentrant sur l'obtention des entrées utilisateur via le moniteur série et en effectuant différentes opérations en fonction de l'entrée. Voici un bref aperçu de ce que vous allez apprendre :

1. **Introduction à la saisie utilisateur via le moniteur série** : Une introduction au concept de lecture des entrées utilisateur depuis le moniteur série de l'Arduino, essentiel pour les projets interactifs.
2. **Configuration de la communication série** : Instructions détaillées sur la configuration de la communication série dans le code Arduino, en utilisant Serial.begin(9600) pour initialiser le moniteur série.
3. **Lecture de différents types de données** : Guide étape par étape sur la façon de lire divers types de données de l'utilisateur :
   - Entiers : Utilisation de Serial.parseInt() pour lire des valeurs entières.
   - Flottants : Utilisation de Serial.parseFloat() pour lire des nombres à virgule flottante.
   - Chaînes : Utilisation de Serial.readString() pour lire des chaînes de caractères.
4. **Implémentation d'une boucle While pour attendre les entrées utilisateur** : Explication de la façon d'implémenter une boucle while pour attendre les entrées utilisateur, en s'assurant que le programme ne se poursuit pas tant que l'utilisateur n'a pas saisi les données requises.
5. **Gestion des erreurs avec les entrées série** : Conseils sur la gestion des erreurs liées aux types de données incorrects et sur la configuration du moniteur série en "Pas de fin de ligne" pour éviter que des caractères supplémentaires ne soient lus comme entrée.
6. **Application pratique et exemple de code** : Un projet exemple où l'utilisateur est invité à entrer un nombre, un flottant et une chaîne de caractères, démontrant comment capturer et utiliser ces entrées efficacement. Le code fourni montre comment demander une entrée, attendre celle-ci, puis lire et traiter l'entrée.
7. **Devoirs** : Créer un programme qui demande à l'utilisateur un niveau de luminosité (entre 0 et 255) pour une LED et ajuste ensuite la luminosité de la LED en conséquence.

**Vidéo**

.. raw:: html

       <iframe width="700" height="500" src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
