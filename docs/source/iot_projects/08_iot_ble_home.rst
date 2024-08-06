.. note::

    Ciao, benvenuto nella comunità degli appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _iot_ble_home:

Monitor Ambientale Bluetooth
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>


Questo progetto utilizza un'app Android creata con MIT App Inventor per ricevere e visualizzare i dati ambientali da una scheda Arduino. La scheda Arduino raccoglie i dati da un sensore DHT11 per misurare temperatura e umidità. Una volta raccolti i dati, vengono trasmessi tramite Bluetooth. L'app visualizzerà i dati sullo schermo una volta ricevuti.

L'applicazione Android verrà costruita utilizzando una piattaforma web gratuita nota come |link_appinventor|. Il progetto rappresenta un'eccellente opportunità per familiarizzare con l'interfacciamento di un Arduino con uno smartphone. 

**Componenti Necessari**

In questo progetto, avremo bisogno dei seguenti componenti. 

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

Puoi anche acquistarli separatamente dai link sottostanti.

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. Costruisci il Circuito**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>
   
**2. Crea l'App Android**

L'applicazione Android verrà sviluppata utilizzando un'applicazione web gratuita nota come |link_appinventor|. 
MIT App Inventor è un eccellente punto di partenza per lo sviluppo Android, grazie alle sue funzionalità intuitive di drag-and-drop che consentono la creazione di applicazioni semplici.

Iniziamo.

#. Vai su |link_appinventor_login| e clicca su "online tool" per accedere. Avrai bisogno di un account Google per registrarti su MIT App Inventor.

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. Dopo aver effettuato l'accesso, naviga su **Projects** -> **Import project (.aia) from my computer**. Successivamente, carica il file ``ble_environmental_monitor.aia`` situato nel percorso ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``.

   Puoi anche scaricarlo direttamente qui: :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. Una volta caricato il file ``.aia``, vedrai l'applicazione nel software MIT App Inventor. Questo è un modello preconfigurato. Puoi modificare questo modello dopo aver familiarizzato con MIT App Inventor seguendo i passaggi successivi.

#. In MIT App Inventor, hai 2 sezioni principali: il **Designer** e i **Blocks**. Puoi passare da una sezione all'altra nell'angolo in alto a destra della pagina.

   .. image:: img/08_ai_intro_1.png

#. Il **Designer** ti permette di aggiungere pulsanti, testo, schermate e modificare l'estetica generale della tua applicazione.

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. Successivamente, c'è la sezione **Blocks**. Questa sezione ti consente di creare funzionalità personalizzate per la tua app, permettendoti di programmare ogni componente dell'interfaccia utente dell'app per ottenere le funzionalità desiderate.

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. Per installare l'applicazione su uno smartphone, naviga sulla scheda **Build**.

   .. image:: img/08_ai_intro_4.png

   * Puoi generare un file ``.apk``. Dopo aver selezionato questa opzione, apparirà una pagina che ti permetterà di scegliere tra scaricare un file ``.apk`` o scansionare un codice QR per l'installazione. Segui la guida all'installazione per completare l'installazione dell'applicazione. 

     Puoi anche scaricare il nostro APK precompilato qui: :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * Se desideri caricare questa app su Google Play o un altro marketplace di app, puoi generare un file ``.aab``.


**3. Carica il Codice**

#. Apri il file ``08-bluetooth_environmental_monitor.ino`` nel percorso ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``, oppure copia questo codice in **Arduino IDE**.
   
   .. note:: 
      Per installare la libreria, utilizza l'Arduino Library Manager per cercare e installare **"DHT sensor library"** e **"ArduinoBLE"**.

   .. raw:: html
       
      <iframe src=https://create.arduino.cc/editor/sunfounder01/53fd4af4-dcc6-439d-b52f-2f94f17c1263/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante **Upload**.

#. Apri il monitor seriale (imposta il baudrate a **9600**) per visualizzare i messaggi di debug. 

**4. Connessione dell'App e del modulo Bluetooth**

Assicurati che l'applicazione creata in precedenza sia installata sul tuo smartphone.

#. Inizialmente, attiva il **Bluetooth** sul tuo smartphone.

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. Ora apri la nuova app **Environmental Monitor** installata.

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. Quando apri l'app per la prima volta, appariranno due richieste di autorizzazione in successione. Questi sono i permessi necessari per utilizzare il Bluetooth.

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. Nell'APP, clicca sul pulsante **Connetti** per stabilire una connessione tra l'APP e il modulo Bluetooth.

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. Questa pagina mostra un elenco di tutti i dispositivi Bluetooth abbinati. Scegli l'opzione ``xx.xx.xx.xx.xx.xx UNO R4 Home`` dall'elenco. Il nome di ogni dispositivo è elencato accanto al suo indirizzo MAC.

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. Se non vedi dispositivi nella pagina mostrata sopra, puoi provare ad attivare l'interruttore di localizzazione del dispositivo (alcune versioni di sistema Android includono l'interruttore di localizzazione con la funzione Bluetooth).

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. Dopo una connessione riuscita, sarai reindirizzato alla pagina principale dove verranno visualizzati temperatura e umidità.

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. Spiegazione del Codice**

1. Importazione delle Librerie e Definizione delle Costanti

   - Importa le librerie necessarie e definisci le costanti per il pin e il tipo di sensore DHT.

   .. note:: 
      Per installare la libreria, utilizza il Gestore Librerie Arduino per cercare e installare **"DHT sensor library"** e **"ArduinoBLE"**.

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. Inizializzazione dei Servizi e delle Caratteristiche BLE

   - Definisci gli UUID per il Servizio e le Caratteristiche BLE Environmental Sensing. Stiamo utilizzando gli UUID predefiniti forniti da |link_bluetooth_sig|. Il |link_sig_environmental_sensing| è assegnato a ``0x181A``, mentre ``0x2A6E`` e ``0x2A6F`` sono riservati rispettivamente per |link_sig_temperature_humidity|.

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Funzione di Setup

   - Inizializza la comunicazione Seriale, il sensore DHT e il BLE.

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. Loop Principale

   - Controlla gli eventi BLE e aggiorna i dati del sensore a intervalli regolari.

   - La linea ``millis() - lastUpdateTime > updateInterval`` assicura che i dati del sensore vengano aggiornati ogni updateInterval millisecondi.

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Leggi i dati del sensore e aggiorna le caratteristiche BLE
         }
       }

5. Funzioni BLE e di Debug

   Funzioni per configurare il BLE, stampare informazioni di debug e gestire gli eventi BLE.

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``: Utilizzata per stampare i dati di temperatura e umidità letti dal DHT11 sul monitor seriale. Questa funzione è per scopi di debug.

   - ``setupBle()``: Inizializza il Bluetooth, inclusi il nome di broadcast, le caratteristiche e i servizi.

   - ``blePeripheralConnectHandler(BLEDevice central)`` e ``blePeripheralDisconnectHandler(BLEDevice central)``: Queste funzioni gestiscono gli eventi quando il Bluetooth si connette o si disconnette. Quando un dispositivo si connette con UNO R4 tramite Bluetooth, il LED integrato si accende. Quando il dispositivo si disconnette, il LED si spegne.
