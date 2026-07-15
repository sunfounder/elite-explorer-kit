.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions spéciales pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_stepper_motor:

Moteur Pas à Pas
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/stepper_motor_uno.html#stepper-uno

Aperçu
---------------

Dans cette leçon, vous apprendrez à contrôler les moteurs pas à pas, en particulier le modèle 28BYJ-48, en utilisant un pilote ULN2003 et un Arduino Uno R4. Les moteurs pas à pas sont utilisés dans une variété d'applications telles que les imprimantes 3D, les machines CNC, la robotique et même dans les appareils électroménagers courants. Leur contrôle précis permet des mouvements complexes, ce qui les rend idéaux pour des projets nécessitant une haute précision de positionnement.

Dans ce projet, nous allons configurer le moteur pas à pas 28BYJ-48 pour tourner dans les directions horaire et antihoraire à différentes vitesses. Les moteurs pas à pas comme celui-ci sont souvent utilisés dans les systèmes automatisés pour faire tourner des objets ou entraîner des mécanismes nécessitant un contrôle précis. Par exemple, ils peuvent être utilisés dans des rideaux automatiques, où les rideaux s'ouvrent ou se ferment à des moments spécifiques ou sous des conditions spécifiques. En comprenant comment contrôler la rotation et la vitesse d'un moteur pas à pas, vous serez bien préparé à les intégrer dans vos propres projets électroniques.

Composants nécessaires
-------------------------

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_power`
        - \-


Câblage
----------------------

.. warning::
    En raison de la haute consommation d'énergie du moteur pas à pas, il est conseillé d'utiliser une alimentation externe de 5V au lieu de se fier à l'Arduino.

    Bien qu'il soit possible d'alimenter le moteur pas à pas directement à partir de l'Arduino, cela n'est pas recommandé car cela peut provoquer des interférences électriques sur ses lignes d'alimentation, pouvant potentiellement endommager l'Arduino.

.. note::
    Pour protéger le Power Pack du :ref:`cpn_power`, veuillez le charger complètement avant de l'utiliser pour la première fois.

.. image:: img/26-stepper_motor_bb.png
    :align: center


Schéma de câblage
-----------------------

.. image:: img/26_stepper_motor_schematic.png
   :align: center
   :width: 80%


Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``26-stepper_motor.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\26-stepper_motor.rst`` directement.
    * Ou copier ce code dans l'IDE Arduino.

.. literalinclude:: /_code/26_basic_stepper_motor.ino
   :language: cpp
   :linenos:
   :caption: 26-stepper_motor.ino

Après avoir téléversé le code sur la carte Arduino Uno, le moteur pas à pas 28BYJ-48 commencera à tourner, entraîné par le pilote ULN2003. Initialement, le moteur tournera dans le sens horaire à une vitesse de 5 RPM (tours par minute) pour une révolution complète. Après avoir terminé la rotation horaire, le moteur s'arrêtera pendant 1 seconde.

Ensuite, le moteur tournera dans le sens antihoraire à une vitesse augmentée de 15 RPM pour une autre révolution complète. Encore une fois, le moteur s'arrêtera pendant 1 seconde après la rotation antihoraire. Le cycle de rotation et de pause continuera indéfiniment tant que l'Arduino restera alimenté.


Analyse du code
-----------------

1. **Initialisation du moteur pas à pas**

   .. code-block:: arduino
   
       #include <Stepper.h>  // Inclure la bibliothèque Stepper

       #define STEPS 2038                   // Définir le nombre de pas par révolution pour le moteur
       Stepper stepper(STEPS, 2, 3, 4, 5);  // Initialiser l'objet stepper et définir les connexions de broches (IN1, IN3, IN2, IN4)

   Inclure un fichier d'en-tête ``Stepper.h``, définir les pas à 2038 et initialiser ensuite le stepper avec une fonction stepper().

   ``STEPS``: Le nombre de pas dans une révolution de votre moteur. Pour ce moteur pas à pas, cette valeur est de 2038.

   ``Stepper(steps, pin1, pin2, pin3, pin4)``: Cette fonction crée une nouvelle instance de la classe Stepper qui représente un moteur pas à pas particulier connecté à votre carte Arduino. Les broches pin1, pin2, pin3 et pin4 correspondent aux broches IN1, IN3, IN2 et IN4 sur le pilote ULN2003.
   

2. **Fonction loop()**

   .. code-block:: arduino
   
      void loop() {
        // Tourner dans le sens horaire à 5 RPM
        stepper.setSpeed(5);
        stepper.step(STEPS);  // Tourner d'une révolution complète dans le sens horaire
        delay(1000);          // Attendre 1 seconde
      
        // Tourner dans le sens antihoraire à 15 RPM
        stepper.setSpeed(15);
        stepper.step(-STEPS);  // Tourner d'une révolution complète dans le sens antihoraire
        delay(1000);           // Attendre 1 seconde
      }
   
   Le programme principal fait tourner le moteur pas à pas continuellement, complétant un cercle complet dans le sens horaire à 5 RPM puis un cercle complet dans le sens antihoraire à 15 RPM.


   - ``setSpeed(rpms)``: Définit la vitesse du moteur en rotations par minute (RPM). Cette fonction ne fait pas tourner le moteur, elle définit simplement la vitesse à laquelle il tournera lorsque vous appellerez step().

     - ``rpms``: la vitesse à laquelle le moteur doit tourner en rotations par minute - un nombre positif (long)
   
   .. raw::html

        <br/>

   
   - ``step(steps)``: Cette fonction fait tourner le moteur d'un nombre de pas spécifié, en utilisant la vitesse définie dans le dernier appel à setSpeed(). Il est important de noter que cette fonction fonctionne de manière bloquante, ce qui signifie qu'elle attendra que le moteur ait terminé son mouvement avant de permettre au contrôle de passer à la ligne suivante de votre croquis. 
   
     Par exemple, si vous définissez la vitesse à 1 RPM et appelez step(2038) sur un moteur avec 2038 pas, il faudra une minute entière pour que cette fonction s'exécute. Pour obtenir un contrôle plus précis, il est recommandé de maintenir une vitesse plus élevée et de ne déplacer que quelques pas à chaque appel à step().
   
     - ``steps``: le nombre de pas pour faire tourner le moteur - positif pour tourner dans un sens, négatif pour tourner dans l'autre (int).
