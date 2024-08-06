.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_dht11:

Modulo Sensore di Umidità e Temperatura DHT11
=====================================================

Il sensore digitale di temperatura e umidità DHT11 è un sensore composito che contiene un'uscita digitale calibrata del segnale di temperatura e umidità. 
La tecnologia di raccolta dei moduli digitali dedicati e la tecnologia di rilevamento della temperatura e dell'umidità sono applicate per garantire che il prodotto abbia un'alta affidabilità e un'eccellente stabilità a lungo termine.

Sono disponibili solo tre pin per l'uso: VCC, GND e DATA. 
Il processo di comunicazione inizia con la linea DATA che invia segnali di avvio al DHT11, e il DHT11 riceve i segnali e restituisce un segnale di risposta. 
Successivamente, l'host riceve il segnale di risposta e inizia a ricevere i dati di umidità e temperatura a 40 bit (8 bit di umidità intera + 8 bit di umidità decimale + 8 bit di temperatura intera + 8 bit di temperatura decimale + 8 bit di checksum).

.. image:: img/Dht11.png


* |link_dht11_datasheet|

**Esempio**

* :ref:`basic_humiture_sensor` (Progetto Base)
* :ref:`fun_plant_monitor` (Progetto Divertente)
* :ref:`iot_arduino_cloud` (Progetto IoT)
* :ref:`iot_ble_home` (Progetto IoT)
