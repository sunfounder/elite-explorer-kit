.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions de fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_irrecv:

Récepteur Infrarouge
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/infrared_Receiver_uno.html#receive-uno

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/infrared_Receiver_uno.html#receive-uno


Aperçu
------------------

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut indépendamment recevoir des rayons infrarouges et produire des signaux compatibles avec le niveau TTL. Il est de taille similaire à un transistor encapsulé dans du plastique et convient à tous les types de télécommandes infrarouges et de transmissions infrarouges.

Composants nécessaires
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

Vous pouvez également les acheter séparément via les liens ci-dessous.

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
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|


Câblage
----------------------

.. image:: img/22-ir_receiver_bb.png
    :align: center
    :width: 80%


Schéma de câblage
---------------------

.. image:: img/22_irrecv_schematic.png
    :align: center
    :width: 50%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``22-ir_receiver.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\22-ir_receiver`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/92e1cb75-cda1-4fc7-9680-28e28df8dccc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Gestionnaire de Bibliothèques**.

    .. image:: img/22_irrecv_lib.png
        :align: center

.. note::

    * Il y a une pièce en plastique transparent à l'arrière de la télécommande pour couper l'alimentation, retirez-la avant d'utiliser la télécommande.

Analyse du code
---------------------

Ce code est conçu pour fonctionner avec une télécommande infrarouge (IR) en utilisant la bibliothèque ``IRremote``. Voici le détail :

#. Inclusion de la bibliothèque et définition des constantes. Tout d'abord, la bibliothèque IRremote est incluse et le numéro de broche pour le récepteur IR est défini comme étant 2.

   .. code-block:: cpp
 
     #include <IRremote.h>
     const int IR_RECEIVE_PIN = 2;

#. Initialisation de la communication série à un débit de 9600 bauds. Initialisation du récepteur IR sur la broche spécifiée (``IR_RECEIVE_PIN``) et activation du retour d'information LED (si applicable).

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);                                     // Démarrer la communication série à 9600 bauds
           IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Démarrer le récepteur IR
       }

#. La boucle s'exécute en continu pour traiter les signaux entrants de la télécommande IR.

   .. code-block:: arduino

      void loop() {
        // Vérifie s'il y a un signal IR entrant
        if (IrReceiver.decode()) {
          // IrReceiver.printIRResultShort(&Serial);                 // Imprimer les données reçues en une ligne
          // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Imprimer la commande en format hexadécimal
          Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Mapper et imprimer le signal IR décodé à la valeur de la touche correspondante
      
          IrReceiver.resume();  // Activer la réception de la prochaine valeur
        }
      }

   * Vérifie si un signal IR est reçu et décodé avec succès.
   * Décode la commande IR et la stocke dans ``decodedValue`` en utilisant une fonction personnalisée ``decodeKeyValue()``.
   * Imprime la valeur IR décodée sur le moniteur série.
   * Reprend la réception des signaux IR pour le signal suivant.

   .. raw:: html

        <br/>

#. Fonction auxiliaire pour mapper les signaux IR reçus aux touches correspondantes

   .. image:: img/22_irrecv_key.png
      :align: center
      :width: 80%

   .. code-block:: arduino

      // Fonction pour mapper les signaux IR reçus aux touches correspondantes
      String decodeKeyValue(long result) {
        // Chaque case correspond à une commande IR spécifique
        switch (result) {
          case 0x16:
            return "0";
          case 0xC:
            return "1";
          case 0x18:
            return "2";
          case 0x5E:
            return "3";
          case 0x8:
            return "4";
          case 0x1C:
            return "5";
          case 0x5A:
            return "6";
          case 0x42:
            return "7";
          case 0x52:
            return "8";
          case 0x4A:
            return "9";
          case 0x9:
            return "+";
          case 0x15:
            return "-";
          case 0x7:
            return "EQ";
          case 0xD:
            return "U/SD";
          case 0x19:
            return "CYCLE";
          case 0x44:
            return "PLAY/PAUSE";
          case 0x43:
            return "FORWARD";
          case 0x40:
            return "BACKWARD";
          case 0x45:
            return "POWER";
          case 0x47:
            return "MUTE";
          case 0x46:
            return "MODE";
          case 0x0:
            return "ERROR";
          default:
            return "ERROR";
        }
      }