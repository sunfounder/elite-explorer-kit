.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !
    
.. _update_firmware:

Mettre à jour le firmware du module radio sur votre carte UNO R4 WiFi
=============================================================================

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. Connectez la carte UNO R4 WiFi à votre ordinateur avec le câble USB.
2. Si vous avez l'IDE Arduino Serial Monitor ou Serial Plotter en cours d'exécution, fermez-les.

   Vous pouvez fermer le moniteur série en cliquant sur l'icône X qui apparaît sur son onglet lorsqu'il est sélectionné :

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. Sélectionnez Outils > Mise à jour du firmware dans les menus de l'IDE Arduino.
   La boîte de dialogue "Mise à jour du firmware" s'ouvrira.

   .. image:: img/update_firmware_1.png
         :width: 70%

4. Sélectionnez l'UNO R4 WiFi dans le menu "Sélectionner la carte" de la boîte de dialogue "Mise à jour du firmware".
5. Cliquez sur le bouton "VÉRIFIER LES MISES À JOUR".
   Un bouton "INSTALLER" sera ajouté à la boîte de dialogue.

   .. image:: img/update_firmware_2.png
         :width: 85%

6. Cliquez sur le bouton "INSTALLER".
   Un processus d'installation du firmware commencera, comme indiqué par le message en bas de la boîte de dialogue.

   .. image:: img/update_firmware_3.png
         :width: 85%

7. Attendez la fin du processus de mise à jour du firmware, comme indiqué par le message dans la boîte de dialogue :
   Firmware installé avec succès.

   .. image:: img/update_firmware_4.png
         :width: 85%

8. Cliquez sur l'icône X dans la boîte de dialogue.
   La boîte de dialogue se fermera.
9. Déconnectez le câble USB de la carte UNO R4 WiFi de votre ordinateur.
10. Reconnectez la carte UNO R4 WiFi à votre ordinateur avec le câble USB.


**Référence**

- |link_update_firmware|