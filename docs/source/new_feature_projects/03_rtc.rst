.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _new_rtc:

Horloge Temps Réel
========================================

L'horloge temps réel (RTC) est intégrée dans le microcontrôleur de l'UNO R4 WiFi (RA4M1). La RTC est un module d'horloge autonome capable de fonctionner même lorsque l'alimentation principale est déconnectée, grâce à une source d'alimentation de secours telle qu'une batterie. Cela rend la RTC incroyablement polyvalente pour diverses applications telles que la planification de tâches temporisées dans les systèmes domotiques ou l'horodatage des points de données individuels dans les applications de journalisation des données.

.. note::
    L'UNO R4 WiFi dispose d'une broche VRTC qui maintient le fonctionnement de la RTC intégrée même lorsque la carte perd de l'alimentation. Pour utiliser cette fonctionnalité, appliquez une tension entre 1,6 et 3,6 V à la broche VRTC.


Tâches Répétitives Planifiées
++++++++++++++++++++++++++++++++++++++++++++

Dans certains cas d'utilisation, vous pouvez avoir besoin d'exécuter des tâches spécifiques à intervalles réguliers. Pour établir des interruptions périodiques, vous devrez d'abord initialiser une fonction de rappel périodique. Voici un exemple de code Arduino qui utilise une interruption périodique pour faire clignoter une LED toutes les 2 secondes.


**Télécharger le code**

Ouvrez le fichier ``03-rtc.ino`` situé dans ``elite-explorer-kit-main\r4_new_feature\03-rtc``, ou collez le code suivant dans votre IDE Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Explication du code**

1. Initialisation des composants et bibliothèques

   .. code-block:: arduino
   
     #include "RTC.h"
     volatile bool irqFlag = false;
     bool ledState = false;
     const int led = LED_BUILTIN;
   
     void setup() {
       pinMode(led, OUTPUT);
       Serial.begin(9600);
       RTC.begin();
     }
   
   - ``#include "RTC.h"``: Inclut la bibliothèque RTC.
   - ``volatile bool irqFlag = false;``: Déclare un drapeau booléen volatile. ``volatile`` garantit que la variable peut être correctement accédée ou modifiée par une interruption. Pour plus de détails sur ``volatile``, consultez la `documentation Arduino sur volatile <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_.
   - ``bool ledState = false;``: Déclare une variable booléenne pour suivre l'état de la LED.
   - ``const int led = LED_BUILTIN;``: Déclare une constante pour la broche de la LED intégrée.
   - ``pinMode(led, OUTPUT);``: Définit la broche de la LED comme sortie.
   - ``Serial.begin(9600);``: Initialise la communication série à 9600 bauds.
   - ``RTC.begin();``: Initialise la RTC.

   .. raw:: html
    
        <br/>

2. Configuration de l'horloge temps réel

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: Crée un objet ``RTCTime`` et l'initialise avec une date et une heure spécifiques.
   - ``RTC.setTime(mytime);``: Définit la RTC avec l'heure initialisée.
   
   Configuration et vérification de la fonction de rappel périodique
   
   .. code-block:: arduino
   
     if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
       Serial.println("ERROR: periodic callback not set");
     }
   
     void loop() {
       if (irqFlag) {
         Serial.println("Timed CallBack");
         ledState = !ledState;
         digitalWrite(led, ledState);
         irqFlag = false;
       }
     }
   
     void periodicCallback() {
       irqFlag = true;
     }
   
   - ``RTC.setPeriodicCallback(...);``: Définit un rappel périodique pour se déclencher toutes les 2 secondes. La période peut être spécifiée en utilisant les énumérations suivantes :

      - ``ONCE_EVERY_2_SEC``
      - ``ONCE_EVERY_1_SEC``
      - ``N2_TIMES_EVERY_SEC``
      - ``N4_TIMES_EVERY_SEC``
      - ``N8_TIMES_EVERY_SEC``
      - ``N16_TIMES_EVERY_SEC``
      - ``N32_TIMES_EVERY_SEC``
      - ``N64_TIMES_EVERY_SEC``
      - ``N128_TIMES_EVERY_SEC``
      - ``N256_TIMES_EVERY_SEC``

   - ``void loop() {...}``: Vérifie si le rappel a été déclenché. Si c'est le cas, bascule l'état de la LED.
   - ``void periodicCallback() {...}``: La fonction de rappel définit ``irqFlag = true`` lorsqu'elle est déclenchée.


**Référence**

- |link_r4_rtc|