.. note::

    Bonjour et bienvenue dans la communauté SunFounder des passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _new_dac:

Convertisseur numérique-analogique (DAC)
==============================================

L'Arduino Uno R4 WiFi est doté d'un convertisseur numérique-analogique (DAC) intégré. Un DAC est crucial pour convertir des signaux numériques en leurs équivalents analogiques, une fonctionnalité particulièrement vitale dans des applications telles que le traitement audio, la génération de signaux analogiques et d'autres scénarios nécessitant une sortie analogique précise.

Le DAC de l'Uno R4 WiFi offre une résolution allant jusqu'à 12 bits, fournissant des capacités de sortie analogique véritable qui surpassent celles des broches PWM.

.. image:: img/07_dac.png
  :width: 70%

Jouer de la musique avec le DAC
++++++++++++++++++++++++++++++++++++++

**Schéma de circuit**

.. image:: img/07_dac_bb.png
  :width: 100%
  :align: center

**Téléverser le code**

Ouvrez le fichier ``07-dac.ino`` situé dans ``elite-explorer-kit-main\r4_new_feature\07-dac``, ou copiez le code suivant dans votre Arduino IDE.

.. note:: 
    Veuillez placer le fichier ``pitches.h`` dans le même répertoire que le code pour assurer un fonctionnement correct.

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :linenos:
   :caption: pitches.h

.. literalinclude:: /_code/07_dac.ino
   :language: cpp
   :linenos:
   :caption: 07-dac.ino

Ce projet utilise l'Arduino et le DAC (convertisseur numérique-analogique) pour jouer le thème emblématique de Super Mario Bros. Il utilise une bibliothèque appelée ``analogWave`` pour la génération d'ondes sinusoïdales et une autre bibliothèque, ``pitches.h``, pour définir les fréquences des notes.

- ``melody[]`` : Ce tableau contient les notes à jouer ainsi que leurs durées. Les notes sont représentées par des hauteurs prédéfinies (par exemple, ``NOTE_E5``) et les durées sont représentées en termes de temps (par exemple, 4 signifie une noire). Vous pouvez essayer de composer votre propre mélodie en changeant les notes et les durées dans le tableau melody[]. Si vous êtes intéressé, il existe un référentiel sur GitHub (|link_arduino_songs|) qui fournit du code Arduino pour jouer différentes chansons. Bien que leur approche puisse être différente de celle de ce projet, vous pouvez vous référer à leurs notes et durées. (Il suffit de remplacer le ``melody[]`` dans la piste correspondante par le code de ce projet.)

- ``tempo`` : Le tempo pour ce projet est fixé à 200 BPM (battements par minute), qui est utilisé pour calculer la durée de chaque note. Modifier cette valeur changera la vitesse de l'exécution de la chanson.

- **Générateur d'ondes sinusoïdales** : La fonction ``sine`` de la bibliothèque ``analogWave`` initialise un générateur d'ondes sinusoïdales à 10 Hz, qui est utilisé pour la sortie des notes via le DAC.

- **Durée de la note** : En fonction du tempo défini et du nombre de battements pour chaque note, la durée de chaque note est calculée.

- **Lecture et pause** : Chaque note est jouée pendant 85% de sa durée calculée, suivie d'une pause de 15% pour distinguer les notes.

- **Boucle** : Une fois la mélodie terminée, le code se réinitialise automatiquement et commence à rejouer.

Cet exemple montre comment utiliser Arduino et du matériel externe (DAC) pour générer de la musique. Il montre également comment utiliser des tableaux et des boucles pour simplifier la logique de la lecture musicale.


**Référence**

- |link_r4_dac|