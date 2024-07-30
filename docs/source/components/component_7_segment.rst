.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support expert** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_7segment:

Afficheur 7 segments
======================

.. image:: img/7-seg.jpg

Un afficheur 7 segments est un composant en forme de 8 qui intègre 7 LED. Chaque LED est appelée un segment - lorsqu'elle est alimentée, un segment forme une partie d'un chiffre à afficher.

Il existe deux types de connexion de broches : Cathode Commune (CC) et Anode Commune (CA). Comme son nom l'indique, un afficheur CC a toutes les cathodes des 7 LED connectées ensemble, tandis qu'un afficheur CA a toutes les anodes des 7 segments connectées ensemble.

Dans ce kit, nous utilisons l'afficheur 7 segments à cathode commune, voici le symbole électronique.

.. image:: img/segment_cathode.png
    :width: 800

Chacune des LED de l'afficheur est positionnée avec une broche de connexion qui sort du boîtier plastique rectangulaire. Ces broches LED sont étiquetées de "a" à "g" représentant chaque LED individuelle. Les autres broches LED sont connectées ensemble formant une broche commune. En polarisant directement les broches appropriées des segments LED dans un ordre particulier, certains segments s'allument et d'autres restent éteints, affichant ainsi le caractère correspondant sur l'afficheur.

**Codes d'affichage**

Pour vous aider à comprendre comment les afficheurs 7 segments (Cathode Commune) affichent les chiffres, nous avons dessiné le tableau suivant. Les chiffres sont les numéros 0-F affichés sur l'afficheur 7 segments ; (DP) GFEDCBA fait référence aux LED correspondantes réglées sur 0 ou 1. Par exemple, 00111111 signifie que DP et G sont réglés sur 0, tandis que les autres sont réglés sur 1. Par conséquent, le chiffre 0 est affiché sur l'afficheur 7 segments, tandis que le code HEX correspond au nombre hexadécimal.

.. image:: img/segment_code.png

**Exemple**

* :ref:`basic_7segment` (Basic Project)
* :ref:`basic_74hc595` (Basic Project)
* :ref:`fun_digital_dice` (Fun Project)
