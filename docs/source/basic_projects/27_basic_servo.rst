.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Explorez plus en profondeur le Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support expert** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_servo:

Servo
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/servo_uno.html#servo-uno

Vue d'ensemble
------------------

Dans cette leçon, vous découvrirez l'utilisation de l'Arduino et des moteurs servo. En vous concentrant sur l'Arduino Uno et le servo moteur SG90, vous apprendrez à programmer l'Arduino pour contrôler le mouvement de balayage du servo. Cette technique est essentielle dans diverses applications comme la robotique et les systèmes automatisés.

Composants nécessaires
-------------------------

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

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

Câblage
----------------------

.. image:: img/27-servo_bb.png
    :align: center
    :width: 70%

.. raw:: html

   <br/>

Schéma de câblage
-----------------------

.. image:: img/27_servo_schematic.png
    :align: center
    :width: 60%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``27-servo.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\27-servo`` directement.
    * Ou copier ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c57ddb7a-0acb-4a64-938a-0a0abfc0ec4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Analyse du code
------------------------


1. Ici, la bibliothèque ``Servo`` est incluse, ce qui permet de contrôler facilement le moteur servo. La broche connectée au servo et l'angle initial du servo sont également définis.

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Définir la broche du servo
      int angle = 0;           // Initialiser la variable d'angle à 0 degrés
      Servo servo;             // Créer un objet servo

2. La fonction ``setup()`` s'exécute une fois lorsque l'Arduino démarre. Le servo est attaché à la broche définie à l'aide de la fonction ``attach()``.

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. La boucle principale contient deux boucles ``for``. La première boucle augmente l'angle de 0 à 180 degrés, et la seconde boucle diminue l'angle de 180 à 0 degrés. La commande ``servo.write(angle)`` règle le servo à l'angle spécifié. Le ``delay(15)`` fait attendre le servo pendant 15 millisecondes avant de passer à l'angle suivant, contrôlant ainsi la vitesse du mouvement de balayage.

   .. code-block:: arduino

      void loop() {
        // Balayage de 0 à 180 degrés
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // Balayage de retour de 180 à 0 degrés
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }