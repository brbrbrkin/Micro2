#include <mbed.h>

PwmOut LEDpwm(LED1);

Serial pc(USBTX, USBRX, 9600);

char charinput = '/';
float intensity;

void input(){
  charinput = pc.getc();
}

int main(){
    pc.attach(&input);

    while (1){
        
            if(charinput == '+')
            	if (intensity < 1.0) intensity += 0.05;
            
            else if(charinput == '-')
            	if (intensity > 0.0) intensity -= 0.05;
  
            else if(charinput == '*')
                intensity = 1.0;
            
            else if(charinput == '/')
                intensity = 0.0;
            
            else pc.printf("Invalido\n");
        
         led.write(intensity)
        wait_ms(500);
    }
}
