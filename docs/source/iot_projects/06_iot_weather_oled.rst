.. note::

    Ciao, benvenuto nella community di appassionati SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _iot_weathertime_screen:

WeatherTime Screen
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/06_iot_weather_oled.mp4" type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo sketch si connette a una rete WiFi, recupera i dati meteo da OpenWeatherMap ogni minuto, ottiene l'ora corrente da un server NTP e visualizza il giorno, l'ora e le informazioni meteorologiche su uno schermo OLED.

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

**Cablaggio**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center

**Schema**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center

**OpenWeather**

Ottieni le chiavi API di OpenWeather

.. .|link_openweather| is an online service, owned by OpenWeather Ltd, that provides global weather data via API, including current weather data, forecasts, nowcasts and historical weather data for any geographical location.

`OpenWeather <https://openweathermap.org/>`_ è un servizio online, di proprietà di OpenWeather Ltd, che fornisce dati meteorologici globali tramite API, inclusi dati meteorologici attuali, previsioni, nowcast e dati storici per qualsiasi posizione geografica.


#. Visita OpenWeather per accedere o creare un account.

   .. image:: img/06_owm_1.png


#. Clicca sulla pagina delle API dalla barra di navigazione.

   .. image:: img/06_owm_2.png


#. Trova **Current Weather Data** e clicca su Iscriviti.

   .. image:: img/06_owm_3.png


#. Sotto **Current weather and forecasts collection**, iscriviti al servizio appropriato. Nel nostro progetto, la versione gratuita è sufficiente.

   .. image:: img/06_owm_4.png


#. Copia la chiave dalla pagina **API keys**.

   .. image:: img/06_owm_5.png

#. Copiala nel file ``arduino_secrets.h``.

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // your network SSID (name)
       #define SECRET_PASS "<PASSWORD>"        // your network password 
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"

#. Imposta il fuso orario della tua posizione.

   Prendi la capitale della Svezia, Stoccolma, come esempio. Cerca "fuso orario Stoccolma" su Google.

   .. image:: img/06_weather_oled_01.png 

   Nei risultati della ricerca, vedrai "GMT+1", quindi imposta il parametro della funzione sottostante su ``3600 * 1`` secondi.
   
   .. code-block:: Arduino

      timeClient.setTimeOffset(3600 * 1);  // Regola per il tuo fuso orario (questo è +1 ora)

**Installa la Libreria**

Per installare la libreria, utilizza il Gestore delle Librerie Arduino e cerca "ArduinoMqttClient", "FastLED", "Adafruit GFX" e "Adafruit SSD1306" e installale.

``ArduinoJson.h``: Utilizzato per gestire i dati JSON (dati ottenuti da OpenWeatherMap).

``NTPClient.h``: Utilizzato per ottenere l'ora in tempo reale.

``Adafruit_GFX.h``, ``Adafruit_SSD1306.h``: Utilizzati per il modulo OLED.

**Esegui il Codice**

.. note::

    * Puoi aprire il file ``06_weather_oled.ino`` nel percorso ``elite-explorer-kit-main\iot_project\06_weather_oled`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note::
    Nel codice, SSID e password sono memorizzati in ``arduino_secrets.h``. Prima di caricare questo esempio, è necessario modificarli con le proprie credenziali WiFi. Inoltre, per motivi di sicurezza, assicurati che queste informazioni siano mantenute riservate durante la condivisione o la memorizzazione del codice.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come Funziona?**

1. Librerie e Definizioni:

   #. ``WiFiS3.h``: Probabilmente una libreria specifica per un modulo WiFi o una scheda per gestire le connessioni WiFi.
   #. ``ArduinoJson.h``: Questa libreria è utilizzata per decodificare (e codificare) dati JSON.
   #. ``arduino_secrets.h``: Un file separato in cui sono memorizzati i dati sensibili (come le credenziali WiFi). Questa è una buona pratica per mantenere le credenziali fuori dal codice principale.
   #. **NTPClient & WiFiUdp**: Sono utilizzati per recuperare l'ora corrente da un server NTP (Network Time Protocol).
   #. **Librerie Adafruit**: Utilizzate per gestire il display OLED.
   #. **Varie variabili globali**: Includono le credenziali WiFi, i dettagli del server e altro, che saranno utilizzati durante tutto il programma.

2. ``setup()``:

   #. Inizializza la comunicazione seriale.
   #. Controlla e stampa la versione del firmware del modulo WiFi.
   #. Tenta di connettersi alla rete WiFi utilizzando l'SSID e la password forniti.
   #. Stampa lo stato della connessione WiFi (SSID, IP, Intensità del segnale).
   #. Inizializza il display OLED.
   #. Avvia il client NTP per recuperare l'ora corrente e imposta un offset temporale (in questo caso, 1 ora, che potrebbe corrispondere a un fuso orario specifico).

3. ``read_response()``:

   #. Legge la risposta dal server, cercando specificamente dati JSON (denotati da ``{`` e ``}``).
   #. Se vengono trovati dati JSON, li decodifica per estrarre dettagli meteo come temperatura, umidità, pressione, velocità del vento e direzione del vento.
   #. Chiama la funzione ``displayWeatherData`` per visualizzare le informazioni meteorologiche sullo schermo OLED.

4. ``httpRequest()``:

   #. Chiude eventuali connessioni esistenti per garantire che il socket del modulo WiFi sia libero.
   #. Tenta di connettersi al server OpenWeatherMap.
   #. Se connesso, invia una richiesta GET HTTP per recuperare i dati meteorologici per una specifica posizione definita da ``LOCATION`` (probabilmente definita in ``arduino_secrets.h`` o altrove).
   #. Registra l'ora in cui è stata effettuata la richiesta.

5. ``loop()``:

   #. Chiama la funzione ``read_response`` per elaborare eventuali dati in arrivo dal server.
   #. Aggiorna l'ora dal server NTP.
   #. Verifica se è il momento di effettuare un'altra richiesta al server meteorologico (basato sull'intervallo di pubblicazione, ``postingInterval``). Se sì, chiama la funzione ``httpRequest``.

6. ``printWifiStatus()``:

   #. Stampa l'SSID della rete connessa.
   #. Stampa l'indirizzo IP locale della scheda.
   #. Stampa l'intensità del segnale (RSSI).

7. ``displayWeatherData()``:

   #. Cancella lo schermo OLED.
   #. Visualizza il giorno della settimana corrente.
   #. Visualizza l'ora corrente nel formato HH:MM.
   #. Visualizza i dati meteorologici forniti (temperatura, umidità, pressione e velocità del vento).
