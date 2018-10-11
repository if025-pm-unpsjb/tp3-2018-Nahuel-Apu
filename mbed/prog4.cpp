#include "mbed.h"

DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
Serial pc (USBTX, USBRX);

/*Leer un carácter desde la entrada serial. Si es la letra “h”, enviar un saludo
(“¡hola!”) a través de la salida serial*/

int main() {
    while(1) {
        char  c = pc. getc ();
        if (c ==  'h' ) {
            pc.printf("hola!\n\r");
        }
    }
}
