.. _cpn_power:

Stromversorgungsmodul
=====================

Wenn wir einen großen Strom benötigen, um eine Komponente zu betreiben, kann dies die normale Arbeit des Arduino UNO-Boards stark beeinträchtigen. Daher versorgen wir die Komponente separat mit diesem Modul, um sie sicher und stabil laufen zu lassen.

Sie können es einfach in das Steckbrett stecken, um Strom zu liefern. Es bietet eine Spannung von 3,3V und 5V, und Sie können entweder über eine mitgelieferte Jumperkappe verbinden.

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**Merkmale und Spezifikationen**

* Stromversorgungseingang: USB Typ-C, 5V
* Ausgangsspannung: 5V, 3.3V (einstellbar über Jumper. 0V, 3.3V und 5V Konfiguration)
* Ausgangsstrom: 5V/1,5A, 3,3V/1A
* Ein-Aus-Schalter verfügbar
* Zwei unabhängige Kanäle
* Onboard-Berg-Männchen-Header für GND, 5V, 3.3V Ausgang
* USB (Typ-C) Ausgang verfügbar
* USB (Typ-A) Eingang verfügbar
* An Bord LED: Ladeanzeige CHG, Betriebsanzeige PWR
* Akku: 3,7V 14500 Lithium-Ionen-Akku, 500mAh
* Abmessungen: 52mm x 32mm (L x B)


**Beispiel**

* :ref:`basic_motor` (Grundprojekt)
* :ref:`basic_pump` (Grundprojekt)
* :ref:`basic_stepper_motor` (Grundprojekt)
* :ref:`fun_smart_fan` (Spaßprojekt)
* :ref:`fun_plant_monitor` (Spaßprojekt)
* :ref:`fun_access` (Spaßprojekt)
* :ref:`fun_pong` (Spaßprojekt)

