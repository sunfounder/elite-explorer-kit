.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_active_buzzer:

Buzzer Actif
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

Vue d'ensemble
-------------------

Le buzzer actif est un dispositif de sortie numérique typique aussi facile à utiliser qu'une LED !

Deux types de buzzers sont inclus dans le kit.
Nous devons utiliser le buzzer actif. Retournez-les, le dos scellé (pas le PCB exposé) est celui que nous voulons.

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

Composants requis
----------------------------

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
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

Câblage
----------------------

.. note::
    Lors de la connexion du buzzer, assurez-vous de vérifier ses broches. La broche la plus longue est l'anode et la plus courte est la cathode. Il est important de ne pas les mélanger, car cela empêcherait le buzzer de produire du son.

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

Schéma de câblage
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``16-active_buzzer.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\16-active_buzzer`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. literalinclude:: /_code/16_basic_active_buzzer.ino
   :language: cpp
   :linenos:
   :caption: 16-active_buzzer.ino

Après avoir téléversé le code avec succès, vous entendrez un bip toutes les secondes.
