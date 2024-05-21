.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_buzzer:

Summer
=======

.. image:: img/buzzer1.png
    :width: 50%
    :align: center

Als eine Art elektronischer Summer mit integrierter Struktur werden Summer, die mit Gleichstrom versorgt werden, häufig in Computern, Druckern, Fotokopierern, Alarmanlagen, elektronischem Spielzeug, Automobil-Elektronikgeräten, Telefonen, Zeitgebern und anderen elektronischen Produkten oder Sprachgeräten eingesetzt.

Summer können in aktive und passive Typen unterteilt werden (siehe das folgende Bild). Drehen Sie den Summer so, dass seine Pins nach oben zeigen, und der Summer mit einer grünen Platine ist ein passiver Summer, während derjenige, der mit schwarzem Klebeband umhüllt ist, ein aktiver ist.

.. image:: img/buzzer2.png
    :width: 60%
    :align: center

Der Unterschied zwischen einem aktiven und einem passiven Summer:

Ein aktiver Summer hat eine eingebaute Oszillationsquelle, daher erzeugt er Töne, wenn er mit Strom versorgt wird. Ein passiver Summer hat jedoch keine solche Quelle, daher wird er nicht piepen, wenn Gleichstromsignale verwendet werden; stattdessen benötigen Sie Quadratwellen mit einer Frequenz zwischen 2K und 5K, um ihn zu betreiben. Der aktive Summer ist oft teurer als der passive aufgrund mehrerer eingebauter Oszillationsschaltungen.

Das Folgende ist das elektrische Symbol eines Summers. Er hat zwei Pins mit positiven und negativen Polen. Ein + auf der Oberfläche repräsentiert den Anodenpol und der andere ist der Kathodenpol.

.. image:: img/buzzer_symbol.png
    :width: 150

Sie können die Pins des Summers überprüfen, der längere ist der Anodenpol und der kürzere der Kathodenpol. Bitte verwechseln Sie diese nicht beim Anschließen, sonst wird der Summer keinen Ton erzeugen.

|link_buzzer_wiki|

**Beispiel**

* :ref:`basic_active_buzzer` (Grundprojekt)
* :ref:`basic_passive_buzzer` (Grundprojekt)
* :ref:`fun_access` (Spaßprojekt)

