.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

Overview
---------------

In this lesson, you will learn about OLED Displays using the SSD1306 driver. OLED (Organic Light-Emitting Diodes) displays are widely used in various electronic devices such as smartwatches, mobile phones, and even televisions. The SSD1306 is a single-chip CMOS OLED/PLED driver with controller for organic/polymer light emitting diode dot-matrix graphic display system. It offers a crisp and clear visual output through the means of organic material-based diodes that emit light when an electric current passes through them.

In the code provided, an OLED display is interfaced with an Arduino board via the I2C protocol. The code uses the Adafruit SSD1306 library to control the display. The program covers various functionalities such as:

1. Displaying text: "Hello world!" is printed on the screen.
2. Inverted text: The text "Hello world!" is displayed in an inverted color scheme.
3. Font Size: The text "Hello!" is displayed with an increased font size.
4. Numerical Display: The numbers 123456789 are displayed.
5. ASCII Characters: A set of ASCII characters are displayed.
6. Scrolling: Text is scrolled horizontally across the display.
7. Bitmap Display: A predefined bitmap image is displayed on the OLED screen.

This OLED display can be used in a multitude of applications including digital clocks, mini game consoles, information displays, and so on. It offers a great way to provide a user interface in compact and portable devices.


Required Components
-------------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

Wiring
----------------------

.. image:: img/15-oled_bb.png
    :align: center

Schematic Diagram
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

Code
---------------

.. note::

    * You can open the file ``15-oled.ino`` under the path of ``elite-explorer-kit-main\basic_project\15-oled`` directly.
    * Or copy this code into Arduino IDE.

    .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit SSD1306"** and **"Adafruit GFX"** and install it. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ec580f40-78b4-42c2-af7c-bb5bc05a7c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>


Code Analysis
------------------------

1. **Library Inclusion and Initial Definitions**:
   The necessary libraries for interfacing with the OLED are included. Following that, definitions regarding the OLED's dimensions and I2C address are provided.


   - **Adafruit SSD1306**: This library is designed to help with the interfacing of the SSD1306 OLED display. It provides methods to initialize the display, control its settings, and display content.
   - **Adafruit GFX Library**: This is a core graphics library for displaying text, producing colors, drawing shapes, etc., on various screens including OLEDs.

   .. note:: 
      To install the library, use the Arduino Library Manager and search for **"Adafruit SSD1306"** and **"Adafruit GFX"** and install it. 

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // OLED display width, in pixels
      #define SCREEN_HEIGHT 64  // OLED display height, in pixels

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Bitmap Data**:
   Bitmap data for displaying a custom icon on the OLED screen. This data represents an image in a format that the OLED can interpret.

   You can use this online tool called |link_image2cpp| that can turn your image into an array. 

   The ``PROGMEM`` keyword denotes that the array is stored in the program memory of the Arduino microcontroller. Storing data in program memory(PROGMEM) instead of RAM can be helpful for large amounts of data, which would otherwise take up too much space in RAM.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Setup Function (Initialization and Display)**:
   The ``setup()`` function initializes the OLED and displays a series of patterns, texts, and animations.

   .. code-block:: arduino

      void setup() {
         ...  // Serial initialization and OLED object initialization
         ...  // Displaying various text, numbers, and animations
      }