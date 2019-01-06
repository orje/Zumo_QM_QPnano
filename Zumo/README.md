Because I'm not able to adapt the build and upload process within the QM/QPnano framework, I use the work around from [nagarkar](https://github.com/nagarkar/pololuzumo32u4). I program in QM & generate the .ino file and then build/compile & upload it with the Arduino IDE.  
To make the interaction between QM and Arduino IDE more comfortable, check in the Preferences of the IDE "Use external editor". Than, just generate in QM and build/upload in the IDE.  

First I write a program, where the Zumo drives forward and tries to avoid barriers in two steps: First reduce velocity of one motor to turn away from the barrier and second, in case the Zumo comes to a stop, only drive to the right side.
It works but not very smooth.
