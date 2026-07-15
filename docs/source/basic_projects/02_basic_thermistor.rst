.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_thermistor:

Thermistance
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.27_thermistor.html#ar-thermistor

Aperçu
-------------

Dans cette leçon, vous allez apprendre à utiliser une thermistance. La thermistance peut être utilisée comme composant de circuit électronique pour la compensation de température des circuits d'instruments. Dans l'ampèremètre, le débitmètre, l'analyseur de gaz et d'autres dispositifs. Elle peut également être utilisée pour la protection contre la surchauffe, le relais sans contact, la température constante, le contrôle automatique du gain, le démarrage du moteur, le retardement, le démagnétisation automatique des téléviseurs couleur, l'alarme incendie et la compensation de température.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Câblage
----------------------

Dans cet exemple, nous utilisons la broche analogique A0 pour obtenir la valeur de la thermistance. Une broche de la thermistance est connectée au 5V, et l'autre est reliée à A0. En même temps, une résistance de 10kΩ est connectée à l'autre broche avant de la connecter à la masse (GND).

.. image:: img/02-thermistor_bb.png
    :align: center
    :width: 70%

Schéma
-----------------------

.. image:: img/02_thermistor_schematic.png
   :align: center
   :width: 70%

Code
-----------

.. note::

    * Vous pouvez ouvrir le fichier ``02-thermistor.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\02-thermistor`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. literalinclude:: /_code/02_basic_thermistor.ino
   :language: cpp
   :linenos:
   :caption: 02-thermistor.ino

Après avoir téléversé le code sur la carte uno r4, vous pouvez ouvrir le moniteur série pour vérifier la température actuelle.

La température Kelvin est calculée en utilisant la formule **T\ K\ =1/(ln(R\ T/R\ N)/B+1/T\ N)**. Cette équation est dérivée de la |link_steinhart_hart| et simplifie les calculs. Vous pouvez également trouver plus d'informations sur cette formule sur la page de présentation détaillée de la :ref:`cpn_thermistor`.
