.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _new_hid:

USB HID
========================================

L'Arduino Uno R4 WiFi n'est pas seulement une puissante carte de développement ; elle prend également en charge les dispositifs d'interface humaine (HID). Cela vous permet d'utiliser la carte pour émuler des dispositifs tels que des souris et des claviers, ajoutant un nouveau niveau d'interactivité à vos projets.

Les HID, ou dispositifs d'interface humaine, sont une catégorie de dispositifs informatiques conçus pour une interaction directe avec les humains, généralement à des fins d'entrée. Cette catégorie comprend des dispositifs tels que les claviers, les souris et les manettes de jeu. Avec l'Arduino Uno R4 WiFi, vous pouvez émuler ces dispositifs, ouvrant ainsi un monde de possibilités pour les projets DIY.

Contrôle de la souris
----------------------------

Contrôler une souris avec l'Arduino Uno R4 WiFi est simple. En utilisant la commande ``Mouse.move(x,y)``, vous pouvez facilement contrôler le mouvement de la souris. Lors de la mise à jour de la position du curseur, celle-ci est toujours relative à la position précédente du curseur.

Voici un exemple simple qui démontre le contrôle du curseur de la souris à l'aide d'un bouton.

**Schéma du circuit**

.. image:: img/05_hid_1_bb.png
  :width: 70%
  :align: center

**Téléchargez le code**

Ouvrez le fichier ``05-hid_mouse.ino`` situé dans ``elite-explorer-kit-main\r4_new_feature\05-hid_mouse``, ou collez le code suivant dans votre IDE Arduino.

.. warning::
    Lorsque vous utilisez la commande ``Mouse.move()``, l'Arduino prend le contrôle de la souris de votre ordinateur ! Pour vous assurer de ne pas perdre le contrôle de votre ordinateur lors de l'exécution d'un sketch avec cette fonction, assurez-vous de mettre en place un système de contrôle fiable avant d'appeler ``Mouse.move()``. Ce sketch inclut un bouton-poussoir pour activer la souris, de sorte qu'elle ne fonctionne qu'après avoir appuyé sur le bouton.

.. warning:: 
    En raison de l'architecture multiprocesseur de la carte UNO R4 WiFi, vous pouvez rencontrer des erreurs **"No device found on..."** lors du téléchargement de code utilisant les fonctionnalités HID.
    
    Pour télécharger dans de telles circonstances, suivez ces étapes :
    
    1. Appuyez rapidement deux fois sur le bouton "RESET" de la carte. La LED marquée "L" devrait commencer à clignoter.
    
    2. Dans le menu de l'IDE Arduino, sélectionnez le port de la carte. Le port peut changer après la réinitialisation, alors assurez-vous qu'il est correctement sélectionné.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/4b72e0f4-57cb-4627-b728-10a16f61d15c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

En plus de contrôler le mouvement de la souris, vous pouvez également gérer les clics de la souris. Pour plus de détails, consultez |link_r4_usb_mouse|.

.. _new_hid_keyboard:

Contrôle du clavier
---------------------------

L'Arduino Uno R4 WiFi offre également des capacités d'émulation de clavier. Il vous permet d'envoyer non seulement des pressions de touches individuelles mais aussi d'exécuter des combinaisons de touches complexes.

.. warning::
   Lorsque vous utilisez la commande ``Keyboard.print()``, l'Arduino prend le contrôle du clavier de votre ordinateur ! Pour vous assurer de ne pas perdre le contrôle de votre ordinateur lors de l'exécution d'un sketch avec cette fonction, assurez-vous de mettre en place un système de contrôle fiable avant d'appeler ``Keyboard.print()``. Ce sketch inclut un bouton-poussoir pour activer le clavier, de sorte qu'il ne fonctionne qu'après avoir appuyé sur le bouton.

**Exemple de code pour envoyer des raccourcis clavier**
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Dans cet exemple, l'Arduino Uno R4 WiFi est configuré pour émuler deux raccourcis clavier fréquemment utilisés : "Ctrl+C" pour copier et "Ctrl+V" pour coller. Deux boutons physiques connectés à l'Arduino servent de déclencheurs. Le bouton connecté à la broche 7 initie l'action de copie, tandis que celui connecté à la broche 8 déclenche l'action de collage.

En appuyant sur l'un des boutons, l'Arduino utilise les fonctions ``Keyboard.press()`` et ``Keyboard.releaseAll()`` pour imiter les raccourcis clavier respectifs. Cet exemple illustre comment vous pouvez concevoir une interface matérielle dédiée pour des tâches spécifiques, facilitant les actions répétitives sans l'intervention du clavier. Cela pourrait être particulièrement avantageux dans les environnements de travail nécessitant une manipulation rapide des données ou dans les configurations d'accessibilité qui bénéficient de contrôles simplifiés.

**Schéma du circuit**

.. image:: img/05_hid_2_bb.png
  :width: 70%
  :align: center

**Téléchargez le code**

Ouvrez le fichier ``05-hid_keyboard.ino`` situé dans ``elite-explorer-kit-main\r4_new_feature\05-hid_keyboard``, ou collez le code suivant dans votre IDE Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/2a5b61d3-d5d6-4c78-a3a0-73880fa1fb57/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Précautions et conseils
----------------------------------

1. **Note de prudence sur les bibliothèques de souris et de clavier** : Si la bibliothèque Mouse ou Keyboard fonctionne en continu, elle peut interférer avec la programmation de votre carte. Les fonctions comme ``Mouse.move()`` et ``Keyboard.print()`` prendront le contrôle de votre ordinateur connecté et ne doivent être invoquées que lorsque vous êtes prêt à les gérer. Il est conseillé d'utiliser un système de contrôle, tel qu'un interrupteur physique ou des contrôles d'entrée spécifiques, pour activer ou désactiver cette fonctionnalité.

2. **Si vous rencontrez des problèmes de téléchargement de code** : En raison de l'architecture multiprocesseur de la carte UNO R4 WiFi, vous pouvez rencontrer des erreurs ``"No device found on..."`` lors du téléchargement de code utilisant les fonctionnalités HID.

   Pour télécharger dans de telles circonstances, suivez ces étapes :
   
   1. Appuyez rapidement deux fois sur le bouton "RESET" de la carte. La LED marquée "L" devrait commencer à clignoter.
   
   2. Dans le menu de l'IDE Arduino, sélectionnez le port de la carte. Le port peut changer après la réinitialisation, alors assurez-vous qu'il est correctement sélectionné.




**Référence**

- |link_r4_usb_hid|
- |link_r4_usb_mouse|
- |link_r4_usb_keyboard|
