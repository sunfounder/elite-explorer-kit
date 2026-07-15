.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Module IMU GY-87
==========================

Le module GY-87 est équipé de trois puces de capteur : MPU6050, QMC5883L et BMP180, chacune offrant des capacités uniques. Le MPU6050 combine un gyroscope et un accéléromètre pour le suivi des mouvements, le QMC5883L sert de magnétomètre pour la détection directionnelle et le BMP180 est utilisé pour mesurer la pression barométrique et la température. Ces capteurs peuvent être interfacés en utilisant le protocole I2C pour une communication efficace avec un Arduino.

Ces capteurs sont conçus pour une intégration transparente via le protocole I2C, assurant une communication efficace avec des plateformes comme Arduino. Chaque capteur du module GY-87 est accessible par des adresses I2C uniques : le MPU6050 à l'adresse 0x68, le QMC5883L à l'adresse 0x0D et le BMP180 à l'adresse 0x77.


Tutoriels individuels pour chaque puce de capteur :

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l


.. raw:: html

   <br/>

.. **Code pour le module GY-87**

Si vous souhaitez utiliser ces trois puces simultanément, voici un exemple simple :


.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


.. note::

    * Vous pouvez ouvrir le fichier ``09-gy87.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\09-gy87`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino. 
    
        - Recherchez **"Adafruit MPU6050"** et installez

          Lors de l'installation de chaque bibliothèque, veuillez vous assurer de sélectionner l'installation de toutes les dépendances.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Recherchez **"Adafruit Unified Sensor"** et installez
        - Recherchez **"QMC5883LCompass"** et installez
        - Recherchez **"Adafruit BMP085 Library"** et installez

.. literalinclude:: /_code/09_basic_gy87.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87.ino

.. note::
   Les magnétomètres doivent être calibrés (:ref:`basic_gy87_calibrate`) avant de pouvoir être utilisés comme compas, et doivent être tenus à niveau lors de l'utilisation et **éloignés des objets en fer, des matériaux magnétisés et des fils porteurs de courant**.


Après que le code a été téléversé avec succès sur votre Arduino Uno R4, le moniteur série affichera continuellement les données des capteurs du module IMU GY-87. Ce module intègre trois capteurs individuels : le MPU6050 pour les lectures de l'accéléromètre et du gyroscope, le QMC5883L pour les lectures du magnétomètre et le BMP180 pour les lectures de la pression barométrique et de la température.
