.. _cpn_realy:

Relais
==========================================

.. image:: img/relay_pic.png
    :width: 200
    :align: center

Wie wir vielleicht wissen, ist ein Relais ein Gerät, das dazu dient, eine Verbindung zwischen zwei oder mehr Punkten oder Geräten als Reaktion auf das angelegte Eingangssignal herzustellen. Mit anderen Worten, Relais bieten eine Isolierung zwischen dem Controller und dem Gerät, da Geräte sowohl mit Wechselstrom als auch mit Gleichstrom betrieben werden können. Sie erhalten jedoch Signale von einem Mikrocontroller, der mit Gleichstrom arbeitet, und benötigen daher ein Relais, um die Lücke zu überbrücken. Relais sind äußerst nützlich, wenn Sie eine große Menge an Strom oder Spannung mit einem kleinen elektrischen Signal steuern müssen.

Es gibt 5 Teile in jedem Relais:

.. image:: img/relay142.jpeg

**Electromagnet** - Er besteht aus einem Eisenkern, der von Spulen umwickelt ist. Wenn Strom hindurchfließt, wird er magnetisch. Daher wird er Elektromagnet genannt.

**Armature** - Der bewegliche magnetische Streifen wird als Anker bezeichnet. Wenn Strom durch ihn fließt, wird die Spule energisiert und erzeugt ein Magnetfeld, das verwendet wird, um die normalerweise offenen (N/O) oder normalerweise geschlossenen (N/C) Kontakte herzustellen oder zu unterbrechen. Und der Anker kann mit Gleichstrom (DC) sowie Wechselstrom (AC) bewegt werden.

**Spring** - Wenn kein Strom durch die Spule am Elektromagneten fließt, zieht die Feder den Anker weg, sodass der Stromkreis nicht geschlossen werden kann.

Satz elektrischer **contacts** - Es gibt zwei Kontaktstellen:

-  Normalerweise offen - verbunden, wenn das Relais aktiviert ist, und getrennt, wenn es inaktiv ist.

-  Normalerweise geschlossen - nicht verbunden, wenn das Relais aktiviert ist, und verbunden, wenn es inaktiv ist.

**Molded frame** - Relais sind zum Schutz mit Kunststoff überzogen.

Das Funktionsprinzip eines Relais ist einfach. Wenn Strom an das Relais geliefert wird, beginnt der Strom durch die Steuerspule zu fließen; als Ergebnis beginnt der Elektromagnet sich zu aktivieren. Dann wird der Anker zur Spule gezogen und zieht den beweglichen Kontakt nach unten, wodurch er sich mit den normalerweise offenen Kontakten verbindet. So wird der Stromkreis mit der Last aktiviert. Das Unterbrechen des Stromkreises wäre ein ähnlicher Fall, da der bewegliche Kontakt unter der Kraft der Feder zu den normalerweise geschlossenen Kontakten gezogen wird. Auf diese Weise kann das Ein- und Ausschalten des Relais den Zustand eines Lastkreises steuern.

**Beispiel**

* :ref:`basic_relay` (Grundprojekt)
