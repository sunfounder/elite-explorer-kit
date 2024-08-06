.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_light_array:

Array Sensibile alla Luce
==========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/04_fun_lightarray.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo programma converte le letture di un fotoresistore in un numero corrispondente di LED illuminati, creando un semplice indicatore di luminosità.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|


**Collegamenti**

.. image:: img/04_light_sensitive_array_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/04_light_sensitive_array_schematic.png
   :width: 60%

**Codice**

.. note::

    * Puoi aprire il file ``04_light_sensitive_array.ino`` nel percorso ``elite-explorer-kit-main\fun_project\04_light_sensitive_array`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9da7af57-c002-41a0-bc84-372e91885d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

Ecco una spiegazione passo-passo del codice:

1. Definizioni di Costanti e Variabili:

   ``NbrLEDs``: Definisce la presenza di 8 LED.
   ``ledPins[]``: I LED sono collegati ai pin 5-12 di Arduino.
   ``photocellPin``: Il fotoresistore è collegato al pin A0 di Arduino.
   ``sensorValue``: Questa variabile memorizza il valore letto dal fotoresistore.
   ``ledLevel``: Questa variabile memorizza il numero di LED accesi in base alla conversione del valore del sensore.

2. ``setup()``:

   Configura i pin 5-12 come output per controllare i LED.

3. ``loop()``:

   Legge il valore analogico del fotoresistore dal pin A0, generalmente compreso tra 0 e 1023.
   Usa la funzione map per mappare il valore del fotoresistore da un intervallo di 300-1023 a un intervallo di 0-8.
   Questo significa che se la lettura dal fotoresistore è 300, nessun LED sarà acceso;
   se la lettura è 1023 o superiore, tutti gli 8 LED saranno accesi.
   
   Il successivo ciclo for controlla ogni LED. Se l'indice è inferiore a ledLevel,
   il LED sarà acceso; altrimenti, sarà spento.

