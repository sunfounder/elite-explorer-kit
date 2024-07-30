.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_resistor:

Résistance
===============

.. image:: img/resistor.png
    :width: 300

Une résistance est un élément électronique qui peut limiter le courant dans une branche. 
Une résistance fixe est un type de résistance dont la valeur ne peut pas être changée, tandis que celle d'un potentiomètre ou d'une résistance variable peut être ajustée. 

Voici deux symboles de circuit généralement utilisés pour une résistance. Normalement, la valeur de la résistance est marquée dessus. Donc, si vous voyez ces symboles dans un circuit, cela représente une résistance. 

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** est l'unité de résistance, et les unités plus grandes incluent KΩ, MΩ, etc. 
Leur relation peut être montrée comme suit : 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalement, la valeur de la résistance est marquée dessus. 

Lors de l'utilisation d'une résistance, nous devons d'abord connaître sa valeur. Voici deux méthodes : vous pouvez observer les bandes sur la résistance ou utiliser un multimètre pour mesurer la résistance. Il est recommandé d'utiliser la première méthode car elle est plus pratique et plus rapide. 

.. image:: img/resistance_card.jpg

Comme montré sur la carte, chaque couleur représente un chiffre. 

.. list-table::

   * - Noir
     - Marron
     - Rouge
     - Orange
     - Jaune
     - Vert
     - Bleu
     - Violet
     - Gris
     - Blanc
     - Or
     - Argent
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Les résistances à 4 et 5 bandes sont fréquemment utilisées, elles comportent respectivement 4 et 5 bandes colorées. 

Normalement, lorsque vous obtenez une résistance, vous pouvez trouver difficile de décider par quel bout commencer pour lire la couleur. 
L'astuce est que l'écart entre la 4e et la 5e bande sera relativement plus grand.

Par conséquent, vous pouvez observer l'écart entre les deux bandes colorées à une extrémité de la résistance ; 
s'il est plus grand que tous les autres écarts entre les bandes, alors vous pouvez lire de l'autre côté. 

Voyons comment lire la valeur de la résistance d'une résistance à 5 bandes comme montré ci-dessous.

.. image:: img/220ohm.jpg
    :width: 500

Donc, pour cette résistance, la valeur doit être lue de gauche à droite. 
La valeur doit être au format suivant : 1ère Bande 2e Bande 3e Bande x 10^Multiplicateur (Ω) et la tolérance permise est de ±Tolerance%. 
Ainsi, la valeur de cette résistance est de 2(rouge) 2(rouge) 0(noir) x 10^0(noir) Ω = 220 Ω, 
et la tolérance permise est de ± 1% (marron). 

.. list-table:: Couleurs de bande courantes des résistances
    :header-rows: 1

    * - Résistance 
      - Bande de couleur  
    * - 10Ω   
      - marron noir noir argent marron
    * - 100Ω   
      - marron noir noir noir marron
    * - 220Ω 
      - rouge rouge noir noir marron
    * - 330Ω 
      - orange orange noir noir marron
    * - 1kΩ 
      - marron noir noir marron marron
    * - 2kΩ 
      - rouge noir noir marron marron
    * - 5.1kΩ 
      - vert marron noir marron marron
    * - 10kΩ 
      - marron noir noir rouge marron 
    * - 100kΩ 
      - marron noir noir orange marron 
    * - 1MΩ 
      - marron noir noir vert marron 

Vous pouvez en apprendre plus sur les résistances sur Wiki : `Résistance - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

