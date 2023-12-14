.. _cpn_mpr121:

MPR121
===========================

.. image:: img/mpr121.png


* **3.3V**: Stromversorgung
* **IRQ**: Open-Collector-Interrupt-Ausgangspin, aktiv niedrig
* **SCL**: I2C-Takt
* **SDA**: I2C-Daten
* **ADD**: I2C-Adressauswahl-Eingangspin. Verbindet man den ADDR-Pin mit der VSS-, VDD-, SDA- oder SCL-Leitung, ergeben sich die I2C-Adressen 0x5A, 0x5B, 0x5C und 0x5D
* **GND**: Masse
* **0~11**: Elektrode 0~11, Elektrode ist ein Berührungssensor. Typischerweise können Elektroden einfach ein Stück Metall oder ein Draht sein. Manchmal können jedoch die Länge des Drahtes oder das Material, auf dem die Elektrode liegt, das Auslösen des Sensors erschweren. Aus diesem Grund ermöglicht der MPR121, zu konfigurieren, was erforderlich ist, um eine Elektrode auszulösen und wieder zu deaktivieren.

**ÜBERSICHT MPR121**

Der MPR121 ist der Nachfolger des kapazitiven Touchsensor-Controllers nach der Erstveröffentlichung der MPR03x-Serie. Der MPR121 verfügt über erhöhte interne Intelligenz, einige der wichtigen Ergänzungen umfassen eine erhöhte Elektrodenanzahl, eine hardwarekonfigurierbare I2C-Adresse, ein erweitertes Filtersystem mit Entprellung und völlig unabhängige Elektroden mit eingebauter Auto-Konfiguration. Das Gerät verfügt auch über einen 13. simulierten Sensor-Kanal, der für die Näherungserkennung mittels multiplexierter Sensoreingänge gewidmet ist.

* |link_mpr121_datasheet|

**Merkmale**

* Niedriger Stromverbrauch
    • 1,71 V bis 3,6 V Betriebsspannung
    • 29 μA Versorgungsstrom bei 16 ms Abtastintervall
    • 3 μA Strom im Stoppmodus
* 12 Kapazitätssensoreingänge
    • 8 Eingänge sind multifunktional für LED-Treiber und GPIO
* Komplette Berührungserkennung
    • Auto-Konfiguration für jeden Sensoreingang
    • Auto-Kalibrierung für jeden Sensoreingang
    • Berührungs-/Freigabeschwelle und Entprellung für die Berührungserkennung
* I2C-Schnittstelle mit Interrupt-Ausgang
* 3 mm x 3 mm x 0,65 mm 20-poliges QFN-Gehäuse
* Betriebstemperaturbereich von -40°C bis +85°C



**Beispiel**

* :ref:`basic_mpr121` (Grundprojekt)
* :ref:`fun_fruit_piano` (Spaßprojekt)
