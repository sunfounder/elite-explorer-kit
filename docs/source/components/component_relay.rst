.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_realy:

Relais
==========================================

.. image:: img/relay_pic.png
    :width: 200
    :align: center

Comme nous le savons, un relais est un dispositif qui permet de connecter deux ou plusieurs points ou dispositifs en réponse à un signal d'entrée appliqué. En d'autres termes, les relais offrent une isolation entre le contrôleur et le dispositif, car les dispositifs peuvent fonctionner en courant alternatif (AC) ainsi qu'en courant continu (DC). Cependant, ils reçoivent des signaux d'un microcontrôleur qui fonctionne en DC, nécessitant ainsi un relais pour combler l'écart. Le relais est extrêmement utile lorsque vous avez besoin de contrôler une grande quantité de courant ou de tension avec un petit signal électrique.

Chaque relais se compose de 5 parties :

.. image:: img/relay142.jpeg

**Électroaimant** - Il se compose d'un noyau de fer enroulé par une bobine de fils. Lorsque l'électricité passe à travers, il devient magnétique. Par conséquent, il est appelé électroaimant.

**Armature** - La bande magnétique mobile est connue sous le nom d'armature. Lorsque le courant les traverse, la bobine est énergisée, produisant ainsi un champ magnétique utilisé pour ouvrir ou fermer les points normalement ouverts (N/O) ou normalement fermés (N/C). Et l'armature peut être déplacée avec un courant continu (DC) ainsi qu'un courant alternatif (AC).

**Ressort** - Lorsque aucun courant ne circule dans la bobine de l'électroaimant, le ressort tire l'armature vers l'arrière, empêchant ainsi la fermeture du circuit.

Ensemble de **contacts électriques** - Il y a deux points de contact :

-  Normalement ouvert - connecté lorsque le relais est activé, et déconnecté lorsqu'il est inactif.

-  Normalement fermé - non connecté lorsque le relais est activé, et connecté lorsqu'il est inactif.

**Cadre moulé** - Les relais sont recouverts de plastique pour la protection.

Le principe de fonctionnement du relais est simple. Lorsqu'une alimentation est fournie au relais, le courant commence à circuler à travers la bobine de commande ; en conséquence, l'électroaimant commence à s'énergiser. Ensuite, l'armature est attirée par la bobine, abaissant le contact mobile pour se connecter aux contacts normalement ouverts. Ainsi, le circuit avec la charge est énergisé. Ensuite, pour ouvrir le circuit, c'est un cas similaire, car le contact mobile sera tiré vers le haut vers les contacts normalement fermés sous l'effet du ressort. De cette manière, la mise en marche et l'arrêt du relais peuvent contrôler l'état d'un circuit de charge.

**Exemple**

* :ref:`basic_relay` (Projet de base)
