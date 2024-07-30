.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_gy87_qmc5883l:

QMC5883L
==========================

Vue d'ensemble
---------------

Dans ce tutoriel, nous allons explorer le module IMU GY-87, en nous concentrant sur son magnétomètre QMC5883L. La première partie du tutoriel vous guide à travers la calibration du magnétomètre QMC5883L, essentielle pour des mesures précises du champ magnétique. Vous apprendrez à téléverser un sketch de calibration sur Arduino, à effectuer une calibration en temps réel et à appliquer ces paramètres dans vos projets. La deuxième partie du tutoriel couvre l'initialisation du MPU6050 (accéléromètre et gyroscope) et du QMC5883L sur un Arduino Uno en utilisant les bibliothèques Adafruit MPU6050 et QMC5883LCompass. Vous apprendrez à lire et afficher les données des capteurs sur le moniteur série, une compétence fondamentale pour les applications de navigation, de suivi de mouvement et de détection d'orientation.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-

Câblage
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 90%

.. raw:: html

   <br/>


Schéma de câblage
-----------------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%


Installer la bibliothèque
-------------------------------

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino. 
    
        - Recherchez **"Adafruit MPU6050"** et installez

          Lors de l'installation de chaque bibliothèque, veuillez vous assurer de sélectionner l'installation de toutes les dépendances.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Recherchez **"QMC5883LCompass"** et installez


.. _basic_gy87_calibrate:

Calibrer le QMC5883L
-------------------------

.. note::

    * Vous pouvez ouvrir le fichier ``09-gy87_compass_calibration.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\09-gy87_compass_calibration`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/252c7a58-3a9f-4c66-959e-f45fc19e68aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code, ouvrez le moniteur série. Suivez les instructions dans le moniteur série pour calibrer le QMC5883L. Lorsqu'il vous est demandé de déplacer le capteur, il est recommandé d'utiliser la méthode de calibration en huit. Alternativement, gardez simplement le capteur parallèle au sol et tournez-le dans le sens horaire ou antihoraire jusqu'à ce que le moniteur série indique que la calibration est terminée.

.. image:: img/09_calibrate_qmc5883l.png
    :width: 100%
    :align: center

Une fois que toutes les données de calibration ont été collectées, le sketch vous fournira un code qui ressemblera à ``compass.setCalibrationOffsets(-375.00, -179.00, 85.00);`` et ``compass.setCalibrationScales(1.04, 0.96, 1.01);``. Copiez ce code. Vous voudrez peut-être le sauvegarder pour référence future.

Utilisation du QMC5883L : Ouvrez le sketch de votre projet et collez la ligne de code que vous avez copiée juste en dessous de l'appel ``compass.init()``. Comme ceci :

.. code:: arduino 

   void initializeQMC5883L() {
   
     compass.init();
   
     // Vous devriez remplacer le code ci-dessous selon vos résultats de calibration
     compass.setCalibrationOffsets(-375.00, -179.00, 85.00);
     compass.setCalibrationScales(1.04, 0.96, 1.01);
   
   }

Code
---------------------------------------------

.. note::

   Les magnétomètres doivent être calibrés (:ref:`basic_gy87_calibrate`) avant de pouvoir être utilisés comme compas, et doivent être tenus à niveau lors de l'utilisation et **éloignés des objets en fer, des matériaux magnétisés et des fils porteurs de courant**.

.. note::

    * Vous pouvez ouvrir le fichier ``09-gy87_qmc5883l.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\09-gy87_qmc5883l`` directement.
    * Ou copiez ce code dans l'IDE Arduino.
    * Placez le code obtenu à partir des étapes de calibration sous la ligne de code ``compass.init()`` dans la fonction ``initializeQMC5883L()``.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b266a18-ce7b-4330-8c10-c9f4148bb8ec/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Analyse du code
------------------------

#. Inclusion des bibliothèques et initialisation des capteurs
   Cette section inclut les bibliothèques nécessaires pour les capteurs MPU6050 et QMC5883L et initialise leurs objets.

   .. code-block:: arduino
      
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>

      Adafruit_MPU6050 mpu;
      QMC5883LCompass compass;

#. Fonction de configuration

   Initialise la communication série, le capteur MPU6050, et configure le MPU6050 en mode bypass I2C pour permettre l'accès direct au magnétomètre QMC5883L. Ensuite, il initialise le magnétomètre QMC5883L.

   .. code-block:: arduino
      
      void setup() {
        // Initialise la communication série avec un débit de 9600 bauds
        Serial.begin(9600);
      
        // Initialise le capteur MPU6050 (accéléromètre et gyroscope)
        initializeMPU6050();
      
        // Active le bypass I2C sur le MPU6050 pour accéder directement au magnétomètre QMC5883L
        mpu.setI2CBypass(true);
      
        // Initialise le magnétomètre QMC5883L
        initializeQMC5883L();
      }

#. Fonction boucle

   Lit continuellement les données du magnétomètre QMC5883L et les affiche sur le moniteur série.

   .. code-block:: arduino
      
      void loop() {
        printQMC5883L();
        delay(500);
      }

#. Fonction d'initialisation du QMC5883L

   Initialise et calibre le magnétomètre QMC5883L. Les valeurs de calibration doivent être ajustées en fonction des données de calibration spécifiques. (:ref:`basic_gy87_calibrate`)

   .. code-block:: arduino
      
      void initializeQMC5883L() {
        compass.init();
      
        // Vous devriez remplacer le code ci-dessous selon vos résultats de calibration
        compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
        compass.setCalibrationScales(0.97, 1.02, 1.02);
      }

#. Fonction d'impression des données du QMC5883L

   Cette fonction lit les valeurs X, Y, Z et l'azimut du magnétomètre, puis les affiche sur le moniteur série.

   .. code-block:: arduino

    void printQMC5883L() {
    
      Serial.println();
      Serial.println("QMC5883L ------------");
    
    	int x, y, z, a;
    	char myArray[3];
    	
    	compass.read();
      
    	x = compass.getX();
    	y = compass.getY();
    	z = compass.getZ();
    	
    	a = compass.getAzimuth();
    
    	compass.getDirection(myArray, a);
      
    	Serial.print("X: ");
    	Serial.print(x);
    
    	Serial.print(" Y: ");
    	Serial.print(y);
    
    	Serial.print(" Z: ");
    	Serial.print(z);
    
    	Serial.print(" Azimuth: ");
    	Serial.print(a);
    
    	Serial.print(" Direction: ");
    	Serial.print(myArray[0]);
    	Serial.print(myArray[1]);
    	Serial.println(myArray[2]);
    
      Serial.println("QMC5883L ------------");
      Serial.println();
    }
