.. _basic_7segment:

7-segment Display
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/7_segment_display_uno.html#segmeng-uno


Overview
-------------------

A 7-segment display is a device that can display numerals and letters. It's made up of seven LEDs connected in parallel. Different letters/numbers can be shown by connecting pins on the display to the power source and enabling the related pins, thus turning on the corresponding LED segments. In this lesson let's learn how to display specific characters on it.

Required Components
------------------------

* :ref:`uno_r4_wifi`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_7segment`

Wiring
----------------------

.. image:: img/13-7_segment_display_bb.png
    :align: center
    :width: 80%


Schematic Diagram
------------------------

In this experiment, connect each of pin a-g of the 7-Segment Display to one 220ohm current limiting resistor respectively and then to pin 4-11. GND connects to GND. By programming, we can set one or several of pin4-11 as High level to light up the corresponding LED(s).

.. image:: img/13-7_segment_display_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * You can open the file ``13-7_segment.ino`` under the path of ``Elite-Explorer-Kit-main\basic_project\13-7_segment`` directly.
    * Or copy this code into Arduino IDE.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce9857dc-6285-45cd-9918-e35b0b135836/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Code Analysis
----------------------

The code may be a little long for this experiment. But the syntax is simple. Let's take a look.

**Call the function in loop()**

.. code-block:: arduino

   digital_1(); //diaplay 1 to the 7-segment

   delay(1000); //wait for a second

   digital_2(); //diaplay 2 to the 7-segment

   delay(1000); //wait for a second

   digital_3(); //diaplay 3 to the 7-segment

   delay(1000); //wait for a second

   digital_4(); //diaplay 4 to the 7-segment


Calling these functions into the loop() is to let the 7-Segment display 0-F. The functions are shown below. Take ``digital_2()`` for example:

**Detailed analysis of digital_2()**

.. code-block:: arduino

   void digital_2()  //diaplay 2 to the 7-segment
   {
     turnOffAllSegments();
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(g, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(d, HIGH);
   }

.. image:: img/13_7segment.jpeg
   :align: center

First, we need to understand how the numeral **2** appears on the 7-Segment display. It is achieved by powering on segments a, b, d, e, and g. In programming, pins connected to these segments are set to a High level while c and f are set to Low level. We start by using the function ``turnOffAllSegments()`` to turn off all segments and then light up the required ones.

After running this part, the 7-segment will display **2**. Similarly, the display of other characters are the same. Since the letters b and d in upper case, namely **B** and **D**, would look the same with **8** and **0** on the display, they are displayed in lower case instead.