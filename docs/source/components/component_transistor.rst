.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_transistor:

Transistor
============

.. image:: img/npn_pnp.png
    :width: 300

Un transistor est un dispositif semi-conducteur qui contrôle le courant par le courant. Il amplifie un signal faible en un signal de plus grande amplitude et est également utilisé comme interrupteur sans contact.

Un transistor est une structure à trois couches composée de semi-conducteurs de type P et N. Ils forment les trois régions internes. La plus fine au milieu est la région de base ; les deux autres sont des régions de type N ou P - la région plus petite avec des porteurs majoritaires intenses est la région émettrice, tandis que l'autre est la région collectrice. Cette composition permet au transistor d'être un amplificateur. 
De ces trois régions, trois pôles sont générés respectivement, qui sont la base (b), l'émetteur (e) et le collecteur (c). Ils forment deux jonctions P-N, à savoir, la jonction émettrice et la jonction collectrice. La direction de la flèche dans le symbole du circuit du transistor indique celle de la jonction émettrice.

* `Jonction P–N - Wikipedia <https://fr.wikipedia.org/wiki/Jonction_p-n>`_

En fonction du type de semi-conducteur, les transistors peuvent être divisés en deux groupes, les NPN et PNP. D'après l'abréviation, nous pouvons dire que le premier est composé de deux semi-conducteurs de type N et d'un de type P et que le second est l'inverse. Voir la figure ci-dessous.

.. note::
    Le s8550 est un transistor PNP et le s8050 est un transistor NPN. Ils se ressemblent beaucoup, et nous devons vérifier attentivement leurs étiquettes.

.. image:: img/transistor_symbol.png
    :width: 600

Lorsqu'un signal de niveau haut passe par un transistor NPN, il est activé. Mais un transistor PNP a besoin d'un signal de niveau bas pour fonctionner. Les deux types de transistors sont fréquemment utilisés comme interrupteurs sans contact, comme dans cette expérience.

Placez l'étiquette face à nous et les broches vers le bas. Les broches de gauche à droite sont l'émetteur (e), la base (b) et le collecteur (c).

.. image:: img/ebc.png
    :width: 150

* |link_s8050_datasheet|
* |link_s8550_datasheet|

**Exemple**

* :ref:`basic_relay` (Projet de base)
* :ref:`basic_active_buzzer` (Projet de base)
* :ref:`basic_passive_buzzer` (Projet de base)

