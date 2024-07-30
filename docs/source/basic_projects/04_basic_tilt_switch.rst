.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_tilt_switch:

Interrupteur à bascule
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.17_tilt_switch.html#ar-tilt

Aperçu
---------------

Dans cette leçon, vous allez découvrir l'interrupteur à bascule. L'interrupteur à bascule peut être utilisé pour détecter si des objets sont inclinés, ce qui est d'une grande utilité dans les applications pratiques. Il peut être utilisé pour juger de l'inclinaison des ponts, des bâtiments, des tours de lignes de transmission, etc., ce qui a une fonction de guidage importante dans la réalisation des travaux de maintenance.

Composants nécessaires
-------------------------

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_tilt_switch`
        - \-

Circuit Fritzing
---------------------

Dans cet exemple, la broche numérique 2 est utilisée pour lire le signal de l'interrupteur à bascule.

.. image:: img/04-tilt_switch_bb.png
   :align: center
   :width: 85%

Schéma
-----------------------

.. image:: img/04_tilt_switch_schematic.png
   :align: center
   :width: 70%


Code
----------

.. note::

    * Vous pouvez ouvrir le fichier ``04-tilt_switch.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\04-tilt_switch`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d85d75d9-e491-424c-93be-95e1f4e99549/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois les codes téléversés sur la carte uno r4, vous pouvez ouvrir le moniteur série pour voir les lectures des broches. Les lectures afficheront soit "1" soit "0" selon que l'interrupteur à bascule est en position verticale (avec la bille métallique interne en contact avec les broches métalliques) ou incliné.
