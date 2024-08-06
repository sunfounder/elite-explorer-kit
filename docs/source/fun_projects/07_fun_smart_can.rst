.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_smart_can:

Pattumiera Intelligente
==============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo codice Arduino è progettato per controllare una pattumiera intelligente. 
Quando un oggetto è entro 20 centimetri di distanza davanti alla pattumiera, il coperchio si apre automaticamente. 
Questo progetto utilizza un servo motore SG90 e un sensore di distanza ultrasonico HC-SR04.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Collegamenti**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**Schema Elettrico**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**Codice**

.. note::

    * Puoi aprire il file ``07_smart_trash_can.ino`` nel percorso ``elite-explorer-kit-main\fun_project\07_smart_trash_can`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/509f1bee-6e38-4106-bea7-9b06cdb3719f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come funziona?**

Ecco una spiegazione passo-passo del codice:

1. Importa Librerie e Definisci Costanti/Variabili:

   La libreria ``Servo.h`` viene importata per controllare il servo motore SG90.
   I parametri per il servo motore, il sensore ultrasonico e altre costanti e variabili necessarie sono definiti.

2. ``setup()``:

   Inizializza la comunicazione seriale con il computer a un baud rate di 9600.
   Configura i pin di trigger ed echo del sensore ultrasonico.
   Collega il servo motore al suo pin di controllo e imposta la sua posizione iniziale all'angolo di chiusura. Dopo aver impostato l'angolo, il servo motore viene disconnesso per risparmiare energia.

3. ``loop()``:

   Misura la distanza tre volte e memorizza i valori di ciascuna misurazione.
   Calcola la distanza media dalle tre misurazioni.
   Se la distanza media è minore o uguale a 20 centimetri (soglia di distanza definita), il servo motore ruota all'angolo di apertura (0 gradi). 
   Altrimenti, il servo motore ritorna alla posizione di chiusura (90 gradi) dopo un ritardo di un secondo. Il servo motore viene disconnesso quando non in uso per conservare energia.

4. ``readDistance()``:

   Invia un impulso al pin di trigger del sensore ultrasonico.
   Misura la durata dell'impulso del pin di echo e calcola il valore della distanza. 
   Questo calcolo utilizza la velocità del suono nell'aria per determinare la distanza basata sul tempo dell'impulso.

