.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

La diode électroluminescente (DEL) est un type de composant qui peut transformer l'énergie électrique en énergie lumineuse via des jonctions PN. Selon la longueur d'onde, elle peut être classée en diode laser, diode électroluminescente infrarouge et diode électroluminescente visible, généralement appelée diode électroluminescente (LED).

La diode a une conductivité unidirectionnelle, donc le flux de courant suivra la direction indiquée par la flèche dans le symbole du circuit. Vous ne pouvez fournir une alimentation positive qu'à l'anode et une alimentation négative à la cathode. Ainsi, la LED s'allumera.

.. image:: img/led_symbol.png

Une LED a deux broches. La plus longue est l'anode, et la plus courte, la cathode. Faites attention à ne pas les connecter à l'envers. Il y a une chute de tension directe fixe dans la LED, donc elle ne peut pas être connectée directement au circuit car la tension d'alimentation pourrait dépasser cette chute et causer la combustion de la LED. La tension directe de la LED rouge, jaune et verte est de 1,8 V et celle de la blanche est de 2,6 V. La plupart des LED peuvent supporter un courant maximal de 20 mA, donc nous devons connecter une résistance de limitation de courant en série.

La formule de la valeur de la résistance est la suivante :

    R = (Vsupply – VD) / I

**R** représente la valeur de la résistance de limitation de courant, **Vsupply** la tension d'alimentation, **VD** la chute de tension et **I** le courant de fonctionnement de la LED.

Voici l'introduction détaillée de la LED : |link_led_wiki|.


**Exemple**


* :ref:`basic_led` (Basic Project)
* :ref:`basic_relay` (Basic Project)
* :ref:`fun_light_array` (Fun Project)
* :ref:`fun_smart_fan` (Fun Project)
