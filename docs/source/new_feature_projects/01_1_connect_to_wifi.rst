.. note::

    Ciao, benvenuto nella Community degli Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Apprendi e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e ai teaser.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Connettersi a Wi-Fi
=========================

Questo tutorial ti guiderà attraverso i passaggi essenziali per connettere il tuo board Arduino a una rete Wi-Fi. Imparerai come inizializzare il modulo Wi-Fi, verificare il firmware e unirti in modo sicuro a una rete utilizzando il suo SSID e password. Una volta connesso, scoprirai come monitorare importanti dettagli di rete come l'IP del tuo dispositivo e gli indirizzi MAC, nonché la potenza del segnale della rete, direttamente dalla console seriale. Questo tutorial serve sia come guida pratica alla connettività Wi-Fi che come introduzione al monitoraggio di rete con Arduino, aiutandoti a stabilire e mantenere una connessione Wi-Fi affidabile.

1. Carica il codice
========================

Apri il file ``01-wifi_connect.ino`` nel percorso ``elite-explorer-kit-main\r4_new_feature\01-wifi_connect``, oppure copia questo codice nell'**Arduino IDE**.

.. note:: 
      Il supporto Wi-Fi® è abilitato tramite la libreria integrata ``WiFiS3`` fornita con il Core Arduino UNO R4. Installando il core, viene automaticamente installata anche la libreria ``WiFiS3``.


È ancora necessario creare o modificare ``arduino_secrets.h``, sostituendo ``SECRET_SSID`` e ``SECRET_PASS`` con il nome e la password della rete Wi-Fi a cui desideri connetterti. Il file dovrebbe contenere:

.. code:: arduino

    // file intestazione arduino_secrets.h
    #define SECRET_SSID "tuarete"
    #define SECRET_PASS "tuapassword"

.. literalinclude:: /_code/01_1_connect_to_wifi_secrets.h
   :language: cpp
   :caption: arduino_secrets.h

.. literalinclude:: /_code/01_1_connect_to_wifi.ino
   :language: cpp
   :linenos:
   :caption: 01-wifi_connect.ino


Apri il monitor seriale e vedrai un contenuto simile a quanto segue. Arduino mostrerà l'IP e gli indirizzi MAC del tuo dispositivo, nonché la potenza del segnale della rete.

.. image:: img/01_1_wifi.png
    :width: 100%


2. Spiegazione del codice
================================

1. Inclusione delle Librerie e Dati Segreti

   .. code-block:: arduino

      #include <WiFiS3.h>
      #include "arduino_secrets.h" 

   - ``WiFiS3`` è una libreria che fornisce funzioni per la connettività Wi-Fi. Installando il core R4, viene automaticamente installata la libreria WiFiS3.
   - ``arduino_secrets.h`` è un file separato dove vengono conservati SSID e password per evitare la loro esposizione nel codice principale. Conservare rete e password separatamente riduce la condivisione accidentale delle credenziali Wi-Fi.

   .. raw:: html

      <br/>

2. Dichiarazione di Variabili Globali

   .. code-block:: arduino

      char ssid[] = SECRET_SSID;
      char pass[] = SECRET_PASS;
      int status = WL_IDLE_STATUS;

   - ``ssid`` e ``pass`` contengono il nome della tua rete e la password.
   - ``status`` memorizza lo stato attuale della connessione Wi-Fi.

   .. raw:: html

      <br/>

3. Funzione ``setup()``

   L'interfaccia seriale viene inizializzata con un baud rate di 9600. La linea ``while (!Serial);`` assicura che il programma attenda finché la connessione seriale non è stabilita.

   .. code-block:: arduino

      void setup() {
          //Initialize serial and wait for port to open:
          Serial.begin(9600);
          while (!Serial) {
            ; // wait for serial port to connect. Needed for native USB port only
          }
          ...
      }

   E quindi, il codice verifica se il modulo Wi-Fi è disponibile o meno. Se non lo è, il programma si interromperà, impedendo efficacemente qualsiasi ulteriore esecuzione.

   .. code-block:: arduino

     ...
     // check for the WiFi module:
     if (WiFi.status() == WL_NO_MODULE) {
         Serial.println("Communication with WiFi module failed!");
         // don't continue
         while (true);
     }
     ...

   In questa parte del codice, controlliamo se la versione del firmware di uno R4 WiFi è aggiornata. Se non è l'ultima versione, verrà visualizzato un prompt per l'aggiornamento. Puoi fare riferimento a :ref:`update_firmware` per l'aggiornamento del firmware.

   .. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

   .. code-block:: arduino

      ...
      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
          Serial.println("Please upgrade the firmware");
      }
      ...

4. Funzione ``loop()``

   .. code-block:: arduino

      void loop() {
        // check the network connection once every 10 seconds:
        delay(10000);
        printCurrentNet();
      }

   - Ogni 10 secondi, la funzione ``printCurrentNet()`` viene chiamata per stampare i dettagli attuali della rete.


**Riferimenti**

- |link_r4_wifi|
