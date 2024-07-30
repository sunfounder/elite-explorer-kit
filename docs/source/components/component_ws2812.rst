.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ws2812:

Bande LED RGB WS2812 à 8 LEDs
===================================

.. image:: img/ws2812b.png

La bande LED RGB WS2812 à 8 LEDs est composée de 8 LEDs RGB.
Une seule broche est nécessaire pour contrôler toutes les LEDs. Chaque LED RGB possède une puce WS2812, qui peut être contrôlée indépendamment.
Elle peut réaliser un affichage de luminosité à 256 niveaux et un affichage de couleur véritable complet de 16 777 216 couleurs.
De plus, chaque pixel contient un circuit amplificateur de signal de verrouillage de données à interface numérique intelligente, et un circuit de façonnage de signal intégré pour garantir une cohérence élevée de la couleur des points lumineux des pixels.

Elle est flexible, peut être raccordée, pliée et coupée à volonté, et son dos est équipé d'un ruban adhésif, ce qui permet de la fixer sur une surface irrégulière à volonté, et de l'installer dans un espace restreint.

**Caractéristiques**

* Tension de fonctionnement : DC 5V
* IC : Un IC pilote une LED RGB
* Consommation : 0,3 W par LED
* Température de fonctionnement : -15 à 50 °C
* Couleur : RGB pleine couleur
* Type de LED : 5050 RGB (IC intégré WS2812B)
* Épaisseur de la bande LED : 2 mm
* Chaque LED peut être contrôlée individuellement

**Présentation du WS2812B**

* |link_ws2812b_datasheet|

Le WS2812B est une source de lumière LED à contrôle intelligent qui intègre le circuit de contrôle et la puce RGB dans un composant de 5050. Il comprend un verrouillage de données du port numérique intelligent et un circuit de redressement et d'amplification du signal. Il inclut également un oscillateur interne de précision et une partie de contrôle de courant constant programmable de 12V, garantissant efficacement la cohérence des couleurs des points lumineux des pixels.

Le protocole de transfert de données utilise le mode de communication NZR unique. Après la réinitialisation de l'alimentation des pixels, le port DIN reçoit les données du contrôleur, le premier pixel collecte les premières 24 bits de données puis les envoie au verrouillage de données interne. Les autres données, redressées par le circuit de redressement et d'amplification du signal interne, sont envoyées au pixel en cascade suivant via le port DO. Après la transmission pour chaque pixel, le signal est réduit de 24 bits. Le pixel adopte une technologie de transmission automatique de redressement, ce qui fait que le nombre de pixels en cascade n'est pas limité par la transmission du signal, mais dépend uniquement de la vitesse de transmission du signal.

La LED avec une basse tension de conduite, la protection de l'environnement et l'économie d'énergie, une haute luminosité, un grand angle de diffusion, une bonne cohérence, une faible puissance, une longue durée de vie et d'autres avantages. La puce de contrôle intégrée dans la LED rend le circuit plus simple, de petit volume, une installation pratique.

.. Example
.. -------------------

.. :ref:`RGB LED Strip`



**Exemple**

* :ref:`basic_ws2812` (Projet de base)
* :ref:`iot_cheerlights` (Projet IoT)

