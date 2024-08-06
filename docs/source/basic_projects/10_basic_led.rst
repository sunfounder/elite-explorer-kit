.. note::
    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_led:

Modulo LED
==========================

Proprio come stampare "Hello, world!" è il primo passo per imparare a programmare, utilizzare un programma per pilotare un LED è l'introduzione tradizionale alla programmazione fisica.

Componenti necessari
-------------------------

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

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

Collegamenti
----------------------

.. image:: img/10-led_bb.png
    :align: center
    :width: 60%


Schema elettrico
-----------------------

.. image:: img/10_led_schematic.png
    :align: center
    :width: 80%


Codice
---------------

.. note::
   * Puoi aprire il file ``10-led.ino`` sotto il percorso ``elite-explorer-kit-main\basic_project\10-led``.
   * Oppure copia questo codice nell'**Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2d23289e-ebd1-49e9-b11f-b1bbc1f192c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style="max-width:100%">
      <source src="../_static/videos/basic_projects/10_basic_led.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Dopo che il codice è stato caricato con successo, vedrai il LED collegato al pin digitale 9 della scheda Arduino iniziare a lampeggiare. Il LED si accenderà per mezzo secondo e poi si spegnerà per un altro mezzo secondo, ripetendo questo ciclo continuamente mentre il programma è in esecuzione.

Analisi del codice
------------------------

Qui, colleghiamo il LED al pin digitale 9, quindi dobbiamo dichiarare una variabile ``int`` chiamata ``ledpin`` all'inizio del programma e assegnare il valore 9.

.. code-block:: arduino

    const int ledPin = 9;


Ora, inizializza il pin nella funzione ``setup()``, dove è necessario inizializzare il pin in modalità ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

Nel ``loop()``, viene utilizzato ``digitalWrite()`` per fornire un segnale ad alto livello di 5V al ledPin, il che causerà una differenza di tensione tra i pin del LED e accenderà il LED.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Se il segnale di livello viene cambiato a LOW, il segnale del ledPin verrà riportato a 0V per spegnere il LED.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);


È necessario un intervallo tra acceso e spento per consentire alle persone di vedere il cambiamento,
quindi utilizziamo un codice ``delay(1000)`` per far sì che il controller non faccia nulla per 1000 ms.

.. code-block:: arduino

    delay(1000);
