.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND** : Masse
* **VCC** : Alimentation, 5V.
* **SDA** : Ligne de données série. Connecter à VCC via une résistance de tirage.
* **SCL** : Ligne d'horloge série. Connecter à VCC via une résistance de tirage.

Comme nous le savons tous, bien que les écrans LCD et certains autres affichages enrichissent grandement l'interaction homme-machine, ils partagent une faiblesse commune. Lorsqu'ils sont connectés à un contrôleur, plusieurs IOs seront occupés, limitant ainsi les autres fonctions du contrôleur qui n'a pas autant de ports externes.

Par conséquent, le LCD1602 avec un module I2C a été développé pour résoudre ce problème. Le module I2C intègre une puce PCF8574 I2C qui convertit les données série I2C en données parallèles pour l'affichage LCD.

* |link_pcf8574_datasheet|

**Adresse I2C**

L'adresse par défaut est généralement 0x27, dans quelques cas elle peut être 0x3F.

Prenons l'exemple de l'adresse par défaut 0x27, l'adresse du dispositif peut être modifiée en court-circuitant les pads A0/A1/A2 ; à l'état par défaut, A0/A1/A2 est à 1, et si le pad est court-circuité, A0/A1/A2 est à 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Rétroéclairage/Contraste**

Le rétroéclairage peut être activé par un cavalier, débranchez le cavalier pour désactiver le rétroéclairage. Le potentiomètre bleu à l'arrière est utilisé pour ajuster le contraste (le rapport de luminosité entre le blanc le plus lumineux et le noir le plus sombre).

.. image:: img/back_lcd1602.jpg

* **Cavalier** : Le rétroéclairage peut être activé par ce cavalier, débranchez ce cavalier pour désactiver le rétroéclairage.
* **Potentiomètre** : Il est utilisé pour ajuster le contraste (la clarté du texte affiché), qui augmente dans le sens horaire et diminue dans le sens antihoraire.

**Exemple**

* :ref:`basic_i2c_lcd1602` (Basic Project)
* :ref:`basic_ultrasonic_sensor` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`fun_guess_number` (Fun Project)
* :ref:`iot_Bluetooth_lcd` (IoT Project)
