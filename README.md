This project's ambition has grown, prompting a change in functionality to NodeMCU running on a Wemos D1 Mini.

An Arduino is still necessary because the NodeMCU environment loses PWM functionality when the PCM module is in use. An Arduino is used for this PWM functionality instead, and triggered by the NodeMCU gpio.serout() function using two pins: one increments the PWM value and the other calls analogWrite() and resets the temp value to zero.
