.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support expert** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_audio_speaker:

Module Amplificateur Audio et Haut-Parleur
===========================================

**Module Amplificateur Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Le module amplificateur audio contient une puce amplificatrice audio HXJ8002. Cette puce est un amplificateur de puissance avec une faible alimentation, capable de fournir une puissance audio moyenne de 3W pour une charge BTL de 3Ω avec une faible distorsion harmonique (sous le seuil de distorsion de 10% à 1KHz) à partir d'une alimentation de 5V DC. Cette puce peut amplifier les signaux audio sans aucun condensateur de couplage ou de bootstrap.

Le module peut être alimenté par une source de 2,0V à 5,5V DC avec un courant de fonctionnement de 10mA (0,6uA pour un courant de veille typique) et produire un son amplifié puissant dans un haut-parleur de 3Ω, 4Ω ou 8Ω d'impédance. Ce module dispose d'un circuit amélioré pour réduire significativement le bruit de transition au moment de l'allumage et de l'extinction. Sa petite taille, son efficacité élevée et sa faible consommation d'énergie le rendent applicable dans divers projets portables et alimentés par batterie, ainsi que dans les microcontrôleurs.

* **IC** : HXJ8002
* **Tension d'entrée** : 2V ~ 5.5V
* **Courant en mode veille** : 0.6uA (valeur typique)
* **Puissance de sortie** : 3W (charge de 3Ω), 2.5W (charge de 4Ω), 1.5W (charge de 8Ω)
* **Impédance du haut-parleur de sortie** : 3Ω, 4Ω, 8Ω
* **Taille** : 19.8mm x 14.2mm

**Haut-Parleur**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Taille** : 20x30x7mm
* **Impédance** : 8ohm
* **Puissance nominale d'entrée** : 1.5W
* **Puissance maximale d'entrée** : 2.0W
* **Longueur du fil** : 10cm

.. image:: img/2030_speaker.png

Le tableau des tailles est le suivant :

* :download:`Fiche Technique du Haut-Parleur 2030 <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`

**Exemple**

* :ref:`basic_audio_speaker` (Basic Project)
* :ref:`fun_welcome` (Fun Project)
* :ref:`fun_fruit_piano` (Fun Project)
* :ref:`new_dac`

