.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

LEZIONE 19: Mescolare i Colori con un LED RGB
===============================================

Questa lezione dimostra come creare un sistema LED RGB controllato dall'utente utilizzando Arduino, dove l'utente può scegliere diversi colori basandosi sull'input tramite il monitor seriale. Ecco una breve panoramica di ciò che imparerai:

1. **Revisione del Compito Precedente**: Ricapitolazione dell'assegnazione della Lezione 18, che prevedeva il controllo di un LED RGB per produrre vari colori mescolando le luci rosse, verdi e blu.
2. **Configurazione del Circuito**: Istruzioni dettagliate su come collegare correttamente un LED RGB e le sue resistenze limitatrici di corrente all'Arduino. Ogni canale di colore (rosso, verde, blu) è collegato a un pin digitale (pin 9, 10 e 11), e il catodo comune (gamba lunga) è collegato a terra.
3. **Scrittura del Codice**: Istruzioni passo-passo per:
   - Definire i pin per ciascun canale di colore del LED RGB,
   - Configurare il monitor seriale per l'input dell'utente,
   - Utilizzare i comandi analogWrite per regolare la luminosità di ciascun canale di colore per mescolare diversi colori,
   - Convertire l'input dell'utente in minuscolo per gestire diversi casi,
   - Gestire vari input dell'utente per produrre colori specifici (rosso, verde, blu, ciano, magenta, giallo, arancione, bianco) mescolando adeguatamente i valori RGB.
4. **Consigli per il Debug**: Guida alla risoluzione dei problemi comuni come:
   - Assicurarsi della corretta capitalizzazione e sintassi nel codice,
   - Controllare la presenza di punti e virgola mancanti e parentesi graffe errate,
   - Regolare i valori RGB per ottenere la corretta uscita di colore modificando i livelli di luminosità.
5. **Applicazioni Pratiche**: Esempi di mescolanza di colori utilizzando i valori RGB per produrre una vasta gamma di colori.
6. **Compito per Casa**: Far lampeggiare il LED RGB in una sequenza di rosso, verde, blu, attendere un secondo e ripetere questa sequenza 25 volte. Assicurarsi che il programma si fermi dopo 25 cicli. Creare un breve video della soluzione, postarlo su YouTube e collegarsi alla lezione per la revisione.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

