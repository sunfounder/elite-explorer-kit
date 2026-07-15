.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

Vue d'ensemble
--------------------

Dans cette leçon, vous allez découvrir les écrans OLED utilisant le pilote SSD1306. Les écrans OLED (Organic Light-Emitting Diodes) sont largement utilisés dans divers appareils électroniques tels que les montres connectées, les téléphones mobiles et même les téléviseurs. Le SSD1306 est un pilote CMOS OLED/PLED à puce unique avec contrôleur pour un système d'affichage graphique à matrice de points à diodes électroluminescentes organiques/polymères. Il offre une sortie visuelle nette et claire grâce aux diodes à base de matériaux organiques qui émettent de la lumière lorsqu'un courant électrique les traverse.

Dans le code fourni, un écran OLED est interfacé avec une carte Arduino via le protocole I2C. Le code utilise la bibliothèque Adafruit SSD1306 pour contrôler l'affichage. Le programme couvre diverses fonctionnalités telles que :

1. Affichage de texte : "Hello world!" est affiché à l'écran.
2. Texte inversé : Le texte "Hello world!" est affiché dans un schéma de couleurs inversé.
3. Taille de police : Le texte "Hello!" est affiché avec une taille de police augmentée.
4. Affichage numérique : Les chiffres 123456789 sont affichés.
5. Caractères ASCII : Un ensemble de caractères ASCII est affiché.
6. Défilement : Le texte défile horizontalement sur l'écran.
7. Affichage de bitmap : Une image bitmap prédéfinie est affichée sur l'écran OLED.

Cet écran OLED peut être utilisé dans une multitude d'applications, y compris les horloges numériques, les mini consoles de jeux, les affichages d'informations, etc. Il offre un excellent moyen de fournir une interface utilisateur dans des appareils compacts et portables.


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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

Câblage
----------------------

.. image:: img/15-oled_bb.png
    :align: center

Schéma de câblage
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``15-oled.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\15-oled`` directement.
    * Ou copiez ce code dans Arduino IDE.

    .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"Adafruit SSD1306"** et **"Adafruit GFX"** et installez-les. 

.. literalinclude:: /_code/15_basic_oled.ino
   :language: cpp
   :linenos:
   :caption: 15-oled.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analyse du code
------------------------

1. **Inclusion des bibliothèques et définitions initiales** :
   Les bibliothèques nécessaires pour l'interfaçage avec l'OLED sont incluses. Ensuite, des définitions concernant les dimensions de l'OLED et l'adresse I2C sont fournies.

   - **Adafruit SSD1306** : Cette bibliothèque est conçue pour faciliter l'interfaçage avec l'affichage OLED SSD1306. Elle fournit des méthodes pour initialiser l'affichage, contrôler ses paramètres et afficher du contenu.
   - **Adafruit GFX Library** : Il s'agit d'une bibliothèque graphique de base pour afficher du texte, produire des couleurs, dessiner des formes, etc., sur divers écrans, y compris les OLED.

   .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"Adafruit SSD1306"** et **"Adafruit GFX"** et installez-les. 

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // Largeur de l'écran OLED en pixels
      #define SCREEN_HEIGHT 64  // Hauteur de l'écran OLED en pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Données bitmap** :
   Les données bitmap pour afficher une icône personnalisée sur l'écran OLED. Ces données représentent une image dans un format que l'OLED peut interpréter.

   Vous pouvez utiliser cet outil en ligne appelé |link_image2cpp| qui peut transformer votre image en un tableau.

   Le mot-clé ``PROGMEM`` indique que le tableau est stocké dans la mémoire programme du microcontrôleur Arduino. Stocker les données dans la mémoire programme (PROGMEM) au lieu de la RAM peut être utile pour de grandes quantités de données, qui prendraient autrement trop de place dans la RAM.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Fonction Setup (initialisation et affichage)** :
   La fonction ``setup()`` initialise l'OLED et affiche une série de motifs, de textes et d'animations.

   .. code-block:: arduino

      void setup() {
         ...  // Initialisation de la communication série et de l'objet OLED
         ...  // Affichage de divers textes, chiffres et animations
      }