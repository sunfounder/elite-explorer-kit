.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_thermistor:

Thermistance
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Une thermistance est un type de résistance dont la résistance dépend fortement de la température, bien plus que les résistances standard. Le mot est une combinaison de "thermique" et "résistance". Les thermistances sont largement utilisées comme limiteurs de courant d'appel, capteurs de température (de type à coefficient de température négatif ou NTC), protecteurs de surintensité auto-réarmables et éléments chauffants auto-régulants (de type à coefficient de température positif ou PTC).

* |link_thermistor_wikipedia|

Voici le symbole électronique de la thermistance.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Les thermistances sont de deux types fondamentaux opposés :

* Avec les thermistances NTC, la résistance diminue à mesure que la température augmente, généralement en raison d'une augmentation des électrons de conduction provoquée par l'agitation thermique de la bande de valence. Un NTC est couramment utilisé comme capteur de température ou en série avec un circuit comme limiteur de courant d'appel.
* Avec les thermistances PTC, la résistance augmente à mesure que la température augmente, généralement en raison des agitations thermiques du réseau, en particulier celles des impuretés et des imperfections. Les thermistances PTC sont couramment installées en série avec un circuit et utilisées pour protéger contre les conditions de surintensité, comme des fusibles réarmables.

Dans ce kit, nous utilisons une thermistance NTC. Chaque thermistance a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Voici la relation entre la résistance et la température :

    RT = RN * expB(1/TK – 1/TN)   

* **RT** est la résistance de la thermistance NTC lorsque la température est TK. 
* **RN** est la résistance de la thermistance NTC sous la température nominale TN. Ici, la valeur numérique de RN est de 10k.
* **TK** est une température en Kelvin et l'unité est K. Ici, la valeur numérique de TK est de 273,15 + degré Celsius.
* **TN** est une température en Kelvin nominale ; l'unité est également K. Ici, la valeur numérique de TN est de 273,15+25.
* Et **B(beta)**, la constante matérielle de la thermistance NTC, est également appelée indice de sensibilité thermique avec une valeur numérique de 3950.
* **exp** est l'abréviation de exponentiel, et le nombre de base e est un nombre naturel et vaut environ 2,7.  

Convertissez cette formule TK=1/(ln(RT/RN)/B+1/TN) pour obtenir la température en Kelvin qui, moins 273,15, donne les degrés Celsius.

Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage efficace.

**Exemple**

* :ref:`basic_thermistor` (Projet de base)
* :ref:`fun_smart_fan` (Projet amusant)
