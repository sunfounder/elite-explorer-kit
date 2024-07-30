.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_i2c_lcd1602:

LCD1602 I2C
===========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

Vue d'ensemble
-------------------

Dans cette leçon, vous allez découvrir les écrans à cristaux liquides (LCD) avec une interface I2C. Ces types de LCD sont largement utilisés dans une variété de dispositifs électroniques, tels que les horloges numériques, les fours à micro-ondes, les tableaux de bord de voiture et même les équipements industriels. L'interface I2C simplifie le câblage et les connexions, les rendant plus pratiques et efficaces pour les amateurs et les professionnels.

Composants requis
------------------------------

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Câblage
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

Schéma de câblage
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%
Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``14-i2c_lcd.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\14-i2c_lcd`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"LiquidCrystal I2C"** et installez-la. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/096326ad-eccf-4d2e-be52-66f4819ca7d8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Après avoir téléversé le code sur l'Arduino, l'écran à cristaux liquides (LCD) affichera le message "Hello world!" sur sa première ligne et "LCD Tutorial" sur sa deuxième ligne.

.. note::
    Si le LCD n'affiche aucun caractère après avoir téléversé le code, vous pouvez ajuster le contraste en tournant le potentiomètre sur le module I2C jusqu'à ce que le LCD fonctionne correctement.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd_2.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analyse du code
------------------------

1. Inclusion de la bibliothèque et initialisation du LCD :
   La bibliothèque LiquidCrystal I2C est incluse pour fournir des fonctions et des méthodes pour l'interfaçage LCD. Ensuite, un objet LCD est créé en utilisant la classe LiquidCrystal_I2C, spécifiant l'adresse I2C, le nombre de colonnes et le nombre de lignes.

   .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"LiquidCrystal I2C"** et installez-la.  

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Fonction Setup :
   La fonction ``setup()`` est exécutée une fois lorsque l'Arduino démarre. Dans cette fonction, le LCD est initialisé, effacé et le rétroéclairage est activé. Ensuite, deux messages sont affichés sur le LCD.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // initialiser le LCD
        lcd.clear();      // effacer l'affichage du LCD
        lcd.backlight();  // s'assurer que le rétroéclairage est activé
      
        // Imprimer un message sur les deux lignes du LCD.
        lcd.setCursor(2, 0);  // Placer le curseur au caractère 2 sur la ligne 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  // Déplacer le curseur au caractère 2 sur la ligne 1
        lcd.print("LCD Tutorial");
      }