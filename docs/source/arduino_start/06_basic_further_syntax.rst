Regeln für das Schreiben eines Sketches
===========================================

Wenn Sie einen Freund bitten, das Licht für Sie einzuschalten, können Sie sagen „Schalte das Licht ein.“ oder „Licht an, Kumpel.“, Sie können jeden Tonfall verwenden, den Sie möchten.

Wenn Sie jedoch möchten, dass das Arduino-Board etwas für Sie tut, müssen Sie die Programmiersprache von Arduino befolgen, um die Befehle einzugeben.

Dieses Kapitel enthält die grundlegenden Regeln der Arduino-Sprache und wird Ihnen helfen zu verstehen, wie man natürliche Sprache in Code übersetzt.

Natürlich ist dies ein Prozess, der Zeit braucht, um sich daran zu gewöhnen, und es ist auch der fehleranfälligste Teil des Prozesses für Anfänger. Wenn Sie also oft Fehler machen, ist das in Ordnung, versuchen Sie es einfach noch ein paar Mal.


Semikolon ``;``
---------------

Genau wie beim Schreiben eines Briefes, wo Sie am Ende jedes Satzes einen Punkt als Ende schreiben, erfordert die Arduino-Sprache, dass Sie ``;`` verwenden, um dem Board das Ende des Befehls mitzuteilen.

Nehmen wir das bekannte Beispiel „Blinkende LED an Bord“. Ein korrekter Sketch sollte so aussehen.

Beispiel:

.. code-block:: C

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

Als Nächstes werfen wir einen Blick auf die folgenden zwei Skizzen und raten, ob sie vor dem Ausführen von Arduino korrekt erkannt werden können.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Das Ergebnis ist, dass **Sketch A** einen Fehler meldet und **Sketch B** funktioniert.

* Die Fehler in **Sketch A** sind fehlende ``;`` und obwohl es normal aussieht, kann Arduino es nicht lesen.
* **Sketch B**, sieht ungewöhnlich aus, aber tatsächlich existieren Einrückungen, Zeilenumbrüche und Leerzeichen in Arduino-Programmen nicht, also sieht es für den Arduino-Compiler genauso aus wie im Beispiel.

Schreiben Sie Ihren Code jedoch bitte nicht wie **Sketch B**, denn normalerweise sind es Menschen, die den Code schreiben und betrachten, also bringen Sie sich nicht in Schwierigkeiten.


Geschweifte Klammern ``{}``
------------------------------

``{}`` ist ein Hauptbestandteil der Arduino-Programmiersprache, und sie müssen paarweise auftreten. 
Eine bessere Programmierkonvention ist es, eine Struktur, die geschweifte Klammern erfordert, einzufügen, indem man die rechte geschweifte Klammer direkt nach dem Tippen der linken geschweiften Klammer eintippt und dann den Cursor zwischen die Klammern bewegt, um die Anweisung einzufügen.



Kommentar ``//``
--------------------

Kommentare sind der Teil des Sketches, den der Compiler ignoriert. Sie werden normalerweise verwendet, um anderen zu erklären, wie das Programm funktioniert.

Wenn wir zwei benachbarte Schrägstriche in einer Codezeile schreiben, ignoriert der Compiler alles bis zum Ende der Zeile.

Wenn wir einen neuen Sketch erstellen, kommt er mit zwei Kommentaren, und wenn wir diese zwei Kommentare entfernen, wird der Sketch in keiner Weise beeinflusst.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }

Kommentare sind sehr nützlich in der Programmierung, und einige häufige Verwendungen sind unten aufgeführt.

* Verwendung A: Sich selbst oder anderen erklären, was dieser Abschnitt des Codes macht.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Verwendung B: Einige Aussagen vorübergehend invalidieren (ohne sie zu löschen) und sie entsperren, wenn Sie sie verwenden müssen, sodass Sie sie nicht neu schreiben müssen. Dies ist sehr nützlich beim Debuggen von Code und beim Versuch, Programmfehler zu lokalisieren.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Verwenden Sie das Tastenkürzel ``Ctrl+/``, um Ihnen beim schnellen Kommentieren oder Entkommentieren Ihres Codes zu helfen.

Kommentar ``/**/``
------------------

Wie ``//`` für Kommentare. Diese Art von Kommentar kann mehr als eine Zeile lang sein, und sobald der Compiler ``/*`` liest, ignoriert er alles, was folgt, bis er auf ``*/`` trifft.

Beispiel 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

Dies ist ein nützliches Werkzeug in C++.

.. code-block:: C

    #define identifier token-string

Der Compiler ersetzt automatisch ``identifier`` durch ``token-string``, wenn er es liest, was normalerweise für Konstantendefinitionen verwendet wird.

Als Beispiel hier ein Sketch, der define verwendet, was die Lesbarkeit des Codes verbessert.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Für den Compiler sieht es tatsächlich so aus.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Wir können sehen, dass der ``identifier`` ersetzt wird und im Programm nicht existiert.
Daher gibt es einige Vorsichtsmaßnahmen bei der Verwendung.

1. Ein ``token-string`` kann nur manuell geändert werden und kann nicht durch Rechenoperationen im Programm in andere Werte umgewandelt werden.

2. Vermeiden Sie die Verwendung von Symbolen wie ``;``. Zum Beispiel.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Der Compiler wird es als Folgendes erkennen, was als Fehler gemeldet wird.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Eine Namenskonvention für ``#define`` ist, den ``identifier`` zu groß zu schreiben, um Verwechslungen mit Variablen zu vermeiden.
