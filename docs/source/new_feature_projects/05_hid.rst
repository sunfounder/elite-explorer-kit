.. note::
    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _new_hid:

USB HID
========================================

L'Arduino Uno R4 WiFi non è solo una potente scheda di sviluppo; viene anche fornita con il supporto integrato per dispositivi HID (Human Interface Devices). Questo ti permette di utilizzare la scheda per emulare dispositivi come mouse e tastiere, aggiungendo un nuovo livello di interattività ai tuoi progetti.

Gli HID, o Human Interface Devices, sono una categoria di dispositivi informatici progettati per l'interazione diretta con gli esseri umani, tipicamente per scopi di input. Questa categoria include dispositivi come tastiere, mouse e controller di gioco. Con l'Arduino Uno R4 WiFi, puoi emulare questi dispositivi, sbloccando così una serie di possibilità per progetti fai-da-te.

Controllo del Mouse
----------------------

Controllare un mouse usando l'Arduino Uno R4 WiFi è semplice. Utilizzando il comando ``Mouse.move(x,y)``, puoi facilmente controllare il movimento del mouse. Quando aggiorni la posizione del cursore, essa è sempre relativa alla posizione precedente del cursore.

Ecco un semplice esempio che dimostra il controllo del cursore del mouse utilizzando un pulsante.

**Schema Elettrico**

.. image:: img/05_hid_1_bb.png
  :width: 70%
  :align: center

**Carica il Codice**

Apri il file ``05-hid_mouse.ino`` situato nel percorso ``elite-explorer-kit-main\r4_new_feature\05-hid_mouse``, oppure incolla il seguente codice nel tuo Arduino IDE.

.. warning::
    Quando utilizzi il comando ``Mouse.move()``, l'Arduino prende il controllo del mouse del tuo computer! Per assicurarti di non perdere il controllo del tuo computer mentre esegui uno sketch con questa funzione, assicurati di impostare un sistema di controllo affidabile prima di chiamare ``Mouse.move()``. Questo sketch include un pulsante per attivare il mouse, in modo che funzioni solo dopo che il pulsante è stato premuto.

.. warning:: 
    A causa dell'architettura multi-processore della scheda UNO R4 WiFi, potresti riscontrare errori **"No device found on..."** durante il caricamento del codice che utilizza le funzionalità HID.
    
    Per caricare in tali circostanze, segui questi passaggi:
    
    1. Premi e rilascia rapidamente il pulsante "RESET" sulla scheda due volte. Il LED contrassegnato con "L" dovrebbe iniziare a lampeggiare.
    
    2. Dal menu dell'Arduino IDE, seleziona la porta della scheda. La porta potrebbe cambiare dopo il reset, quindi assicurati che sia correttamente selezionata.

.. literalinclude:: /_code/05_hid_mouse.ino
   :language: cpp
   :linenos:
   :caption: 05-hid_mouse.ino

Oltre a controllare il movimento del mouse, puoi anche gestire i clic del mouse. Per ulteriori dettagli, consulta |link_r4_usb_mouse|.

.. _new_hid_keyboard:

Controllo della Tastiera
---------------------------------

L'Arduino Uno R4 WiFi offre anche capacità di emulazione della tastiera. Ti consente di inviare non solo singoli tasti ma anche di eseguire combinazioni di tasti complesse.

.. warning::
   Quando utilizzi il comando ``Keyboard.print()``, l'Arduino prende il controllo della tastiera del tuo computer! Per assicurarti di non perdere il controllo del tuo computer mentre esegui uno sketch con questa funzione, assicurati di impostare un sistema di controllo affidabile prima di chiamare ``Keyboard.print()``. Questo sketch include un pulsante per attivare la tastiera, in modo che funzioni solo dopo che il pulsante è stato premuto.

**Esempio di Codice per l'Invio di Tasti di Scelta Rapida**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

In questo esempio, l'Arduino Uno R4 WiFi è configurato per emulare due scorciatoie da tastiera frequentemente utilizzate: "Ctrl+C" per copiare e "Ctrl+V" per incollare. Due pulsanti fisici collegati all'Arduino fungono da trigger. Il pulsante collegato al pin 7 avvia l'azione di copia, mentre quello collegato al pin 8 avvia l'azione di incolla.

Quando viene premuto uno dei due pulsanti, l'Arduino utilizza le funzioni ``Keyboard.press()`` e ``Keyboard.releaseAll()`` per simulare le rispettive scorciatoie da tastiera. Questo esempio illustra come puoi progettare un'interfaccia hardware dedicata per attività specifiche, facilitando azioni ripetitive senza coinvolgere la tastiera. Questo potrebbe essere particolarmente vantaggioso in ambienti di lavoro che richiedono una rapida manipolazione dei dati o in configurazioni di accessibilità che traggono vantaggio da controlli semplificati.

**Schema Elettrico**

.. image:: img/05_hid_2_bb.png
  :width: 70%
  :align: center

**Carica il Codice**

Apri il file ``05-hid_keyboard.ino`` situato nel percorso ``elite-explorer-kit-main\r4_new_feature\05-hid_keyboard``, oppure incolla il seguente codice nel tuo Arduino IDE.

.. literalinclude:: /_code/05_hid_keyboard.ino
   :language: cpp
   :linenos:
   :caption: 05-hid_keyboard.ino



Avvertenze e Suggerimenti
--------------------------------

1. **Nota di Cautela sulle Librerie Mouse e Tastiera**: Se la libreria Mouse o Keyboard è in esecuzione continua, potrebbe interferire con la programmazione della tua scheda. Funzioni come ``Mouse.move()`` e ``Keyboard.print()`` assumeranno il controllo del computer collegato e dovrebbero essere invocate solo quando sei pronto a gestirle. Si consiglia di utilizzare un sistema di controllo, come un interruttore fisico o controlli di input specifici, per attivare questa funzionalità.

2. **Se incontri problemi di caricamento del codice**: A causa dell'architettura multi-processore della scheda UNO R4 WiFi, potresti riscontrare errori ``"No device found on..."`` durante il caricamento del codice che utilizza le funzionalità HID.

   Per caricare in tali circostanze, segui questi passaggi:
   
   1. Premi e rilascia rapidamente il pulsante "RESET" sulla scheda due volte. Il LED contrassegnato con "L" dovrebbe iniziare a lampeggiare.
   
   2. Dal menu dell'Arduino IDE, seleziona la porta della scheda. La porta potrebbe cambiare dopo il reset, quindi assicurati che sia correttamente selezionata.




**Riferimenti**

- |link_r4_usb_hid|
- |link_r4_usb_mouse|
- |link_r4_usb_keyboard|
