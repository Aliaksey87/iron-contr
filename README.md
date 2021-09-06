# Soldering iron controller
Controller for soldering iron on arduino 328p nano.


![circuit](https://user-images.githubusercontent.com/53950388/132259680-e6848379-1e6c-4fa6-a554-8de42274198d.jpg)
![moc3063](https://user-images.githubusercontent.com/53950388/132259761-2bee01f6-f23c-4819-9ae7-e87ee9eb6365.jpg)

https://www.youtube.com/watch?v=hDxlYdVfry4&t=195s&ab_channel=%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B5%D0%B9%D0%A2%D0%B8%D1%83%D0%BD%D1%87%D0%B8%D0%BA

The video demonstrates the process of assembling a PID controller for a soldering iron.
Description of the components. And at the end of the video, an in-depth demonstration of the temperature change on the device screen.

What is a PID controller: https://ru.wikipedia.org/wiki/%D0%9F%D0%98%D0%94-%D1%80%D0%B5%D0%B3%D1%83%D0%BB%D1%8F%D1%82%D0%BE%D1%80

Implemented functions:
  - enable / disable the operation of the regulator.
  - change the control temperature.
  - change the proportional, integral and differentiating coefficients of the controller.
  - all parameters are saved in non-volatile memory and are not reset after
power on the device again.
  - if you stay for a long time in any of the menu items, the menu will return after 5 seconds to its original state.
  - LED to indicate heating of the soldering iron.
 
The link below is an archive with firmware for arduino:
  - firmware for testing a two-line display.
  - the main firmware of the PID controller.
  - electrical diagram of the entire project.
 
Link to project files:
https://1drv.ms/u/s!Ak4t8ud0Q2W6hJwTPu0SYuNhooABmA?e=aOwCLH

Easyeda triac solid state relay circuit:
https://oshwlab.com/Aliaksey.1987/moc3063
