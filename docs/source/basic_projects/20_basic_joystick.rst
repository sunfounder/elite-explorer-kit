.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_joystick:

Module Joystick
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/joystick_ps2_uno.html#joystick-uno


Vue d'ensemble
-------------------

Un joystick est un dispositif d'entrée constitué d'un manche qui pivote sur une base et transmet son angle ou sa direction à l'appareil qu'il contrôle. Les joysticks sont souvent utilisés pour contrôler les jeux vidéo et les robots. Un Joystick PS2 est utilisé ici.

Composants requis
-------------------------

Pour ce projet, nous avons besoin des composants suivants. 

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Câblage
----------------------

.. image:: img/20-joystick_bb.png
    :align: center
    :width: 70%

Schéma de câblage
---------------------

Ce module possède deux sorties analogiques (correspondant aux décalages biaxiaux X,Y). 

Dans cette expérience, nous utilisons la carte Uno pour détecter la direction de déplacement du bouton du joystick.

.. image:: img/20_joystick_schematic.png
    :align: center 
    :width: 70%

Code
-------

.. note::

    * Vous pouvez ouvrir le fichier ``20-joystick.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\20-joystick`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac0f9910-e53e-43a3-a5ae-ec4d3a3f4aa1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Maintenant, lorsque vous poussez le joystick, les coordonnées des axes X et Y affichées sur le Moniteur Série changeront en conséquence. En appuyant sur le bouton, la coordonnée Z=0 sera également affichée.

Analyse du code
-------------------

Le code utilise le moniteur série pour afficher la valeur des broches VRX et VRY du joystick PS2.

.. code-block:: arduino

    void loop()
    {
        Serial.print("X: "); 
        Serial.print(analogRead(xPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // print the value of SW
        delay(50);
    }