.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_gy87:

GY-87 IMU-Modul
============================

.. image:: img/gy87.png
    :align: center
    :width: 40%

Das GY-87-Sensormodul ist ein hochpräzises 10-Achsen-Modul (10DOF), das in der Lage ist, Beschleunigung, Winkelgeschwindigkeit und magnetische Feldstärke entlang drei Achsen: x, y und z zu messen. Es besteht aus drei Hauptkomponenten: MPU6050, QMC5883L und BMP180 und kommuniziert über das I2C-Protokoll.

Das GY-87-Sensormodul basiert auf drei Sensoren:

1. **MPU6050**: Dies ist ein 6-Achsen-Beschleunigungsmesser und Gyroskop, das Beschleunigung und Winkelgeschwindigkeit in den drei Achsen x, y und z messen kann.
2. **QMC5883L**: Dies ist ein 3-Achsen-Digitalkompass, der die Stärke des Magnetfelds in den drei Achsen x, y und z messen kann.
3. **BMP180**: Dies ist ein barometrischer Temperatur- und Drucksensor, der den atmosphärischen Druck und die Temperatur messen kann.

Der MPU6050 misst Beschleunigung und Winkelgeschwindigkeit in den drei Achsen x, y und z. Der QMC5883L misst die Stärke des Magnetfelds in den drei Achsen x, y und z. Der BMP180 misst den atmosphärischen Druck und die Temperatur. Die Daten dieser Sensoren werden kombiniert, um genaue Informationen über die Orientierung des Moduls im Raum zu liefern.

Das GY-87-Sensormodul wird häufig in Anwendungen wie Drohnen, Robotik und anderen Projekten verwendet, die genaue Orientierungsinformationen benötigen. Es ist mit Arduino-Boards kompatibel und kann leicht über das I2C-Kommunikationsprotokoll mit ihnen verbunden werden.

.. image:: img/GY-87-SCH.jpg
    :align: center
    :width: 100%

.. raw:: html

    <br/>

**Beispiel**

* :ref:`basic_gy87_bmp180` (Grundprojekt)
* :ref:`basic_gy87_mpu6050` (Grundprojekt)
* :ref:`basic_gy87_qmc5883l` (Grundprojekt)
* :ref:`fun_escape` (Spaßprojekt)

