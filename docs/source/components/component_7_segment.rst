.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_7segment:

Display a 7 Segmenti
======================

.. image:: img/7-seg.jpg

Un display a 7 segmenti è un componente a forma di 8 che racchiude 7 LED. Ogni LED è chiamato segmento - quando alimentato, un segmento forma parte di una cifra da visualizzare.

Esistono due tipi di connessione dei pin: Catodo Comune (CC) e Anodo Comune (CA). Come suggerisce il nome, un display CC ha tutti i catodi dei 7 LED collegati mentre un display CA ha tutti gli anodi dei 7 segmenti collegati.

In questo kit, utilizziamo il display a 7 segmenti con Catodo Comune, ecco il simbolo elettronico.

.. image:: img/segment_cathode.png
    :width: 800

Ciascuno dei LED nel display è associato a un segmento posizionale con uno dei suoi pin di connessione che sporge dal pacchetto di plastica rettangolare. Questi pin LED sono etichettati da "a" a "g" rappresentando ciascun LED individuale. Gli altri pin LED sono collegati insieme formando un pin comune. Quindi, polarizzando direttamente i pin appropriati dei segmenti LED in un ordine particolare, alcuni segmenti si illumineranno e altri rimarranno spenti, mostrando così il carattere corrispondente sul display.

**Codici del Display**

Per aiutarti a comprendere come i display a 7 segmenti (Catodo Comune) mostrano i Numeri, abbiamo disegnato la seguente tabella. I Numeri sono i numeri da 0 a F visualizzati sul display a 7 segmenti; (DP) GFEDCBA si riferisce al set di LED corrispondenti impostato su 0 o 1, ad esempio, 00111111 significa che DP e G sono impostati su 0, mentre gli altri sono impostati su 1. Pertanto, il numero 0 è visualizzato sul display a 7 segmenti, mentre il Codice HEX corrisponde al numero esadecimale.

.. image:: img/segment_code.png

**Esempio**

* :ref:`basic_7segment` (Basic Project)
* :ref:`basic_74hc595` (Basic Project)
* :ref:`fun_digital_dice` (Fun Project)
