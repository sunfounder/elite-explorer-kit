.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_mpr121:

MPR121
===========================

.. image:: img/mpr121.png


* **3.3V**: Alimentation
* **IRQ**: Broche de sortie d'interruption collecteur ouvert, active à l'état bas
* **SCL**: Horloge I2C
* **SDA**: Données I2C
* **ADD**: Broche de sélection d'adresse I2C. Connectez la broche ADDR à la ligne VSS, VDD, SDA ou SCL, les adresses I2C résultantes sont respectivement 0x5A, 0x5B, 0x5C et 0x5D
* **GND**: Terre
* **0~11**: Électrode 0~11, l'électrode est un capteur tactile. Typiquement, les électrodes peuvent être simplement un morceau de métal ou un fil. Mais parfois, en fonction de la longueur de notre fil ou du matériau sur lequel se trouve l'électrode, cela peut rendre le déclenchement du capteur difficile. Pour cette raison, le MPR121 vous permet de configurer ce qui est nécessaire pour déclencher et désactiver une électrode.

**APERÇU DU MPR121**

Le MPR121 est le contrôleur de capteur tactile capacitif de deuxième génération 
après la sortie initiale des dispositifs de la série MPR03x. Le MPR121 dispose 
d'une intelligence interne accrue, parmi les principales améliorations figurent 
un nombre accru d'électrodes, une adresse I2C configurable matériellement, un 
système de filtrage étendu avec anti-rebond, et des électrodes complètement 
indépendantes avec auto-configuration intégrée. L'appareil dispose également d'un 
13ème canal de détection simulée dédié à la détection de proximité en utilisant 
les entrées de détection multiplexées.

* |link_mpr121_datasheet|

**Caractéristiques**

* Fonctionnement à faible puissance
    • Alimentation de 1,71 V à 3,6 V
    • Courant d'alimentation de 29 μA à une période d'intervalle d'échantillonnage de 16 ms
    • Courant en mode arrêt de 3 μA
* 12 entrées de détection de capacité
    • 8 entrées sont multifonctionnelles pour le pilotage de LED et GPIO
* Détection tactile complète
    • Auto-configuration pour chaque entrée de détection
    • Auto-calibration pour chaque entrée de détection
    • Seuil de toucher/libération et anti-rebond pour la détection tactile
* Interface I2C, avec sortie d'interruption
* Boîtier QFN de 3 mm x 3 mm x 0,65 mm à 20 broches
* Plage de température de fonctionnement de -40°C à +85°C



**Exemple**

* :ref:`basic_mpr121` (Projet de base)
* :ref:`fun_fruit_piano` (Projet amusant)
