.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_thermistor:

Termistore
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Un termistore è un tipo di resistore la cui resistenza dipende fortemente dalla temperatura, più di quanto avviene nei resistori standard. La parola è una combinazione di "thermal" e "resistor". I termistori sono ampiamente utilizzati come limitatori di corrente di spunto, sensori di temperatura (tipicamente di tipo a coefficiente di temperatura negativo o NTC), protettori da sovracorrente autoripristinanti e elementi riscaldanti autorregolanti (tipicamente di tipo a coefficiente di temperatura positivo o PTC).

* |link_thermistor_wikipedia|

Ecco il simbolo elettronico del termistore.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

I termistori sono di due tipi fondamentali opposti:

* Con i termistori NTC, la resistenza diminuisce con l'aumentare della temperatura, solitamente a causa di un aumento degli elettroni di conduzione spinti dall'agitazione termica dalla banda di valenza. Un NTC è comunemente utilizzato come sensore di temperatura o in serie con un circuito come limitatore di corrente di spunto.
* Con i termistori PTC, la resistenza aumenta con l'aumentare della temperatura, solitamente a causa delle aumentate agitazioni del reticolo termico, in particolare quelle delle impurità e delle imperfezioni. I termistori PTC sono comunemente installati in serie con un circuito e utilizzati per proteggere da condizioni di sovracorrente, come fusibili ripristinabili.

In questo kit utilizziamo un NTC. Ogni termistore ha una resistenza nominale. Qui è di 10k ohm, che è misurata a 25 gradi Celsius.

Ecco la relazione tra resistenza e temperatura:

    RT = RN * expB(1/TK – 1/TN)   

* **RT** è la resistenza del termistore NTC quando la temperatura è TK. 
* **RN** è la resistenza del termistore NTC alla temperatura nominale TN. Qui, il valore numerico di RN è 10k.
* **TK** è una temperatura Kelvin e l'unità è K. Qui, il valore numerico di TK è 273,15 + gradi Celsius.
* **TN** è una temperatura Kelvin nominale; anche l'unità è K. Qui, il valore numerico di TN è 273,15 + 25.
* E **B(beta)**, la costante del materiale del termistore NTC, è anche chiamata indice di sensibilità termica con un valore numerico di 3950.      
* **exp** è l'abbreviazione di esponenziale, e il numero base e è un numero naturale che vale circa 2,7.  

Converti questa formula TK=1/(ln(RT/RN)/B+1/TN) per ottenere la temperatura Kelvin che meno 273,15 equivale ai gradi Celsius.

Questa relazione è una formula empirica. È accurata solo quando la temperatura e la resistenza sono entro l'intervallo effettivo.

**Esempio**

* :ref:`basic_thermistor` (Progetto di Base)
* :ref:`fun_smart_fan` (Progetto Divertente)
