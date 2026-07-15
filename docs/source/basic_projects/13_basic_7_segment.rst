.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_7segment:

Afficheur 7 segments
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/7_segment_display_uno.html#segmeng-uno

Vue d'ensemble
-------------------

Un afficheur 7 segments est un dispositif capable d'afficher des chiffres et des lettres. Il est composé de sept LED connectées en parallèle. Différentes lettres/chiffres peuvent être affichés en connectant les broches de l'afficheur à la source d'alimentation et en activant les broches correspondantes, allumant ainsi les segments LED correspondants. Dans cette leçon, apprenons à afficher des caractères spécifiques.

Composants requis
------------------------

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

Câblage
----------------------

.. image:: img/13-7_segment_display_bb.png
    :align: center
    :width: 70%


Schéma de câblage
------------------------

Dans cette expérience, connectez chaque broche a-g de l'afficheur 7 segments à une résistance de limitation de courant de 1000 ohms respectivement, puis aux broches 4-11. GND se connecte à GND. En programmant, nous pouvons définir une ou plusieurs des broches 4-11 en niveau haut pour allumer les LED correspondantes.

.. image:: img/13-7_segment_display_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``13-7_segment.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\13-7_segment`` directement.
    * Ou copiez ce code dans Arduino IDE.


.. literalinclude:: /_code/13_basic_7_segment.ino
   :language: cpp
   :linenos:
   :caption: 13-7_segment.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/13_basic_7_segment.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analyse du code
----------------------

Le code peut sembler un peu long pour cette expérience. Mais la syntaxe est simple. Jetons un coup d'œil.

**Appeler la fonction dans loop()**

.. code-block:: arduino

   digital_1(); //afficher 1 sur le 7 segments

   delay(1000); //attendre une seconde

   digital_2(); //afficher 2 sur le 7 segments

   delay(1000); //attendre une seconde

   digital_3(); //afficher 3 sur le 7 segments

   delay(1000); //attendre une seconde

   digital_4(); //afficher 4 sur le 7 segments


Appeler ces fonctions dans la loop() permet d'afficher 0-F sur l'afficheur 7 segments. Les fonctions sont montrées ci-dessous. Prenons ``digital_2()`` comme exemple :

**Analyse détaillée de digital_2()**

.. code-block:: arduino

   void digital_2()  //afficher 2 sur le 7 segments
   {
     turnOffAllSegments();
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(g, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(d, HIGH);
   }

.. image:: img/13_7segment.jpeg
   :align: center

Tout d'abord, nous devons comprendre comment le chiffre **2** apparaît sur l'afficheur 7 segments. Cela est réalisé en alimentant les segments a, b, d, e et g. En programmation, les broches connectées à ces segments sont définies à un niveau haut tandis que c et f sont définies à un niveau bas. Nous commençons par utiliser la fonction ``turnOffAllSegments()`` pour éteindre tous les segments puis allumer ceux requis.


Après avoir exécuté cette partie, l'afficheur 7 segments affichera **2**. De même, l'affichage d'autres caractères se fait de la même manière. Étant donné que les lettres B et D en majuscules, c'est-à-dire **B** et **D**, ressembleraient à **8** et **0** sur l'afficheur, elles sont affichées en minuscules à la place.
