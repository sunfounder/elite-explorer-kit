.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Der 74HC595 besteht aus einem 8-Bit-Schieberegister und einem Speicherregister mit dreistufigen parallelen Ausgängen. Er wandelt serielle Eingaben in parallele Ausgaben um, sodass Sie IO-Ports eines Mikrocontrollers einsparen können.
Wenn MR (Pin10) auf hohem Niveau und OE (Pin13) auf niedrigem Niveau ist, werden Daten bei steigender Flanke von SHcp eingegeben und gelangen durch die steigende Flanke von SHcp ins Speicherregister. Wenn die beiden Uhren miteinander verbunden sind, ist das Schieberegister immer einen Impuls früher als das Speicherregister. Im Speicherregister gibt es einen seriellen Schiebeeingangspin (Ds), einen seriellen Ausgangspin (Q) und einen asynchronen Reset-Knopf (niedriges Niveau). Das Speicherregister gibt einen Bus mit parallelen 8-Bit in drei Zuständen aus. Wenn OE aktiviert ist (niedriges Niveau), werden die Daten im Speicherregister auf den Bus ausgegeben.

* |link_74hc595_datasheet|

.. image:: img/74hc595_pin.png
    :width: 600

Pins des 74HC595 und ihre Funktionen:

* **Q0-Q7**: 8-Bit parallele Datenausgangspins, können direkt 8 LEDs oder 8 Pins einer 7-Segment-Anzeige steuern.
* **Q7’**: Serieller Ausgangspin, verbunden mit DS eines anderen 74HC595, um mehrere 74HC595 in Serie zu schalten
* **MR**: Reset-Pin, aktiv bei niedrigem Pegel;
* **SHcp**: Zeitsequenzeingang des Schieberegisters. Bei steigender Flanke bewegen sich die Daten im Schieberegister sukzessive um ein Bit, d.h. Daten in Q1 bewegen sich nach Q2 usw. Während bei fallender Flanke die Daten im Schieberegister unverändert bleiben.
* **STcp**: Zeitsequenzeingang des Speicherregisters. Bei steigender Flanke bewegen sich die Daten im Schieberegister in das Speicherregister.
* **CE**: Ausgangsaktivierungspin, aktiv bei niedrigem Pegel.
* **DS**: Serieller Dateneingangspin
* **VCC**: Positive Versorgungsspannung.
* **GND**: Masse.

**Beispiel**

* :ref:`basic_74hc595` (Grundprojekt)
* :ref:`fun_digital_dice` (Spaßprojekt)

