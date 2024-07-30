.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez plus profondément dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ir_receiver:

Récepteur Infrarouge
=================================

Récepteur IR
----------------------------

.. image:: img/infrared-receiver_01.png
    :width: 60%

* S : Sortie de signal
* + : VCC
* - : GND

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut recevoir indépendamment les rayons infrarouges et émettre des signaux compatibles avec le niveau TTL. Il est similaire à un transistor encapsulé en plastique de taille normale et est adapté à tous types de télécommandes et de transmissions infrarouges.

Le SL838 est un petit récepteur pour systèmes de télécommande infrarouge. Il contient une photodiode à grande vitesse et haute sensibilité ainsi qu'un préamplificateur, et est encapsulé avec de la résine époxy pour former un filtre infrarouge. Son principal avantage est sa fiabilité même dans un environnement perturbé.

La communication infrarouge, ou IR, est une technologie de communication sans fil populaire, peu coûteuse et facile à utiliser. La lumière infrarouge a une longueur d'onde légèrement plus longue que la lumière visible, ce qui la rend imperceptible à l'œil humain - idéale pour la communication sans fil. Un schéma de modulation courant pour la communication infrarouge est la modulation à 38KHz.

* Peut être utilisé pour la télécommande
* Large plage de tension de fonctionnement : 2.7~5V
* Filtre interne pour la fréquence PCM 
* Compatibilité TTL et CMOS
* Forte capacité anti-interférence
* Conforme RoHS

Télécommande
-------------------------

.. image:: img/infrared-receiver_02.jpeg
    :width: 70%

Il s'agit d'une télécommande sans fil infrarouge mince et mini avec 21 boutons de fonction et une distance de transmission pouvant atteindre 8 mètres, adaptée à l'utilisation de nombreux appareils dans une chambre d'enfant.

* Taille : 85x39x6mm
* Portée de la télécommande : 8-10m
* Batterie : Pile bouton au lithium-manganèse 3V
* Fréquence porteuse infrarouge : 38KHz
* Matériau de surface : PET de 0,125mm
* Durée de vie effective : plus de 20 000 utilisations

**Exemple**

* :ref:`basic_irrecv` (Projet de base)
* :ref:`fun_guess_number` (Projet amusant)

