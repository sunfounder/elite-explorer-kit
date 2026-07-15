.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_photoresistor:

Photoresistor
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.26_photoresistor.html

Aperçu
------------------

Dans cette leçon, vous allez découvrir la photorésistance. La photorésistance est utilisée dans de nombreux produits électroniques, tels que le posemètre d'appareil photo, le radio-réveil, le dispositif d'alarme (comme détecteur de faisceau), les petites veilleuses, les horloges extérieures, les lampes de rue solaires, etc. La photorésistance est placée dans une lampe de rue pour contrôler l'allumage de la lumière. La lumière ambiante tombant sur la photorésistance provoque l'allumage ou l'extinction des lampes de rue.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Câblage
----------------------

Dans cet exemple, nous utilisons la broche analogique (A0) pour lire la valeur de la photorésistance. Une broche de la photorésistance est connectée au 5V, l'autre est reliée à A0. De plus, une résistance de 10kΩ est nécessaire avant que l'autre broche ne soit connectée à la masse (GND).

.. image:: img/01-photoresistor_bb.png
    :align: center
    :width: 80%

Schéma
-----------------------

.. image:: img/01_photoresistor_schematic.png
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``01-photoresistor`` sous le chemin ``elite-explorer-kit-main\basic_project\01-photoresistor`` directement.
    * Ou copiez ce code dans l'IDE Arduino.




.. literalinclude:: /_code/01_basic_photoresistor.ino
   :language: cpp
   :linenos:
   :caption: 01-photoresistor.ino

Après avoir téléversé le code sur la carte uno, vous pouvez ouvrir le moniteur série pour voir la valeur lue de la broche. Lorsque la lumière ambiante devient plus forte, la lecture augmentera en conséquence, et la plage de lecture de la broche est de « 0 » à « 1023 ». Cependant, selon les conditions environnementales et les caractéristiques de la photorésistance, la plage de lecture réelle peut être inférieure à la plage théorique.
