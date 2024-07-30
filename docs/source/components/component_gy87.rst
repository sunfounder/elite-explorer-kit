.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_gy87:

Module IMU GY-87
============================

.. image:: img/gy87.png
    :align: center
    :width: 40%

Le module de capteur GY-87 est un module de haute précision à 10 axes (10DOF) capable de mesurer l'accélération, la vitesse angulaire et la force du champ magnétique sur trois axes : x, y et z. Il se compose de trois capteurs principaux : MPU6050, QMC5883L et BMP180, et communique via le protocole I2C.

Le module de capteur GY-87 repose sur trois capteurs :

1. **MPU6050** : C'est un accéléromètre et gyroscope à 6 axes capable de mesurer l'accélération et la vitesse angulaire sur trois axes x, y et z.
2. **QMC5883L** : C'est une boussole numérique à 3 axes capable de mesurer la force du champ magnétique sur trois axes x, y et z.
3. **BMP180** : C'est un capteur de température et de pression barométrique capable de mesurer la pression atmosphérique et la température.

Le MPU6050 mesure l'accélération et la vitesse angulaire sur trois axes x, y et z. Le QMC5883L mesure la force du champ magnétique sur trois axes x, y et z. Le BMP180 mesure la pression atmosphérique et la température. Les données de ces capteurs sont combinées pour fournir des informations précises sur l'orientation du module dans l'espace.

Le module de capteur GY-87 est couramment utilisé dans des applications telles que les drones, la robotique et d'autres projets nécessitant des informations d'orientation précises. Il est compatible avec les cartes Arduino et peut être facilement interfacé avec elles en utilisant le protocole de communication I2C.

.. image:: img/GY-87-SCH.jpg
    :align: center
    :width: 100%

.. raw:: html

    <br/>

**Exemple**

* :ref:`basic_gy87_bmp180` (Basic Project)
* :ref:`basic_gy87_mpu6050` (Basic Project)
* :ref:`basic_gy87_qmc5883l` (Basic Project)
* :ref:`fun_escape` (Fun Project)
