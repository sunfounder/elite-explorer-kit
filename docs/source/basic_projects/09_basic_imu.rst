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


Installer la bibliothèque
---------------------------------

Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino.

   - Recherchez **"SunFounder_IMU"** et installez


      .. image:: img/09-add_lib_tip_imu.png



Calibrage
----------------------

Avant d'utiliser le module IMU, il est recommandé d'effectuer un calibrage pour garantir la précision des données du capteur. Voici les étapes de calibrage :

* Ouvrez le fichier ``09-imu_calibration.ino`` directement sous le chemin ``elite-explorer-kit-main\basic_project\09-imu_calibration``.

Après avoir exécuté ce code, ouvrez le moniteur série et vous verrez les données du capteur s'afficher. Elles se présentent généralement dans le format suivant :

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

Copiez ces données.

Exécuter le code
----------------------


Ouvrez le fichier ``09-imu.ino`` directement sous le chemin ``elite-explorer-kit-main\basic_project\09-imu``.

Accédez à la page ``calibration_data.h`` dans le projet, collez les données que vous venez de copier dans le fichier ``calibration_data.h``, en remplaçant les données d'origine.

.. image:: img/imu_cali_data.png
   :width: 80%

Revenez à la page ``09-imu.ino`` et téléversez le code sur votre carte Arduino Uno R4.

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

Après le téléversement réussi du code sur votre Arduino Uno R4, le moniteur série s'anime et affiche en continu les données des capteurs du module IMU 10 axes.

.. image:: img/imu_reading.png