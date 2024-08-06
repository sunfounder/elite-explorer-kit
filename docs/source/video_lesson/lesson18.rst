.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 18: Controllare un LED RGB con Arduino
=================================================

Questa lezione dimostra come utilizzare un LED RGB con un Arduino per creare diversi colori combinando luce rossa, verde e blu, basandosi sulle lezioni precedenti sul controllo dei LED e sull'uso delle capacità PWM dell'Arduino. Ecco una breve panoramica di ciò che imparerai:

1. **Revisione del Compito Precedente**: Ricapitolazione dell'assegnazione della Lezione 17, che prevedeva la creazione di un circuito con tre LED (rosso, giallo e verde) e il loro controllo basato sull'input dell'utente.
2. **Configurazione del Circuito**: Istruzioni dettagliate su come collegare correttamente un LED RGB all'Arduino. Il LED RGB ha quattro gambe: una comune a terra e tre per i LED rosso, verde e blu. Ogni canale di colore richiede una resistenza limitatrice di corrente separata per prevenire interferenze e garantire un funzionamento corretto.
3. **Scrittura del Codice**: Istruzioni passo-passo per:
   - Definire i pin per ciascun canale di colore del LED RGB,
   - Configurare il monitor seriale per l'input dell'utente,
   - Utilizzare i comandi digital write per accendere e spegnere ciascun canale di colore,
   - Convertire l'input dell'utente in minuscolo per gestire diversi casi.
4. **Applicazioni Pratiche**: Esempi di controllo del LED RGB per produrre vari colori accendendo diverse combinazioni dei LED rosso, verde e blu.
5. **Compito per Casa**: Estendere il progetto chiedendo all'utente colori specifici, inclusi rosso, verde, blu, ciano, magenta, giallo, arancione e bianco.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/ASHBCGGeEPk?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
