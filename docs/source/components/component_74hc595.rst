.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support expert** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Le 74HC595 est composé d'un registre à décalage de 8 bits et d'un registre de stockage avec des sorties parallèles à trois états. Il convertit l'entrée série en sortie parallèle, ce qui permet de sauvegarder les ports IO d'un MCU.
Lorsque MR (broche 10) est à un niveau élevé et que OE (broche 13) est à un niveau bas, les données sont saisies sur le front montant de SHcp et vont dans le registre de mémoire par le front montant de SHcp. Si les deux horloges sont connectées ensemble, le registre à décalage est toujours une impulsion en avance sur le registre de mémoire. Il y a une broche d'entrée de décalage série (Ds), une broche de sortie série (Q) et un bouton de réinitialisation asynchrone (niveau bas) dans le registre de mémoire. Le registre de mémoire fournit une sortie parallèle de 8 bits en trois états. Lorsque OE est activé (niveau bas), les données du registre de mémoire sont envoyées sur le bus.

* |link_74hc595_datasheet|

.. image:: img/74hc595_pin.png
    :width: 600

Broches du 74HC595 et leurs fonctions :

* **Q0-Q7** : Broches de sortie de données parallèles 8 bits, capables de contrôler directement 8 LED ou 8 broches d'un afficheur à 7 segments.
* **Q7’** : Broche de sortie série, connectée à DS d'un autre 74HC595 pour connecter plusieurs 74HC595 en série.
* **MR** : Broche de réinitialisation, active à niveau bas.
* **SHcp** : Entrée de séquence temporelle du registre à décalage. Sur le front montant, les données dans le registre à décalage se déplacent successivement d'un bit, c'est-à-dire que les données de Q1 passent à Q2, et ainsi de suite. Sur le front descendant, les données dans le registre à décalage restent inchangées.
* **STcp** : Entrée de séquence temporelle du registre de stockage. Sur le front montant, les données dans le registre à décalage passent dans le registre de mémoire.
* **CE** : Broche d'activation de sortie, active à niveau bas.
* **DS** : Broche d'entrée de données série.
* **VCC** : Tension d'alimentation positive.
* **GND** : Terre.

**Exemple**

* :ref:`basic_74hc595` (Basic Project)
* :ref:`fun_digital_dice` (Fun Project)
