.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

LESSON 21: Understanding While Loops
======================================
This lesson demonstrates how to use while loops in Arduino to create a user-controlled RGB LED blinking system based on input through the serial monitor. Here’s a brief overview of what you will learn:

1. **Reviewing Previous Homework**: Recapping the assignment from Lesson 20, which involved blinking an RGB LED in a red-green-blue sequence a user-specified number of times using a while loop instead of a for loop.
2. **Setting Up the Circuit**: Detailed instructions on how to correctly connect an RGB LED and its current-limiting resistors to the Arduino. Each color channel (red, green, blue) is connected to a PWM digital pin (pins 9, 10, and 11), and the common cathode (long leg) is connected to ground.
3. **Writing the Code**: Step-by-step coding instructions to:Define the pins for each color channel of the RGB LED.Set up the serial monitor for user input.Use digital write commands to control the on/off state of each color channel.Implement a while loop to control the number of blink cycles based on user input.Ensure the program stops after the specified number of blinks.
4. **Debugging Tips**: Guidance on troubleshooting common issues such as:Correcting syntax errors in the code.Ensuring the program loops the correct number of times.Handling user input correctly and stopping the program after the specified cycles.Initializing and incrementing loop counters properly.
5. **Practical Applications**: Examples of using while loops to repeat a sequence of actions a specified number of times. The lesson emphasizes the importance of getting user input to control the behavior of the program and ensuring the loop counter is correctly managed.
6. **Testing and Debugging**: Emphasis on thoroughly testing code under various conditions to ensure reliability. 
7. **Homework Assignment**: Repeating the blink sequence a user-specified number of times without using a for loop.Ensure the program stops after the specified number of blinks.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/Cw_i7l_RFVE?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
