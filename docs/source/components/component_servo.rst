.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo est généralement composé des éléments suivants : boîtier, arbre, système d'engrenages, potentiomètre, moteur DC et carte embarquée.

Voici comment cela fonctionne : le microcontrôleur envoie des signaux PWM au servo, et la carte embarquée dans le servo reçoit les signaux via la broche de signal et contrôle le moteur interne pour tourner. En conséquence, le moteur entraîne le système d'engrenages et puis motive l'arbre après décélération. L'arbre et le potentiomètre du servo sont reliés ensemble. Lorsque l'arbre tourne, il entraîne le potentiomètre, de sorte que le potentiomètre émet un signal de tension à la carte embarquée. Ensuite, la carte détermine la direction et la vitesse de rotation en fonction de la position actuelle, de sorte qu'elle peut s'arrêter exactement à la position définie et s'y maintenir.

.. image:: img/servo_internal.png
    :align: center

L'angle est déterminé par la durée d'une impulsion appliquée au fil de contrôle. C'est ce qu'on appelle la modulation de largeur d'impulsion (PWM). Le servo s'attend à recevoir une impulsion toutes les 20 ms. La longueur de l'impulsion détermine la rotation du moteur. Par exemple, une impulsion de 1,5 ms fera tourner le moteur à la position de 90 degrés (position neutre). Lorsqu'une impulsion est envoyée à un servo de moins de 1,5 ms, le servo tourne vers une position et maintient son arbre de sortie à quelques degrés dans le sens antihoraire par rapport au point neutre. Lorsque l'impulsion est plus large que 1,5 ms, l'inverse se produit. La largeur minimale et maximale de l'impulsion qui commandera au servo de tourner à une position valide dépend de chaque servo. Généralement, l'impulsion minimale sera d'environ 0,5 ms et l'impulsion maximale sera de 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Exemple**

* :ref:`basic_servo` (Projet de base)
* :ref:`fun_smart_fan` (Projet amusant)

