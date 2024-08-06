.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_gy87:

Modulo IMU GY-87
============================

.. image:: img/gy87.png
    :align: center
    :width: 40%

Il modulo sensore GY-87 è un modulo ad alta precisione a 10 assi (10DOF) in grado di misurare accelerazione, velocità angolare e intensità del campo magnetico su tre assi: x, y e z. È composto da tre sensori principali: MPU6050, QMC5883L e BMP180, e comunica tramite il protocollo I2C.

Il modulo sensore GY-87 si basa su tre sensori:

1. **MPU6050**: Un accelerometro e giroscopio a 6 assi che può misurare accelerazione e velocità angolare su tre assi x, y e z.
2. **QMC5883L**: Una bussola digitale a 3 assi che può misurare l'intensità del campo magnetico su tre assi x, y e z.
3. **BMP180**: Un sensore barometrico di temperatura e pressione che può misurare pressione atmosferica e temperatura.

L'MPU6050 misura accelerazione e velocità angolare su tre assi x, y e z. Il QMC5883L misura l'intensità del campo magnetico su tre assi x, y e z. Il BMP180 misura pressione atmosferica e temperatura. I dati di questi sensori vengono combinati per fornire informazioni accurate sull'orientamento del modulo nello spazio.

Il modulo sensore GY-87 è comunemente utilizzato in applicazioni come droni, robotica e altri progetti che richiedono informazioni accurate sull'orientamento. È compatibile con le schede Arduino e può essere facilmente interfacciato con esse utilizzando il protocollo di comunicazione I2C.

.. image:: img/GY-87-SCH.jpg
    :align: center
    :width: 100%

.. raw:: html

    <br/>

**Esempio**

* :ref:`basic_gy87_bmp180` (Progetto Base)
* :ref:`basic_gy87_mpu6050` (Progetto Base)
* :ref:`basic_gy87_qmc5883l` (Progetto Base)
* :ref:`fun_escape` (Progetto Divertente)

