.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ultrasonic:

Module Ultrasonique
=============================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Un module de capteur ultrasonique est un instrument qui mesure la distance à un objet en utilisant des ondes sonores ultrasoniques. Il a deux sondes : l'une pour émettre les ondes ultrasoniques et l'autre pour les recevoir et transformer le temps d'émission et de réception en distance, permettant ainsi de détecter la distance entre l'appareil et un obstacle. En pratique, il est vraiment pratique et fonctionnel.

Il offre une fonction de mesure sans contact de 2cm à 400cm, avec une précision de 
mesure pouvant atteindre 3mm. Il peut garantir que le signal est stable dans un 
rayon de 5m, et le signal s'affaiblit progressivement après 5m, jusqu'à disparaître à 7m.

Le module comprend des émetteurs ultrasoniques, un récepteur et un circuit de contrôle. Les principes de base sont les suivants :

#. Utilisez un flip-flop IO pour traiter un signal de haut niveau d'au moins 10us.

#. Le module envoie automatiquement huit signaux à 40 kHz et détecte s'il y a un retour de signal d'impulsion.

#. Si le signal revient, en passant par le haut niveau, la durée de sortie IO élevée est le temps écoulé entre l'émission de l'onde ultrasonique et son retour. Ici, la distance mesurée = (temps haut x vitesse du son (340 m/s) / 2.

Le diagramme temporel est présenté ci-dessous.

.. image:: img/ultrasonic228.png

Vous n'avez besoin de fournir qu'une impulsion courte de 10us pour l'entrée de 
déclenchement pour démarrer la mesure, puis le module enverra une rafale de 8 
cycles d'ultrasons à 40 kHz et élèvera son écho. Vous pouvez calculer la distance 
par l'intervalle de temps entre l'envoi du signal de déclenchement et la réception 
du signal d'écho.

Formule : us / 58 = centimètres ou us / 148 = pouces ; ou : la distance = temps 
haut \* vitesse (340M/S) / 2 ; il est conseillé d'utiliser un cycle de mesure de 
plus de 60ms afin de prévenir les collisions de signal entre le signal de 
déclenchement et le signal d'écho.

**Exemple**

* :ref:`basic_ultrasonic_sensor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)
