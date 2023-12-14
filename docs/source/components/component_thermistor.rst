.. _cpn_thermistor:

Thermistor
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Ein Thermistor ist eine Art Widerstand, dessen Widerstand stark temperaturabhängig ist, stärker als bei herkömmlichen Widerständen. Das Wort ist eine Kombination aus "thermal" (thermisch) und "resistor" (Widerstand). Thermistoren werden weit verbreitet eingesetzt, unter anderem als Einschaltstrombegrenzer, Temperatursensoren (typischerweise vom Typ NTC, also mit negativem Temperaturkoeffizienten), selbstzurücksetzende Überstromschutzgeräte und selbstregulierende Heizelemente (typischerweise vom Typ PTC, also mit positivem Temperaturkoeffizienten).

* |link_thermistor_wikipedia|

Hier ist das elektronische Symbol eines Thermistors.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Thermistoren gibt es in zwei grundlegend entgegengesetzten Typen:

* Bei NTC-Thermistoren sinkt der Widerstand mit steigender Temperatur, in der Regel aufgrund einer Zunahme an Leitungselektronen, die durch thermische Agitation aus dem Valenzband gehoben werden. Ein NTC wird häufig als Temperatursensor eingesetzt oder in Reihe mit einem Schaltkreis als Einschaltstrombegrenzer verwendet.
* Bei PTC-Thermistoren steigt der Widerstand mit zunehmender Temperatur, in der Regel aufgrund erhöhter thermischer Gitterschwingungen, insbesondere jener von Verunreinigungen und Fehlstellen. PTC-Thermistoren werden üblicherweise in Reihe mit einem Schaltkreis installiert und dienen als Schutz gegen Überstrombedingungen, als rückstellbare Sicherungen.

In diesem Kit verwenden wir einen NTC-Typ. Jeder Thermistor hat einen normalen Widerstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Hier ist die Beziehung zwischen Widerstand und Temperatur:

    RT = RN * expB(1/TK – 1/TN)   

* **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur TK. 
* **RN** ist der Widerstand des NTC-Thermistors unter der Nenntemperatur TN. Hier beträgt der numerische Wert von RN 10k.
* **TK** ist eine Kelvin-Temperatur, und die Einheit ist K. Hier beträgt der numerische Wert von TK 273,15 + Grad Celsius.
* **TN** ist eine Nenn-Kelvin-Temperatur; die Einheit ist ebenfalls K. Hier beträgt der numerische Wert von TN 273,15+25.
* Und **B(beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet und hat den numerischen Wert 3950.      
* **exp** ist die Abkürzung für Exponentialfunktion, und die Basiszahl e ist eine natürliche Zahl und ungefähr gleich 2,7.  

Konvertieren Sie diese Formel TK=1/(ln(RT/RN)/B+1/TN), um die Kelvin-Temperatur zu erhalten, von der 273,15 abgezogen die Grad Celsius ergibt.

Diese Beziehung ist eine empirische Formel. Sie ist nur genau, wenn Temperatur und Widerstand innerhalb des wirksamen Bereichs liegen.

**Beispiel**

* :ref:`basic_thermistor` (Grundprojekt)
* :ref:`fun_smart_fan` (Spaßprojekt)

