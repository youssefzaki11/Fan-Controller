Description:
This is an Embedded Systems Project. I implemented a Fan Controller System which is used for changing speed according to changing in temperature. 
I used multiple drivers: GPIO, ADC, PWM, DC Motor, LM35 Temperature Sensor, LCD. 

if Temperature less than 30C, Fan Stops.
else if Temperature greater than or equal 30C and less than 60C, Fan operates with 25% of its maximum speed 
else if Temperature greater than or equal 60C and less than 90C, Fan operates with 50% of its maximum speed 
else if Temperature greater than or equal 90C and less than 120C, Fan operates with 75% of its maximum speed 
else if Temperature greater than or equal 120C, Fan operates with 100% of its maximum speed 

Fan state is displayed on LCD. 
Temperature is displayed on LCD. 
