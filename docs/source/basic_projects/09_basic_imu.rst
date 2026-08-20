.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_imu:

IMU-Modul (10-Achsen)
==========================

.. note:: Verschiedene Versionen dieses Kits können unterschiedliche IMU-Module verwenden. Bitte wählen Sie das passende Tutorial basierend auf der Version Ihres Kits. Wenn Sie ein 10-Achsen-IMU-Modul haben, lesen Sie bitte dieses Tutorial. Wenn Sie ein GY-87-Modul haben, lesen Sie bitte :ref:`basic_gy87`.

Das 10-Achsen-IMU-Modul (Inertial Measurement Unit, Trägheitsmesseinheit) kombiniert mehrere Sensoren, um umfassende Bewegungs- und Umgebungsdaten bereitzustellen. Es integriert einen barometrischen Drucksensor (SPL06_001) für die Höhenmessung, einen 6-Achsen-Bewegungssensor (SH3001) für Beschleunigung und Rotation sowie ein 3-Achsen-Magnetometer (QMC6310) für die Kompassrichtung. Dieses hochentwickelte Modul ist ideal für Robotik, Navigationssysteme und Anwendungen zur Bewegungserfassung.

Fritzing-Schaltplan
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


Bibliothek installieren
---------------------------------

Um die Bibliothek zu installieren, verwenden Sie den Arduino Library Manager.

   - Suchen Sie nach **„SunFounder_IMU“** und installieren Sie diese


      .. image:: img/09-add_lib_tip_imu.png



Kalibrierung
----------------------

Bevor Sie das IMU-Modul verwenden, wird empfohlen, eine Kalibrierung durchzuführen, um die Genauigkeit der Sensordaten zu gewährleisten. Die folgenden Schritte beschreiben die Kalibrierung:

* Öffnen Sie die Datei ``09-imu_calibration.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\09-imu_calibration``.

Nachdem Sie diesen Code ausgeführt haben, öffnen Sie den seriellen Monitor und Sie sehen die Ausgabe der Sensordaten. Sie hat normalerweise folgendes Format:

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

Kopieren Sie diese Daten.

Code ausführen
----------------------

Öffnen Sie die Datei ``09-imu.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\09-imu``.

Wechseln Sie zur Seite ``calibration_data.h`` im Projekt und fügen Sie die soeben kopierten Daten in die Datei ``calibration_data.h`` ein, wobei Sie die ursprünglichen Daten ersetzen.

.. image:: img/imu_cali_data.png
   :width: 80%

Wechseln Sie zurück zur Seite ``09-imu.ino`` und laden Sie den Code auf Ihr Arduino Uno R4 Board hoch.

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

Nachdem der Code erfolgreich auf Ihren Arduino Uno R4 hochgeladen wurde, erwacht der serielle Monitor zum Leben und gibt kontinuierlich Sensordaten des 10-Achsen-IMU-Moduls aus.

.. image:: img/imu_reading.png
