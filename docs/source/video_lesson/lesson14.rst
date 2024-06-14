.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

LESSON 14: Read User Input From the Serial Monitor
====================================================

This lesson demonstrates how to create a user-interactive program using the Arduino, focusing on obtaining user input through the serial monitor and performing different operations based on the input. Here’s a brief overview of what you will learn:

1. **Introduction to User Input via Serial Monitor** : An introduction to the concept of reading user input from the Arduino serial monitor, which is essential for interactive projects.
2. **Setting Up Serial Communication**: Detailed instructions on setting up serial communication in the Arduino code, using Serial.begin(9600) to initialize the serial monitor.
3. **Reading Different Data Types**: Step-by-step guidance on how to read various data types from the user:Integers: Using Serial.parseInt() to read integer values.Floats: Using Serial.parseFloat() to read floating-point numbers.Strings: Using Serial.readString() to read strings.
4. **Implementing a While Loop for Waiting on User Input**: Explanation of how to implement a while loop to wait for user input, ensuring the program does not proceed until the user has entered the required data.
5. **Error Handling with Serial Input**: Tips on handling errors related to incorrect data types and ensuring the serial monitor is set to 'No line ending' to prevent additional characters from being read as input.
6. **Practical Application and Example Code**: An example project where the user is asked for a number, a float, and a string, demonstrating how to capture and use these inputs effectively. The provided code shows how to ask for input, wait for it, and then read and process the input.
7. **Homework Assignment**: creating a program that asks the user for a brightness level (between 0 and 255) for an LED and then sets the LED brightness accordingly. 


**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
