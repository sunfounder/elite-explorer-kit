.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Il 74HC595 è composto da un registro a scorrimento a 8 bit e un registro di memoria con uscite parallele a tre stati. Converte l'input seriale in output parallelo per risparmiare porte IO di un MCU.
Quando MR (pin10) è a livello alto e OE (pin13) è a livello basso, i dati vengono inseriti nel fronte di salita di SHcp e passano al registro di memoria tramite il fronte di salita di SHcp. Se i due clock sono collegati insieme, il registro a scorrimento è sempre un impulso prima del registro di memoria. C'è un pin di ingresso a scorrimento seriale (Ds), un pin di uscita seriale (Q) e un pulsante di reset asincrono (livello basso) nel registro di memoria. Il registro di memoria fornisce un bus con un output parallelo a 8 bit e in tre stati. Quando OE è abilitato (livello basso), i dati nel registro di memoria vengono inviati al bus.

* |link_74hc595_datasheet|

.. image:: img/74hc595_pin.png
    :width: 600

Pin del 74HC595 e le loro funzioni:

* **Q0-Q7**: Pin di uscita dati paralleli a 8 bit, in grado di controllare direttamente 8 LED o 8 pin di un display a 7 segmenti.
* **Q7’**: Pin di uscita seriale, collegato a DS di un altro 74HC595 per collegare più 74HC595 in serie.
* **MR**: Pin di reset, attivo a livello basso.
* **SHcp**: Ingresso di sequenza temporale del registro a scorrimento. Nel fronte di salita, i dati nel registro a scorrimento si spostano successivamente di un bit, cioè i dati in Q1 si spostano in Q2 e così via. Nel fronte di discesa, i dati nel registro a scorrimento rimangono invariati.
* **STcp**: Ingresso di sequenza temporale del registro di memoria. Nel fronte di salita, i dati nel registro a scorrimento vengono trasferiti nel registro di memoria.
* **CE**: Pin di abilitazione dell'uscita, attivo a livello basso.
* **DS**: Pin di ingresso dati seriali.
* **VCC**: Tensione di alimentazione positiva.
* **GND**: Massa.

**Esempio**

* :ref:`basic_74hc595` (Basic Project)
* :ref:`fun_digital_dice` (Fun Project)
