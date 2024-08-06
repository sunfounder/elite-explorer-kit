.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_i2c_lcd1602:

LCD1602 I2C
================

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Terra
* **VCC**: Alimentazione, 5V.
* **SDA**: Linea dati seriale. Collegare a VCC attraverso una resistenza di pullup.
* **SCL**: Linea di clock seriale. Collegare a VCC attraverso una resistenza di pullup.

Come tutti sappiamo, sebbene gli LCD e alcuni altri display arricchiscano notevolmente l'interazione uomo-macchina, condividono una debolezza comune. Quando sono collegati a un controller, occupano molte porte IO del controller, limitando altre funzioni del controller stesso.

Perciò, l'LCD1602 con un modulo I2C è stato sviluppato per risolvere questo problema. Il modulo I2C ha un chip I2C PCF8574 integrato che converte i dati seriali I2C in dati paralleli per il display LCD.

* |link_pcf8574_datasheet|

**Indirizzo I2C**

L'indirizzo predefinito è fondamentalmente 0x27, in alcuni casi potrebbe essere 0x3F.

Prendendo come esempio l'indirizzo predefinito di 0x27, l'indirizzo del dispositivo può essere modificato cortocircuitando i pad A0/A1/A2; nello stato predefinito, A0/A1/A2 è 1, e se il pad è cortocircuitato, A0/A1/A2 è 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Retroilluminazione/Contrasto**

La retroilluminazione può essere abilitata tramite un cappuccio jumper, scollegare il cappuccio jumper per disabilitare la retroilluminazione. Il potenziometro blu sul retro viene utilizzato per regolare il contrasto (il rapporto di luminosità tra il bianco più luminoso e il nero più scuro).

.. image:: img/back_lcd1602.jpg

* **Cappuccio Jumper**: La retroilluminazione può essere abilitata tramite questo cappuccio, scollegare questo cappuccio per disabilitare la retroilluminazione.
* **Potenziometro**: Viene utilizzato per regolare il contrasto (la chiarezza del testo visualizzato), che aumenta in senso orario e diminuisce in senso antiorario.



**Esempio**

* :ref:`basic_i2c_lcd1602` (Progetto Base)
* :ref:`basic_ultrasonic_sensor` (Progetto Base)
* :ref:`fun_plant_monitor` (Progetto Divertente)
* :ref:`fun_guess_number` (Progetto Divertente)
* :ref:`iot_Bluetooth_lcd` (Progetto IoT)

