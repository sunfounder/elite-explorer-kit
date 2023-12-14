.. _cpn_7segment:

7-Segment-Anzeige
======================

.. image:: img/7-seg.jpg

Eine 7-Segment-Anzeige ist eine 8-förmige Komponente, die 7 LEDs umfasst. Jede LED wird als Segment bezeichnet - wenn sie aktiviert wird, bildet jedes Segment einen Teil einer anzuzeigenden Zahl.

Es gibt zwei Arten von Pin-Verbindungen: Gemeinsame Kathode (CC) und Gemeinsame Anode (CA). Wie der Name schon sagt, hat eine CC-Anzeige alle Kathoden der 7 LEDs verbunden, während eine CA-Anzeige alle Anoden der 7 Segmente verbunden hat.

In diesem Kit verwenden wir die 7-Segment-Anzeige mit gemeinsamer Kathode. Hier ist das elektronische Symbol.

.. image:: img/segment_cathode.png
    :width: 800

Jede der LEDs in der Anzeige erhält ein positionelles Segment mit einem ihrer Anschlusspins, der aus dem rechteckigen Kunststoffgehäuse herausgeführt wird. Diese LED-Pins sind von "a" bis "g" beschriftet und repräsentieren jede einzelne LED. Die anderen LED-Pins sind miteinander verbunden und bilden einen gemeinsamen Pin. Indem die entsprechenden Pins der LED-Segmente in einer bestimmten Reihenfolge in Vorwärtsrichtung polarisiert werden, leuchten einige Segmente auf und andere bleiben dunkel, sodass der entsprechende Charakter auf der Anzeige dargestellt wird.

**Anzeigecodes**

Um Ihnen zu helfen, zu verstehen, wie 7-Segment-Anzeigen (Gemeinsame Kathode) Zahlen darstellen, haben wir die folgende Tabelle gezeichnet. Zahlen sind die Zahlen 0-F, die auf der 7-Segment-Anzeige angezeigt werden; (DP) GFEDCBA bezieht sich auf das entsprechende LED-Set auf 0 oder 1, zum Beispiel bedeutet 00111111, dass DP und G auf 0 gesetzt sind, während die anderen auf 1 gesetzt sind. Daher wird die Zahl 0 auf der 7-Segment-Anzeige angezeigt, während HEX-Code der entsprechenden Hexadezimalzahl entspricht.

.. image:: img/segment_code.png

**Beispiel**

* :ref:`basic_7segment` (Grundprojekt)
* :ref:`basic_74hc595` (Grundprojekt)
* :ref:`fun_digital_dice` (Spaßprojekt)

