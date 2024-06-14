.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

LESSON 19: Mixing Colors with an RGB LED
==========================================

This lesson demonstrates how to create a user-controlled RGB LED system using the Arduino, where the user can choose different colors based on input through the serial monitor. Here’s a brief overview of what you will learn:

1. **Reviewing Previous Homework**:Recapping the assignment from Lesson 18, which involved controlling an RGB LED to produce various colors by mixing red, green, and blue lights.
2. **Setting Up the Circuit**:Detailed instructions on how to correctly connect an RGB LED and its current-limiting resistors to the Arduino. Each color channel (red, green, blue) is connected to a digital pin (pins 9, 10, and 11), and the common cathode (long leg) is connected to ground.
3. **Writing the Code**:Step-by-step coding instructions to:Define the pins for each color channel of the RGB LED.Set up the serial monitor for user input.Use analog write commands to adjust the brightness of each color channel to mix different colors.Convert user input to lowercase to handle different cases.Handle various user inputs to produce specific colors (red, green, blue, cyan, magenta, yellow, orange, white) by mixing the RGB values appropriately.
4. **Debugging Tips**:Guidance on troubleshooting common issues such as:Ensuring proper capitalization and syntax in the code.Checking for missing semicolons and incorrect curly braces.Adjusting RGB values to get the correct color output by tweaking brightness levels.
5. **Practical Applications**:Examples of mixing colors using RGB values to produce a wide range of colors. 
6. **Homework Assignment**:Flash the RGB LED in a sequence of red, green, blue, wait for a second, and repeat this sequence 25 times.Ensure the program stops after 25 cycles.Create a short video of the solution, post it on YouTube, and link back to the lesson for review.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
