.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_access:

Sistema di Controllo Accessi
======================================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/09_fun_access.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

La funzione principale di questo codice è eseguire l'autenticazione dell'utente utilizzando un modulo RFID. 
Se l'autenticazione ha successo, controlla un motore passo-passo per aprire la porta ed emette un suono tramite un buzzer per indicare il risultato dell'autenticazione. 
Se l'autenticazione fallisce, la porta non si aprirà.

Puoi aprire il monitor seriale per visualizzare l'ID della tua carta RFID e riconfigurare la password in questo codice.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_power`
        - \-


**Collegamenti**

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/09_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/09_access_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Codice**

.. note::

    * Puoi aprire il file ``09_access_control_system.ino`` nel percorso ``elite-explorer-kit-main\fun_project09_access_control_system`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::

    * La libreria ``RFID1`` viene utilizzata qui. La libreria può essere trovata nella directory ``elite-explorer-kit-main/library/``, oppure puoi cliccare qui :download:`RFID1.zip </_static/RFID1.zip>` per scaricarla. Consulta :ref:`manual_install_lib` per un tutorial su come installarla.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/3486dd4e-a76e-478f-b5a4-a86281f7f374/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come funziona?**

Di seguito una spiegazione passo-passo del codice:

1. **Includere File di Libreria**: Sono inclusi tre file di libreria: ``rfid1.h``, ``Stepper.h`` e ``Wire.h``. Queste librerie vengono utilizzate per comunicare con il modulo RFID, il motore passo-passo e per la comunicazione I2C.

2. **Definizioni di Costanti**: Sono definite alcune costanti, tra cui ``ID_LEN`` (lunghezza dell'ID), ``stepsPerRevolution`` (passi per rivoluzione per il motore passo-passo), ``rolePerMinute`` (velocità del motore passo-passo), così come i quattro pin del motore passo-passo (IN1, IN2, IN3, IN4), il pin del buzzer (``buzPin``) e le variabili relative all'autenticazione.

3. **Definizioni di Variabili**: Sono definite variabili come un array per memorizzare l'ID utente letto (``userIdRead``), l'ID utente autenticato (``userId``) e una variabile booleana (``approved``) per indicare l'autenticazione avvenuta con successo.

4. **Istanze di Oggetti**: Sono create istanze di due oggetti: ``RFID1 rfid`` e ``Stepper stepper`` per interagire rispettivamente con il modulo RFID e il motore passo-passo.

5. ``setup()``: Nella funzione ``setup()``, si inizializza la velocità del motore passo-passo, si imposta il pin del buzzer come output e si inizializza il modulo RFID.

6. ``loop()``: Nella funzione ``loop()``, il codice principale viene eseguito. Se ``approved`` è 0 (indicando che l'autenticazione non è ancora avvenuta), chiama la funzione ``rfidRead()`` per leggere i dati dal modulo RFID e poi svuota l'array ``userIdRead``. Se ``approved`` è 1 (indicando l'autenticazione avvenuta con successo), chiama la funzione ``openDoor()`` per aprire la porta e resetta ``approved`` a 0.

7. ``beep()``: Questa funzione controlla il suono del buzzer in base ai parametri ``duration`` e ``frequency`` forniti.

8. ``verifyPrint()``: Questa funzione emette suoni differenti tramite il buzzer in base al parametro ``result`` per indicare se l'autenticazione è avvenuta con successo o meno.

9. ``openDoor()``: Questa funzione controlla il motore passo-passo per aprire la porta a un certo angolo (``doorStep``) e poi attende un periodo prima di chiudere la porta.

10. ``rfidRead()``: Questa funzione legge i dati dal modulo RFID, prima chiamando ``getId()`` per ottenere l'ID utente e poi ``idVerify()`` per verificare se l'ID utente corrisponde all'ID autenticato.

11. ``getId()``: Questa funzione recupera l'ID utente dal modulo RFID e lo memorizza nell'array ``userIdRead``. Emette un beep se la lettura fallisce.

12. ``idVerify()``: Questa funzione verifica se l'ID utente corrisponde all'ID autenticato ed emette un suono indicando se l'autenticazione è avvenuta con successo o meno.

