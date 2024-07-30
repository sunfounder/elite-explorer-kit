.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_mfrc522:

Module MFRC522
=====================

**RFID**

La Radio Frequency Identification (RFID) désigne les technologies utilisant la communication sans fil entre un objet (ou étiquette) et un dispositif d'interrogation (ou lecteur) pour suivre et identifier automatiquement ces objets. La portée de transmission de l'étiquette est limitée à quelques mètres du lecteur. Une ligne de vue claire entre le lecteur et l'étiquette n'est pas nécessaire.

La plupart des étiquettes contiennent au moins un circuit intégré (IC) et une antenne. La puce stocke des informations et est responsable de la gestion de la communication radiofréquence (RF) avec le lecteur. Les étiquettes passives n'ont pas de source d'énergie indépendante et dépendent d'un signal électromagnétique externe fourni par le lecteur pour alimenter leurs opérations. Les étiquettes actives contiennent une source d'énergie indépendante, telle qu'une batterie. Elles peuvent ainsi avoir des capacités de traitement et de transmission accrues ainsi qu'une portée étendue.

.. image:: img/mfrc522.png

**MFRC522**

Le MFRC522 est un type de puce de lecture et d'écriture de cartes intégrée. Il est couramment utilisé pour les communications radio à 13,56 MHz. Lancé par la société NXP, c'est une puce de carte sans contact à faible tension, faible coût et petite taille, un excellent choix pour les instruments intelligents et les appareils portables.

Le MF RC522 utilise un concept avancé de modulation et de démodulation, pleinement présent dans tous les types de méthodes et protocoles de communication sans contact passifs à 13,56 MHz. De plus, il prend en charge l'algorithme de cryptage rapide CRYPTO1 pour vérifier les produits MIFARE. Le MFRC522 prend également en charge la communication sans contact haute vitesse de la série MIFARE, avec un taux de transmission de données bidirectionnel allant jusqu'à 424 kbit/s. En tant que nouveau membre de la série de lecteurs de cartes hautement intégrés à 13,56 MHz, le MF RC522 est très similaire aux MF RC500 et MF RC530 existants, mais présente également de grandes différences. Il communique avec la machine hôte via un mode série nécessitant moins de câblage. Vous pouvez choisir entre les modes SPI, I2C et UART série (similaire à RS232), ce qui aide à réduire les connexions, à économiser de l'espace sur la carte PCB (taille plus petite) et à réduire les coûts.

**Exemple**

* :ref:`basic_mfrc522` (Basic Project)
* :ref:`fun_access` (Fun Project)