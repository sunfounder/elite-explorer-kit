.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_button:

Bouton
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_led_by_button_uno.html#button-uno


Vue d'ensemble
--------------------

Dans cette leçon, vous allez apprendre à contrôler une LED à l'aide d'un bouton avec Arduino. Les boutons et les LED sont des composants fondamentaux dans une large gamme d'appareils électroniques, tels que les télécommandes, les lampes de poche et les installations interactives. Dans cette configuration, un bouton est utilisé comme dispositif d'entrée pour contrôler l'état d'une LED, qui sert de dispositif de sortie.

Le bouton est connecté à la broche 12 de la carte Arduino Uno R4, et la LED est connectée à la broche 13. Lorsque le bouton est enfoncé, un signal est envoyé à l'Arduino, déclenchant l'allumage de la LED. Inversement, lorsque le bouton est relâché, la LED s'éteint. Ce mécanisme simple mais efficace peut être la base de projets plus complexes, tels que des systèmes domotiques, des affichages interactifs, et bien plus encore.

À la fin de cette leçon, vous comprendrez comment lire l'entrée d'un bouton et l'utiliser pour contrôler une LED, acquérant ainsi une compréhension fondamentale des opérations d'entrée/sortie avec Arduino.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


Câblage
----------------------

.. image:: img/18-button_bb.png
    :align: center
    :width: 70%


Schéma de câblage
------------------------

Connectez une extrémité du bouton à la broche 12, qui est reliée à une résistance pull-down et à un condensateur de 0.1uF (104) (pour éliminer les parasites et obtenir un niveau stable lorsque le bouton fonctionne). Connectez l'autre extrémité de la résistance à la masse (GND) et l'une des broches à l'autre extrémité du bouton au 5V. Lorsque le bouton est enfoncé, la broche 12 est à 5V (HIGH) et la broche 13 (intégrée à une LED) est également définie sur HIGH. Ensuite, relâchez le bouton (la broche 12 passe à LOW) et la broche 13 est à LOW. Vous verrez ainsi la LED s'allumer et s'éteindre alternativement lorsque le bouton est enfoncé et relâché.

.. image:: img/18_button_schematic.png
    :align: center
    :width: 70%


Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``18-button.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\18-button`` directement.
    * Ou copiez ce code dans Arduino IDE.




.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a710eb54-9447-4542-ac98-c9a7e1ec4256/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    


Analyse du code
-------------------

#. Définir les constantes et les variables

   Dans ce segment, les numéros de broche pour le bouton et la LED sont définis. De plus, une variable ``buttonState`` est déclarée pour contenir l'état actuel du bouton.
 
   .. code-block:: arduino
 
     const int buttonPin = 12;
     const int ledPin = 13;
     int buttonState = 0;

#. Fonction Setup

   La fonction ``setup()`` s'exécute une fois lorsque la carte Arduino démarre. Les modes des broches pour le bouton et la LED sont définis à l'aide de la fonction ``pinMode``.
 
   .. code-block:: arduino
 
     void setup() {
       pinMode(buttonPin, INPUT);
       pinMode(ledPin, OUTPUT);
     }

#. Boucle principale

   La fonction ``loop()`` s'exécute en continu. À l'intérieur de cette boucle, la fonction ``digitalRead()`` est utilisée pour lire l'état du bouton. En fonction de l'état du bouton, la LED est allumée ou éteinte.
 
   .. code-block:: arduino
 
     void loop() {
       buttonState = digitalRead(buttonPin);
       if (buttonState == HIGH) {
         digitalWrite(ledPin, HIGH);
       } else {
         digitalWrite(ledPin, LOW);
       }
     }
