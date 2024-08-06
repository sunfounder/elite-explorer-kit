.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_mpr121:

MPR121
===========================

.. image:: img/mpr121.png

* **3.3V**: Alimentazione
* **IRQ**: Pin di uscita interrupt a collettore aperto, attivo basso
* **SCL**: Clock I2C
* **SDA**: Dati I2C
* **ADD**: Pin di selezione dell'indirizzo I2C. Collegare il pin ADDR alla linea VSS, VDD, SDA o SCL, gli indirizzi I2C risultanti sono rispettivamente 0x5A, 0x5B, 0x5C e 0x5D.
* **GND**: Massa
* **0~11**: Elettrodo 0~11, l'elettrodo è un sensore tattile. Tipicamente, gli elettrodi possono essere semplicemente un pezzo di metallo o un filo. Tuttavia, a seconda della lunghezza del filo o del materiale su cui si trova l'elettrodo, può risultare difficile attivare il sensore. Per questo motivo, l'MPR121 consente di configurare ciò che è necessario per attivare e disattivare un elettrodo.

**PANORAMICA MPR121**

L'MPR121 è la seconda generazione di controller per sensori tattili capacitivi dopo 
il rilascio iniziale dei dispositivi della serie MPR03x. L'MPR121 presenta un'intelligenza 
interna aumentata, alcune delle principali aggiunte includono un conteggio degli 
elettrodi aumentato, un indirizzo I2C configurabile tramite hardware, un sistema di 
filtraggio espanso con debounce e elettrodi completamente indipendenti con 
auto-configurazione integrata. Il dispositivo presenta anche un tredicesimo canale di 
rilevamento simulato dedicato al rilevamento di prossimità utilizzando gli ingressi di 
rilevamento multiplexati.

* |link_mpr121_datasheet|

**Caratteristiche**

* Funzionamento a basso consumo
    • Alimentazione da 1.71 V a 3.6 V
    • Corrente di alimentazione di 29 μA con intervallo di campionamento di 16 ms
    • Corrente in modalità Stop di 3 μA
* 12 ingressi di rilevamento capacitivo
    • 8 ingressi sono multifunzionali per driver LED e GPIO
* Rilevamento touch completo
    • Auto-configurazione per ciascun ingresso di rilevamento
    • Auto-calibrazione per ciascun ingresso di rilevamento
    • Soglia di tocco/rilascio e debounce per il rilevamento touch
* Interfaccia I2C, con uscita interrupt
* Pacchetto QFN a 20 pin da 3 mm x 3 mm x 0.65 mm
* Intervallo di temperatura operativa da -40°C a +85°C

**Esempio**

* :ref:`basic_mpr121` (Progetto di base)
* :ref:`fun_fruit_piano` (Progetto divertente)
