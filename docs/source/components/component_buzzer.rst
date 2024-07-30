.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_buzzer:

Buzzer
=======

.. image:: img/buzzer1.png
    :width: 50%
    :align: center

Les buzzers, en tant que type de buzzer électronique avec une structure intégrée, alimentés par courant continu, sont largement utilisés dans les ordinateurs, imprimantes, photocopieurs, alarmes, jouets électroniques, dispositifs électroniques automobiles, téléphones, minuteries et autres produits électroniques ou dispositifs vocaux. 

Les buzzers peuvent être classés en deux catégories : actifs et passifs (voir l'image suivante). Tournez le buzzer de manière à ce que ses broches soient orientées vers le haut : le buzzer avec une carte de circuit imprimé verte est un buzzer passif, tandis que celui entouré de ruban noir est un buzzer actif.

.. image:: img/buzzer2.png
    :width: 60%
    :align: center

La différence entre un buzzer actif et un buzzer passif :

Un buzzer actif a une source oscillante intégrée, il émet donc des sons lorsqu'il est alimenté. En revanche, un buzzer passif n'a pas de source oscillante intégrée, il ne bipera pas avec des signaux de courant continu ; il nécessite des ondes carrées dont la fréquence est comprise entre 2K et 5K pour fonctionner. Le buzzer actif est souvent plus cher que le buzzer passif en raison des multiples circuits oscillants intégrés.

Voici le symbole électrique d'un buzzer. Il possède deux broches avec des pôles positif et négatif. Le + sur la surface représente l'anode et l'autre la cathode.

.. image:: img/buzzer_symbol.png
    :width: 150

Vous pouvez vérifier les broches du buzzer, la plus longue est l'anode et la plus courte est la cathode. Veuillez ne pas les mélanger lors de la connexion, sinon le buzzer ne fera pas de bruit.

|link_buzzer_wiki|

**Exemple**

* :ref:`basic_active_buzzer` (Basic Project)
* :ref:`basic_passive_buzzer` (Basic Project)
* :ref:`fun_access` (Fun Project)
