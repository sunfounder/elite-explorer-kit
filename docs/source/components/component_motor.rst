.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_motor:

Moteur à courant continu (DC)
==================================

.. image:: img/motor.jpeg
    :align: center

Voici un moteur à courant continu (DC) de 3V. Lorsque vous appliquez un niveau élevé et un niveau bas à chacun des deux terminaux, il tourne.

* **Longueur** : 25 mm
* **Diamètre** : 21 mm
* **Diamètre de l'axe** : 2 mm
* **Longueur de l'axe** : 8 mm
* **Tension** : 3-6V
* **Courant** : 0,35-0,4A
* **Vitesse à 3V** : 19000 tr/min (Tours Par Minute)
* **Poids** : Environ 14g (par unité)

Un moteur à courant continu (DC) est un actionneur continu qui convertit l'énergie électrique en énergie mécanique. Les moteurs DC font fonctionner des pompes rotatives, des ventilateurs, des compresseurs, des hélices et d'autres dispositifs en produisant une rotation angulaire continue.

Un moteur DC se compose de deux parties, la partie fixe du moteur appelée le **stator** et la partie interne du moteur appelée le **rotor** (ou **induit** d'un moteur DC) qui tourne pour produire le mouvement. 
La clé pour générer du mouvement est de positionner l'induit dans le champ magnétique de l'aimant permanent (dont le champ s'étend du pôle nord au pôle sud). L'interaction du champ magnétique et des particules chargées en mouvement (le fil conducteur de courant génère le champ magnétique) produit le couple qui fait tourner l'induit.

.. image:: img/motor_sche.png
    :align: center

Le courant circule depuis la borne positive de la batterie à travers le circuit, via les balais en cuivre jusqu'au collecteur, puis vers l'induit. 
Mais en raison des deux espaces dans le collecteur, ce flux s'inverse à mi-chemin de chaque rotation complète. 
Cette inversion continue convertit essentiellement l'alimentation DC de la batterie en AC, permettant à l'induit de ressentir le couple dans la bonne direction au bon moment pour maintenir la rotation.

**Exemple**

* :ref:`basic_motor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)