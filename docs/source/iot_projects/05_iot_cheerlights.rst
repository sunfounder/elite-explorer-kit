.. note::

    Ciao, benvenuto nella community di appassionati SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _iot_cheerlights:

CheerLights
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/05_iot_cheerlights.mp4" type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

CheerLights è una rete globale di luci sincronizzate che può essere controllata da chiunque. Unisciti alla comunità |link_cheerlights| di LED che cambiano colore, permettendo ai LED di tutto il mondo di cambiare colore simultaneamente. Posiziona i tuoi LED in un angolo del tuo ufficio per ricordarti che non sei solo.

In questo progetto utilizziamo anche MQTT, ma invece di pubblicare i nostri messaggi, ci iscriviamo al topic "cheerlights". Questo ci permette di ricevere messaggi inviati da altri al topic "cheerlights" e di utilizzare tali informazioni per cambiare il colore della nostra striscia LED di conseguenza.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Cablaggio**

.. image:: img/05_cheerlight_bb.png
    :width: 100%
    :align: center

**Schema**

.. image:: img/05_cheerlight_schematic.png
    :width: 50%
    :align: center

.. raw:: html

   <br/>

**Installa la Libreria**

Per installare la libreria, utilizza il Gestore delle Librerie Arduino e cerca "ArduinoMqttClient" e "FastLED" e installale.

``ArduinoMqttClient.h``: Utilizzato per la comunicazione MQTT.

``FastLED.h``: Utilizzato per pilotare la striscia LED RGB.

.. important::
    Con il rilascio di |link_fastled_3_7_0|, la libreria FastLED supporta ufficialmente Arduino UNO R4. Pertanto, non è più necessario installare manualmente la versione di sviluppo. Aggiorna o installa semplicemente la libreria FastLED utilizzando il Gestore delle Librerie Arduino.

.. warning::
    **[Non aggiornato]** Poiché la libreria |link_FastLED_lib| non ha ancora rilasciato una versione che supporta ufficialmente Arduino R4, dovrai scaricare :download:`l'ultima versione di sviluppo della libreria FastLED <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` e sovrascrivere i file esistenti della libreria FastLED. Per istruzioni dettagliate su come fare ciò, consulta la sezione :ref:`manual_install_lib`. (Questa nota sarà ritirata quando la libreria FastLED rilascerà ufficialmente un aggiornamento che supporta Arduino UNO R4.)

**Esegui il Codice**

.. note::

    * Puoi aprire il file ``05_cheerlight.ino`` nel percorso ``elite-explorer-kit-main\iot_project\05_cheerlight`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note::
    Nel codice, SSID e password sono memorizzati in ``arduino_secrets.h``. Prima di caricare questo esempio, è necessario modificarli con le proprie credenziali WiFi. Inoltre, per motivi di sicurezza, assicurati che queste informazioni siano mantenute riservate durante la condivisione o la memorizzazione del codice.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9d7ad736-9725-499f-a6ea-91602120d53e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Controlla i dispositivi globali @CheerLights**

#. Unisciti al |link_discord_server| e utilizza il bot CheerLights per impostare il colore. Digita semplicemente ``/cheerlights`` in uno dei canali sul **CheerLights Discord Server** per attivare il bot.

   .. image:: img/05_iot_cheerlights_1.png

#. Segui le istruzioni fornite dal bot per impostare il colore. Questo ti permetterà di controllare i dispositivi CheerLights globalmente.

   .. image:: img/05_iot_cheerlights_2.png

**Come Funziona?**

Ecco le principali parti del codice e le spiegazioni delle loro funzioni:

1. Includi le librerie necessarie:

   * ``WiFiS3.h``: Utilizzata per gestire le connessioni Wi-Fi.
   * ``ArduinoMqttClient.h``: Utilizzata per gestire le connessioni MQTT.
   * ``FastLED.h``: Utilizzata per controllare le strisce LED NeoPixel.

2. Definisci alcune costanti:

   * ``NUM_LEDS``: Il numero di LED sulla striscia LED.
   * ``DATA_PIN``: Il pin dati collegato ad Arduino per controllare la striscia LED.
   * ``arduino_secrets.h``: File header contenente il nome e la password della rete Wi-Fi per proteggere le informazioni sensibili.
   * ``broker``: Indirizzo del server MQTT.
   * ``port``: Porta del server MQTT.
   * ``topic``: Il topic MQTT a cui iscriversi.

3. Definisci alcune variabili globali:

   * ``CRGB leds[NUM_LEDS]``: Un array per memorizzare i dati del colore dei LED.
   * ``colorName``: Un array di nomi di colori supportati dal progetto CheerLights.
   * ``colorRGB``: Un array di codici colore RGB corrispondenti ai nomi dei colori.

4. Funzione ``setup()``:

   * Inizializza la comunicazione seriale.
   * Verifica se il modulo Wi-Fi è presente e stampa la versione del firmware.
   * Tenta di connettersi alla rete Wi-Fi; se fallisce, attende 10 secondi e riprova.
   * Una volta connesso con successo, si connette al broker MQTT (server) e si iscrive al topic specificato.
   * Inizializza la striscia LED NeoPixel.

5. Funzione ``loop()``:

   * Chiama periodicamente la funzione ``mqttClient.poll()`` per ricevere messaggi MQTT e inviare segnali di keep-alive MQTT.
   * Aggiungi un ritardo di 5 secondi per evitare una connessione continua.

6. Le funzioni ``printWifiData()`` e ``printCurrentNet()`` sono utilizzate per stampare le informazioni sulla rete Wi-Fi e sulla connessione.

7. La funzione ``printMacAddress()`` è utilizzata per stampare l'indirizzo MAC in formato esadecimale.

8. La funzione ``onMqttMessage()`` è una funzione di callback attivata quando viene ricevuto un messaggio MQTT. Stampa il topic del messaggio ricevuto e il contenuto, convertendo il contenuto del messaggio in minuscolo. Se il topic è "cheerlights", chiama la funzione ``setColor()`` per impostare il colore della striscia LED.

9. La funzione ``setColor()`` prende un nome di colore come parametro, quindi cerca un colore corrispondente nell'array ``colorName``. Se viene trovato un colore corrispondente, imposta il colore della striscia LED sul valore RGB corrispondente e aggiorna```
la striscia LED utilizzando la funzione ``FastLED.show()``.
