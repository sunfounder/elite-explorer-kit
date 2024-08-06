.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Come caricare uno Sketch sulla scheda?
=============================================

In questa sezione, imparerai come caricare lo sketch creato in precedenza sulla scheda Arduino e alcune considerazioni importanti.

**1. Scegli la Scheda e la Porta**

Le schede di sviluppo Arduino sono solitamente fornite con un cavo USB. Puoi usarlo per collegare la scheda al computer.

Seleziona la **Scheda** e la **Porta** corrette nell'Arduino IDE. Normalmente, le schede Arduino vengono riconosciute automaticamente dal computer e assegnate a una porta, quindi puoi selezionarla qui.

    .. image:: img/04_upload_1.png
        :width: 90%

Se la tua scheda è già collegata ma non viene riconosciuta, controlla se appare il logo **INSTALLED** nella sezione **Arduino UNO R4 Boards** del **Boards Manager**, in caso contrario, scorri verso il basso e clicca su **INSTALL**.

Cerca **"UNO R4"** nel **Boards Manager** e verifica se la libreria corrispondente è installata.

    .. image:: img/04_upload_2.png
        :width: 90%

Riavviare l'Arduino IDE e ricollegare la scheda Arduino risolverà la maggior parte dei problemi. Puoi anche cliccare su **Strumenti** -> **Scheda** o **Porta** per selezionarli.

**2. Verifica lo Sketch**

Dopo aver cliccato sul pulsante Verifica, lo sketch verrà compilato per vedere se ci sono errori.

    .. image:: img/04_upload_3.png
        :width: 90%

Puoi usarlo per trovare errori se elimini alcuni caratteri o digiti alcune lettere per errore. Dalla barra dei messaggi, puoi vedere dove e che tipo di errori si sono verificati.

    .. image:: img/04_upload_4.png
        :width: 90%

Se non ci sono errori, vedrai un messaggio simile a quello sottostante.

    .. image:: img/04_upload_5.png
        :width: 90%

**3. Carica lo Sketch**

Dopo aver completato i passaggi precedenti, clicca sul pulsante **Carica** per caricare questo sketch sulla scheda.

    .. image:: img/04_upload_6.png
        :width: 90%

Se il caricamento ha successo, vedrai il seguente messaggio.

    .. image:: img/04_upload_7.png
        :width: 90%

Allo stesso tempo, il LED sulla scheda inizierà a lampeggiare.

.. image:: img/04_upload_8.png
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

Dopo che lo sketch è stato caricato, la scheda Arduino eseguirà automaticamente lo sketch all'accensione. Il programma in esecuzione può essere sovrascritto caricando un nuovo sketch.
