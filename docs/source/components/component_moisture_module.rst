.. _cpn_soil_moisture:

Bodenfeuchtigkeitsmodul
================================

.. image:: img/soil_mositure.png

* GND: Erde
* VCC: Stromversorgung, 3.3v~5V
* AOUT: Gibt den Wert der Bodenfeuchtigkeit aus, je feuchter der Boden, desto geringer sein Wert.

Dieser kapazitive Bodenfeuchtigkeitssensor unterscheidet sich von den meisten auf dem Markt erhältlichen resistiven Sensoren, da er das Prinzip der kapazitiven Induktion zur Messung der Bodenfeuchtigkeit nutzt. Dies vermeidet das Problem der Korrosionsanfälligkeit bei resistiven Sensoren und verlängert dadurch die Lebensdauer erheblich.

Er besteht aus korrosionsbeständigen Materialien und hat eine ausgezeichnete Lebensdauer. Setzen Sie ihn in die Erde um Pflanzen herum ein, um Echtzeitdaten zur Bodenfeuchtigkeit zu überwachen. Das Modul beinhaltet einen Spannungsregler, der es ermöglicht, in einem Spannungsbereich von 3,3 ~ 5,5 V zu arbeiten. Es eignet sich ideal für Niederspannungs-Mikrocontroller mit 3,3 V und 5 V Versorgung.

Das Hardware-Schaltbild des kapazitiven Bodenfeuchtigkeitssensors ist unten dargestellt.

.. image:: img/solid_schematic.png

Es gibt einen Festfrequenz-Oszillator, der mit einem 555-Timer-IC aufgebaut ist. Die erzeugte Rechteckwelle wird dann wie ein Kondensator an den Sensor geführt. Allerdings hat der Kondensator für das Rechteckwellensignal eine gewisse Reaktanz oder, um es anders auszudrücken, einen Widerstand mit einem rein ohmschen Widerstand (10k-Widerstand an Pin 3), um einen Spannungsteiler zu bilden.

Je höher die Bodenfeuchtigkeit, desto höher die Kapazität des Sensors. Infolgedessen hat die Rechteckwelle weniger Reaktanz, was die Spannung auf der Signalleitung verringert, und der Wert des analogen Eingangs über den Mikrocontroller ist kleiner.

**Spezifikation**

* Betriebsspannung: 3,3 ~ 5,5 VDC
* Ausgangsspannung: 0 ~ 3,0VDC
* Betriebsstrom: 5mA
* Schnittstelle: PH2.0-3P
* Abmessungen: 3,86 x 0,905 Zoll (L x B)
* Gewicht: 15g

**Beispiel**

* :ref:`basic_moisture` (Grundprojekt)
* :ref:`fun_plant_monitor` (Spaßprojekt)

