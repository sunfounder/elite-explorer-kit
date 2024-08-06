.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_stepper_motor:

Motore Passo-Passo
=========================

.. image:: img/stepper_motor2.jpeg
   :align: center

I motori passo-passo, grazie al loro design unico, possono essere controllati con un alto grado di precisione senza alcun meccanismo di feedback. L'albero di un motore passo-passo, dotato di una serie di magneti, è controllato da una serie di bobine elettromagnetiche che vengono caricate positivamente e negativamente in una sequenza specifica, muovendolo esattamente in avanti o indietro in piccoli "passi".

**Principio**

Ci sono due tipi di motori passo-passo, unipolari e bipolari, ed è molto importante sapere quale tipo stai utilizzando. In questo esperimento, useremo un motore passo-passo unipolare.

Il motore passo-passo è un motore a quattro fasi, che utilizza un'alimentazione a corrente continua unipolare. Finché si alimentano tutte le fasi del motore con una sequenza temporale appropriata, è possibile farlo ruotare passo dopo passo. Il diagramma schematico di un motore passo-passo reattivo a quattro fasi:

.. image:: img/stepper_motor3.png
   :align: center

Nella figura, al centro del motore c'è un rotore - un magnete permanente a forma di ingranaggio. Intorno al rotore, da 0 a 5 ci sono i denti. Più esternamente, ci sono 8 poli magnetici, con ciascuna coppia opposta collegata da un avvolgimento di bobina. Quindi formano quattro coppie da A a D, che è chiamata fase. Ha quattro fili di piombo da collegare agli interruttori SA, SB, SC e SD. Pertanto, le quattro fasi sono in parallelo nel circuito, e i due poli magnetici in una fase sono in serie.

**Ecco come funziona un motore passo-passo a 4 fasi:**

All'inizio, l'interruttore SB è acceso, gli interruttori SA, SC e SD sono spenti, e i poli magnetici della fase B si allineano con i denti 0 e 3 del rotore. Allo stesso tempo, i denti 1 e 4 generano denti sfalsati con i poli delle fasi C e D. I denti 2 e 5 generano denti sfalsati con i poli magnetici delle fasi D e A. Quando l'interruttore SC è acceso, gli interruttori SB, SA e SD sono spenti, il rotore ruota sotto il campo magnetico dell'avvolgimento della fase C e quello tra i denti 1 e 4. Poi i denti 1 e 4 si allineano con i poli magnetici dell'avvolgimento della fase C. Mentre i denti 0 e 3 generano denti sfalsati con i poli delle fasi A e B, e i denti 2 e 5 generano denti sfalsati con i poli magnetici delle fasi A e D. La situazione simile continua. Alimenta le fasi A, B, C e D in successione, e il rotore ruoterà nell'ordine di A, B, C e D.

Il motore passo-passo a quattro fasi ha tre modalità operative: singolo passo a quattro fasi, doppio passo a quattro fasi e otto passi. L'angolo di passo per il singolo passo a quattro fasi e il doppio passo a quattro fasi è lo stesso, ma la coppia motrice per il singolo passo a quattro fasi è più piccola. L'angolo di passo dell'otto passi è la metà di quello del singolo passo a quattro fasi e del doppio passo a quattro fasi. Pertanto, la modalità operativa a otto passi può mantenere una coppia motrice elevata e migliorare la precisione del controllo. In questo esperimento, faremo funzionare il motore passo-passo in modalità otto passi.

**Modulo ULN2003**

.. image:: img/uln2003.png
    :align: center

Per applicare il motore nel circuito, è necessario utilizzare una scheda driver. Il Driver del Motore Passo-Passo ULN2003 è un circuito invertitore a 7 canali. Cioè, quando l'estremità di ingresso è ad alto livello, l'estremità di uscita dell'ULN2003 è a basso livello, e viceversa. Se forniamo un livello alto a IN1, e un livello basso a IN2, IN3 e IN4, allora l'estremità di uscita OUT1 è a basso livello, e tutte le altre estremità di uscita sono ad alto livello. Quindi D1 si accende, l'interruttore SA è acceso, e il motore passo-passo ruota di un passo. Il caso simile si ripete. Pertanto, basta dare al motore passo-passo una sequenza temporale specifica, e ruoterà passo dopo passo. L'ULN2003 qui è utilizzato per fornire sequenze temporali particolari per il motore passo-passo.


**Esempio**


* :ref:`basic_stepper_motor` (Progetto di Base)
* :ref:`fun_access` (Progetto Divertente)
