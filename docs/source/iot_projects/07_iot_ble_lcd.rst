.. note::

    Ciao, benvenuto nella Community di appassionati SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _iot_Bluetooth_lcd:

Bluetooth Message Box
=============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4" type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo progetto riceve messaggi e li visualizza su uno schermo LCD.

Puoi usarlo come bacheca dei messaggi di famiglia, ricordando ai membri della famiglia che non sono ancora usciti di ricordarsi di prendere le chiavi.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ARTICOLI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

È anche possibile acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Cablaggio**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

**Schema**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**Genera il UUID**

Gli UUID svolgono un ruolo cruciale nella comunicazione BLE, garantendo l'unicità dei dispositivi e l'accuratezza dello scambio di dati tra essi. Devi personalizzare gli UUID per creare i tuoi servizi e caratteristiche BLE per soddisfare requisiti applicativi specifici. (Qui, dobbiamo creare una caratteristica che supporti l'input di testo.)

1. Usa l'`Online UUID Generator Tool <https://www.uuidgenerator.net/version4>`_ per creare UUID unici per te per evitare conflitti di UUID.

2. Genera due UUID versione 4.

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. Copiali e sostituisci i due UUID nel tuo codice.

   .. code-block:: arduino
   
       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**Installa la Libreria**

``ArduinoBLE.h``: Utilizzato per gestire la comunicazione Bluetooth Low Energy (BLE).
``LiquidCrystal_I2C.h``: Utilizzato per controllare uno schermo LCD 16x2 con interfaccia I2C.

**Esegui il Codice**

.. note::

    * Puoi aprire il file ``07_lightblue_lcd.ino`` nel percorso ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note:: 
      Per installare la libreria, usa il Gestore delle Librerie Arduino per cercare e installare **"ArduinoBLE"** e **"LiquidCrystal I2C"**.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/958c37c2-a897-4c4c-b6c1-0e7fea67c7b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come Giocare?**

Per interagire con i servizi e le caratteristiche creati in questo sketch, dovresti usare un'app centrale generica Bluetooth® Low Energy come LightBlue (disponibile per iOS e Android) o nRF Connect (per Android).

Utilizziamo LightBlue come esempio per dimostrare come controllare l'LED di Arduino via Bluetooth.

1. Scarica l'app LightBlue dall'App Store (per iOS) o Google Play (per Android).

   .. image:: img/07_lightblue.png

2. Collegare Arduino al tuo Smartphone via Bluetooth

   Vai alle impostazioni Bluetooth e individua il dispositivo chiamato "UNO R4 BLE." Connetti a esso.

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. Interagire con Arduino via Bluetooth usando LightBlue

   Avvia LightBlue e tocca la scheda **Bonded** nella parte inferiore dell'interfaccia. Qui, vedrai un elenco di dispositivi BLE con cui il tuo smartphone è stato precedentemente associato. Individua **UNO R4 BLE** e tocca **CONNECT**.

   .. image:: img/07_iot_ble_02.jpg

   Una volta connesso, avrai accesso a informazioni dettagliate sul dispositivo Bluetooth. Scorri verso il basso per trovare il tuo UUID di servizio e il tuo UUID di caratteristica.

   Tocca la Caratteristica. Noterai che questa Caratteristica è sia leggibile che scrivibile, permettendoti sia di leggere che di scrivere su di essa.

   Continua a scorrere fino alla sezione "Formato dei dati" e cambia in Stringa UTF-8.
   Inserisci il testo nella casella di testo e fai clic su scrivi. Il messaggio inserito apparirà sullo schermo LCD.

   .. image:: img/07_iot_ble_03.jpg

**Come Funziona?**

Ecco le principali parti del codice e le spiegazioni delle loro funzioni:

1. Includere le librerie necessarie:

   * ``ArduinoBLE.h``: Utilizzato per gestire la comunicazione BLE.
   * ``Wire.h``: Utilizzato per la comunicazione I2C.
   * ``LiquidCrystal_I2C.h``: Utilizzato per controllare uno schermo LCD 16x2 con interfaccia I2C.

2. Definire un servizio BLE e una caratteristica BLE:

   * Usa la classe ``BLEService`` per definire un servizio BLE e assegnargli un UUID univoco.
   * Usa la classe ``BLECharacteristic`` per definire una caratteristica BLE, assegnarle un UUID univoco e darle permessi di lettura (``BLERead``) e scrittura (``BLEWrite``).
   * Crea un array di caratteri ``stringValue`` come valore iniziale della caratteristica.

3. Inizializzare uno schermo LCD 16x2 (LCD):

   * Usa la classe ``LiquidCrystal_I2C`` per inizializzare un LCD, specificando l'indirizzo I2C (0x27) e il numero di righe e colonne (16x2).
   * Accendi la retroilluminazione dell'LCD, cancella lo schermo, sposta il cursore all'inizio della prima riga e visualizza "Bluetooth LCD."

4. Eseguire l'inizializzazione nella funzione ``setup()``:

   * Inizializza la comunicazione seriale.
   * Inizializza il modulo BLE e, se l'inizializzazione fallisce, entra in un ciclo infinito.
   * Imposta il nome locale e l'UUID del servizio per il dispositivo periferico BLE.
   * Aggiungi la caratteristica BLE al servizio BLE.
   * Inizia a pubblicizzare il servizio BLE affinché i dispositivi centrali possano scoprirlo e connettersi ad esso.
   * Inizializza l'LCD.

5. La funzione ``loop()``:

   * Controlla se c'è un dispositivo centrale connesso al dispositivo periferico BLE chiamando ``BLE.central()``. Se un dispositivo centrale è connesso, entra nella logica di gestione della connessione.
   * In stato di connessione, controlla se i dati sono stati scritti nella caratteristica BLE controllando ``boxCharacteristic.written()``.
   * Se i dati sono stati scritti, ottieni la lunghezza dei dati scritti usando ``boxCharacteristic.valueLength()`` e crea un array di byte ``buffer`` per memorizzare i dati scritti.
   * Usa ``boxCharacteristic.readValue()`` per leggere i dati dalla caratteristica BLE nel ``buffer``.
   * Aggiungi un carattere nullo ``'\0'`` alla fine del ``buffer`` per convertirlo in una stringa.
   * Stampa il messaggio ricevuto sul monitor seriale e visualizzalo sull'LCD.
   * Continua ad aspettare il prossimo dispositivo centrale da connettere dopo che il dispositivo centrale si è disconnesso.
