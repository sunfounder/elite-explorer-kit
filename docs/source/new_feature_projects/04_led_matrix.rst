.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _new_led_matrix:

Matrice LED 12x8
========================================

L'Arduino UNO R4 WiFi est équipé d'une matrice LED 12x8 intégrée, programmable pour afficher une variété de graphiques, animations, servir d'interface ou même faciliter les expériences de jeu.

.. image:: img/unor4wifi.webp
    :width: 60%

Dans ce guide, nous vous proposons un exemple simple pour vous aider à afficher le motif de votre choix sur la matrice LED.

Comment stocker les données de la matrice LED dans Arduino
-------------------------------------------------------------------

Pour utiliser la matrice LED, vous aurez besoin de la bibliothèque ``Arduino_LED_Matrix``, installée avec le cœur Renesas.

La bibliothèque LED Matrix pour l'UNO R4 WiFi fonctionne en créant et en chargeant des cadres dans un tampon pour les afficher. Un cadre, également appelé "image", représente ce qui est actuellement affiché sur la matrice. Dans une animation composée de plusieurs images, chaque image est considérée comme un cadre.

Pour contrôler la matrice LED 12x8 sur l'UNO R4 WiFi, un minimum de 96 bits d'espace mémoire est requis. La bibliothèque propose deux approches pour cela.

**Une approche utilise un tableau à deux dimensions**, avec des zéros et des uns pour indiquer si la LED correspondante est éteinte ou allumée. Chaque numéro correspond à une LED sur la matrice LED. Le tableau suivant illustre un motif en forme de cœur.

.. code-block:: arduino
   
   // Utiliser un tableau à deux dimensions pour représenter une matrice LED 12x8.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**Une autre approche utilise un tableau d'entiers 32 bits** pour maintenir l'état de la matrice LED. Cette méthode est plus compacte mais légèrement plus complexe. Chaque ``unsigned long`` stocke 32 bits. Ainsi, pour une matrice LED 12x8, qui contient 96 LED, vous aurez besoin d'au moins trois variables ``unsigned long``.

1. Chaque ``unsigned long`` contient 32 bits, et vous pouvez considérer ces bits comme l'état d'une certaine partie de la matrice LED.
2. Ces variables ``unsigned long`` forment un tableau qui encapsule l'état complet de la matrice LED.

Voici un extrait de code utilisant trois variables `unsigned long` pour représenter une matrice LED 12x8.

.. code-block:: arduino

   // Utiliser un tableau d'entiers 32 bits pour stocker la matrice LED.
   unsigned long frame[] = {
     0x3184a444, // État des 32 premières LED
     0x42081100, // État des 32 LED suivantes
     0xa0040000  // État des 32 dernières LED
   };

Pour mieux visualiser l'état des LED, ces valeurs peuvent être converties en forme binaire, où chaque bit représente séquentiellement l'état de chaque LED de gauche à droite et de haut en bas. Un 0 indique éteint, et un 1 indique allumé.

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

Afficher le motif sur la matrice LED
-----------------------------------------

Une fois votre motif prêt, l'étape suivante consiste à transmettre ces données à la matrice LED 12x8. Cela implique généralement d'invoquer les fonctions de la bibliothèque et de passer le tableau ou les variables contenant les états des LED à ces fonctions.

1. Utiliser un tableau à deux dimensions

   Pour afficher le motif stocké dans un tableau 2D, vous pouvez utiliser le code suivant :
   
   .. code-block:: arduino
   
      #include <Arduino_LED_Matrix.h>
   
      ArduinoLEDMatrix matrix;
   
      // Tableau 2D prédéfini
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };
   
      void setup() {
        // Initialiser la matrice LED
        matrix.begin();
      }
   
      void loop() {
        // Afficher le motif sur la matrice LED
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }
   
   Dans ce code, nous utilisons la fonction ``matrix.renderBitmap(frame, 8, 12);`` pour afficher la matrice LED. Ici, 8 et 12 représentent respectivement les lignes et les colonnes de la matrice LED.

2. Utiliser un tableau d'entiers 32 bits
   
   Pour afficher le motif stocké dans un tableau de ``unsigned long``, utilisez le code suivant :
   
   .. code-block:: arduino
   
      #include "Arduino_LED_Matrix.h"
      
      ArduinoLEDMatrix matrix;
      
      void setup() {
        matrix.begin();
      }
      
      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };
        
      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }
   
   Dans ce cas, nous devons utiliser la fonction ``matrix.loadFrame(heart)`` pour afficher le motif sur la matrice LED.


Éditeur de matrice LED Arduino
-----------------------------------------

Je recommande d'utiliser un tableau ``unsigned long`` pour stocker l'état de la matrice LED, car cela permet d'économiser de la mémoire sur l'Arduino. Bien que cette méthode puisse ne pas être très intuitive, vous pouvez utiliser l'|link_led_matrix_editor| comme aide, qui vous aide à générer un tableau ``unsigned long``. 

Avec l'|link_led_matrix_editor| et la bibliothèque ``Arduino_LED_Matrix``, vous pouvez créer facilement des icônes ou des animations et les afficher sur la carte UNO R4 WiFi. Tout ce que vous avez à faire est de dessiner, de télécharger le fichier ``.h`` et d'appeler la fonction ``matrix.play()`` dans votre sketch pour réaliser facilement votre prochain projet.



#. Ouvrez l'éditeur de matrice LED

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. Dessinez votre motif sur la toile centrale

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. Définissez l'intervalle des cadres en millisecondes

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. Vous pouvez créer un nouveau cadre vierge ou copier et créer un nouveau cadre à partir du cadre actuel.

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. Exportez le fichier d'en-tête ``.h``

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   Après avoir cliqué sur OK, vous recevrez un fichier nommé ``animation.h``.


Afficher des animations
-----------------------------------------

Dans les étapes précédentes, nous avons obtenu un fichier ``.h`` qui stocke une série de cadres ainsi que leurs durées. Ensuite, affichons-les sur la matrice LED.

#. Tout d'abord, créez un sketch. Vous pouvez soit ouvrir le fichier ``04-led_matrix.ino`` situé sous le chemin ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, soit copier ce code dans l'IDE Arduino.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/f3712371-7c3d-4a4b-bd98-f74fe43269ed/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Si vous utilisez le code du chemin ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, vous trouverez un onglet nommé ``animation.h`` dans l'IDE Arduino. Ouvrez-le et remplacez le code existant par le fichier .h que vous avez obtenu sur le site.

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. Si vous avez créé votre propre sketch, vous devez copier le fichier ``.h`` obtenu sur la page web dans le même répertoire que le sketch.

#. Après avoir configuré votre code préféré dans l'IDE Arduino et l'avoir téléchargé sur votre Arduino UNO R4 WiFi, votre matrice LED devrait maintenant afficher le motif que vous avez défini.

   .. raw:: html
   
      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         Votre navigateur ne supporte pas la balise vidéo.
      </video>

   Félicitations ! Vous avez programmé avec succès la matrice LED 12x8 de votre Arduino UNO R4 WiFi !


**Référence**

- |link_r4_led|

**Plus de projets**

* :ref:`fun_snake` (Projet amusant)
