.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e ai sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 15: Controllo di un LED Basato su Input dell'Utente dal Monitor Seriale
====================================================================================

Questa lezione dimostra come creare un programma interattivo utilizzando Arduino, concentrandosi sull'ottenimento di input dall'utente tramite il monitor seriale e sull'esecuzione di diverse operazioni in base all'input. Ecco una breve panoramica di ciò che imparerai:

1. **Revisione del Compito Precedente**: Ricapitolazione dell'assegnazione dalla Lezione 14, che prevedeva il controllo della luminosità di un LED ottenendo input dall'utente sul monitor seriale.
2. **Configurazione del Circuito**: Istruzioni su come collegare correttamente un LED e una resistenza all'Arduino, assicurandosi che ogni componente sia configurato correttamente per l'esperimento.
3. **Scrittura del Codice**: Istruzioni passo-passo per scrivere il codice che legge l'input dell'utente dal monitor seriale e lo utilizza per regolare la luminosità del LED. Questo include calcoli matematici per tradurre l'input dell'utente in un valore che l'Arduino può utilizzare per controllare la luminosità del LED.
4. **Scalatura Esponenziale**: Spiegazione di come utilizzare la scalatura esponenziale per garantire che la luminosità percepita del LED aumenti uniformemente lungo l'intervallo degli input dell'utente.
5. **Suggerimenti per il Debug**: Linee guida per risolvere problemi comuni come letture errate o errori nell'output che influenzano la luminosità del LED.
6. **Compito per Casa**: Creare un programma che chieda all'utente un livello di luminosità (tra 0 e 10) per un LED e poi imposti di conseguenza la luminosità del LED.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/d-Ma3u7GngA?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

