.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_audio_speaker:

Module Audio et Haut-parleur
===================================

Vue d'ensemble
----------------------
Dans cette leçon, vous allez découvrir le module audio et le haut-parleur utilisés avec une carte Arduino Uno. Ces composants sont largement utilisés dans diverses applications électroniques, y compris les jouets musicaux, les systèmes audio DIY, les alarmes et même les instruments de musique sophistiqués. En combinant un Arduino avec un module audio et un haut-parleur, vous pouvez créer un lecteur de mélodies simple mais efficace.


Composants requis
-----------------------------

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
    *   - :ref:`cpn_audio_speaker`
        - \-


Câblage
----------------------

Étant donné qu'il s'agit d'un amplificateur mono, vous pouvez connecter la broche 8 à la broche L ou R du module amplificateur audio.

La résistance de 10K est utilisée pour réduire le bruit haute fréquence et diminuer le volume audio. Elle forme un filtre passe-bas RC avec la capacité parasite du DAC et de l'amplificateur audio. Ce filtre diminue l'amplitude des signaux haute fréquence, réduisant efficacement le bruit haute fréquence. Ainsi, l'ajout de la résistance de 10K adoucit la musique et élimine les bruits haute fréquence indésirables.

.. image:: img/17-audio_bb.png
    :align: center
    :width: 100%

Schéma de câblage
-----------------------

.. image:: img/17-audio_schematic.png
    :align: center
    :width: 80%


Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``17-speaker.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\17-speaker`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33b690b5-0be6-434d-83d7-5bfcfce3775e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Lorsque vous avez terminé de téléverser le code sur la carte R4, vous pouvez entendre une mélodie contenant sept notes.

Analyse du code
------------------------

1. Inclusion de la bibliothèque pitches:
   Cette bibliothèque fournit les valeurs de fréquence pour diverses notes de musique, vous permettant d'utiliser la notation musicale dans votre code.

   .. note::
      Veuillez placer le fichier ``pitches.h`` dans le même répertoire que le code pour assurer son bon fonctionnement. |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. Définition des constantes et des tableaux :

   * ``speakerPin`` est la broche numérique sur l'Arduino où le haut-parleur est connecté.

   * ``melody[]`` est un tableau qui stocke la séquence des notes à jouer.

   * ``noteDurations[]`` est un tableau qui stocke la durée de chaque note de la mélodie.

   .. code-block:: arduino
   
      const int speakerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Jouer la mélodie :

   * La boucle ``for`` itère sur chaque note de la mélodie.

   * La fonction ``tone()`` joue une note sur le haut-parleur pour une durée spécifique.

   * Un délai est ajouté entre les notes pour les distinguer.

   * La fonction ``noTone()`` arrête le son.

   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speakerPin);
        }
      }

4. Fonction loop vide :
   Comme la mélodie est jouée une seule fois dans le setup, il n'y a pas de code dans la fonction loop.

5. N'hésitez pas à expérimenter en modifiant les notes et les durées dans les tableaux ``melody[]`` et ``noteDurations[]`` pour créer vos propres mélodies. Si cela vous intéresse, il existe un dépôt GitHub (|link_arduino-songs|) qui propose du code Arduino pour jouer diverses chansons. Bien que leur approche puisse différer de ce projet, vous pouvez consulter leurs notes et durées à titre de référence.
