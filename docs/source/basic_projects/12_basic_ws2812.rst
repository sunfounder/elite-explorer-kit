.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_ws2812:

Bande de LED RVB WS2812
=============================

Vue d'ensemble
---------------------

Dans cette leçon, vous allez découvrir les LED NeoPixel et comment les contrôler à l'aide de la bibliothèque FastLED sur un Arduino Uno R4. Les LED NeoPixel sont largement utilisées dans diverses applications telles que la décoration intérieure, les vêtements et l'éclairage événementiel. La bibliothèque FastLED simplifie le processus de programmation de ces LED. Ici, une chaîne de 8 LED NeoPixel est connectée à un Arduino, et chaque LED de la séquence s'allume en bleu momentanément avant de s'éteindre, passant à la LED suivante de la chaîne. Cet exemple de base peut servir de fondation pour des motifs lumineux plus complexes ou des projets d'éclairage interactifs.

Composants requis
---------------------------

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

Câblage
----------------------

.. image:: img/12-ws2812_bb.png
    :align: center

Schéma de câblage
-----------------------

.. image:: img/12_ws2812_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``12-ws2812.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\12-ws2812`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"FastLED"** et installez-la. 

.. important::
    Avec la sortie de la version |link_fastled_3_7_0|, la bibliothèque FastLED prend désormais officiellement en charge l'Arduino UNO R4. Vous n'avez donc plus besoin d'installer manuellement la version de développement. Mettez simplement à jour ou installez la bibliothèque FastLED en utilisant le gestionnaire de bibliothèques Arduino.

.. warning::
    **[Obsolète]** Comme la bibliothèque |link_FastLED_lib| n'a pas encore publié officiellement une version supportant l'Arduino R4, vous devrez télécharger :download:`la dernière version de développement de la bibliothèque FastLED <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` et remplacer les fichiers existants de la bibliothèque FastLED. Pour des instructions détaillées sur la façon de faire cela, veuillez vous référer à la section :ref:`manual_install_lib`. (Cette note sera retirée lorsque la bibliothèque FastLED publiera officiellement une mise à jour prenant en charge l'Arduino UNO R4.)




.. literalinclude:: /_code/12_basic_ws2812.ino
   :language: cpp
   :linenos:
   :caption: 12-ws2812.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/12_basic_ws2812.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Une fois le code téléversé avec succès, vous verrez chaque LED de la chaîne de 8 LED NeoPixel s'allumer une par une en bleu. Le programme bouclera cette séquence continuellement, éteignant chaque LED avant de passer à la suivante. Avec un court délai entre chaque LED, l'effet lumineux apparaîtra comme un point bleu se déplaçant le long de la chaîne.

Analyse du code
------------------------

1. Importer la bibliothèque et définir les constantes

   - Importation de la bibliothèque ``FastLED`` pour utiliser ses fonctions.
   - Définition du nombre de LEDs et de la broche de données à laquelle elles sont connectées.
   
   .. code-block:: arduino
   
      #include <FastLED.h>  // Inclure la bibliothèque FastLED
      #define NUM_LEDS 8    // Nombre de LEDs dans la chaîne
      #define DATA_PIN 6    // Broche de données pour le contrôle des LEDs

2. Initialiser le tableau de LEDs
   
   Création d'un tableau de type ``CRGB`` pour stocker les informations de couleur de chaque LED.

   .. code-block:: arduino

      CRGB leds[NUM_LEDS];  // Tableau pour stocker les données de couleur des LEDs

3. Initialiser les LEDs dans la fonction Setup

   Utilisation de ``FastLED.addLeds`` pour initialiser les LEDs.

   .. code-block:: arduino

      void setup() {
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Initialiser les LEDs
      }

4. Contrôler les LEDs dans la boucle Loop
   
   Boucler à travers chaque LED pour la définir en bleu, l'afficher, la réinitialiser, puis attendre un court délai.

   - Le tableau ``leds`` sert de tampon de couleur pour votre bande LED. Chaque élément de ce tableau correspond à une LED individuelle sur votre bande physique, et sa valeur de couleur détermine la couleur que la LED affichera. L'ordre des éléments dans le tableau correspond à l'ordre des LEDs sur la bande, en commençant par la première LED (qui correspond à ``leds[0]``) jusqu'à la dernière LED. Pour changer la couleur d'une LED spécifique sur votre bande, il suffit de modifier l'élément correspondant dans le tableau ``leds``. Vous pouvez utiliser |fastled_color| ou définir les couleurs en utilisant les valeurs RVB (en prenant le vert comme exemple, utilisez ``leds[dot] = CRGB::Green`` ou ``leds[dot] = CRGB(0, 255, 0);``).

   - La fonction ``FastLED.show();`` met à jour la bande LED avec les nouvelles données de couleur, rendant les changements visibles. C'est comme appuyer sur le bouton "publier" pour votre bande LED après avoir fait des modifications et des ajustements dans le code.

   .. raw:: html

     <br/>

   .. code-block:: arduino

      void loop() {
        for (int dot = 0; dot < NUM_LEDS; dot++) {
          leds[dot] = CRGB::Blue;   // Définir la LED actuelle en bleu
          FastLED.show();           // Mettre à jour les LEDs
          leds[dot] = CRGB::Black;  // Réinitialiser la LED actuelle
          delay(30);                // Attendre un court instant avant de passer à la LED suivante
        }
      }