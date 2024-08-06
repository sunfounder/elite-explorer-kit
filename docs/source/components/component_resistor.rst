.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_resistor:

Resistenza
==============

.. image:: img/resistor.png
    :width: 300

La resistenza è un elemento elettronico che può limitare la corrente di un ramo di circuito. 
Una resistenza fissa è un tipo di resistenza il cui valore non può essere cambiato, mentre quello di un potenziometro o di una resistenza variabile può essere regolato. 

Due simboli di circuito generalmente usati per la resistenza. Normalmente, il valore della resistenza è indicato su di essa. Quindi, se vedi questi simboli in un circuito, rappresentano una resistenza. 

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** è l'unità di resistenza e le unità più grandi includono KΩ, MΩ, ecc. 
La loro relazione può essere mostrata come segue: 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalmente, il valore della resistenza è indicato su di essa. 

Quando si utilizza una resistenza, è necessario conoscere prima il suo valore. Ecco due metodi: puoi osservare le bande sulla resistenza o utilizzare un multimetro per misurare la resistenza. Ti consigliamo di utilizzare il primo metodo in quanto è più conveniente e veloce. 

.. image:: img/resistance_card.jpg

Come mostrato nella scheda, ogni colore rappresenta un numero. 

.. list-table::

   * - Nero
     - Marrone
     - Rosso
     - Arancione
     - Giallo
     - Verde
     - Blu
     - Viola
     - Grigio
     - Bianco
     - Oro
     - Argento
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Le resistenze a 4 e 5 bande sono frequentemente utilizzate, su cui ci sono 4 e 5 bande cromatiche. 

Normalmente, quando ottieni una resistenza, potresti trovare difficile decidere da quale estremità iniziare a leggere il colore. 
Il suggerimento è che il divario tra la quarta e la quinta banda sarà relativamente più grande.

Pertanto, puoi osservare il divario tra le due bande cromatiche a un'estremità della resistenza; 
se è più grande di qualsiasi altro intervallo tra le bande, allora puoi leggere dal lato opposto. 

Vediamo come leggere il valore della resistenza di una resistenza a 5 bande come mostrato di seguito.

.. image:: img/220ohm.jpg
    :width: 500

Quindi, per questa resistenza, il valore deve essere letto da sinistra a destra. 
Il valore dovrebbe essere in questo formato: 1ª Banda 2ª Banda 3ª Banda x 10^Moltiplicatore (Ω) e l'errore permesso è ±Tolleranza%. 
Quindi, il valore della resistenza di questa resistenza è 2(rosso) 2(rosso) 0(nero) x 10^0(nero) Ω = 220 Ω, 
e l'errore permesso è ± 1% (marrone). 

.. list-table:: Tabella dei colori delle resistenze comuni
    :header-rows: 1

    * - Resistenza 
      - Banda di colore  
    * - 10Ω   
      - marrone nero nero argento marrone
    * - 100Ω   
      - marrone nero nero nero marrone
    * - 220Ω 
      - rosso rosso nero nero marrone
    * - 330Ω 
      - arancione arancione nero nero marrone
    * - 1kΩ 
      - marrone nero nero marrone marrone
    * - 2kΩ 
      - rosso nero nero marrone marrone
    * - 5.1kΩ 
      - verde marrone nero marrone marrone
    * - 10kΩ 
      - marrone nero nero rosso marrone 
    * - 100kΩ 
      - marrone nero nero arancione marrone 
    * - 1MΩ 
      - marrone nero nero verde marrone 

Puoi saperne di più sulla resistenza su Wiki: `Resistenza - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.
