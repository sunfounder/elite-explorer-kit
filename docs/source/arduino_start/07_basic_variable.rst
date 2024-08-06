.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Variabile
==============

La variabile è uno degli strumenti più potenti e critici in un programma. Ci aiuta a memorizzare e richiamare dati nei nostri programmi.

Il seguente file sketch utilizza le variabili. Memorizza i numeri dei pin del LED integrato nella variabile ``ledPin`` e il numero "500" nella variabile ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Aspetta, è una duplicazione di ciò che fa ``#define``? La risposta è NO.

* Il ruolo di ``#define`` è semplicemente e direttamente quello di sostituire il testo, non è considerato dal compilatore come parte del programma.
* Una ``variabile``, d'altra parte, esiste all'interno del programma e viene utilizzata per memorizzare e richiamare valori. Una variabile può anche modificare il proprio valore all'interno del programma, cosa che un define non può fare.

Il file sketch qui sotto aggiunge automaticamente un valore alla variabile e farà sì che il LED integrato lampeggi più a lungo dopo ogni lampeggio.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Ogni esecuzione incrementa il valore di 200
    }

Dichiarare una variabile
-----------------------------

Dichiarare una variabile significa creare una variabile.

Per dichiarare una variabile, hai bisogno di due cose: il tipo di dato e il nome della variabile. Il tipo di dato deve essere separato dal nome della variabile da uno spazio, e la dichiarazione della variabile deve essere terminata da un ``;``.

Usiamo questa variabile come esempio.

.. code-block:: C

    int delayTime;

**Tipo di dato**

Qui ``int`` è un tipo di dato chiamato intero, che può essere utilizzato per memorizzare interi da -32768 a 32766. Non può essere utilizzato per memorizzare decimali.

Le variabili possono contenere diversi tipi di dati oltre agli interi. Il linguaggio Arduino (che, ricordiamo, è C++) ha un supporto integrato per alcuni di essi (solo quelli più frequentemente usati e utili sono elencati qui):

* ``float``: Memorizza un numero decimale, per esempio 3.1415926.
* ``byte``: Può contenere numeri da 0 a 255.
* ``boolean``: Contiene solo due valori possibili, ``True`` o ``False``, anche se occupa un byte in memoria.
* ``char``: Contiene un numero da -127 a 127. Poiché è contrassegnato come ``char`` il compilatore cercherà di abbinarlo a un carattere dal |link_ascii|.
* ``string``: Può memorizzare una stringa di caratteri, ad esempio ``Halloween``.

**Nome della variabile**

Puoi assegnare alla variabile qualsiasi nome desideri, come ``i``, ``mela``, ``Bruce``, ``R2D2``, ``Sectumsempra``, ma ci sono alcune regole di base da seguire.

1. Descrivi a cosa serve. Qui, ho chiamato la variabile delayTime, così puoi capire facilmente cosa fa. Funzionerebbe anche se chiamassi la variabile ``barryAllen``, ma confonderebbe la persona che guarda il codice.

2. Usa una nomenclatura regolare. Puoi usare il CamelCase come ho fatto io, con la T iniziale in ``delayTime`` così è facile vedere che la variabile è composta da due parole. Puoi anche usare l'UnderScoreCase per scrivere la variabile come ``delay_time``. Non influisce sull'esecuzione del programma, ma aiuterebbe il programmatore a leggere il codice se usi la nomenclatura che preferisci.

3. Non usare parole chiave. Simile a ciò che accade quando digitiamo "int", l'IDE di Arduino lo colorerà per ricordarti che è una parola con uno scopo speciale e non può essere usata come nome di variabile. Cambia il nome della variabile se è colorata.

4. Simboli speciali non sono consentiti. Ad esempio, spazio, #, $, /, +, %, ecc. La combinazione di lettere inglesi (case sensitive), trattini bassi e numeri (ma i numeri non possono essere utilizzati come primo carattere di un nome di variabile) è sufficientemente ricca.

**Assegnare un valore a una variabile**

Una volta dichiarata la variabile, è il momento di memorizzare i dati. Utilizziamo l'operatore di assegnazione (cioè ``=``) per inserire il valore nella variabile.

Possiamo assegnare valori alla variabile non appena la dichiariamo.

.. code-block:: C

    int delayTime = 500;

È anche possibile assegnare un nuovo valore in seguito.

.. code-block:: C

    int delayTime; // nessun valore
    delayTime = 500; // valore è 500
    delayTime = delayTime +200; // valore è 700
