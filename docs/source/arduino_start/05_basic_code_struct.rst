Arduino Programmstruktur
===========================

Schauen wir uns die neue Sketch-Datei an. Obwohl sie selbst einige Zeilen Code enthält, ist es tatsächlich ein „leerer“ Sketch. 
Das Hochladen dieses Sketches auf das Entwicklungsboard bewirkt nichts.

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

Wenn wir ``setup()`` und ``loop()`` entfernen und den Sketch zu einer wirklich ``leeren`` Datei machen, werden Sie feststellen, dass er die Überprüfung nicht besteht. 
Sie sind gleichbedeutend mit dem menschlichen Skelett und unverzichtbar.

Während des Skizzierens wird ``setup()`` zuerst ausgeführt, und der Code darin (innerhalb von ``{}``) wird ausgeführt, nachdem das Board mit Strom versorgt oder zurückgesetzt wurde, und zwar nur einmal. 
``loop()`` wird verwendet, um die Hauptfunktion zu schreiben, und der Code darin wird in einer Schleife ausgeführt, nachdem ``setup()`` ausgeführt wurde.

Um setup() und loop() besser zu verstehen, verwenden wir vier Skizzen. Ihr Zweck ist es, die LED auf dem Arduino-Board blinken zu lassen. Bitte führen Sie jedes Experiment nacheinander durch und zeichnen Sie ihre spezifischen Effekte auf.

* Sketch 1: Lassen Sie die LED auf dem Board kontinuierlich blinken.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Lassen Sie die LED auf dem Board nur einmal blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Sketch 3: Lassen Sie die LED auf dem Board langsam einmal blinken und dann schnell blinken.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Meldet einen Fehler.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

Mit Hilfe dieser Skizzen können wir mehrere Merkmale von ``setup-loop`` zusammenfassen.

* ``loop()`` wird wiederholt ausgeführt, nachdem das Board mit Strom versorgt wurde. 
* ``setup()`` wird nur einmal ausgeführt, nachdem das Board mit Strom versorgt wurde. 
* Nachdem das Board mit Strom versorgt wurde, wird zuerst ``setup()`` ausgeführt, gefolgt von ``loop()``. 
* Der Code muss innerhalb des ``{}``-Bereichs von ``setup()`` oder ``loop()`` geschrieben werden, außerhalb des Rahmens wird ein Fehler auftreten.

.. note::
    Anweisungen wie ``digitalWrite(13,HIGH)`` werden verwendet, um die On-Board-LED anzusteuern, und wir werden in späteren Kapiteln detailliert auf ihre Verwendung eingehen.
