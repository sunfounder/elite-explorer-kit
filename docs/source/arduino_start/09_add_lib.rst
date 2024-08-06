.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _add_libraries:

Come aggiungere librerie? (Importante)
=========================================

Una libreria è una raccolta di codice o funzioni pre-scritte che estendono le capacità dell'IDE di Arduino. Le librerie forniscono codice pronto all'uso per varie funzionalità, permettendoti di risparmiare tempo e fatica nella scrittura di caratteristiche complesse.

Utilizzare il Library Manager
-------------------------------

Molte librerie sono disponibili direttamente tramite l'Arduino Library Manager. Puoi accedere al Library Manager seguendo questi passaggi:

#. Nel **Library Manager**, puoi cercare la libreria desiderata per nome o sfogliare diverse categorie.

   .. note::

      Nei progetti in cui è richiesta l'installazione della libreria, ci saranno dei suggerimenti che indicano quali librerie installare. Segui le istruzioni fornite, come "La libreria del sensore DHT è utilizzata qui, puoi installarla dal Library Manager." Installa semplicemente le librerie raccomandate come suggerito.

   .. image:: img/install_lib3.png

#. Una volta trovata la libreria che vuoi installare, clicca su di essa e poi clicca sul pulsante **Install**.

   .. image:: img/install_lib2.png

#. L'IDE di Arduino scaricherà e installerà automaticamente la libreria per te.

.. _manual_install_lib:

Installazione Manuale
-----------------------

Alcune librerie non sono disponibili tramite il **Library Manager** e devono essere installate manualmente. Per installare queste librerie, segui questi passaggi:

#. Apri l'IDE di Arduino e vai su **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/add_lib_zip.png

#. Naviga nella directory in cui si trovano i file della libreria, come la cartella ``elite-explorer-kit-main/library/``, seleziona il file della libreria e clicca su **Open**.

   .. image:: img/rfid_choose.png

#. Una volta completata l'installazione, riceverai una notifica che conferma che la libreria è stata aggiunta con successo al tuo IDE di Arduino. La prossima volta che dovrai usare questa libreria, non dovrai ripetere il processo di installazione.

   .. image:: img/rfid_success.png

#. Ripeti lo stesso processo per aggiungere altre librerie.


Posizione delle Librerie
-----------------------------------

Le librerie installate utilizzando uno dei metodi sopra descritti possono essere trovate nella directory predefinita delle librerie dell'IDE di Arduino, che di solito si trova in ``C:\Users\xxx\Documents\Arduino\libraries``.

Se la tua directory delle librerie è diversa, puoi controllarla andando su **File** -> **Preferences**.

.. image:: img/install_lib1.png

**Riferimento**

* |link_install_arduino_lib|
