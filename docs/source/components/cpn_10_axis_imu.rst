.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_10_axis_imu:

Modulo IMU 10 assi
============================

.. image:: img/10_axis.png
    :align: center
    :width: 40%

Il modulo IMU a 10 assi è un modulo ad alta precisione a 10 assi (10DOF) in grado di misurare accelerazione, velocità angolare e intensità del campo magnetico su tre assi: x, y e z. È composto da tre sensori principali: SH3001, QMC6310 e SPL06_001, e comunica tramite il protocollo I2C.

Questo modulo si basa su tre sensori:

1. **SH3001**: È un accelerometro e giroscopio a 6 assi che può misurare accelerazione e velocità angolare su tre assi x, y e z.
2. **QMC6310**: È una bussola digitale a 3 assi che può misurare l'intensità del campo magnetico su tre assi x, y e z.
3. **SPL06_001**: È un sensore barometrico di temperatura e pressione che può misurare la pressione atmosferica e la temperatura.

L'SH3001 misura accelerazione e velocità angolare su tre assi x, y e z. Il QMC6310 misura l'intensità del campo magnetico su tre assi x, y e z. L'SPL06_001 misura la pressione atmosferica e la temperatura. I dati di questi sensori sono combinati per fornire informazioni accurate sull'orientamento del modulo nello spazio.

Il modulo IMU a 10 assi è comunemente utilizzato in applicazioni come droni, robotica e altri progetti che richiedono informazioni accurate sull'orientamento. È compatibile con le schede Arduino e può essere facilmente interfacciato con esse tramite il protocollo di comunicazione I2C.