.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 20: Cicli For in Arduino
======================================
Questa lezione dimostra come creare un sistema LED RGB controllato dall'utente utilizzando Arduino, dove l'utente può specificare il numero di lampeggi tramite il monitor seriale. Ecco una breve panoramica di ciò che imparerai:

1. **Revisione del Compito Precedente**: Ricapitolazione dell'assegnazione della Lezione 19, che prevedeva il lampeggiamento di un LED RGB in una sequenza rosso-verde-blu per 25 cicli.
2. **Configurazione del Circuito**: Istruzioni dettagliate su come collegare correttamente un LED RGB e le sue resistenze limitatrici di corrente all'Arduino. Ogni canale di colore (rosso, verde, blu) è collegato a un pin digitale PWM (pin 9, 10 e 11), e il catodo comune (gamba lunga) è collegato a terra.
3. **Scrittura del Codice**: Istruzioni passo-passo per:
   - Definire i pin per ciascun canale di colore del LED RGB.
   - Configurare il monitor seriale per l'input dell'utente.
   - Utilizzare i comandi analogWrite per controllare la luminosità di ciascun canale di colore.
   - Implementare un ciclo for per controllare il numero di cicli di lampeggiamento in base all'input dell'utente.
   - Assicurarsi che il programma si fermi dopo il numero specificato di lampeggi.
4. **Consigli per il Debug**: Guida alla risoluzione dei problemi comuni come:
   - Correzione degli errori di sintassi nel codice.
   - Assicurarsi che il programma cicli il numero corretto di volte.
   - Gestione corretta dell'input dell'utente e arresto del programma dopo i cicli specificati.
5. **Applicazioni Pratiche**: Esempi di utilizzo dei cicli for per ripetere una sequenza di azioni un numero specificato di volte.
6. **Compito per Casa**: Ripetere la sequenza di lampeggiamento un numero di volte specificato dall'utente senza utilizzare un ciclo for. Assicurarsi che il programma si fermi dopo il numero specificato di lampeggi.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/CZh8QB26jjU?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

