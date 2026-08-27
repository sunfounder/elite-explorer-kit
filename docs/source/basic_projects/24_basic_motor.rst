.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_motor:

Moteur
==========================

Aperçu
--------

Dans cette leçon, vous apprendrez à utiliser un moteur, dont le principe de fonctionnement repose sur le fait qu'une bobine sous tension est forcée de tourner dans un champ magnétique, entraînant ainsi la rotation du rotor du moteur. L'engrenage pignon entraîne alors le volant moteur à tourner.

Composants nécessaires
-----------------------------

Pour ce projet, nous avons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DU COMPOSANT
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_power`
        - \-

Câblage
----------------------

Dans cet exemple, nous utilisons un module d'alimentation pour alimenter l'anode et la cathode de la breadboard.

.. note::
    Le moteur nécessite davantage de puissance pendant son fonctionnement ; veuillez donc maintenir le module d'alimentation connecté à un câble de charge lorsqu'il est utilisé.

.. image:: img/24-motor_bb.png
    :align: center
    :width: 90%

.. raw:: html
  
  <br/> 

Schéma de câblage
-------------------------

.. image:: img/24_motor_schematic.png
    :align: center
    :width: 100%

.. raw:: html
  
  <br/> 

Code
----

.. note::

    * Vous pouvez ouvrir le fichier ``24-motor.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\24-motor`` directement.
    * Ou copier ce code dans l'IDE Arduino.

.. literalinclude:: /_code/24_basic_motor.ino
   :language: cpp
   :linenos:
   :caption: 24-motor.ino

Après avoir téléversé le code sur la carte UNO, vous pouvez choisir la direction de rotation du moteur en tapant "A" ou "B" dans le moniteur série.


Analyse du code
--------------------------

Le moteur peut être entraîné en fournissant une différence de tension entre les plaques de cuivre des deux côtés du moteur. 
Ainsi, il suffit d'écrire 0 pour la tension d'un côté de la plaque de cuivre et 5V pour l'autre côté. Modifiez la valeur du signal analogique écrit pour ajuster la direction et la vitesse.

.. code-block:: arduino

   // Fonction pour faire tourner le moteur dans le sens horaire
   void clockwise(int Speed) {
     analogWrite(motorBI, 0);
     analogWrite(motorFI, Speed);
   }
   
   // Fonction pour faire tourner le moteur dans le sens antihoraire
   void anticlockwise(int Speed) {
     analogWrite(motorBI, Speed);
     analogWrite(motorFI, 0);
   }

Dans cet exemple, Serial.Read() est utilisé pour contrôler la direction du moteur. 

Lorsque vous tapez "A" dans le moniteur série, la fonction clockwise(255) est appelée pour faire tourner le moteur à une vitesse de 255. 
Entrez "B", et le moteur tournera dans le sens inverse.

.. code-block:: arduino

   void loop() {
     // Vérifiez s'il y a des données disponibles sur le port série
     if (Serial.available() > 0) {
       int incomingByte = Serial.read(); // Lire les données entrantes
       
       // Déterminez la direction du moteur en fonction de l'entrée utilisateur
       switch (incomingByte) {
         case 'A':
           clockwise(255); // Faire tourner le moteur dans le sens horaire
           Serial.println("Le moteur tourne dans le sens horaire.");
           break;
         case 'B':
           anticlockwise(255); // Faire tourner le moteur dans le sens antihoraire
           Serial.println("Le moteur tourne dans le sens antihoraire.");
           break;
       }
     }
     
     delay(3000); // Attendre 3 secondes
     stopMotor(); // Arrêter le moteur
   }

