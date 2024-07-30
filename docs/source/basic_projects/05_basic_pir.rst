.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_pir:

Module Capteur de Mouvement PIR
======================================

.. https://docs.sunfounder.com/projects/kepler-kit/en/latest/cproject/ar_pir.html#ar-pir


Aperçu
---------------

Dans cette leçon, vous allez découvrir le module capteur de mouvement PIR. Le capteur de mouvement infrarouge passif (PIR) est un capteur qui détecte les mouvements. Il est couramment utilisé dans les systèmes de sécurité et les systèmes d'éclairage automatique. Le capteur possède deux fentes qui détectent le rayonnement infrarouge. Lorsqu'un objet, tel qu'une personne, passe devant le capteur, il détecte une variation de la quantité de rayonnement infrarouge et déclenche un signal de sortie.


Composants nécessaires
----------------------------

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

Câblage
----------------------

.. image:: img/05-pir_bb.png
   :align: center
   :width: 100%


Schéma
-----------------------

.. image:: img/05-pir_schematic.png
   :align: center
   :width: 50%


Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``05-pir_motion_sensor.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\05-pir_motion_sensor`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9fc9198-1538-413d-b501-2cddc8d7cfe6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code sur la carte Arduino Uno, vous pouvez ouvrir le moniteur série pour observer la sortie du capteur. Lorsque le capteur de mouvement PIR (infrarouge passif) détecte un mouvement, le moniteur série affiche le message "Somebody here!" pour indiquer qu'un mouvement a été détecté. Si aucun mouvement n'est détecté, le message "Monitoring..." sera affiché à la place.

Le capteur PIR fournit un signal numérique HIGH ou LOW, correspondant respectivement à un mouvement détecté ou non détecté. Contrairement à un capteur analogique qui fournit une plage de valeurs, la sortie numérique de ce capteur PIR sera soit HIGH (généralement représenté par '1'), soit LOW (généralement représenté par '0').

Notez que la sensibilité réelle et la portée de détection peuvent varier en fonction des caractéristiques du capteur PIR et des conditions environnementales. Il est donc conseillé de calibrer le capteur en fonction de vos besoins spécifiques.
