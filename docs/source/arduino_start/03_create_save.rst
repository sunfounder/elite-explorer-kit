Wie man einen Sketch erstellt, öffnet oder speichert?
===========================================================

#. Wenn Sie die Arduino IDE zum ersten Mal öffnen oder einen neuen Sketch erstellen, sehen Sie eine Seite wie diese, auf der die Arduino IDE eine neue Datei für Sie erstellt, die als „Sketch“ bezeichnet wird.

   .. image:: img/sp221014_173458.png

   Diese Sketch-Dateien haben einen regulären temporären Namen, an dem Sie das Erstellungsdatum der Datei erkennen können. ``sketch_oct14a.ino`` bedeutet erster Sketch am 14. Oktober, ``.ino`` ist das Dateiformat dieses Sketches.

#. Jetzt versuchen wir, einen neuen Sketch zu erstellen. Kopieren Sie den folgenden Code in die Arduino IDE, um den ursprünglichen Code zu ersetzen.

   .. image:: img/create1.png

   .. code-block:: Arduino

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

#. Drücken Sie ``Ctrl+S`` oder klicken Sie auf **File** -> **Save**. Der Sketch wird standardmäßig unter ``C:\Users\{your_user}\Documents\Arduino`` gespeichert. Sie können ihn umbenennen oder einen neuen Pfad zum Speichern auswählen.

   .. image:: img/create2.png

#. Nach erfolgreichem Speichern sehen Sie, dass der Name in der Arduino IDE aktualisiert wurde.

   .. image:: img/create3.png

Bitte fahren Sie mit dem nächsten Abschnitt fort, um zu lernen, wie Sie diesen erstellten Sketch auf Ihr Arduino-Board hochladen.
