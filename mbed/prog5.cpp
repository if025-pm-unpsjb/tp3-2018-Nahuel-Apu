#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
Serial pc (USBTX, USBRX);

/*Hacer parpadear un LED, indicado por el usuario, con un intervalo de 250 ms. 
El LED se indica mediante un número (1 a 4) leído desde la entrada serial.*/

int main() {
    while(1) {
        char  c = pc. getc ();
        pc.printf("Tecla %c\n\r", c);
              
      switch (c){
        case '1':
            myled1 = 1;
            wait (0.25);
            myled1 = 0;
            break;
        case '2':
            myled2 = 1;
            wait (0.25);
            myled2 = 0;
            break;
        case '3':
            myled3 = 1;
            wait (0.25);
            myled3 = 0;
            break;
        case '4':
            myled4 = 1;
            wait (0.25);
            myled4 = 0;
            break;
          }
    }
}
