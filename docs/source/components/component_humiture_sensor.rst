.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_dht11:

Module Capteur d'Humidité et de Température DHT11
====================================================

Le capteur numérique de température et d'humidité DHT11 est un capteur composite qui contient un signal numérique calibré de sortie de température et d'humidité.
La technologie de collecte de modules numériques dédiés et la technologie de détection de température et d'humidité sont appliquées pour garantir que le produit a une haute fiabilité et une excellente stabilité à long terme.

Seules trois broches sont disponibles pour une utilisation : VCC, GND et DATA.
Le processus de communication commence avec la ligne DATA envoyant des signaux de démarrage au DHT11, et le DHT11 reçoit les signaux et retourne un signal de réponse.
Ensuite, l'hôte reçoit le signal de réponse et commence à recevoir les données de l'humidité sur 40 bits (8 bits pour l'humidité entière + 8 bits pour l'humidité décimale + 8 bits pour la température entière + 8 bits pour la température décimale + 8 bits pour la somme de contrôle).

.. image:: img/Dht11.png


* |link_dht11_datasheet|

**Exemple**

* :ref:`basic_humiture_sensor` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`iot_arduino_cloud` (IoT Project)
* :ref:`iot_ble_home` (IoT Project)