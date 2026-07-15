.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_light_array:

Array sensible à la lumière
==========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/04_fun_lightarray.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Ce programme convertit les lectures d'une résistance dépendante de la lumière en un nombre correspondant de lumières LED allumées, créant ainsi un indicateur simple de la luminosité.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Câblage**

.. image:: img/04_light_sensitive_array_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schéma**

.. image:: img/04_light_sensitive_array_schematic.png
   :width: 60%

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``04_light_sensitive_array.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\04_light_sensitive_array`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. literalinclude:: /_code/04_fun_light_array.ino
   :language: cpp
   :linenos:
   :caption: 04_light_sensitive_array.ino

**Comment ça marche ?**

Voici une explication détaillée du code :

1. Définitions des constantes et des variables :

   ``NbrLEDs`` : Définit la présence de 8 LEDs.
   ``ledPins[]`` : Les LEDs sont connectées aux broches 5 à 12 de l'Arduino.
   ``photocellPin`` : La photorésistance est connectée à la broche A0 de l'Arduino.
   ``sensorValue`` : Cette variable stocke la valeur lue de la photorésistance.
   ``ledLevel`` : Cette variable stocke le nombre de LEDs allumées en fonction de la conversion de sensorValue.

2. ``setup()`` :

   Configure les broches 5 à 12 comme sorties pour contrôler les LEDs.

3. ``loop()`` :

   Lit la valeur analogique de la photorésistance à partir de la broche A0, généralement comprise entre 0 et 1023.
   Utilise la fonction map pour convertir la valeur de la photorésistance de la plage 300-1023 à la plage 0-8.
   Cela signifie que si la lecture de la photorésistance est de 300, aucune LED ne s'allumera ; si la lecture est de 1023 ou plus, les 8 LEDs s'allumeront.
   
   La boucle suivante vérifie chaque LED. Si son index est inférieur à ledLevel, la LED s'allumera ; sinon, elle s'éteindra.

