.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_potentiometer:

Potentiomètre
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_an_led_by_potentiometer_uno.html


Vue d'ensemble
--------------------

Dans cette leçon, voyons comment modifier la luminosité d'une LED à l'aide d'un potentiomètre et recevoir les données du potentiomètre dans le Moniteur Série pour voir ses valeurs changer.

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
    *   - :ref:`led`
        - |link_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


Câblage
----------------------

.. image:: img/19-potentiometer_bb.png
    :align: center
    :width: 70%

Schéma de câblage
---------------------------

Dans cette expérience, le potentiomètre est utilisé comme diviseur de tension, ce qui signifie connecter des dispositifs à ses trois broches. Connectez la broche centrale du potentiomètre à la broche A0 et les deux autres broches respectivement à 5V et GND. Par conséquent, la tension du potentiomètre est de 0-5V. Tournez le bouton du potentiomètre et la tension à la broche A0 changera. Ensuite, convertissez cette tension en une valeur numérique (0-1024) avec le convertisseur AD de la carte de contrôle. Grâce à la programmation, nous pouvons utiliser la valeur numérique convertie pour contrôler la luminosité de la LED sur la carte de contrôle.

.. image:: img/19_potentiometer_schematic.png
   :align: center
   :width: 70%
   
Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``19-potentiometer.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\19-potentiometer`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb09e333-4057-40d8-8485-0de2d88c06c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code sur la carte Uno, vous pouvez ouvrir le moniteur série pour observer les valeurs lues du potentiomètre. Lorsque vous tournez le bouton du potentiomètre, la valeur lue changera en conséquence. La lecture analogique brute du potentiomètre variera de \(0\) à \(1023\). Simultanément, le code ajuste cette valeur à une plage de \(0\) à \(255\), qui est également affichée sur le moniteur série. Cette valeur ajustée est ensuite utilisée pour contrôler la luminosité de la LED connectée. La LED deviendra plus brillante ou plus faible en fonction de la valeur ajustée. Il est à noter que bien que la plage théorique du potentiomètre soit de \(0\) à \(1023\), la plage réelle peut varier légèrement en raison des tolérances matérielles.

Analyse du code
------------------

#. Initialisation et configuration (définition des modes des broches et initialisation de la communication série)

   Avant d'entrer dans la boucle, nous définissons les broches que nous utilisons et initialisons la communication série.

   .. code-block:: arduino

      const int analogPin = 0;  // Broche d'entrée analogique connectée au potentiomètre
      const int ledPin = 9;     // Broche de sortie numérique connectée à la LED

      void setup() {
        Serial.begin(9600);  // Initialiser la communication série avec un débit de 9600 bauds
      }

#. Lecture de l'entrée analogique (obtention des données du potentiomètre)

   Dans ce segment, nous lisons les données analogiques du potentiomètre et les imprimons sur le moniteur série.

   .. code-block:: arduino

        inputValue = analogRead(analogPin);  // Read the analog value from the potentiometer
        Serial.print("Input: ");             // Print "Input: " to the serial monitor
        Serial.println(inputValue);          // Print the raw input value to the serial monitor

#. Cartographie et mise à l'échelle (conversion des données du potentiomètre)

   Nous ajustons les données brutes du potentiomètre, qui se situent dans la plage de 0 à 1023, à une nouvelle plage de 0 à 255.

   ``map(value, fromLow, fromHigh, toLow, toHigh)`` est utilisé pour convertir un nombre d'une plage à une autre. Par exemple, si la valeur se situe dans la plage de ``fromLow`` et ``fromHigh``, elle sera convertie en une valeur correspondante dans la plage de ``toLow`` et ``toHigh``, en maintenant la proportionnalité entre les deux plages.

   Dans ce cas, comme la broche LED (broche 9) a une plage de 0 à 255, nous devons mapper les valeurs dans la plage de 0 à 1023 pour correspondre à cette même échelle de 0 à 255.

   .. code-block:: arduino

      outputValue = map(inputValue, 0, 1023, 0, 255);  // Mapper la valeur d'entrée à une nouvelle plage

#. Contrôle de la LED et sortie série

   Enfin, nous contrôlons la luminosité de la LED en fonction de la valeur ajustée et imprimons la valeur ajustée pour la surveillance.

   .. code-block:: arduino

      Serial.print("Output: ");                        // Imprimer "Output: " sur le moniteur série
      Serial.println(outputValue);                     // Imprimer la valeur de sortie ajustée sur le moniteur série
      analogWrite(ledPin, outputValue);                // Contrôler la luminosité de la LED en fonction de la valeur ajustée
      delay(1000);     