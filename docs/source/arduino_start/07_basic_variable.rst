Variable
========

Die Variable ist eines der mächtigsten und kritischsten Werkzeuge in einem Programm. Sie hilft uns, Daten in unseren Programmen zu speichern und abzurufen.

Das folgende Sketch-File verwendet Variablen. Es speichert die Pin-Nummern der LED an Bord in der Variablen ``ledPin`` und eine Zahl „500“ in der Variablen ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
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

Warte, ist das eine Duplikation dessen, was ``#define`` macht? Die Antwort ist NEIN.

* Die Rolle von ``#define`` ist es, einfach und direkt Text zu ersetzen, es wird vom Compiler nicht als Teil des Programms betrachtet. 
* Eine ``Variable`` hingegen existiert innerhalb des Programms und wird verwendet, um Werte zu speichern und abzurufen. Eine Variable kann auch ihren Wert innerhalb des Programms ändern, was ein define nicht kann.

Das untenstehende Sketch-File fügt sich selbst zur Variablen hinzu und wird dazu führen, dass die LED an Bord nach jedem Blinken länger blinkt.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Each execution increments the value by 200
    }

Eine Variable deklarieren
-----------------------------

Eine Variable zu deklarieren bedeutet, eine Variable zu erstellen. 

Um eine Variable zu deklarieren, benötigen Sie zwei Dinge: den Datentyp und den Variablennamen. Der Datentyp muss durch ein Leerzeichen von der Variable getrennt sein, und die Variablendeklaration muss mit einem ``;`` beendet werden.

Verwenden wir diese Variable als Beispiel.

.. code-block:: C

    int delayTime;

**Datentyp**

Hier ist ``int`` ein Datentyp, der als Integer-Typ bezeichnet wird und verwendet werden kann, um ganze Zahlen von -32768 bis 32766 zu speichern. Es kann jedoch keine Dezimalzahlen speichern.

Variablen können andere Arten von Daten als ganze Zahlen speichern. Die Arduino-Sprache (die, wie wir uns erinnern, C++ ist) hat eingebaute Unterstützung für einige davon (nur die am häufigsten verwendeten und nützlichsten sind hier aufgeführt):

* ``float``: Speichert eine Dezimalzahl, zum Beispiel 3,1415926.
* ``byte``: Kann Zahlen von 0 bis 255 speichern.
* ``boolean``: Hält nur zwei mögliche Werte, ``True`` oder ``False``, obwohl es ein Byte im Speicher belegt.
* ``char``: Hält eine Zahl von -127 bis 127. Da es als ``char`` gekennzeichnet ist, versucht der Compiler, es einer Zeichen aus dem |link_ascii| zuzuordnen.
* ``string``: Kann eine Zeichenkette speichern, z.B. ``Halloween``.


**Variablenname**


Sie können der Variablen jeden Namen geben, den Sie möchten, wie ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, aber es gibt einige grundlegende Regeln zu befolgen.

1. Beschreiben Sie, wofür sie verwendet wird. Hier habe ich die Variable delayTime genannt, damit Sie leicht verstehen können, was sie macht. Es funktioniert auch, wenn ich die Variable ``barryAllen`` nenne, aber es verwirrt die Person, die den Code betrachtet.

2. Verwenden Sie eine reguläre Nomenklatur. Sie können CamelCase verwenden, wie ich es getan habe, mit dem anfänglichen T in ``delayTime``, damit leicht zu erkennen ist, dass die Variable aus zwei Wörtern besteht. Sie können auch UnderScoreCase verwenden, um die Variable als ``delay_time`` zu schreiben. Es hat keinen Einfluss auf den Programmablauf, aber es würde dem Programmierer helfen, den Code zu lesen, wenn Sie die von Ihnen bevorzugte Nomenklatur verwenden.

3. Verwenden Sie keine Schlüsselwörter. Ähnlich wie bei der Eingabe von „int“ färbt die Arduino-IDE es, um Sie daran zu erinnern, dass es ein Wort mit einer besonderen Bedeutung ist und nicht als Variablenname verwendet werden kann. Ändern Sie den Namen der Variablen, wenn sie gefärbt ist.

4. Spezielle Symbole sind nicht erlaubt. Zum Beispiel Raum, #, $, /, +, % usw. Die Kombination aus englischen Buchstaben (Groß-/Kleinschreibung beachten), Unterstrichen und Zahlen (aber Zahlen können nicht als erstes Zeichen eines Variablennamens verwendet werden) ist reichhaltig genug.


**Einer Variablen einen Wert zuweisen**

Sobald wir die Variable deklariert haben, ist es an der Zeit, die Daten zu speichern. Wir verwenden den Zuweisungsoperator (d.h. ``=``), um den Wert in die Variable zu setzen.

Wir können Werte der Variablen zuweisen, sobald wir sie deklarieren.


.. code-block:: C

    int delayTime = 500;

Es ist auch möglich, ihr zu einem späteren Zeitpunkt einen neuen Wert zuzuweisen.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700