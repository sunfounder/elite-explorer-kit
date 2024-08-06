.. note::
    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _iot_security_system_ifttt:

Sistema di Sicurezza via IFTTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/03_iot_security_alert.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Con questo progetto, creiamo un dispositivo di sicurezza che utilizza un sensore PIR per rilevare intrusi o animali randagi che entrano nella tua casa. In caso di violazione, riceverai un avviso via email.

Utilizzeremo Webhooks come servizio fondamentale. Una richiesta POST viene inviata al servizio di IFTTT dall'UNO R4.

**Componenti necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

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

    *   - INTRODUZIONE COMPONENTI
        - LINK ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Collegamenti**

.. image:: img/03-ifttt_pir_bb.png
    :width: 90%
    :align: center

**Schema**

.. image:: img/03-ifttt_pir_schematic.png
   :width: 50%
   :align: center

**Configurazione di IFTTT**

IFTTT è un servizio gratuito che offre vari metodi per collegare diversi servizi dati tra loro.

Creiamo un Applet che risponde a un webhook (URL personalizzato) inviando dati a IFTTT, che poi ti invierà un'email.

Segui i passaggi seguenti su IFTTT.

1. Visita |link_ifttt| per accedere o creare un account.

   .. image:: img/03_ifttt_1.png
       :width: 90%

2. Clicca su **Create**.

   .. image:: img/03_ifttt_2.png
       :width: 90%

3. Aggiungi un evento **If This**.

   .. image:: img/03_ifttt_3.png
       :width: 70%

4. Cerca **Webhooks**.

   .. image:: img/03_ifttt_4.png
       :width: 70%

5. Seleziona **Receive a web request**.

   .. image:: img/03_ifttt_5.png
       :width: 90%

6. Compila il nome dell'evento (es. SecurityWarning) e clicca su **Create trigger**.

   .. image:: img/03_ifttt_6.png
       :width: 70%

7. Aggiungi un evento **Then That**.

   .. image:: img/03_ifttt_7.png
       :width: 70%

8. Cerca Email.

   .. image:: img/03_ifttt_8.png
       :width: 80%

9. Scegli **Send me an email**.

   .. image:: img/03_ifttt_9.png
       :width: 80%

10. Inserisci l'**Oggetto** e il **Corpo**, quindi clicca su **Create action**.

   .. image:: img/03_ifttt_10.png
       :width: 70%

11. Clicca su **Continue** per terminare la configurazione.

   .. image:: img/03_ifttt_11.png
       :width: 70%

12. Regola il nome del titolo se necessario.

   .. image:: img/03_ifttt_12.png
       :width: 80%

13. Verrai reindirizzato automaticamente alla pagina dei dettagli dell'Applet, dove puoi vedere che l'Applet è attualmente connesso e puoi attivare/disattivare l'interruttore per abilitarlo/disabilitarlo.

   .. image:: img/03_ifttt_13.png
       :width: 70%

14. Ora che abbiamo creato l'Applet IFTTT, abbiamo anche bisogno della chiave webhooks, che può essere ottenuta da |link_webhooks| per permettere al tuo dispositivo di accedere a IFTTT.

   .. image:: img/03_ifttt_14.png

15. Copia la chiave webhooks in "arduino_secrets.h" e inserisci il tuo SSID e password.

    .. code-block:: arduino
    
        #define SECRET_SSID "your_ssid"        // your network SSID (name)
        #define SECRET_PASS "your_password"        // your network password (used for WPA, or as a key for WEP)
        #define WEBHOOKS_KEY "your_key"

**Esegui il codice**

.. note::
    * Puoi aprire il file ``03_ifttt_pir.ino`` nel percorso ``elite-explorer-kit-main\iot_project\03_ifttt_pir`` direttamente.
    * Oppure copia questo codice nell'IDE Arduino.

.. note::    Nel codice, SSID e password sono memorizzati in ``arduino_secrets.h``. Prima di caricare questo esempio, devi modificarli con le tue credenziali WiFi. Inoltre, per motivi di sicurezza, assicurati che queste informazioni siano mantenute riservate quando condividi o memorizzi il codice.

.. warning::
   Per evitare che la tua casella di posta venga inondata, ti preghiamo di testare in anticipo il :ref:`cpn_pir` prima di eseguire il codice per questo progetto.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/adec1608-4642-4469-bdf4-8dc3e3e4ce4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
 
**Come funziona?**

1. Includi le librerie necessarie e i file header:

   * ``"WiFiS3.h"``: Utilizzata per gestire le connessioni Wi-Fi.
   * ``"arduino_secrets.h"``: Contiene il nome della rete Wi-Fi e la password per proteggere le informazioni sensibili.

2. Definisci alcune variabili globali e costanti:

   * ``ssid``: Nome della rete Wi-Fi.
   * ``pass``: Password della rete Wi-Fi.
   * ``status``: Stato della connessione Wi-Fi.
   * ``client``: Client utilizzato per comunicare con il server Wi-Fi.
   * ``server``: Indirizzo del server Webhook di IFTTT.
   * ``event``: Nome dell'evento Webhook di IFTTT.
   * ``webRequestURL``: URL costruito per l'invio delle richieste HTTP, incluso il nome dell'evento Webhook e la chiave.
   * ``pirPin``: Pin digitale a cui è collegato il sensore PIR.
   * ``motionDetected``: Variabile flag per monitorare la rilevazione di movimento.

3. Funzione ``setup()``:

   * Inizializza la comunicazione seriale.
   * Verifica la presenza del modulo Wi-Fi e stampa la sua versione firmware.
   * Tenta di connettersi alla rete Wi-Fi, con ritenti in caso di fallimento.
   * Imposta il pin collegato al sensore PIR come input.

4. Funzione ``readResponse()``:

   * Legge i dati di risposta HTTP dal server IFTTT e li stampa sulla console seriale.

5. Funzione ``loop()``:

   * Chiama la funzione ``readResponse()`` per leggere i dati di risposta HTTP.
   * Controlla il movimento utilizzando il sensore PIR. Se viene rilevato movimento e non era stato rilevato in precedenza:
       * Stampa "Movimento rilevato!" sulla console.
       * Chiama la funzione ``triggerIFTTTEvent()`` per inviare una richiesta HTTP al server IFTTT, attivando l'evento Webhook.
       * Imposta il flag ``motionDetected`` su ``true`` per indicare che è stato rilevato un movimento.
   * Se non viene rilevato alcun movimento, imposta il flag ``motionDetected`` su ``false``.

6. Funzione ``triggerIFTTTEvent()``:

   * Stabilisce una connessione con il server IFTTT.
   * Invia una richiesta HTTP GET, includendo l'URL dell'evento Webhook e altre intestazioni HTTP.

7. Funzione ``printWifiStatus()``:

   * Mostra informazioni sulla rete Wi-Fi connessa, inclusi SSID, indirizzo IP e intensità del segnale (RSSI) sulla console seriale.
