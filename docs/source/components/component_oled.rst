.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_oled:

Module d'affichage OLED
==========================

.. image:: img/oled.png
    :width: 300
    :align: center

Introduction
---------------------------
Un module d'affichage OLED (diode électroluminescente organique) est un dispositif qui peut afficher du texte, des graphiques et des images sur un écran fin et flexible utilisant des matériaux organiques qui émettent de la lumière lorsqu'un courant électrique est appliqué.

Le principal avantage d'un écran OLED est qu'il émet sa propre lumière et n'a pas besoin d'une autre source de rétroéclairage. En raison de cela, les écrans OLED ont souvent un meilleur contraste, une meilleure luminosité et des angles de vision plus larges par rapport aux écrans LCD.

Une autre caractéristique importante des écrans OLED est leur niveau de noir profond. Étant donné que chaque pixel émet sa propre lumière dans un écran OLED, pour produire la couleur noire, le pixel individuel peut être éteint.

En raison de leur faible consommation d'énergie (seuls les pixels allumés consomment du courant), les écrans OLED sont également populaires dans les appareils fonctionnant sur batterie comme les montres intelligentes, les trackers de santé et autres appareils portables.

Principe
---------------------------
Un module d'affichage OLED se compose d'un panneau OLED et d'une puce de pilote OLED montée à l'arrière du module. Le panneau OLED est composé de nombreux petits pixels capables de produire différentes couleurs de lumière. Chaque pixel se compose de plusieurs couches de matériaux organiques pris en sandwich entre deux électrodes (anode et cathode). Lorsque le courant électrique circule entre les électrodes, les matériaux organiques émettent une lumière de différentes longueurs d'onde en fonction de leur composition.

La puce de pilote OLED est une puce qui peut contrôler les pixels du panneau OLED en utilisant un protocole de communication série appelé I2C (Inter-Integrated Circuit).

La puce de pilote OLED convertit les signaux de l'Arduino en commandes pour le panneau OLED. L'Arduino peut envoyer des données à la puce de pilote OLED en utilisant une bibliothèque capable de contrôler le protocole I2C. Une telle bibliothèque est la bibliothèque Adafruit SSD1306. Avec cette bibliothèque, vous pouvez initialiser le module d'affichage OLED, régler le niveau de luminosité, imprimer du texte, des graphiques ou des images, etc.

**Exemple**

* :ref:`basic_oled` (Projet de base)
* :ref:`fun_pong` (Projet amusant)
* :ref:`iot_weathertime_screen` (Projet IoT)
