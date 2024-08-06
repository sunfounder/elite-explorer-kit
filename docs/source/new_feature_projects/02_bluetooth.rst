.. note::

    Ciao, benvenuto nella Community degli appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato alle nuove presentazioni di prodotto e anticipazioni.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto ad esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _new_bluetooth:

Bluetooth
========================================

Dotata del modulo ESP32, la scheda UNO R4 WiFi offre funzionalità Bluetooth® LE e Bluetooth® 5, supportando velocità fino a 2 Mbps. Il modulo ESP32 include un'antenna a traccia integrata, eliminando la necessità di un'antenna esterna per sfruttare le funzionalità di connettività della scheda.

.. note::
    L'antenna a traccia nel modulo ESP32 è condivisa con il modulo Bluetooth®, il che significa che non è possibile utilizzare Bluetooth® e Wi-Fi® contemporaneamente.

Concetti Base del BLE
++++++++++++++++++++++++

**Bluetooth Low Energy (BLE)** è una tecnologia di comunicazione wireless a basso consumo energetico, progettata specificamente per interazioni a corto raggio. Diversa dal Bluetooth classico, il BLE si concentra sull'efficienza energetica e sulla connessione rapida, rendendolo una scelta ideale per una gamma di applicazioni tra cui dispositivi Internet of Things (IoT) e apparecchiature di monitoraggio della salute.

Le comunicazioni BLE si basano su due protocolli chiave: **GATT (Generic Attribute Profile)** e **GAP (Generic Access Profile)**. Il GATT è utilizzato per lo scambio di dati, mentre il GAP è responsabile della scoperta e della connessione dei dispositivi.

.. image:: img/02_ble_relationships.png
 :width: 100%


Dispositivi Periferici (Tipicamente Server GATT)
------------------------------------------------------

Nella rete BLE, i **dispositivi periferici** trasmettono principalmente dati per essere scoperti e accessibili dai dispositivi centrali (tipicamente agendo come client GATT). Tali dispositivi sono solitamente sensori o piccoli hardware come monitor del battito cardiaco, sensori di temperatura o lampadine intelligenti.

Nel modello di comunicazione BLE, i dispositivi periferici spesso forniscono uno o più **servizi**, ciascuno contenente un insieme di **caratteristiche**. Questi servizi e caratteristiche collaborano per abilitare specifiche funzionalità o casi d'uso, permettendo ai dispositivi centrali di leggere o manipolare i dati pertinenti.

- **Servizi**

  Nei BLE, i Servizi agiscono come astrazioni di alto livello utilizzate per organizzare e incapsulare caratteristiche correlate. I Servizi nei BLE possono essere classificati in servizi standard e servizi personalizzati in base alla loro origine e scopo.

  - Servizi Standard: Definiti dal Bluetooth SIG (Bluetooth Special Interest Group), sono destinati a funzioni specifiche. Ad esempio, il servizio di frequenza cardiaca per i monitor del battito cardiaco, il servizio di informazioni sul dispositivo che fornisce dettagli su produttore, modello e versione, e il servizio batteria che indica il livello e lo stato della batteria.
  - Servizi Personalizzati: Sono definiti da sviluppatori o produttori di dispositivi per soddisfare i requisiti di specifiche applicazioni o dispositivi. Ad esempio, un produttore di dispositivi per la casa intelligente potrebbe definire un servizio personalizzato per controllare il colore e la luminosità della luce.

- **Caratteristiche**

  Le Caratteristiche nei BLE sono le unità fondamentali di dati esposte dai dispositivi periferici. Sono incluse all'interno di un Servizio e definiscono vari tipi di dati e le operazioni che possono essere eseguite su di essi. Ogni caratteristica è identificata da un UUID e ha un insieme di attributi associati come valore, descrittore e permessi.

  - Permessi: Nei BLE, ogni caratteristica è associata a un insieme di permessi che determinano se la caratteristica è leggibile, scrivibile o notificabile. Questo aiuta a proteggere i dati e a definire come interagire con essi.

- **UUID**

  Servizi, caratteristiche e descrittori sono collettivamente identificati come attributi, ciascuno con un UUID univoco. Il Bluetooth SIG ha riservato un insieme di UUID per gli attributi standard. Questi UUID sono solitamente rappresentati come identificatori a 16 o 32 bit nel protocollo BLE per efficienza, anziché i 128 bit richiesti per un UUID completo. Ad esempio, il servizio di informazioni sul dispositivo è rappresentato dal codice breve 0x180A.



Dispositivi Centrali (Tipicamente Client GATT)
--------------------------------------------------

I **dispositivi centrali** nella rete BLE scansionano i dispositivi periferici vicini e stabiliscono connessioni per acquisire o controllare i dati. Questi dispositivi sono generalmente più complessi e ricchi di funzionalità, come smartphone, tablet o hardware gateway specializzati. Sono responsabili della scoperta dei dispositivi periferici, della connessione ad essi e dell'accesso o sottoscrizione ai servizi e alle caratteristiche offerti dai periferici per servire varie applicazioni o risolvere specifici problemi.

I dispositivi centrali interagiscono con le caratteristiche nei seguenti modi:

- **Lettura**: Richiedi al dispositivo periferico di inviare il valore corrente di una caratteristica. Questo è comunemente utilizzato per caratteristiche che non cambiano spesso, come impostazioni di configurazione o numeri di versione.
- **Scrittura**: Modifica il valore di una caratteristica, tipicamente utilizzata per operazioni simili a comandi, come istruire un dispositivo periferico ad accendere o spegnere un motore.
- **Sottoscrizione**: Richiedi al dispositivo periferico di inviare continuamente valori aggiornati di una caratteristica, eliminando la necessità che il dispositivo centrale richieda ripetutamente questi dati.



Esempio: LED Controllato via Bluetooth
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

In questo esempio, l'Arduino agisce come dispositivo periferico in una rete Bluetooth Low Energy (BLE). Offre un servizio BLE personalizzato progettato per controllare un LED integrato. Questo servizio include una caratteristica che può essere letta e scritta da un dispositivo centrale, come uno smartphone. Una volta che il dispositivo centrale si connette all'Arduino, può cambiare lo stato del LED scrivendo su questa caratteristica. Il monitor seriale dell'Arduino visualizza informazioni di debug, compreso lo stato corrente del LED e l'indirizzo MAC del dispositivo centrale connesso.

**Carica il Codice**

Apri il file ``02-bluetooth.ino`` situato in ``elite-explorer-kit-main\r4_new_feature\02-bluetooth``, oppure incolla il seguente codice nel tuo Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/44d76bb7-9f0a-4004-b3fe-9a88999c5f06/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Connetti Arduino R4 via Bluetooth**

Per interagire con i servizi e le caratteristiche creati in questo sketch, dovremmo utilizzare un'app central BLE generica come LightBlue (disponibile per iOS e Android) o nRF Connect (per Android). 

Prendiamo LightBlue come esempio per dimostrare come controllare il LED di Arduino via Bluetooth.

1. Scarica l'app **LightBlue** da |link_lightblue_apple| (per iOS) o |link_lightblue_google| (per Android).

   .. image:: img/02_lightblue.png
    :width: 90%

   .. raw:: html

      <br/><br/>

2. Collegamento di Arduino al tuo Smartphone via Bluetooth
   
   Vai alle impostazioni Bluetooth e individua il dispositivo chiamato "UNO R4 LED". Procedi alla connessione.

   .. image:: img/02_connect.png
    :width: 90%

   .. raw:: html

      <br/>

3. Interazione con Arduino via Bluetooth usando LightBlue

   Avvia LightBlue e tocca la scheda **Bonded** situata in basso nell'interfaccia. Qui vedrai un elenco di dispositivi BLE con cui il tuo smartphone è stato precedentemente associato. Individua **UNO R4 LED** e tocca **CONNECT**.

   .. image:: img/02_lightblue_1.png
    :width: 90%

   Una volta connesso, avrai accesso a informazioni dettagliate sul dispositivo Bluetooth "UNO R4 LED". Scorri verso il basso per trovare "ledService (**19B10000-E8F2-537E-4F6C-D104768A1214**)" e "switchCharacteristic (**19B10001-E8F2-537E-4F6C-D104768A1214**)".

   Tocca la Caratteristica 19B10001-E8F2-537E-4F6C-D104768A1214. Noterai che questa Caratteristica è sia leggibile che scrivibile, permettendoti di leggerla e scriverla.
  
   .. image:: img/02_lightblue_2.png
    :width: 90%

   Continua a scorrere fino alla sezione **WRITTEN VALUES**. Inserisci '**1**' nella casella di testo per impostare il valore della Caratteristica su 1, che **accenderà il LED integrato dell'Arduino R4**.

   .. image:: img/02_lightblue_3.png
    :width: 90%

   Allo stesso modo, puoi impostare questo valore su '**0**' per **spegnere il LED integrato**.

   .. image:: img/02_lightblue_4.png
    :width: 90%



**Spiegazione del Codice**

#. Inizializzazione BLE e LED

   .. note::
      Quando si definiscono servizi e caratteristiche, è necessario utilizzare UUID per identificarli. Per evitare conflitti di UUID e semplificare l'uso, puoi utilizzare lo strumento di generazione UUID a |link_uuid_gen_tool|.

   .. code-block:: arduino
   
      #include <ArduinoBLE.h>
      BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Servizio LED BLE
      BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
      const int ledPin = LED_BUILTIN; // pin per il LED

   - Includi la libreria ArduinoBLE.
   - Definisci il servizio e la caratteristica BLE. 
   - Assegna il pin LED integrato a ``ledPin``.

   .. raw:: html

      <br/>

#. Funzione ``setup()``

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        while (!Serial);
        pinMode(ledPin, OUTPUT);
        if (!BLE.begin()) {
          Serial.println("starting Bluetooth® Low Energy module failed!");
          while (1);
        }
        BLE.setLocalName("UNO R4 LED");
        BLE.setAdvertisedService(ledService);
        ledService.addCharacteristic(switchCharacteristic);
        BLE.addService(ledService);
        switchCharacteristic.writeValue(0);
        BLE.advertise();
        Serial.println("BLE LED Peripheral");
      }

   - Inizializza la comunicazione seriale.
   - Imposta il pin del LED come output.
   - Inizializza il BLE e aggiungi il servizio e le caratteristiche.
   - Inizia la pubblicità BLE.

   .. raw:: html

      <br/>

#. Funzione ``loop()``

   .. code-block:: arduino
   
      void loop() {
        BLEDevice central = BLE.central();
        if (central) {
          Serial.print("Connected to central: ");
          Serial.println(central.address());
          while (central.connected()) {
            if (switchCharacteristic.written()) {
              if (switchCharacteristic.value()) {
                Serial.println("LED on");
                digitalWrite(ledPin, HIGH);
              } else {
                Serial.println("LED off");
                digitalWrite(ledPin, LOW);
              }
            }
          }
          Serial.print("Disconnected from central: ");
          Serial.println(central.address());
        }
      }
   

   - Ascolta i dispositivi centrali BLE per connettersi.
   - Se un dispositivo centrale è connesso, leggi il valore della caratteristica per controllare il LED. Se viene ricevuto un valore diverso da 0, accendi il LED. Se viene ricevuto 0, spegni il LED.


**Riferimento**

- |link_r4_bluetooth|