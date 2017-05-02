# Ocean Spray Berry Counter
## Purpose
Up till now ocean spray scientists were hand counting cranberry crops to determine crop yield per cubic foot.  We were asked to come up with a device to speed up the counting of cranberries to quicken this task.
## Solutions
The basic premise of the device was to funnel berries into a pipe. In the pipe, the berries would fall past a sensor that would then count them.  Two sensors were selected for initial testing, a break-beam sensor and a sonic distance sensor.  An Arduino micro was used as the microcontroller for this project due to its ample processor speed, and large community base for trouble shooting and future revisions.

The break-beam sensor would detect berries as they fell past, allowing a microcontroller to keep count.  

The distance sensor would track distance tot he side of the pipe, as berries fell past the sensor would detect them as they went past  (See attached diagrams).
## Solution Chosen
The solution chosen was the distance sensor.  This solution was chosen based on the theory that it would be able to better detect if multiple berries go past, increasing accuracy.  After testing an Accuracy of 94% to 98%

## Materials List
* SparkFun_VL6180X
* Arduino micro
* 1-1/4" PVC pipe
* USB Mini-B Cable

## Assembly 

## Software installation and programming on microcontroller
For installing the counting Software on the Arduino, you will need the Arduino IDE which can be found here: [https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software). Download and extract the zip of this repository to your chosen location.  Then using the Arduino IDE open the "sketch" program (the .ino file).
1. Go to 'Tools' --> Board and select 'Arduino Nano'
2. Go to 'Tools' --> Port and select the port that your board is on (usually not COM 1)
3. Go to 'Sketch' --> Upload or press "Ctrl + U"

The board should now be programmed.

## Setup and Usage Instructions
The Board requires USB power, and will display the count over a serial connection with a PC.
Download a serial communication program like [Putty](http://www.putty.org/).  Open your program and set the port to the COM port of your device.  Then set the baud rate for the port to 115200.  When the board first powers up, it takes some calibration measurements, and will display the calibration measurement.  If the calibration measurement does not display, the board is already done calibrating and is ready to count.  Load berries making sure to poor slowly as not to jam the funnel.  When done loading berries a final count will be displayed in your serial communication program.  To reset the count, simply unplug the device and plug it in again, or push the small red button located on the Arduino board.

## Comments on solution and suggestions for future revisions
