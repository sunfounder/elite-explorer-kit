.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_mfrc522:

MFRC522-Modul
=====================

**RFID**

Radiofrequenzidentifikation (RFID) bezieht sich auf Technologien, die drahtlose Kommunikation zwischen einem Objekt (oder Tag) und einem abfragenden Gerät (oder Lesegerät) zur automatischen Verfolgung und Identifizierung dieser Objekte verwenden. Die Übertragungsreichweite des Tags ist auf einige Meter vom Lesegerät begrenzt. Eine direkte Sichtlinie zwischen Lesegerät und Tag ist nicht unbedingt erforderlich.

Die meisten Tags enthalten mindestens einen integrierten Schaltkreis (IC) und eine Antenne. Der Mikrochip speichert Informationen und ist verantwortlich für das Management der Funkfrequenzkommunikation mit dem Lesegerät. Passive Tags haben keine unabhängige Energiequelle und hängen von einem externen elektromagnetischen Signal, das vom Lesegerät bereitgestellt wird, für ihren Betrieb ab. Aktive Tags verfügen über eine unabhängige Energiequelle, wie eine Batterie, und können daher über erhöhte Verarbeitungs-, Übertragungsfähigkeiten und Reichweite verfügen.

.. image:: img/mfrc522.png

**MFRC522**

Der MFRC522 ist eine Art integrierter Lese- und Schreibchip für Karten. Er wird üblicherweise im Funkbereich bei 13,56 MHz eingesetzt. Von der NXP Company eingeführt, ist er ein Niederspannungs-, kostengünstiger und kleinformatiger kontaktloser Kartenchip, eine ideale Wahl für intelligente Instrumente und tragbare Handgeräte.

Der MF RC522 verwendet fortschrittliche Modulations- und Demodulationskonzepte, die vollständig in allen Arten von 13,56 MHz passiven kontaktlosen Kommunikationsmethoden und -protokollen präsentiert werden. Zusätzlich unterstützt er den schnellen CRYPTO1-Verschlüsselungsalgorithmus zur Verifizierung von MIFARE-Produkten. Der MFRC522 unterstützt auch die MIFARE-Serie von hochgeschwindigkeitskontaktloser Kommunikation mit einer bidirektionalen Datenübertragungsrate von bis zu 424 kbit/s. Als neues Mitglied der 13,56 MHz hochintegrierten Leserkartenserie ist der MF RC522 dem vorhandenen MF RC500 und MF RC530 ähnlich, aber es gibt auch große Unterschiede. Er kommuniziert mit der Hostmaschine über die serielle Art, die weniger Verkabelung benötigt. Sie können zwischen SPI-, I2C- und seriellen UART-Modus (ähnlich wie RS232) wählen, was hilft, die Verbindung zu reduzieren, Platz auf der PCB-Platine zu sparen (kleinere Größe) und die Kosten zu senken.

**Beispiele**

* :ref:`basic_mfrc522` (Grundprojekt)
* :ref:`fun_access` (Spaßprojekt)
