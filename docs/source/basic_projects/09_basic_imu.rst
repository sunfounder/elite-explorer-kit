.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_imu:

Module IMU (10 axes)
==========================

.. note:: Différentes versions de ce kit peuvent utiliser différents modules IMU. Veuillez sélectionner le tutoriel approprié en fonction de la version de votre kit. Si vous possédez un module IMU 10 axes, veuillez vous référer à ce tutoriel. Si vous possédez un module GY-87, veuillez vous référer à :ref:`basic_gy87`.

Le module IMU 10 axes (Unité de Mesure Inertielle) combine plusieurs capteurs pour fournir des données complètes de mouvement et d'environnement. Il intègre un capteur de pression barométrique (SPL06_001) pour la mesure de l'altitude, un capteur de mouvement à 6 axes (SH3001) pour l'accélération et la rotation, ainsi qu'un magnétomètre à 3 axes (QMC6310) pour le cap du compas. Ce module sophistiqué est idéal pour la robotique, les systèmes de navigation et les applications de suivi de mouvement.





Circuit Fritzing
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


Calibrage
----------------------

Avant de lire les données du capteur, calibrez l'IMU pour que les mesures soient précises.

#. Installez la bibliothèque **SunFounder_IMU** : ouvrez le gestionnaire de bibliothèques Arduino, recherchez **"SunFounder_IMU"** et cliquez sur **INSTALL**. L'image ci-dessous montre l'entrée une fois installée.

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. Ouvrez le fichier ``09-imu_calibration.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\09-imu_calibration`` et téléversez-le sur votre carte.

#. Ouvrez le moniteur série et réglez la vitesse en bauds sur **115200** et la fin de ligne sur **Both NL & CR**.

#. Effectuez le calibrage six faces en suivant les instructions du moniteur série :

   * Envoyez un caractère quelconque pour démarrer. Le moniteur série affiche alors la première orientation.
   * Placez le module dans les six orientations dans l'ordre indiqué : Z vers le haut, Z vers le bas, X vers le haut, X vers le bas, Y vers le haut et Y vers le bas.
   * Gardez le module parfaitement immobile pendant chaque mesure, puis envoyez à nouveau un caractère pour mesurer l'orientation en cours et passer à la suivante.

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. Après la sixième orientation, le moniteur série affiche les constantes de calibrage. Copiez les six lignes :

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   Les valeurs ci-dessus ne sont qu'un exemple ; les vôtres appartiennent à votre module.

#. Ouvrez le projet ``09-imu`` et son onglet ``calibration_data.h``, puis remplacez les six tableaux par les valeurs copiées.

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. Téléversez ``09-imu.ino`` sur votre carte Arduino Uno R4. Le moniteur série affiche alors en continu les données de l'accéléromètre, du gyroscope, du magnétomètre et du baromètre.

   .. image:: img/imu_reading.png