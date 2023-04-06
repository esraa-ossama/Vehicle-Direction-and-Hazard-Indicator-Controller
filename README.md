# Vehicle-Direction-and-Hazard-Indicator-Controller 🚗
- [Description](#Description)
- [Schematic](#Schematic)
  - [Main Component](#Main-Component)
- [System Architecture](#System-Architecture)
  - [Finite State Machine](#Finite-State-Machine)
- [IDE](#IDE)
- [Demo](#Demo)
  - [Waiting](#Waiting)
  - [Right & Left Sign](#Right-&-Left-Sign)
 

  
  
  ## Description
  <p>- Here Simulate Vehicle Direction sign as when driver want turn right press on Right indicator and can give left indicator and can give wait sign </p>
  <p>- This System work in AVR atmega32 and use FreeRTOS and Apply Finite State machine and Periodic Polling </p>
  <p>- Polling has High priority  as every specific time check pressed button and store in state and then state machine called and handle state and control led intensity using PWM </p>
  <p>- Picture To system</p>
  <p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/pic/real_task_in_car.png">
</p>

  ## Schematic
  <p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/pic/schema.png">
</p>

  ### Main Component
  - Atmega 32
  - led
  - switch
  - SW-ROT-3

  ## System Architecture
  <p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/pic/system_Architecture.png">
</p>

  ### Finite State Machine
  <p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/pic/FSM.png">
</p>

## IDE
 <p>IDE are Eclipse (Atmel studio to upload code to MCU) & Proteus</p>
 
 
## Demo 

### Waiting 
<p> - Waiting indicator make Right and Left Led high for 500ms and low for 500ms and during 500ms High led on with specific intensity that was setten  in fast PWM </p>
<p> - Waiting work If engine power on/off</p>
<p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/GIF/press%20waiting%20button%20during%20Engine%20is%20off.gif">
  </p>

### Right & Left Sign
<p> - When press on Right indicator button car will blink right led during Engine On If Engine turned Off will stop blinking and when Turn on again will start blinking again as long as still giving rigth sign </p>
<p> - same thing for left indicator </p>
<p align="center">
  <img src="https://github.com/HESHAM47GAMAL/Vehicle-Direction-and-Hazard-Indicator-Controller/blob/main/GIF/test_right_left_indicator.gif">
</p>
  
  
  
# Vehicle-Direction-and-Hazard-Indicator-Controller
