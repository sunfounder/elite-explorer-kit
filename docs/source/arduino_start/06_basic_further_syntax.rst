.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Regole per Scrivere uno Sketch
==================================

Se chiedi a un amico di accendere le luci, puoi dire "Accendi le luci.", oppure "Luci accese, amico.", puoi usare qualsiasi tono di voce tu voglia.

Tuttavia, se vuoi che la scheda Arduino faccia qualcosa per te, devi seguire le regole di scrittura del programma Arduino per digitare i comandi.

Questo capitolo contiene le regole di base del linguaggio Arduino e ti aiuterà a capire come tradurre il linguaggio naturale in codice.

Ovviamente, questo è un processo che richiede tempo per essere familiarizzato, ed è anche la parte più soggetta a errori per i principianti, quindi se commetti spesso errori, va bene, basta provare qualche altra volta.

Punto e virgola ``;``
-------------------------

Proprio come quando scrivi una lettera, dove metti un punto alla fine di ogni frase come fine, il linguaggio Arduino richiede di usare ``;`` per dire alla scheda la fine del comando.

Prendiamo l'esempio familiare del "lampeggio del LED integrato". Uno sketch corretto dovrebbe apparire così.

Esempio:

.. code-block:: C

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

Ora, diamo un'occhiata ai due sketch seguenti e indoviniamo se possono essere correttamente riconosciuti da Arduino prima di eseguirli.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una sola volta:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Il risultato è che **Sketch A** segnala un errore e **Sketch B** funziona.

* Gli errori in **Sketch A** sono dovuti alla mancanza di ``;`` e anche se sembra normale, l'Arduino non può leggerlo.
* **Sketch B**, sembra anti-umano, ma in realtà, l'indentazione, le interruzioni di linea e gli spazi nelle istruzioni non esistono nei programmi Arduino, quindi per il compilatore Arduino, appare uguale all'esempio.

Tuttavia, per favore non scrivere il tuo codice come **Sketch B**, perché di solito sono le persone naturali che scrivono e visualizzano il codice, quindi non complicarti la vita.

Parentesi graffe ``{}``
----------------------------

``{}`` sono il componente principale del linguaggio di programmazione Arduino, e devono apparire in coppia. 
Una migliore convenzione di programmazione è inserire una struttura che richiede parentesi graffe digitando direttamente la parentesi graffa destra dopo aver digitato la parentesi graffa sinistra, e poi spostare il cursore tra le parentesi graffe per inserire l'istruzione.


Comment ``//``
---------------

Il commento è la parte dello sketch che il compilatore ignora. Di solito vengono utilizzati per spiegare agli altri come funziona il programma.

Se scriviamo due barre oblique consecutive in una riga di codice, il compilatore ignorerà tutto fino alla fine della riga.

Se creiamo un nuovo sketch, questo verrà fornito con due commenti e, se rimuoviamo questi due commenti, lo sketch non sarà in alcun modo influenzato.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // inserisci qui il tuo codice di setup, da eseguire una volta:

    }

    void loop() {
        // inserisci qui il tuo codice principale, da eseguire ripetutamente:

    }


Il commento è molto utile nella programmazione, e di seguito sono elencati alcuni usi comuni.

* Utilizzo A: Spiega a te stesso o agli altri cosa fa questa sezione di codice.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Imposta il pin 13 in modalità output, controlla il LED integrato
    }

    void loop() {
        digitalWrite(13,HIGH); // Attiva il LED integrato impostando il pin 13 su HIGH
        delay(500); // Stato attuale per 500 ms
        digitalWrite(13,LOW); // Spegne il LED integrato
        delay(500); // Stato attuale per 500 ms
    }

* Utilizzo B: Invalida temporaneamente alcune istruzioni (senza eliminarle) e rimuovi il commento quando hai bisogno di usarle, così non dovrai riscriverle. Questo è molto utile quando si esegue il debug del codice e si cerca di individuare gli errori del programma.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }

.. note:: 
    Utilizza la scorciatoia ``Ctrl+/`` per commentare o rimuovere rapidamente il commento dal tuo codice.

Comment ``/**/``
------------------

Simile a ``//`` per i commenti. Questo tipo di commento può essere più lungo di una riga e una volta che il compilatore legge ``/*``, ignora tutto ciò che segue fino a quando non incontra ``*/``.

Esempio 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        Il seguente codice farà lampeggiare il LED integrato
        Puoi modificare il numero in delay() per cambiare la frequenza del lampeggio
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``#define``
--------------

Questo è uno strumento utile di C++.

.. code-block:: C

    #define identificatore stringa-di-token

Il compilatore sostituisce automaticamente ``identificatore`` con ``stringa-di-token`` quando lo legge, solitamente utilizzato per le definizioni di costanti.

Ad esempio, ecco uno sketch che utilizza define, il che migliora la leggibilità del codice.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Per il compilatore, in realtà appare così.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Possiamo vedere che ``identificatore`` è sostituito e non esiste all'interno del programma.
Pertanto, ci sono diverse avvertenze quando si utilizza.

1. Una ``stringa-di-token`` può essere modificata solo manualmente e non può essere convertita in altri valori tramite aritmetica nel programma.

2. Evitare l'uso di simboli come ``;``. Ad esempio.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Il compilatore lo riconoscerà come segue, il che verrà segnalato come errore.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Una convenzione di denominazione per ``#define`` è quella di capitalizzare ``identificatore`` per evitare confusione con le variabili.
