.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et tirages au sort** : Participez à des tirages au sort et des promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_rgb_led:

LED RVB
==========================

Vue d'ensemble
-------------------

Dans cette leçon, nous utiliserons le PWM pour contrôler une LED RVB afin qu'elle clignote en différentes couleurs. Lorsque différentes valeurs PWM sont définies pour les broches R, G et B de la LED, sa luminosité varie. Lorsque les trois couleurs différentes sont mélangées, nous pouvons voir que la LED RVB clignote en différentes couleurs.

Composants requis
-------------------------

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|

PWM
--------

La modulation de largeur d'impulsion, ou PWM, est une technique pour obtenir des résultats analogiques avec des moyens numériques. Le contrôle numérique est utilisé pour créer une onde carrée, un signal basculant entre marche et arrêt. Ce motif marche-arrêt peut simuler des tensions entre marche complète (5 Volts) et arrêt (0 Volts) en changeant la proportion du temps pendant lequel le signal est en marche par rapport au temps pendant lequel le signal est en arrêt. La durée du "temps de marche" est appelée largeur d'impulsion. Pour obtenir des valeurs analogiques variables, vous changez, ou modulez, cette largeur. Si vous répétez ce motif marche-arrêt assez rapidement avec un appareil, une LED par exemple, cela ressemblerait à ceci : le signal est une tension stable entre 0 et 5V contrôlant la luminosité de la LED. (Voir la description du PWM sur le site officiel d'Arduino).

Dans le graphique ci-dessous, les lignes vertes représentent une période régulière. Cette durée ou période est l'inverse de la fréquence PWM. En d'autres termes, avec une fréquence PWM d'environ 500Hz sur Arduino, les lignes vertes mesureraient chacune 2 millisecondes.

.. image:: img/11_rgbled_pwm.jpeg
   :align: center
   :width: 60%


Un appel à analogWrite() se fait sur une échelle de 0 à 255, de sorte que analogWrite(255) demande un cycle de service de 100 % (toujours allumé), et analogWrite(127) est un cycle de service de 50 % (allumé la moitié du temps), par exemple. 

Vous constaterez que plus la valeur PWM est petite, plus la valeur sera petite après conversion en tension. Ensuite, la LED devient plus faible en conséquence. Par conséquent, nous pouvons contrôler la luminosité de la LED en contrôlant la valeur PWM.


Câblage
----------------------

.. image:: img/11-rgb_led_bb.png
    :align: center
    :width: 70%

Schéma de câblage
-----------------------

.. image:: img/11-rgb_led_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``11-rgb_led.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\11-rgb_led`` directement.
    * Ou copiez ce code dans Arduino IDE.

.. literalinclude:: /_code/11_basic_rgb_led.ino
   :language: cpp
   :linenos:
   :caption: 11-rgb_led.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/11_basic_rgb_led.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Une fois le code téléversé avec succès, vous observerez la LED RVB clignoter dans un motif circulaire de rouge, vert et bleu au début. Elle continuera ensuite à clignoter dans l'ordre suivant : rouge, orange, jaune, vert, bleu, indigo et violet.


Analyse du code
--------------------

**Définir la couleur**

Ici, nous utilisons la fonction ``color()`` pour définir la couleur de la LED RVB. Dans le code, elle est configurée pour clignoter en 7 couleurs différentes.

Vous pouvez utiliser l'outil de peinture sur votre ordinateur pour obtenir la valeur RVB.

1. Ouvrez l'outil de peinture sur votre ordinateur et cliquez sur Modifier les couleurs.

   .. image:: img/11_rgbled_color1.png
      :align: center


2. Sélectionnez une couleur, puis vous pourrez voir la valeur RVB de cette couleur. Remplissez-les dans le code.
   
   .. note:: 
      En raison de facteurs matériels et environnementaux, les couleurs affichées sur les écrans d'ordinateur et les LED RVB peuvent varier même en utilisant les mêmes valeurs RVB.

   .. image:: img/11_rgbled_color2.png
      :align: center

   .. raw:: html

      <br/>
   
   .. code-block:: arduino
   
       void loop() // run over and over again
   
       {
   
         // Couleurs de base:
   
         color(255, 0, 0); // allumer la LED RVB en rouge
   
         delay(1000); // délai de 1 seconde
   
         color(0,255, 0); // allumer la LED RVB en vert
   
         delay(1000); // délai de 1 seconde
   
         color(0, 0, 255); // allumer la LED RVB en bleu
   
         delay(1000); // délai de 1 seconde
   
         // Exemples de couleurs mélangées:
   
         color(255,0,252); // allumer la LED RVB en rouge
   
         delay(1000); // délai de 1 seconde
   
         color(237,109,0); // allumer la LED RVB en orange
   
         delay(1000); // délai de 1 seconde
   
         color(255,215,0); // allumer la LED RVB en jaune
   
         ......
   
   
**fonction color()**

.. code-block:: arduino

    void color (int red, int green, int blue)
    // la fonction génératrice de couleur

    {

      analogWrite(redPin, red);

      analogWrite(greenPin, green);

      analogWrite(bluePin, blue);

    }

Définissez trois variables unsigned char, red, green et blue. Écrivez leurs valeurs à ``redPin``, ``greenPin`` et ``bluePin``. Par exemple, color(128,0,128) consiste à écrire 128 à ``redPin``, 0 à ``greenPin`` et 128 à ``bluePin``. Le résultat est la LED clignotant en violet.

**analogWrite()**: Écrit une valeur analogique (onde PWM) sur une broche. Cela n'a rien à voir avec une broche analogique, mais concerne uniquement les broches PWM. Vous n'avez pas besoin d'appeler ``pinMode()`` pour définir la broche comme sortie avant d'appeler ``analogWrite()``.