.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_smart_fan:

Ventilatore Intelligente
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/06_fun_smartfan.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo progetto Arduino regola automaticamente la velocità del ventilatore per mantenere la temperatura entro un intervallo adeguato.
Inoltre, gli utenti possono entrare in modalità manuale tramite un pulsante per far funzionare il ventilatore alla massima velocità.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-

**Collegamenti**

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/06_smart_fan_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/06_smart_fan_schematic.png
   :width: 80%
   :align: center

**Codice**

.. note::

    * Puoi aprire il file ``06_smart_fan.ino`` nel percorso ``elite-explorer-kit-main\fun_project\06_smart_fan`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ba484912-14d6-4125-83a0-73a107904144/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come funziona?**

Ecco una spiegazione passo-passo del codice:

1. Definizioni di Costanti e Variabili:

   Usa ``#define`` per definire i pin per vari collegamenti hardware.
   ``TEMP_THRESHOLD`` è definito come 25°C, che è la soglia di temperatura per avviare il ventilatore.
   ``manualMode``: Una variabile booleana che indica se è in modalità manuale.

2. ``setup()``:

   Imposta la modalità per i pin rilevanti (output, input, input con pull-up).
   Inizialmente impostato su modalità automatica, quindi ``LED_AUTO`` è acceso mentre ``LED_MANUAL`` è spento.

3. ``loop()``:

   Monitora lo stato del pulsante. Quando il pulsante viene premuto, cambia modalità e cambia lo stato del LED.
   In modalità manuale, il ventilatore funziona alla massima velocità.
   In modalità automatica, il codice legge prima il valore di tensione dal sensore di temperatura e lo converte in un valore di temperatura.
   Se la temperatura supera la soglia, la velocità del ventilatore viene regolata in base alla temperatura.

4. ``voltageToTemperature()``:

   Questa è una funzione ausiliaria utilizzata per convertire il valore di tensione dal sensore di temperatura in un valore di temperatura (in Celsius).
   La funzione utilizza la formula standard per un termistore per stimare la temperatura.
   Il valore restituito è in gradi Celsius.

