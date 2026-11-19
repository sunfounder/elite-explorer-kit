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


Kalibrierung
----------------------

Kalibrieren Sie das IMU-Modul, bevor Sie Sensordaten auslesen, damit die Messwerte genau sind.

#. Installieren Sie die Bibliothek **SunFounder_IMU**: Öffnen Sie den Arduino Library Manager, suchen Sie nach **„SunFounder_IMU“** und klicken Sie auf **INSTALL**. Das Bild unten zeigt den Eintrag nach der Installation.

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. Öffnen Sie die Datei ``09-imu_calibration.ino`` im Pfad ``elite-explorer-kit-main\basic_project\09-imu_calibration`` und laden Sie sie auf Ihr Board hoch.

#. Öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf **115200** sowie das Zeilenende auf **Both NL & CR** ein.

#. Führen Sie die Kalibrierung über die sechs Flächen durch und folgen Sie den Anweisungen im seriellen Monitor:

   * Senden Sie ein beliebiges Zeichen, um zu starten. Der serielle Monitor zeigt dann die erste Ausrichtung an.
   * Bringen Sie das Modul in der angegebenen Reihenfolge in die sechs Ausrichtungen: Z oben, Z unten, X oben, X unten, Y oben, Y unten.
   * Halten Sie das Modul während jeder Messung vollständig still, senden Sie anschließend erneut ein beliebiges Zeichen und wechseln Sie zur nächsten Ausrichtung.

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. Nach der sechsten Ausrichtung gibt der serielle Monitor die Kalibrierungskonstanten aus. Kopieren Sie die sechs Zeilen:

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   Die Werte oben sind nur ein Beispiel — Ihre Werte gehören zu Ihrem eigenen Modul.

#. Öffnen Sie das Projekt ``09-imu`` und darin die Registerkarte ``calibration_data.h``, und ersetzen Sie die sechs Arrays durch die kopierten Werte.

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. Laden Sie ``09-imu.ino`` auf Ihr Arduino Uno R4 Board hoch. Der serielle Monitor gibt dann fortlaufend die Daten von Beschleunigungsmesser, Gyroskop, Magnetometer und Barometer aus.

   .. image:: img/imu_reading.png
