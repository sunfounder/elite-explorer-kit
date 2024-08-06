.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_plant_monitor:

Monitor per Piante
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/08_fun_plant_monitor.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo progetto irriga automaticamente le piante attivando una pompa dell'acqua quando l'umidità del suolo scende sotto una soglia specifica.
Inoltre, visualizza temperatura, umidità e umidità del suolo su uno schermo LCD, fornendo agli utenti informazioni sull'ambiente di crescita della pianta.

**Componenti Necessari**

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

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|
    *   - :ref:`cpn_power`
        - \-

**Collegamenti**

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/08_plant_monitor_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/08_plant_monitor_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**Codice**

.. note::

    * Puoi aprire il file ``08_plant_monitor.ino`` nel percorso ``elite-explorer-kit-main\fun_project\08_plant_monitor`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
   Per installare la libreria, usa l'Arduino Library Manager e cerca **"DHT sensor library"** e **"LiquidCrystal I2C"** e installale.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/a9d6c9c7-0d7f-4dc2-84b6-9dbda15c89ae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

Ecco una spiegazione dettagliata del codice:

1. Inclusione delle Librerie e Definizioni di Costanti/Variabili:

   Importa le librerie ``Wire.h``, ``LiquidCrystal_I2C.h`` e ``DHT.h``.
   Definisci i numeri dei pin e altri parametri relativi al DHT11, al sensore di umidità del suolo e alla pompa dell'acqua.

2. ``setup()``:

   Inizializza le modalità dei pin relativi al sensore di umidità del suolo e alla pompa dell'acqua.
   Spegni inizialmente la pompa dell'acqua.
   Inizializza il display LCD e accendi la retroilluminazione.
   Avvia il sensore DHT.

3. ``loop()``:

   Leggi l'umidità e la temperatura dal sensore DHT.
   Leggi l'umidità del suolo dal sensore di umidità del suolo.
   Visualizza i valori di temperatura e umidità sullo schermo LCD, poi cancella lo schermo e visualizza il valore di umidità del suolo.
   Determina se attivare la pompa dell'acqua in base all'umidità del suolo. Se l'umidità del suolo è inferiore a 500 (una soglia configurabile), attiva la pompa dell'acqua per 1 secondo.

