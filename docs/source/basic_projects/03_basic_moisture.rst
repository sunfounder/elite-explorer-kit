.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_moisture:

Humidité du sol
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_moisture.html

Aperçu
---------------

Dans l'industrie agricole, les cultures ne peuvent pas directement acquérir les éléments inorganiques du sol. Au lieu de cela, l'eau présente dans le sol agit comme un solvant pour dissoudre ces éléments.

Les cultures absorbent l'humidité du sol par leur système racinaire pour obtenir des nutriments et faciliter leur croissance.

Pendant la croissance et le développement des cultures, les besoins en température du sol varient. Il est donc nécessaire d'utiliser un capteur d'humidité du sol.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

Câblage
----------------------

.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%

Schéma
-----------------------

.. image:: img/03_moisture_schematic.webp
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Ouvrez le fichier ``03-moisture.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\03-moisture``.
    * Ou copiez ce code dans l'**Arduino IDE**.
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois le code téléversé avec succès, le moniteur série affichera la valeur de l'humidité du sol.

En insérant le module dans le sol et en l'arrosant, la valeur du capteur d'humidité du sol diminuera.
