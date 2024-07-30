.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_rgb_led:

LED RGB
=================

.. image:: img/rgb_led.png
    :width: 100
    
Les LED RGB émettent de la lumière dans différentes couleurs. Une LED RGB regroupe trois LED rouge, verte et bleue dans une coque en plastique transparente ou semi-transparente. Elle peut afficher différentes couleurs en changeant la tension d'entrée des trois broches et en les superposant, ce qui, selon les statistiques, peut créer 16 777 216 couleurs différentes. 

.. image:: img/rgb_light.png
    :width: 600

Les LED RGB peuvent être classées en anode commune et cathode commune. Dans ce kit, ce dernier est utilisé. La **cathode commune**, ou CC, signifie connecter les cathodes des trois LED. Après l'avoir connectée à la masse (GND) et branché les trois broches, la LED affichera la couleur correspondante. 

Son symbole de circuit est montré sur la figure.

.. image:: img/rgb_symbol.png
    :width: 300

Une LED RGB a 4 broches : la plus longue est GND ; les autres sont Rouge, Vert et Bleu. Touchez sa coque en plastique et vous trouverez une entaille. La broche la plus proche de l'entaille est la première broche, marquée comme Rouge, puis GND, Vert et Bleu dans cet ordre. 

.. image:: img/rgb_pin.jpg
    :width: 200

**Exemple**

* :ref:`basic_rgb_led` (Projet de base)
* :ref:`fun_hue` (Projet amusant)

