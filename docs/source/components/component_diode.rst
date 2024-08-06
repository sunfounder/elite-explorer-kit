.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_diode:

Diodo
=================


Un diodo è un componente elettronico con due elettrodi. Consente il flusso di corrente in una sola direzione, spesso chiamata funzione di "Rettificazione".
Pertanto, un diodo può essere considerato come una versione elettronica di una valvola di non ritorno.

Grazie alla sua conduttività unidirezionale, il diodo è utilizzato in quasi tutti i circuiti elettronici di una certa complessità. È uno dei primi dispositivi a semiconduttore e ha una vasta gamma di applicazioni.

Secondo la sua classificazione d'uso, può essere diviso in diodi rivelatori, diodi raddrizzatori, diodi limitatori, diodi regolatori di tensione, ecc. 

In questo kit sono inclusi diodi raddrizzatori e diodi regolatori di tensione.

**Diodo Raddrizzatore**

.. image:: img/in4007_diode.png
.. image:: img/symbol_rectifier_diode.png
    :width: 200

Un diodo raddrizzatore è un diodo semiconduttore utilizzato per raddrizzare la corrente alternata (AC) in corrente continua (DC) usando l'applicazione del ponte raddrizzatore. L'alternativa del diodo raddrizzatore tramite la barriera Schottky è principalmente apprezzata nell'elettronica digitale. Questo diodo è in grado di condurre i valori di corrente che variano da mA a pochi kA e le tensioni fino a pochi kV.

La progettazione dei diodi raddrizzatori può essere realizzata con materiale al silicio e sono in grado di condurre alti valori di corrente elettrica. Questi diodi non sono famosi ma sono ancora utilizzati diodi a semiconduttore basati su Ge o arseniuro di gallio. I diodi Ge hanno una minore tensione inversa consentita e una minore temperatura di giunzione consentita. Il diodo Ge ha un vantaggio rispetto al diodo Si, cioè un basso valore di tensione di soglia mentre opera in polarizzazione diretta.

* |link_general_purpose_diode|


**Diodo Zener**

Un diodo Zener è un tipo speciale di diodo progettato per permettere in modo affidabile il flusso di corrente "all'indietro" quando viene raggiunta una determinata tensione inversa di soglia, nota come tensione Zener.

Questo diodo è un dispositivo a semiconduttore che ha una resistenza molto elevata fino alla tensione critica di rottura inversa. A questo punto critico di rottura, la resistenza inversa si riduce a un valore molto basso e la corrente aumenta mentre la tensione rimane costante in questa regione di bassa resistenza.

.. image:: img/zener_diode.png
.. image:: img/symbol-zener-diode.jpg


* |link_zener_diode|


**Esempio**


 * :ref:`basic_relay` (Progetto Base)

