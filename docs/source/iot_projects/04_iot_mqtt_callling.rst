.. note::

    Ciao, benvenuto nella community degli appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Apprendimento e Condivisione**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri ultimi prodotti.
    - **Promozioni Festive e Concorsi**: Partecipa a concorsi e promozioni speciali.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _iot_mqtt_publish:

Sistema di Chiamata Cloud con MQTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/04_iot_mqtt_callling.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Il protocollo di messaggistica Message Queuing Telemetry Transport (MQTT) è semplice ma ampiamente utilizzato nel campo dell'Internet delle cose (IoT).

I protocolli MQTT definiscono come i dispositivi IoT scambiano dati. Operano in modo event-driven e sono interconnessi utilizzando il modello Publish/Subscribe. Il mittente (Publisher) e il ricevente (Subscriber) comunicano tramite Topics. Un dispositivo pubblica un messaggio su un topic specifico e tutti i dispositivi abbonati a quel topic ricevono il messaggio.

In questa sezione, creeremo un sistema di campanello di servizio utilizzando UNO R4, HiveMQ (un servizio broker MQTT pubblico gratuito) e quattro pulsanti. Ogni pulsante corrisponde a un tavolo del ristorante e quando un cliente preme un pulsante, sarà possibile vedere quale tavolo ha bisogno di assistenza su HiveMQ.

**Componenti Necessari**

Per questo progetto, sono necessari i seguenti componenti.

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
        - LINK DI ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Cablaggio**

.. image:: img/04_mqtt_button_bb.png
   :width: 70%
   :align: center

**Schema**

.. image:: img/04_mqtt_button_schematic.png
   :width: 50%
   :align: center

**Come Funziona?**

HiveMQ è una piattaforma di messaggistica basata su broker MQTT che facilita il trasferimento rapido, efficiente e affidabile dei dati ai dispositivi IoT.

1. Apri |link_hivemq| nel tuo browser web.

2. Collega il client al proxy pubblico predefinito.

   .. image:: img/04_mqtt_1.png

3. Clicca su **Aggiungi Nuova Sottoscrizione Topic**.

   .. image:: img/04_mqtt_2.png

4. Inserisci i topic che desideri seguire e clicca su **Sottoscrivi**. Assicurati che i topic che imposti qui siano unici per evitare di ricevere messaggi da altri utenti e presta attenzione alla sensibilità delle maiuscole e minuscole.

   In questo esempio di codice, impostiamo il topic come ``SunFounder MQTT Test``. Se hai apportato modifiche, assicurati che il topic nel codice corrisponda al topic sottoscritto sulla pagina web.

   .. image:: img/04_mqtt_3.png

**Installazione della Libreria**

Per installare la libreria, utilizza il Gestore delle Librerie Arduino e cerca "ArduinoMqttClient" e installalo.

``ArduinoMqttClient.h``: Utilizzato per la comunicazione MQTT.

**Esecuzione del Codice**

.. note::

    * Puoi aprire il file ``04_mqtt_button.ino`` nel percorso ``elite-explorer-kit-main\iot_project\04_mqtt_button`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note::
    Nel codice, SSID e password sono memorizzati in ``arduino_secrets.h``. Prima di caricare questo esempio, è necessario modificarli con le proprie credenziali WiFi. Inoltre, per motivi di sicurezza, assicurati che queste informazioni siano mantenute riservate durante la condivisione o la memorizzazione del codice.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7a4acdf8-beed-47d4-ada8-cbaab0f3477f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver eseguito il codice, torna su |link_hivemq| e quando premi uno dei pulsanti sulla breadboard, vedrai il prompt Messaggi su HiveMQ.

    .. image:: img/04_mqtt_4.png

**Funzionamento del Codice**

Questo codice è per un progetto basato su Arduino che si connette al WiFi e comunica con un broker MQTT utilizzando il protocollo MQTT. Inoltre, può rilevare se quattro pulsanti sono premuti e inviare i messaggi corrispondenti al broker MQTT.

Ecco una spiegazione dettagliata del codice:

1. **Includi Librerie Pertinenti**:

   .. code-block:: Arduino
       
       #include <WiFiS3.h>
       #include <ArduinoMqttClient.h>

2. **Includi Informazioni Sensibili**:

   * Il file ``arduino_secrets.h`` contiene l'SSID e la password per la rete WiFi.
   
   .. code-block:: Arduino
       
       #include "arduino_secrets.h" 
       char ssid[] = SECRET_SSID;   
       char pass[] = SECRET_PASS;   

3. **Inizializza Variabili**:

   * Variabili per gestire le connessioni WiFi e MQTT.
   * Inizializza pin dei pulsanti e stati dei pulsanti.

4. ``setup()``:

   * Inizializza la comunicazione seriale.
   * Verifica la presenza del modulo WiFi e tenta di connettersi al WiFi.
   * Stampa dati di rete.
   * Tentativo di connessione al broker MQTT.
   * Sottoscrivi i topic MQTT.
   * Imposta i pulsanti in modalità input.

5. ``loop()``:

   * Mantieni attiva la connessione MQTT.
   * Verifica se ogni pulsante è premuto e, in caso affermativo, invia messaggi MQTT.

6. **Altre Funzioni di Utilità**:

   * ``printWifiData()``: Stampa informazioni sulla rete WiFi attualmente connessa.
   * ``printCurrentNet()``: Stampa dati rilevanti sulla rete attuale.
   * ``printMacAddress(byte mac[])``: Stampa l'indirizzo MAC.
   * ``onMqttMessage(int messageSize)``: Funzione di callback attivata quando viene ricevuto un messaggio dal broker MQTT. Stampa il topic del messaggio ricevuto e il contenuto.
   * ``sendButtonMessage(int buttonNumber)``: Usa questa funzione per inviare messaggi MQTT quando viene premuto un pulsante.
