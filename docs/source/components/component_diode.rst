.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_diode:

Diode
=================

Une diode est un composant électronique à deux électrodes. Elle permet au courant de circuler dans une seule direction, ce qui est souvent appelé la fonction de "redressement". Ainsi, une diode peut être considérée comme une version électronique d'un clapet anti-retour.

En raison de sa conductivité unidirectionnelle, la diode est utilisée dans presque tous les circuits électroniques de quelque complexité. C'est l'un des premiers dispositifs à semi-conducteurs et il a une large gamme d'applications.

Selon son utilisation, elle peut être classée en diodes détectrices, diodes redresseuses, diodes limiteuses, diodes régulatrices de tension, etc.

Des diodes redresseuses et des diodes régulatrices de tension sont incluses dans ce kit.

**Diode Redresseuse**

.. image:: img/in4007_diode.png
.. image:: img/symbol_rectifier_diode.png
    :width: 200

Une diode redresseuse est une diode semi-conductrice utilisée pour redresser le courant alternatif (CA) en courant continu (CC) en utilisant l'application de pont de redressement. L'alternative de la diode redresseuse par la barrière Schottky est principalement valorisée dans l'électronique numérique. Cette diode est capable de conduire des valeurs de courant allant de mA à quelques kA et des tensions jusqu'à quelques kV.

La conception des diodes redresseuses peut être réalisée avec du silicium et elles sont capables de conduire des valeurs de courant électrique élevées. Ces diodes ne sont pas très populaires mais on utilise encore des diodes à base de Ge ou d'arséniure de gallium. Les diodes Ge ont une tension inverse admissible plus faible ainsi qu'une température de jonction admissible plus basse. La diode Ge a un avantage par rapport à la diode Si, qui est une valeur de tension seuil plus faible en fonctionnement en polarisation directe.

* |link_general_purpose_diode|

**Diode Zener**

Une diode Zener est un type spécial de diode conçue pour permettre au courant de circuler "à l'envers" lorsque une certaine tension inverse prédéfinie, connue sous le nom de tension Zener, est atteinte.

Cette diode est un dispositif semi-conducteur qui présente une très haute résistance jusqu'à la tension critique de claquage inverse. À ce point de claquage critique, la résistance inverse est réduite à une valeur très faible et le courant augmente tandis que la tension reste constante dans cette région de faible résistance.

.. image:: img/zener_diode.png
.. image:: img/symbol-zener-diode.jpg

* |link_zener_diode|

**Exemple**

 * :ref:`basic_relay` (Basic Project)
