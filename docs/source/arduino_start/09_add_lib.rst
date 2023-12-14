.. _add_libraries:

Wie fügt man Bibliotheken hinzu? (Wichtig)
===============================================

Eine Bibliothek ist eine Sammlung von vorab geschriebenem Code oder Funktionen, die die Möglichkeiten der Arduino-IDE erweitern. Bibliotheken bieten gebrauchsfertigen Code für verschiedene Funktionalitäten und ermöglichen es Ihnen, Zeit und Aufwand bei der Programmierung komplexer Funktionen zu sparen.


Verwendung des Bibliotheks-Managers
------------------------------------------

Viele Bibliotheken sind direkt über den Arduino-Bibliotheks-Manager verfügbar. Sie können den Bibliotheks-Manager wie folgt aufrufen:

#. Im **Library Manager** können Sie nach der gewünschten Bibliothek anhand ihres Namens suchen oder durch verschiedene Kategorien stöbern.

   .. note::

      In Projekten, in denen eine Bibliotheksinstallation erforderlich ist, gibt es Hinweise, welche Bibliotheken zu installieren sind. Befolgen Sie die bereitgestellten Anweisungen, wie zum Beispiel „Hier wird die DHT-Sensorbibliothek verwendet, Sie können sie aus dem Bibliotheks-Manager installieren.“ Installieren Sie einfach die empfohlenen Bibliotheken, wie vorgeschlagen.

   .. image:: img/install_lib3.png

#. Wenn Sie die gewünschte Bibliothek gefunden haben, klicken Sie darauf und dann auf den **Install**-Button.

   .. image:: img/install_lib2.png

#. Die Arduino-IDE wird die Bibliothek automatisch für Sie herunterladen und installieren.

.. _manual_install_lib:

Manuelle Installation
-----------------------

Einige Bibliotheken sind nicht über den **Library Manager** verfügbar und müssen manuell installiert werden. Um diese Bibliotheken zu installieren, befolgen Sie diese Schritte:

#. Öffnen Sie die Arduino-IDE und gehen Sie zu **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/add_lib_zip.png

#. Navigieren Sie zum Verzeichnis, in dem sich die Bibliotheksdateien befinden, wie zum Beispiel der Ordner ``elite-explorer-kit-main/library/``, und wählen Sie die Bibliotheksdatei aus und klicken Sie auf **Open**.

   .. image:: img/rfid_choose.png

#. Nach kurzer Zeit erhalten Sie eine Benachrichtigung über eine erfolgreiche Installation.

   .. image:: img/rfid_success.png

#. Wiederholen Sie den gleichen Prozess, um weitere Bibliotheken hinzuzufügen.


Bibliotheksstandort
-----------------------

Die mit einem der oben genannten Methoden installierten Bibliotheken finden Sie im Standardbibliotheksverzeichnis der Arduino-IDE, das normalerweise unter ``C:\Users\xxx\Dokumente\Arduino\libraries`` liegt.

Wenn Ihr Bibliotheksverzeichnis anders ist, können Sie es überprüfen, indem Sie zu **File** -> **Preferences** gehen.

.. image:: img/install_lib1.png



**Referenz**

* |link_install_arduino_lib|
