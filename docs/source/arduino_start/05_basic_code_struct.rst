.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Struttura di un Programma Arduino
======================================

Diamo un'occhiata al nuovo file sketch. Anche se contiene poche righe di codice, è in realtà uno sketch "vuoto". 
Caricare questo sketch sulla scheda di sviluppo non produrrà alcun effetto.

.. code-block:: C

    void setup() {
    // inserisci qui il tuo codice di setup, da eseguire una sola volta:

    }

    void loop() {
    // inserisci qui il tuo codice principale, da eseguire ripetutamente:

    }

Se rimuoviamo ``setup()`` e ``loop()`` e rendiamo lo sketch un vero file ``blank``, scoprirai che non passerà la verifica. 
Sono l'equivalente dello scheletro umano, e sono indispensabili.

Durante l'esecuzione di uno sketch, ``setup()`` viene eseguito per primo e il codice al suo interno (all'interno delle ``{}``) viene eseguito dopo che la scheda è stata alimentata o ripristinata e solo una volta. 
``loop()`` viene utilizzato per scrivere la funzione principale, e il codice al suo interno verrà eseguito in un ciclo continuo dopo l'esecuzione di ``setup()``.

Per comprendere meglio ``setup()`` e ``loop()``, utilizziamo quattro sketch. Il loro scopo è far lampeggiare il LED integrato dell'Arduino. Esegui ogni esperimento a turno e annota i loro effetti specifici.

* Sketch 1: Far lampeggiare continuamente il LED integrato.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Far lampeggiare il LED integrato una sola volta. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
    }

* Sketch 3: Far lampeggiare il LED integrato lentamente una volta e poi velocemente. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Segnalare un errore.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
    }    

Con l'aiuto di questi sketch, possiamo riassumere diverse caratteristiche di ``setup-loop``.

* ``loop()`` verrà eseguito ripetutamente dopo che la scheda è stata alimentata. 
* ``setup()`` verrà eseguito una sola volta dopo che la scheda è stata alimentata. 
* Dopo che la scheda è stata alimentata, ``setup()`` verrà eseguito per primo, seguito da ``loop()``. 
* Il codice deve essere scritto all'interno delle ``{}`` di ``setup()`` o ``loop()``, al di fuori del framework si verificherà un errore.

.. note::  
    I comandi come ``digitalWrite(13,HIGH)`` vengono utilizzati per controllare il LED integrato, e parleremo del loro utilizzo in dettaglio nei capitoli successivi.
