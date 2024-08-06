.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_i2c_lcd1602:

I2C LCD1602
==========================

.. https://docs.sunfounder.com/projects/sensorkit-v2-arduino/en/latest/lesson_1.html

Panoramica
---------------

In questa lezione, imparerai a conoscere i display a cristalli liquidi (LCD) con interfaccia I2C. Questi tipi di LCD sono ampiamente utilizzati in una varietà di dispositivi elettronici, come orologi digitali, forni a microonde, cruscotti delle automobili e persino apparecchiature industriali. L'interfaccia I2C semplifica il cablaggio e le connessioni, rendendola più conveniente ed efficiente per hobbisti e professionisti.

Componenti Necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE DEI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Cablaggio
----------------------

.. image:: img/14-i2c_lcd_bb.png
    :align: center
    :width: 100%

Schema Elettrico
-----------------------

.. image:: img/14-i2c_lcd_schematic.png
    :align: center
    :width: 80%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``14-i2c_lcd.ino`` nel percorso ``elite-explorer-kit-main\basic_project\14-i2c_lcd``.
    * Oppure copia questo codice nell'Arduino IDE.

.. note:: 
    Per installare la libreria, utilizza l'Arduino Library Manager e cerca **"LiquidCrystal I2C"** e installala.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/096326ad-eccf-4d2e-be52-66f4819ca7d8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Dopo aver caricato correttamente il codice sull'Arduino, il display a cristalli liquidi (LCD) mostrerà il messaggio "Hello world!" sulla sua prima linea e "LCD Tutorial" sulla seconda linea.

.. note::
    Se l'LCD non visualizza alcun carattere dopo aver caricato il codice, puoi regolare il contrasto ruotando il potenziometro sul modulo I2C fino a quando l'LCD funziona correttamente.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/14_basic_i2c_lcd_2.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analisi del Codice
------------------------

1. Inclusione della Libreria e Inizializzazione dell'LCD:
   La libreria LiquidCrystal I2C è inclusa per fornire funzioni e metodi per l'interfacciamento con l'LCD. Successivamente, viene creato un oggetto LCD utilizzando la classe LiquidCrystal_I2C, specificando l'indirizzo I2C, il numero di colonne e il numero di righe.

   .. note:: 
      Per installare la libreria, utilizza l'Arduino Library Manager e cerca **"LiquidCrystal I2C"** e installala.

   .. code-block:: arduino

      #include <LiquidCrystal_I2C.h>
      LiquidCrystal_I2C lcd(0x27, 16, 2);

2. Funzione Setup:
   La funzione ``setup()`` viene eseguita una volta quando l'Arduino si avvia. In questa funzione, l'LCD viene inizializzato, cancellato e la retroilluminazione viene accesa. Successivamente, vengono visualizzati due messaggi sull'LCD.

   .. code-block:: arduino

      void setup() {
        lcd.init();       // inizializza l'LCD
        lcd.clear();      // cancella il display LCD
        lcd.backlight();  // accendi la retroilluminazione
      
        // Stampa un messaggio su entrambe le linee dell'LCD.
        lcd.setCursor(2, 0);  //Imposta il cursore sul carattere 2 della linea 0
        lcd.print("Hello world!");
      
        lcd.setCursor(2, 1);  //Sposta il cursore sul carattere 2 della linea 1
        lcd.print("LCD Tutorial");
      }
