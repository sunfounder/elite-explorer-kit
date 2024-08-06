.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e ai sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 14: Leggere Input dall'Utente Tramite il Monitor Seriale
=====================================================================

Questa lezione dimostra come creare un programma interattivo utilizzando Arduino, focalizzandosi sull'ottenimento di input dall'utente tramite il monitor seriale e sull'esecuzione di diverse operazioni in base all'input. Ecco una breve panoramica di ciò che imparerai:

1. **Introduzione all'Input Utente tramite il Monitor Seriale**: Un'introduzione al concetto di lettura degli input dell'utente dal monitor seriale di Arduino, essenziale per i progetti interattivi.
2. **Impostazione della Comunicazione Seriale**: Istruzioni dettagliate su come impostare la comunicazione seriale nel codice Arduino, utilizzando Serial.begin(9600) per inizializzare il monitor seriale.
3. **Lettura di Diversi Tipi di Dati**: Guida passo-passo su come leggere vari tipi di dati dall'utente:
   - Interi: Utilizzando Serial.parseInt() per leggere valori interi.
   - Float: Utilizzando Serial.parseFloat() per leggere numeri in virgola mobile.
   - Stringhe: Utilizzando Serial.readString() per leggere stringhe.
4. **Implementazione di un Ciclo While per l'Attesa dell'Input dell'Utente**: Spiegazione di come implementare un ciclo while per attendere l'input dell'utente, assicurando che il programma non proceda fino a quando l'utente non ha inserito i dati richiesti.
5. **Gestione degli Errori con l'Input Seriale**: Consigli su come gestire errori relativi a tipi di dati errati e garantire che il monitor seriale sia impostato su 'No line ending' per evitare che caratteri aggiuntivi vengano letti come input.
6. **Applicazione Pratica e Codice di Esempio**: Un progetto di esempio in cui viene chiesto all'utente un numero, un float e una stringa, dimostrando come catturare e utilizzare efficacemente questi input. Il codice fornito mostra come chiedere l'input, attendere che arrivi e poi leggere e processare l'input.
7. **Compito per Casa**: Creare un programma che chieda all'utente un livello di luminosità (tra 0 e 255) per un LED e poi imposti di conseguenza la luminosità del LED.


**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
