# Zumo_QM_QPnano
This is a project to /learn/find out, how to program the Pololu Zumo with the QM/QPnano framework. It's an project for me in every way. That's the reason, why I put everything, that I think and try, into the respository. I will sort and clean it up from time to time.  
I share everthing on GitHub for others to learn, get inspired or advice me.  
Because of the fact, that I'm still a freetime beginner in the embedded world and the C language, I have to go step by step, trying to adapt the examples from the QM/QP framework for the ATmega328P to the ATmega32U4.  
And because I'm yet not able to adapt the build and upload process within the QM/QPnano framework, I use following work around: I program in QM & generate the .ino file and then build/compile & upload it with the Arduino IDE.  
To make the interaction between QM and Arduino IDE more comfortable, check in the Preferences of the IDE "Use external editor". Than, just generate in QM and build/upload in the IDE.  
First I tried to adapt the blinky example. And because the framework needs a timer to generate a timetick, I tried to adapt timer/counter 4 for that. This timer is only used in the buzzer library of the Zumo.  
  
sources:
* I got some initial inspiration from [nagarkar](https://github.com/nagarkar/pololuzumo32u4)  
* helpfull for trying [graphs](https://rechneronline.de/funktionsgraphen/)
