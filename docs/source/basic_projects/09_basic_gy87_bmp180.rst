.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans le monde des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_gy87_bmp180:

BMP180
==========================


Aperçu
---------------

Dans ce tutoriel, nous explorons le module IMU GY-87, en nous concentrant sur le capteur BMP180 pour mesurer la température, la pression et l'altitude. Idéal pour des applications telles que la surveillance météorologique et le suivi de l'altitude, cette leçon couvre l'interfaçage du GY-87 avec un Arduino Uno et l'utilisation de la bibliothèque Adafruit BMP085. Vous apprendrez à initialiser le capteur BMP180 et à lire ses données sur le moniteur série Arduino, une compétence cruciale pour les projets nécessitant des données environnementales.

Composants nécessaires
-------------------------

Dans ce projet, nous avons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit Elite Explorer
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
    *   - :ref:`cpn_gy87`
        - \-


Câblage
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>


Schéma de connexion
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Code
-----------

.. note::

    * Vous pouvez ouvrir le fichier ``09-gy87_bmp180.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"Adafruit BMP085 Library"** et installez-la. 

.. literalinclude:: /_code/09_basic_gy87_bmp180.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_bmp180.ino


Analyse du code
------------------------

- ``initializeBMP180()``

  Initialiser le capteur BMP180.

  .. code-block:: arduino

     void initializeBMP180() {
       // Démarrer l'initialisation du BMP180
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Arrêt si le capteur n'est pas trouvé
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  Imprimer les valeurs lues par le capteur BMP180.

  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calculer l'altitude en supposant une pression barométrique 'standard'
       // de 1013,25 millibars = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


