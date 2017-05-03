# Ocean Spray Berry Counter
## Purpose
Up till now ocean spray scientists were hand counting cranberry crops to determine crop yield per cubic foot.  We were asked to come up with a device to speed up the counting of cranberries to quicken this task.
## Solutions
The basic premise of the device was to funnel berries into a pipe. In the pipe, the berries would fall past a sensor that would then count them.  Two sensors were selected for initial testing, a break-beam sensor and a sonic distance sensor.  An Arduino micro was used as the microcontroller for this project due to its ample processor speed, and large community base for trouble shooting and future revisions.

The break-beam sensor would detect berries as they fell past, allowing a microcontroller to keep count.  

The distance sensor would track distance tot he side of the pipe, as berries fell past the sensor would detect them as they went past  (See attached diagrams).
## Solution Chosen
The solution chosen was the distance sensor.  This solution was chosen based on the theory that it would be able to better detect if multiple berries go past, increasing accuracy.  After testing an Accuracy of 94% to 98%

## Technical Explanation
1. The VL6180x: https://www.sparkfun.com/products/12785 , please note this is different from the breakout version of the VL6180x. This version has a built in voltage regulator, therefore we could use 5V output from Arduino to directly connect to VCC on VL6180x; without that, we have to produce a 2.8V output for VCC
2. VL6180x contains both a ambient light sensor (ALS) and range sensor, we are only using the range sensor for counting.
3. Our program will run VL6180x in continuous mode. The minimum ranging interval we're able to set is 10ms. Therefore, the range sensor will do one range count every 10ms, and update the interrupt.
4. Due to the limit in range sensor's refreshing rate, we recommend to reduce the speed of the cranberries running in the pipe.  Multiple experiments have shown that the slower they went through the pipe, the more accurate the counting is.
5. Because printing the count every loop throught the UART (USB) is very slow and could result in delays in the counting process, we use a external push button to trigger the display. Therefore, when the push button is pressed, the current count will be printed to the screen. In the program we enabled the D12 with a built in pull-up resistor.

## Materials List
* SparkFun_VL6180X
* Arduino nano
* 1-1/4" PVC pipe
* USB Mini-B Cable
* one external push-button connected to D12 input on Arduino, as a button to display current count

## Assembly 
1. Arduino: A4 - VL6180x: SDA
2. Arduino: A5 - VL6180x: SCL
3. Arduino: 5V - VL6180x: VCC
4. Arduino: GND - VL6180x: GND
5. Arduino: D12 - push button pin 1
6. Arduino: GND - push button pin 2

## Software installation and programming on microcontroller
For installing the counting Software on the Arduino, you will need the Arduino IDE which can be found here: [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software). Download and extract the zip of this repository to your chosen location.  Then using the Arduino IDE open the "sketch" program (the .ino file).
1. Go to 'Tools' --> Board and select 'Arduino Nano'
2. Go to 'Tools' --> Port and select the port that your board is on (usually not COM 1)
3. Go to 'Sketch' --> Upload or press "Ctrl + U"

The board should now be programmed.

## Setup and Usage Instructions
The Board requires USB power, and will display the count over a serial connection with a PC.
Download a serial communication program like [Putty](http://www.putty.org/).  Open your program and set the port to the COM port of your device.  Then set the baud rate for the port to 2000000.  When the board first powers up, it takes some calibration measurements, and will display the calibration measurement.  If the calibration measurement does not display, the board is already done calibrating and is ready to count.  Load berries making sure to poru slowly as not to jam the funnel.  When done loading berries a final count will be displayed in your serial communication program.  To reset the count, simply unplug the device and plug it in again, or push the small red button located on the Arduino board.

## Comments on solution and suggestions for future revisions
