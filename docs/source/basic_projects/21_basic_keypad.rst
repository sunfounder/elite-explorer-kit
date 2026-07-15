.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_keypad:

Clavier
==========================

.. https://docs.sunfounder.com/projects/vincent-kit-de/en/latest/arduino/2.19_keypad.html#ar-keypad

Vue d'ensemble
-------------------

Dans cette leçon, vous apprendrez à utiliser un clavier. Le clavier peut être intégré dans divers types d'appareils, notamment les téléphones mobiles, les télécopieurs, les fours à micro-ondes, etc. Il est couramment utilisé pour l'entrée utilisateur.

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
    *   - :ref:`cpn_keypad`
        - |link_keypad_buy|

Câblage
----------------------

.. image:: img/21-keypad_bb.png
    :align: center

Schéma de câblage
----------------------

.. image:: img/21_keypad_schematic.png
   :align: center
   :width: 70%

Code
-----------


.. note::

    * Vous pouvez ouvrir le fichier ``21-keypad.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\21-keypad`` directement.
    * Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"Adafruit Keypad"** et installez-la. 

.. literalinclude:: /_code/21_basic_keypad.ino
   :language: cpp
   :linenos:
   :caption: 21-keypad.ino

Après avoir téléversé le code sur la carte UNO, vous pourrez voir sur le moniteur série la valeur de la touche actuellement pressée sur le clavier.

Analyse du Code
-------------------

1. Inclusion de la bibliothèque

   Nous commençons par inclure la bibliothèque ``Adafruit_Keypad``, qui nous permet d'interagir facilement avec le clavier.

   .. code-block:: arduino

     #include "Adafruit_Keypad.h"

   .. note::

      * Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"Adafruit Keypad"** et installez-la. 


2. Configuration du clavier

   .. code-block:: arduino

     const byte ROWS = 4;
     const byte COLS = 4;
     char keys[ROWS][COLS] = {
       { '1', '2', '3', 'A' },
       { '4', '5', '6', 'B' },
       { '7', '8', '9', 'C' },
       { '*', '0', '#', 'D' }
     };
     byte rowPins[ROWS] = { 2, 3, 4, 5 };
     byte colPins[COLS] = { 8, 9, 10, 11 };

   - Les constantes ``ROWS`` et ``COLS`` définissent les dimensions du clavier. 
   - ``keys`` est un tableau 2D stockant l'étiquette de chaque bouton du clavier.
   - ``rowPins`` et ``colPins`` sont des tableaux qui stockent les broches Arduino connectées aux rangées et colonnes du clavier.

   .. raw:: html

      <br/>


3. Initialisation du clavier

   Créez une instance de ``Adafruit_Keypad`` appelée ``myKeypad`` et initialisez-la.

   .. code-block:: arduino

     Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

4. Fonction setup()

   Initialisez la communication série et le clavier personnalisé.

   .. code-block:: arduino

     void setup() {
       Serial.begin(9600);
       myKeypad.begin();
     }

5. Boucle principale

   Vérifiez les événements de touche et affichez-les dans le moniteur série.

   .. code-block:: arduino

     void loop() {
       myKeypad.tick();
       while (myKeypad.available()) {
         keypadEvent e = myKeypad.read();
         Serial.print((char)e.bit.KEY);
         if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
         else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
       }
       delay(10);
     }

