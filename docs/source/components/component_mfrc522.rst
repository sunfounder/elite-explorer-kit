.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_mfrc522:

Modulo MFRC522
=====================

**RFID**

La Radio Frequency Identification (RFID) si riferisce a tecnologie che coinvolgono l'uso della comunicazione wireless tra un oggetto (o tag) e un dispositivo di interrogazione (o lettore) per tracciare e identificare automaticamente tali oggetti. Il raggio di trasmissione del tag è limitato a pochi metri dal lettore. Non è necessariamente richiesta una linea di vista chiara tra il lettore e il tag.

La maggior parte dei tag contiene almeno un circuito integrato (IC) e un'antenna. Il microchip memorizza le informazioni ed è responsabile della gestione della comunicazione a radiofrequenza (RF) con il lettore. I tag passivi non hanno una fonte di energia indipendente e dipendono da un segnale elettromagnetico esterno, fornito dal lettore, per alimentare le loro operazioni. I tag attivi contengono una fonte di energia indipendente, come una batteria. Pertanto, possono avere maggiori capacità di elaborazione, trasmissione e raggio d'azione.

.. image:: img/mfrc522.png

**MFRC522**

MFRC522 è un tipo di chip integrato per la lettura e scrittura delle carte. Viene comunemente utilizzato nella radio a 13,56 MHz. Lanciato dalla NXP Company, è un chip per carte senza contatto a basso costo, basso voltaggio e di piccole dimensioni, la scelta migliore per strumenti intelligenti e dispositivi portatili.

Il MF RC522 utilizza un concetto avanzato di modulazione e demodulazione che viene pienamente presentato in tutti i tipi di metodi e protocolli di comunicazione senza contatto passiva a 13,56 MHz. Inoltre, supporta l'algoritmo di crittografia CRYPTO1 per verificare i prodotti MIFARE. MFRC522 supporta anche la comunicazione senza contatto ad alta velocità della serie MIFARE, con una velocità di trasmissione dati bidirezionale fino a 424kbit/s. Come nuovo membro della serie di lettori integrati a 13,56 MHz, MF RC522 è molto simile ai già esistenti MF RC500 e MF RC530, ma presenta anche grandi differenze. Comunica con la macchina host tramite modalità seriale che richiede meno cablaggio. Puoi scegliere tra modalità SPI, I2C e UART seriale (simile a RS232), il che aiuta a ridurre le connessioni, risparmiare spazio sulla scheda PCB (dimensioni più piccole) e ridurre i costi.



**Esempio**

* :ref:`basic_mfrc522` (Progetto di base)
* :ref:`fun_access` (Progetto divertente)
