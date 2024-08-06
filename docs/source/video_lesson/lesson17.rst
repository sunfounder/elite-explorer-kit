.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 17: Controllare Più LED dal Monitor Seriale
=======================================================

Questa lezione dimostra come creare un sistema di controllo dei LED utilizzando Arduino, in cui l'utente può accendere e spegnere diversi LED in base all'input ricevuto dal monitor seriale. Ecco una breve panoramica di ciò che imparerai:

1. **Revisione del Compito Precedente**: Ricapitolazione dell'assegnazione della Lezione 16, che prevedeva la creazione di un circuito con tre LED (rosso, giallo e verde) e il loro controllo basato sull'input dell'utente.
2. **Configurazione del Circuito**: Istruzioni dettagliate su come collegare correttamente tre LED e le loro resistenze limitatrici di corrente all'Arduino. La gamba lunga (anodo) di ogni LED è collegata a un pin digitale, mentre la gamba corta (catodo) è collegata a terra attraverso una resistenza.
3. **Scrittura del Codice**: Istruzioni passo-passo per:
   - Definire i pin per ogni LED,
   - Configurare il monitor seriale per l'input dell'utente,
   - Utilizzare le istruzioni if per accendere il LED specificato e assicurarsi che tutti gli altri LED siano spenti,
   - Convertire l'input dell'utente in minuscolo per gestire diversi casi.
4. **Suggerimenti per il Debug**: Linee guida per risolvere problemi comuni come punti e virgola mancanti, parentesi graffe errate e assicurarsi che tutti i LED siano correttamente spenti quando viene acceso un nuovo LED.
5. **Applicazioni Pratiche**: Esempi di utilizzo delle istruzioni if per gestire l'input dell'utente e controllare più uscite (LED) in base a tale input.
6. **Compito per Casa**: Estendere il progetto chiedendo all'utente sia il colore del LED che la luminosità desiderata.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/Ai7uqYHt_Yc?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

