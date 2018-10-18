# Zumo_QM_QPnano
This is a project to /learn/find out, how to program the Pololu Zumo with the QM/QPnano framework. It's an project for me in every way. That's the reason, why I put everything, that I think and try, into the respository.  
I share everthing on GitHub for others to learn, get inspired or advice me.  
Because of the fact, that I'm still a freetime beginner in the embedded world and the C language, I have to go step by step, trying to adapt the examples of the QM/QP framework for the ATmega328P to the ATmega32U4.  
And because I'm yet not able to adapt the build and upload process within the QM/QPnano framework, I use following workaround: I program in QM & build the .ino file and then compile & load it with the Arduino IDE.  
First I tried to adapt the blinky example. And because the framework needs a timer to generate a timetick, I tried to adapt timer/counter 4 for that. This timer is only used in the buzzer library of the Zumo. I think, I got it, eventhough the same code did not work right away. But finally it does. So, try it!  
  
sources:  
I got some initial inspiration from [nagarkar](https://github.com/nagarkar/pololuzumo32u4)