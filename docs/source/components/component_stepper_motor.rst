.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_stepper_motor:

Moteur Pas à Pas
=========================

.. image:: img/stepper_motor2.jpeg
   :align: center

Les moteurs pas à pas, grâce à leur conception unique, peuvent être contrôlés avec une grande précision sans aucun mécanisme de rétroaction. L'arbre du moteur pas à pas, monté avec une série d'aimants, est contrôlé par une série de bobines électromagnétiques qui sont chargées positivement et négativement dans une séquence spécifique, le déplaçant précisément vers l'avant ou vers l'arrière par petits "pas".

**Principe**

Il existe deux types de moteurs pas à pas, les unipolaires et les bipolaires, et il est très important de savoir avec quel type vous travaillez. Dans cette expérience, nous utiliserons un moteur pas à pas unipolaire.

Le moteur pas à pas est un moteur à quatre phases, qui utilise une alimentation en courant continu unipolaire. Tant que vous alimentez toutes les phases du moteur avec une séquence de temporisation appropriée, vous pouvez le faire tourner pas à pas. Le schéma d'un moteur pas à pas réactif à quatre phases est le suivant :

.. image:: img/stepper_motor3.png
   :align: center

Dans la figure, au milieu du moteur se trouve un rotor - un aimant permanent en forme de dent. Autour du rotor, de 0 à 5 se trouvent des dents. Plus à l'extérieur, il y a 8 pôles magnétiques, chaque paire opposée étant connectée par un enroulement de bobine. Ils forment ainsi quatre paires de A à D, appelées phase. Il a quatre fils conducteurs à connecter avec les interrupteurs SA, SB, SC et SD. Par conséquent, les quatre phases sont en parallèle dans le circuit, et les deux pôles magnétiques d'une phase sont en série.

**Voici comment fonctionne un moteur pas à pas à 4 phases :**

Au début, l'interrupteur SB est allumé, les interrupteurs SA, SC et SD sont éteints, et les pôles magnétiques de la phase B s'alignent avec les dents 0 et 3 du rotor. En même temps, les dents 1 et 4 créent des dents décalées avec les pôles des phases C et D. Les dents 2 et 5 créent des dents décalées avec les pôles magnétiques des phases D et A. Lorsque l'interrupteur SC est allumé, les interrupteurs SB, SA et SD sont éteints, le rotor tourne sous l'effet du champ magnétique de l'enroulement de la phase C et celui entre les dents 1 et 4. Ensuite, les dents 1 et 4 s'alignent avec les pôles magnétiques de l'enroulement de la phase C. Tandis que les dents 0 et 3 créent des dents décalées avec les pôles des phases A et B, et les dents 2 et 5 créent des dents décalées avec les pôles magnétiques des phases A et D. La situation similaire se répète. Alimentez successivement les phases A, B, C et D, et le rotor tournera dans l'ordre des phases A, B, C et D.

Le moteur pas à pas à quatre phases a trois modes de fonctionnement : le mode simple à quatre pas, le mode double à quatre pas et le mode à huit pas. L'angle de pas pour le mode simple à quatre pas et le mode double à quatre pas est le même, mais le couple de commande pour le mode simple à quatre pas est plus faible. L'angle de pas du mode à huit pas est la moitié de celui des modes simple à quatre pas et double à quatre pas. Ainsi, le mode de fonctionnement à huit pas peut maintenir un couple de commande élevé et améliorer la précision du contrôle. Dans cette expérience, nous faisons fonctionner le moteur pas à pas en mode à huit pas.

**Module ULN2003**

.. image:: img/uln2003.png
    :align: center

Pour appliquer le moteur dans le circuit, une carte de pilote doit être utilisée. Le pilote de moteur pas à pas ULN2003 est un circuit inverseur à 7 canaux. C'est-à-dire que lorsque l'entrée est à un niveau haut, la sortie de l'ULN2003 est à un niveau bas, et vice versa. Si nous alimentons le niveau haut à IN1, et le niveau bas à IN2, IN3 et IN4, alors la sortie OUT1 est à un niveau bas, et toutes les autres sorties sont à un niveau haut. Ainsi, D1 s'allume, l'interrupteur SA est allumé, et le moteur pas à pas tourne d'un pas. Le cas similaire se répète. Par conséquent, il suffit de donner une séquence de temporisation spécifique au moteur pas à pas, il tournera pas à pas. L'ULN2003 ici est utilisé pour fournir des séquences de temporisation particulières pour le moteur pas à pas.


**Exemple**

* :ref:`basic_stepper_motor` (Projet de base)
* :ref:`fun_access` (Projet amusant)
