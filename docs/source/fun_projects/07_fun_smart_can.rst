.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_smart_can:

Poubelle intelligente
==============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Ce code Arduino est conçu pour contrôler une poubelle intelligente.
Lorsqu'un objet se trouve à moins de 20 centimètres devant la poubelle, son couvercle s'ouvre automatiquement.
Ce projet utilise un servomoteur SG90 et un capteur de distance à ultrasons HC-SR04.

**Composants nécessaires**

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Câblage**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**Schéma**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``07_smart_trash_can.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\07_smart_trash_can`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. literalinclude:: /_code/07_fun_smart_can.ino
   :language: cpp
   :linenos:
   :caption: 07_smart_trash_can.ino



**Comment ça marche ?**

Voici une explication étape par étape du code :

1. Importation des bibliothèques et définition des constantes/variables :

   La bibliothèque ``Servo.h`` est importée pour contrôler le servomoteur SG90.
   Les paramètres du servomoteur, du capteur à ultrasons et les autres constantes et variables nécessaires sont définis.

2. ``setup()`` :

   Initialise la communication série avec l'ordinateur à un débit de 9600 bauds.
   Configure les broches trigger et echo du capteur à ultrasons.
   Attache le servomoteur à sa broche de contrôle et définit sa position initiale à l'angle fermé. Après avoir réglé l'angle, le servomoteur est détaché pour économiser de l'énergie.

3. ``loop()`` :

   Mesure la distance trois fois et stocke les valeurs de chaque mesure.
   Calcule la distance moyenne à partir des trois mesures.
   Si la distance moyenne est inférieure ou égale à 20 centimètres (seuil de distance défini), le servomoteur tourne jusqu'à l'angle d'ouverture (0 degré).
   Sinon, le servomoteur revient à la position fermée (90 degrés) après un délai d'une seconde. Le servomoteur est détaché lorsqu'il n'est pas utilisé afin d'économiser de l'énergie.

4. ``readDistance()`` :

   Envoie une impulsion à la broche trigger du capteur à ultrasons.
   Mesure la largeur d'impulsion de la broche echo et calcule la valeur de la distance.
   Ce calcul utilise la vitesse du son dans l'air pour calculer la distance en fonction du temps d'impulsion.