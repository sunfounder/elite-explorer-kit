.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _iot_arduino_cloud:

Arduino IoT Cloud
===========================

Questo esempio dimostra il codice per comunicare con l'Arduino IoT Cloud. Il suo scopo è connettersi all'Arduino IoT Cloud e interagire con le variabili cloud. In questo caso, inviamo i valori di temperatura letti dal sensore DHT11 all'Arduino IoT Cloud, permettendoci di monitorarli dal cloud.

.. image:: img/02_cloud.png

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**Collegamenti**

.. image:: img/02_arduino_iot_cloud_bb.png
    :width: 90%
    :align: center

.. raw:: html
    
    <br/>


**Schema Elettrico**

.. image:: img/02_arduino_iot_cloud_schematic.png
  :width: 40%
  :align: center


**Installa Arduino Create Agent**

1. Visita l'indirizzo https://create.arduino.cc/getting-started/plugin/welcome.

2. Clicca su START.

  .. image:: img/02_install_agent_2.png
     :width: 95%

3. Scegli la versione adatta al tuo computer e scarica il pacchetto di installazione.

  .. image:: img/02_install_agent_3.png
     :width: 95%

4. Installa l'agent.

  .. image:: img/02_install_agent_4.png
    :width: 85%

5. Dopo l'installazione, torna al tuo browser e vedrai la seguente interfaccia.

  .. image:: img/02_install_agent_5.png
     :width: 95%

6. Clicca su NEXT e poi puoi andare al web editor.

  .. image:: img/02_install_agent_6.png
     :width: 95%

**Utilizzare Arduino IoT Cloud**

1. Prima, devi effettuare il login o registrarti su Arduino.

  https://login.arduino.cc/login

2. Una volta effettuato l'accesso, clicca su IoT Cloud nell'angolo in alto a destra.

   .. image:: img/02_iot_cloud_2.png

3. Crea una nuova cosa.

   .. image:: img/02_iot_cloud_3.png
  
4. Associa il tuo dispositivo.

   .. image:: img/02_iot_cloud_4.png

5. Configura un nuovo dispositivo.

   .. image:: img/02_iot_cloud_5.png


6. Scegli la tua scheda Arduino.
 
   .. image:: img/02_iot_cloud_6.png


7. Attendi un momento, e il tuo UNO R4 WiFi sarà rilevato. Continua cliccando su configura.
 
   .. image:: img/02_iot_cloud_7.png

 
8. Dai un nome al tuo dispositivo.

  .. image:: img/02_iot_cloud_8.png


9. Rendi il tuo dispositivo pronto per l'IoT e ricorda di salvare la chiave segreta.

  .. image:: img/02_iot_cloud_9.png


10. Attendi qualche minuto.

  .. image:: img/02_iot_cloud_10.png

.. 5. Select Arduino UNO R4 WiFi.

.. .. image:: img/sp231016_164654.png

11. Configura il WiFi.

  .. image:: img/02_iot_cloud_11.png


12. Qui dovrai inserire la password del tuo WiFi e la chiave segreta.

  .. image:: img/02_iot_cloud_12.png


13. Aggiungi una variabile.

  .. image:: img/02_iot_cloud_13.png


14. Qui vogliamo visualizzare la temperatura nell'IoT Cloud, quindi configuriamo una variabile float di sola lettura.

  .. image:: img/02_iot_cloud_14.png


15. Dopo aver completato, vai allo sketch.

  .. image:: img/02_iot_cloud_15.png


16. Apri l'editor completo.

  .. image:: img/02_iot_cloud_16.png


17. Clicca su Libraries sul lato destro, poi Library Manager.

  .. image:: img/02_iot_cloud_17.png


18. Cerca la libreria del sensore DHT e selezionala.

  .. image:: img/02_iot_cloud_18.png


19. Ora, dobbiamo modificare il codice. Puoi vedere che l'editor ha già preparato il codice relativo all'IoT Cloud per te. Devi solo aggiungere la funzionalità specifica di cui hai bisogno. In questo esempio, abbiamo aggiunto il codice per leggere la temperatura utilizzando il sensore DHT11.

  .. code-block::
      :emphasize-lines: 1,2,3,22,23,24,32,55,56
  
      // Libreria sensore DHT - Versione: Latest 
      #include <DHT.h>
      #include <DHT_U.h>
  
      /* 
      Sketch generato dalla Thing "Untitled" di Arduino IoT Cloud
      https://create.arduino.cc/cloud/things/260edac8-34f9-4e2e-9214-ba0c20994220 
  
      Descrizione delle variabili di Arduino IoT Cloud
  
      Le seguenti variabili sono generate e aggiornate automaticamente quando vengono apportate modifiche alla Thing
  
      float temperature;
  
      Le variabili contrassegnate come READ/WRITE nella Thing del Cloud avranno anche funzioni
      che vengono chiamate quando i loro valori vengono modificati dalla Dashboard.
      Queste funzioni vengono generate con la Thing e aggiunte alla fine di questo sketch.
      */
  
      #include "thingProperties.h"
  
      #define DHTPIN 11     
      #define DHTTYPE DHT11 
      DHT dht(DHTPIN, DHTTYPE);
  
      void setup() {
          // Inizializza la seriale e attendi l'apertura della porta:
          Serial.begin(9600);
          // Questo ritardo dà la possibilità di attendere il Monitor Serial senza bloccarsi se non viene trovato
          delay(1500); 
  
          dht.begin();
  
          // Definito in thingProperties.h
          initProperties();
  
          // Connettiti ad Arduino IoT Cloud
          ArduinoCloud.begin(ArduinoIoTPreferredConnection);
          
          /*
              La seguente funzione permette di ottenere maggiori informazioni
              relative allo stato della connessione di rete e IoT Cloud e agli errori
              maggiore è il numero, più granulari saranno le informazioni ottenute.
              Il valore predefinito è 0 (solo errori).
              Il massimo è 4
          */
          setDebugMessageLevel(2);
          ArduinoCloud.printDebugInfo();
      }
  
      void loop() {
          ArduinoCloud.update();
          // Il tuo codice qui 
          
          float temp = dht.readTemperature();  
          temperature = temp;
          
      }
 
20. Carica il codice. Potrebbe essere richiesto un aggiornamento; segui le istruzioni per completarlo.

  .. image:: img/02_iot_cloud_20.png


21. Torna su IoT CLOUD.

  .. image:: img/02_iot_cloud_21.png


22. Clicca sul menu nell'angolo in alto a sinistra.
  
  .. image:: img/02_iot_cloud_22.png


23. Clicca su dashboard.
  
  .. image:: img/02_iot_cloud_23.png


24. Crea una dashboard.
  
  .. image:: img/02_iot_cloud_24.png


25. Ci sono molti widget disponibili; qui, scegliamo un widget di valore per visualizzare la temperatura.

  .. image:: img/02_iot_cloud_25.png


26. Dopo aver cliccato, apparirà un'interfaccia di impostazioni del widget, dove puoi collegare il widget alla variabile cloud che hai creato in precedenza.

  .. image:: img/02_iot_cloud_26.png


27. Ora, puoi visualizzare le letture del sensore su Arduino IoT Cloud.

  .. image:: img/02_iot_cloud_27.png



**Come funziona?**


Dopo aver configurato l'IoT Cloud (configurazione del dispositivo, configurazione della rete, creazione delle variabili cloud), noterai che lo sketch sul cloud si aggiorna automaticamente. Quindi, la maggior parte del codice è già scritta per te.

Apri l'editor e vedrai che questo sketch contiene quattro file:

``main.ino``: Utilizzato per inizializzare Arduino e svolgere i compiti principali del loop. Inoltre, include la logica per connettersi e comunicare con Arduino IoT Cloud.

``thingProperties.h``: Questo file viene utilizzato per definire variabili e funzioni nell'Arduino IoT Cloud. Contiene le dichiarazioni delle variabili cloud e delle loro funzioni di callback associate. Nel codice fornito, viene utilizzato per inizializzare le proprietà cloud (ad esempio, la variabile temperature) e connettersi all'Arduino IoT Cloud.

``Secret``: Utilizzato per memorizzare informazioni sensibili o private, come password WiFi o chiavi API. Queste informazioni sensibili non sono tipicamente esposte direttamente nel codice, ma vengono memorizzate nel file Secret per migliorare la sicurezza.

``ReadMe.adoc``: Contiene la documentazione del progetto o altre informazioni pertinenti per una più facile comprensione e utilizzo del progetto. Questo file di solito non contiene codice eseguibile, ma piuttosto informazioni documentali e descrittive.

Dobbiamo aggiungere un po' di codice per il sensore DHT11. Questo codice è identico a quello che utilizzeresti nel tuo IDE locale. L'unica differenza è che devi assegnare il valore letto dal DHT11 alla variabile cloud ``temperature``.

(Nota: Non dovresti mai modificare ``thingProperties.h`` e ``Secret``. Verranno modificati quando apporterai modifiche utilizzando l'editor Thing.)

