.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_pir:

Module de Capteur de Mouvement PIR
===================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

Le capteur PIR détecte les radiations infrarouges thermiques qui peuvent être utilisées pour détecter la présence d'organismes émettant des radiations infrarouges.

Le capteur PIR est divisé en deux fentes connectées à un amplificateur différentiel. Lorsqu'un objet stationnaire se trouve devant le capteur, les deux fentes reçoivent la même quantité de radiation et la sortie est nulle. Lorsqu'un objet en mouvement se trouve devant le capteur, l'une des fentes reçoit plus de radiation que l'autre, ce qui fait fluctuer la sortie en haute ou basse. Ce changement de tension de sortie résulte de la détection de mouvement.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Après le câblage du module de détection, il y a une minute d'initialisation. Pendant cette initialisation, le module émettra de 0 à 3 fois à intervalles. Ensuite, le module sera en mode veille. Veuillez éloigner toute source de lumière et autres interférences de la surface du module afin d'éviter les faux déclenchements causés par le signal d'interférence. Il est également préférable d'utiliser le module sans trop de vent, car le vent peut également interférer avec le capteur.

.. image:: img/pir_back.png
    :width: 600
    :align: center

**Réglage de la distance**

En tournant le bouton du potentiomètre de réglage de la distance dans le sens des aiguilles d'une montre, la portée de détection augmente, et la distance maximale de détection est d'environ 0-7 mètres. En le tournant dans le sens antihoraire, la portée de détection diminue, et la distance minimale de détection est d'environ 0-3 mètres.

**Réglage du délai**

En tournant le bouton du potentiomètre de réglage du délai dans le sens des aiguilles d'une montre, vous pouvez également augmenter le délai de détection. Le délai maximal de détection peut atteindre jusqu'à 300 secondes. À l'inverse, en le tournant dans le sens antihoraire, vous pouvez raccourcir le délai avec un minimum de 5 secondes.

**Deux modes de déclenchement**

Choisissez différents modes en utilisant le cavalier.

* **H** : Mode de déclenchement répétable, après détection du corps humain, le module émet un niveau haut. Pendant la période de délai suivante, si quelqu'un entre dans la plage de détection, la sortie restera au niveau haut.
* **L** : Mode de déclenchement non répétable, émet un niveau haut lorsqu'il détecte le corps humain. Après le délai, la sortie passera automatiquement du niveau haut au niveau bas.

**Exemple**

* :ref:`basic_pir` (Projet de base)
* :ref:`fun_welcome` (Projet amusant)
* :ref:`iot_security_system_ifttt` (Projet IoT)

