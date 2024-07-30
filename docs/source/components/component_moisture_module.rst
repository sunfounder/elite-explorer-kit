.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_soil_moisture:

Module de Capteur d'Humidité du Sol
======================================

.. image:: img/soil_mositure.png

* GND : Masse
* VCC : Alimentation, 3.3v~5V
* AOUT : Sortie de la valeur de l'humidité du sol, plus le sol est humide, plus la valeur est faible.

Ce capteur capacitif d'humidité du sol est différent de la plupart des capteurs résistifs sur le marché, utilisant le principe de l'induction capacitive pour détecter l'humidité du sol. Il évite le problème des capteurs résistifs qui sont très sensibles à la corrosion et prolonge considérablement sa durée de vie.

Il est fabriqué à partir de matériaux résistants à la corrosion et possède une excellente durée de vie. Insérez-le dans le sol autour des plantes et surveillez les données d'humidité du sol en temps réel. Le module comprend un régulateur de tension intégré qui lui permet de fonctionner sur une plage de tension de 3,3 à 5,5 V. Il est idéal pour les microcontrôleurs basse tension avec des alimentations de 3,3 V et 5 V.

Le schéma matériel du capteur capacitif d'humidité du sol est présenté ci-dessous.

.. image:: img/solid_schematic.png

Il y a un oscillateur à fréquence fixe, construit avec un CI minuteur 555. L'onde carrée générée est ensuite envoyée au capteur comme un condensateur. Cependant, pour le signal d'onde carrée, le condensateur a une certaine réactance ou, pour simplifier, un résistor pur (résistor de 10k sur la broche 3) pour former un diviseur de tension.

Plus l'humidité du sol est élevée, plus la capacité du capteur est élevée. En conséquence, l'onde carrée a moins de réactance, ce qui réduit la tension sur la ligne de signal, et plus la valeur de l'entrée analogique à travers le microcontrôleur est faible.

**Spécifications**

* Tension de fonctionnement : 3,3 ~ 5,5 VDC
* Tension de sortie : 0 ~ 3,0 VDC
* Courant de fonctionnement : 5 mA
* Interface : PH2.0-3P
* Dimensions : 3,86 x 0,905 pouces (L x l)
* Poids : 15g

**Exemple**

* :ref:`basic_moisture` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)


