.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_relay:

Relè
==========================================

.. image:: img/relay_pic.png
    :width: 200
    :align: center

Come sappiamo, un relè è un dispositivo che viene utilizzato per fornire una connessione tra due o più punti o dispositivi in risposta al segnale di ingresso applicato. In altre parole, i relè forniscono isolamento tra il controllore e il dispositivo poiché i dispositivi possono funzionare sia in AC che in DC. Tuttavia, ricevono segnali da un microcontrollore che funziona in DC, quindi è necessario un relè per colmare il divario. Il relè è estremamente utile quando è necessario controllare una grande quantità di corrente o tensione con un piccolo segnale elettrico.

Ci sono 5 parti in ogni relè:

.. image:: img/relay142.jpeg

**Elettromagnete** - È costituito da un nucleo di ferro avvolto da una bobina di fili. Quando passa elettricità, diventa magnetico. Pertanto, è chiamato elettromagnete.

**Armatura** - La striscia magnetica mobile è nota come armatura. Quando la corrente scorre attraverso di essa, la bobina si energizza producendo un campo magnetico che viene utilizzato per aprire o chiudere i punti normalmente aperti (N/O) o normalmente chiusi (N/C). L'armatura può essere spostata sia con corrente continua (DC) che con corrente alternata (AC).

**Molla** - Quando non scorre corrente attraverso la bobina dell'elettromagnete, la molla tira l'armatura lontano, impedendo il completamento del circuito.

Serie di **contatti** elettrici - Ci sono due punti di contatto:

-  Normalmente aperto - collegato quando il relè è attivato e scollegato quando è inattivo.

-  Normalmente chiuso - non collegato quando il relè è attivato e collegato quando è inattivo.

**Telaio stampato** - I relè sono coperti da plastica per protezione.

Il principio di funzionamento del relè è semplice. Quando viene fornita alimentazione al relè, la corrente inizia a fluire attraverso la bobina di controllo; di conseguenza, l'elettromagnete inizia a energizzarsi. Quindi l'armatura viene attratta verso la bobina, abbassando il contatto mobile e collegandolo ai contatti normalmente aperti. In questo modo, il circuito con il carico viene energizzato. Interrompere il circuito seguirebbe un caso simile, poiché il contatto mobile verrà sollevato verso i contatti normalmente chiusi sotto la forza della molla. In questo modo, l'accensione e lo spegnimento del relè possono controllare lo stato di un circuito di carico.

**Esempio**

* :ref:`basic_relay` (Progetto di base)
