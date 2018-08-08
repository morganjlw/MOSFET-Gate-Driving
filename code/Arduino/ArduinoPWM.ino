/*

  Adaptation sketch of "Secrets of Arduino PWM" by Ken Shirriff with edits by Paul Badger can be found at:
  (https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)
  
  Sketch created MW (07/27/2018) 
  
  Compatible with ATmega168 and ATmega 328 and 328p (UNO) architectures.
  
  Simple PWM sketch to produce 5V PWM output with variable frequency with a fixed duty cycle of 50% for pins 3 and 11.  
  
  *Base frequency for pins 3, 9, 10, and 11 is 31250 Hz.
  
  *Base frequency for pins 5 and 6 is 62500 Hz.
  
  Attach decoupling capacitors are outputs to reduce noise and transient artifacts. 
  Use oscilloscope to confirm PWM outputs.
*/

// Base frequency 31250 Hz. 
const int PWM3 = 3;
const int PWM9 = 9;
const int PWM10 = 10;
const int PWM11 = 11;
  
// Base frequency 62500 Hz. 
const int PWM5 = 5;
const int PWM6 = 6;

void setup() {
  
  // Set pin 3's PWM frequency to (31250/8 = 3906.25 Hz)
  setPwmFrequency(PWM3, 8);
  
  // Set pin 10's PWM frequency to (31250/1024 = 30.517 Hz)
  setPwmFrequency(PWM10, 1024);

  // Set pin 5's PWM frequency to (62500/1 = 62500 Hz)
  setPwmFrequency(PWM5, 1);
  
  // Set pin 6's PWM frequency to (62500/64 = 976.56 Hz)
  setPwmFrequency(PWM6, 64);
  
}

// Available divisors: 1, 8, 64, 256, 1024 
void setPwmFrequency(int pin, int divider) {
  byte mode;
  if(pin == 3 ||pin == 5 || pin == 6 || pin == 9 || pin == 10 || pin == 11) {
    switch(divider) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
  }
}

void loop() { 
  analogWrite(PWM3, 128);
  analogWrite(PWM10, 128);
  analogWrite(PWM5, 128);
  analogWrite(PWM6, 128);
}
