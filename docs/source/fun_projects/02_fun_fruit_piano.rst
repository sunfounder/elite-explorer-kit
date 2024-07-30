.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_fruit_piano:

Piano de fruits
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/02_fun_fruit_piano.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Ce projet est un piano de fruits simple qui lit les entrées d'un capteur tactile MPR121 et joue de la musique via un DAC. En d'autres termes, nous avons transformé des fruits en clavier, vous permettant de jouer de la musique en les touchant simplement.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_mpr121`
        - \-
    *   - :ref:`cpn_audio_speaker`
        - \-


**Câblage**

.. image:: img/02_fruit_piano_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


**Schéma**

.. image:: img/02_fruit_piano_schematic.png
   :width: 100%

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``02_fruit_piano.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\02_fruit_piano`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. note::
   Pour installer la bibliothèque, utilisez le Gestionnaire de bibliothèques Arduino et recherchez **"Adafruit MPR121"** et installez-la.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/e677c06a-7af1-4846-a507-dd69c0c50aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Comment ça marche ?**

Voici une explication étape par étape du code :

1. Initialisation des bibliothèques et des objets :

   Importez les bibliothèques nécessaires : bibliothèque ``Wire`` (pour la communication I2C), bibliothèque ``Adafruit_MPR121`` (pour piloter le MPR121), bibliothèque ``analogWave`` (pour générer des formes d'onde analogiques), et ``pitches.h`` (qui définit les fréquences des notes).
   Créez des instances des objets ``Adafruit_MPR121`` et ``analogWave``.
   Définissez un tableau de notes pour stocker la note correspondant à chaque canal tactile.

2. ``setup()`` :

   Initialisez la communication série et attendez son démarrage.
   Vérifiez et initialisez le MPR121 ; s'il n'est pas trouvé, affichez un message d'erreur sur le moniteur série et arrêtez l'exécution.
   Initialisez l'objet ``analogWave`` et définissez la fréquence initiale de l'onde sinusoïdale à 10Hz.

3. ``loop()`` :

   Lisez les canaux actuellement touchés du MPR121.
   Parcourez tous les canaux, vérifiez lequel est touché et jouez la note correspondante.
   Ajoutez un petit délai entre chaque itération.

4. Fonction ``playNote()`` :

   La fonction ``playNote`` prend un paramètre ``note`` et définit la fréquence du DAC pour jouer la note correspondante.
   Délayez pendant une période pour jouer la note.
   Arrêtez de jouer la note.

