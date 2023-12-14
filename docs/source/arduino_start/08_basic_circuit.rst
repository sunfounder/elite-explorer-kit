Wie man den Schaltkreis aufbaut
====================================

Viele Dinge, die Sie täglich verwenden, werden mit Strom betrieben, wie die Lichter in Ihrem Haus und der Computer, auf dem Sie gerade lesen.

Um Elektrizität zu nutzen, müssen Sie einen elektrischen Schaltkreis aufbauen. Ein Schaltkreis ist grundsätzlich ein Weg, durch den Elektrizität fließt, oder ein elektronischer Schaltkreis, und besteht aus elektrischen Geräten und Komponenten (Geräten), die auf bestimmte Weise verbunden sind, wie Widerstände, Kondensatoren, Stromversorgungen und Schalter.

.. image:: img/circuit.png
    :align: center
    :width: 250

.. raw:: html
    
    <br/>

Ein Schaltkreis ist ein geschlossener Weg, in dem Elektronen sich bewegen, um einen elektrischen Strom zu erzeugen. Damit Strom fließen kann, muss es einen leitenden Pfad zwischen dem positiven Anschluss der Stromversorgung und dem negativen Anschluss geben, was als geschlossener Schaltkreis bezeichnet wird (wenn er unterbrochen ist, spricht man von einem offenen Schaltkreis).



Das Arduino-Board hat einige Stromausgangspins (positiv) und einige Erdungspins (negativ).
Sie können diese Pins als positive und negative Seiten der Stromversorgung nutzen, indem Sie die Stromquelle in das Board einstecken.

.. image:: img/08_circuit_1.png
    :align: center
    :width: 70%

Mit Elektrizität können Sie Werke mit Licht, Klang und Bewegung erschaffen.
Sie können eine LED zum Leuchten bringen, indem Sie den langen Pin an den positiven Anschluss und den kurzen Pin an den negativen Anschluss anschließen.
Allerdings kann dies direkt gemacht schnell nicht nur die LED, sondern auch die Pins Ihres UNO R4-Boards beschädigen. Um dies zu vermeiden, ist es unerlässlich, einen 1kΩ-Widerstand in den Schaltkreis einzufügen, um sowohl die LED als auch die Pins des UNO R4 zu schützen.

Der von ihnen gebildete Schaltkreis ist unten dargestellt.

.. image:: img/08_circuit_2.png
    :align: center
    :width: 65%

.. raw:: html
    
    <br/>

Vielleicht haben Sie jetzt Fragen: Wie baue ich diesen Schaltkreis auf? Halte ich die Drähte mit der Hand fest oder klebe die Pins und Drähte?

In dieser Situation werden lötfreie Steckbretter Ihre stärksten Verbündeten sein.

.. _bc_bb:

Hallo, Steckbrett!
------------------------------

Ein Steckbrett ist eine rechteckige Kunststoffplatte mit einer Menge kleiner Löcher.
Diese Löcher ermöglichen es uns, elektronische Komponenten leicht einzusetzen und elektronische Schaltkreise aufzubauen.
Steckbretter fixieren elektronische Komponenten nicht dauerhaft, sodass wir einen Schaltkreis leicht reparieren und neu starten können, wenn etwas schiefgeht.

.. note::
    Für die Verwendung von Steckbrettern sind keine speziellen Werkzeuge erforderlich. Viele elektronische Komponenten sind jedoch sehr klein, und eine Pinzette kann uns helfen, kleine Teile besser aufzuheben.

Im Internet finden wir viele Informationen über Steckbretter.

* `Wie man ein Steckbrett benutzt - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `Was ist ein STECKBRETT? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_


Hier sind einige Dinge, die Sie über Steckbretter wissen sollten.

.. image:: ../components/img/breadboard_internal.png
    :align: center
    :width: 85%

.. raw:: html

   <br/>

#. Jede Halbzeilengruppe (wie Spalte A-E in Reihe 1 oder Spalte F-J in Reihe 3) ist verbunden. Wenn also ein elektrisches Signal bei A1 eingeht, kann es bei B1, C1, D1, E1 herausfließen, aber nicht bei F1 oder A2.

#. In den meisten Fällen werden beide Seiten des Steckbretts als Stromschienen verwendet, und die Löcher in jeder Spalte (etwa 50 Löcher) sind miteinander verbunden. Als allgemeine Regel gilt, dass positive Stromversorgungen an den Löchern in der Nähe des roten Drahts und negative Stromversorgungen an den Löchern in der Nähe des blauen Drahts angeschlossen werden.

**Lassen Sie uns der Stromrichtung folgen, um den Schaltkreis aufzubauen!**

.. image:: img/08_circuit_3.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

1. In diesem Schaltkreis nutzen wir den 5V-Pin des Boards, um die LED mit Strom zu versorgen. Verwenden Sie ein männlich-zu-männliches (M2M) Jumperkabel, um ihn mit der roten Stromschiene zu verbinden.
#. Um die LED und die Pins des UNO R4 zu schützen, muss der Strom durch einen 1k-Ohm-Widerstand fließen. Verbinden Sie ein Ende (jedes Ende) des Widerstands mit der roten Stromschiene und das andere Ende mit einer freien Reihe des Steckbretts.

   .. note::
        Der Farbring des 1000-Ohm :ref:`cpn_resistor` ist rot, schwarz, schwarz, braun und braun.

#. Wenn Sie die LED aufnehmen, werden Sie sehen, dass einer ihrer Anschlüsse länger ist als der andere. Verbinden Sie den längeren Anschluss mit derselben Reihe wie der Widerstand und den kürzeren Anschluss mit einer anderen Reihe.

   .. note::
        Der längere Anschluss ist die Anode, die die positive Seite des Schaltkreises repräsentiert; der kürzere Anschluss ist die Kathode, die die negative Seite repräsentiert.

        Die Anode muss über einen Widerstand mit dem GPIO-Pin verbunden sein; die Kathode muss mit dem GND-Pin verbunden sein.

#. Verwenden Sie ein männlich-zu-männliches (M2M) Jumperkabel, um den kurzen Pin der LED mit der negativen Stromschiene des Steckbretts zu verbinden.
#. Verbinden Sie den GND-Pin des Boards mit der negativen Stromschiene mit einem Jumper.

Vorsicht vor Kurzschlüssen
------------------------------
Kurzschlüsse können auftreten, wenn zwei Komponenten, die nicht verbunden sein sollten, „versehentlich“ verbunden werden. 
Dieses Kit enthält Widerstände, Transistoren, Kondensatoren, LEDs usw., die lange Metallstifte haben, die aneinanderstoßen und einen Kurzschluss verursachen können. Einige Schaltkreise funktionieren bei einem Kurzschluss einfach nicht richtig. Gelegentlich kann ein Kurzschluss Komponenten dauerhaft beschädigen, insbesondere zwischen der Stromversorgung und der Erdungsschiene, was dazu führt, dass der Schaltkreis sehr heiß wird, das Plastik auf dem Steckbrett schmilzt und sogar die Komponenten verbrennt!

Stellen Sie daher immer sicher, dass die Stifte aller Elektronik auf dem Steckbrett sich nicht berühren.

Ausrichtung des Schaltkreises
-------------------------------
Es gibt eine Orientierung zu Schaltkreisen, und die Ausrichtung spielt bei bestimmten elektronischen Komponenten eine bedeutende Rolle. Es gibt einige Geräte mit Polarität, was bedeutet, dass sie basierend auf ihren positiven und negativen Polen korrekt angeschlossen werden müssen. Schaltkreise, die mit der falschen Ausrichtung aufgebaut werden, funktionieren nicht richtig.

.. image:: img/08_circuit_4.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

Wenn Sie die LED in diesem einfachen Schaltkreis, den wir zuvor aufgebaut haben, umkehren, werden Sie feststellen, dass sie nicht mehr funktioniert.

Im Gegensatz dazu haben einige Geräte keine Richtung, wie die Widerstände in diesem Schaltkreis, sodass Sie sie umkehren können, ohne den normalen Betrieb der LEDs zu beeinflussen.

Die meisten Komponenten und Module mit Bezeichnungen wie „+“, „-“, „GND“, „VCC“ oder mit Anschlüssen unterschiedlicher Länge müssen auf eine bestimmte Weise mit dem Schaltkreis verbunden werden.


Schutz des Schaltkreises
-------------------------------------

Strom ist die Rate, mit der Elektronen an einem Punkt in einem vollständigen elektrischen Schaltkreis vorbeifließen. Im Grundsatz gilt: Strom = Fluss. Ein Ampere (AM-pir), oder Amp, ist die internationale Einheit zur Messung von Strom. Es drückt die Menge der Elektronen (manchmal auch „elektrische Ladung“ genannt) aus, die über einen bestimmten Zeitraum an einem Punkt in einem Schaltkreis vorbeifließen.

Die treibende Kraft (Spannung) hinter dem Fluss von Strom wird als Spannung bezeichnet und in Volt (V) gemessen.

Widerstand (R) ist die Eigenschaft des Materials, die den Fluss von Strom einschränkt, und er wird in Ohm (Ω) gemessen.

Nach dem Ohmschen Gesetz (solange die Temperatur konstant bleibt), sind Strom, Spannung und Widerstand proportional.
Der Strom eines Schaltkreises ist proportional zu seiner Spannung und umgekehrt proportional zu seinem Widerstand.

Daher ist Strom (I) = Spannung (V) / Widerstand (R).

* `Ohmsches Gesetz - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

Über das Ohmsche Gesetz können wir ein einfaches Experiment durchführen.

.. image:: img/08_circuit_5.png
    :width: 55%

Durch das Ändern des Drahtes von 5V auf 3.3V wird die LED schwächer.
Wenn Sie den Widerstand von 1000 Ohm auf 2000 Ohm ändern (Farbring: rot, schwarz, schwarz, braun und braun), werden Sie feststellen, dass die LED schwächer wird als zuvor. Je größer der Widerstand, desto schwächer die LED.

Die meisten fertig verpackten Module benötigen nur Zugang zur richtigen Spannung (normalerweise 3,3V oder 5V), wie z.B. das Ultraschallmodul.

In Ihren selbstgebauten Schaltkreisen müssen Sie jedoch auf die Versorgungsspannung und die Verwendung von Widerständen für elektrische Geräte achten.


Als Beispiel verbrauchen LEDs normalerweise 20mA Strom, und ihr Spannungsabfall beträgt etwa 1,8V. Nach dem Ohmschen Gesetz benötigen wir bei einer 5V-Stromversorgung einen Widerstand von mindestens 160 Ohm ((5-1,8)/20mA), um zu verhindern, dass die LED durchbrennt.



Schaltkreissteuerung mit Arduino
--------------------------------

Nachdem wir nun ein grundlegendes Verständnis von Arduino-Programmierung und elektronischen Schaltkreisen haben, ist es an der Zeit, die entscheidende Frage zu stellen: Wie steuert man Schaltkreise mit Arduino?

Einfach ausgedrückt, steuert Arduino einen Schaltkreis, indem es das Signalniveau der Pins auf dem Board ändert. Zum Beispiel, wenn eine LED auf dem Board gesteuert wird, schreibt es ein hohes oder niedriges Signalniveau auf Pin 13.


Lassen Sie uns nun versuchen, den Arduino-Board so zu programmieren, dass er die blinkende LED auf dem Steckbrett steuert. Bauen Sie den Schaltkreis so auf, dass die LED mit Pin 9 verbunden ist.

.. image:: img/08_circuit_6.png
    :width: 400
    :align: center


Laden Sie anschließend diesen Sketch auf das Arduino-Entwicklungsboard hoch.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Dieser Sketch ist dem, den wir verwendet haben, um das Blinken der LED auf dem Board zu steuern, sehr ähnlich, der Unterschied besteht darin, dass der Wert von ``ledPin`` auf 9 geändert wurde.
Das liegt daran, dass wir dieses Mal versuchen, das Signalniveau von Pin 9 zu steuern.

Nun können Sie sehen, wie die LED auf dem Steckbrett blinkt.

