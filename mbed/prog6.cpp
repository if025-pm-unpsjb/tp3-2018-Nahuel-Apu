#include "mbed.h"

PwmOut myled1(LED1);
PwmOut myled4(LED4);

/*Utilizando PwmOut , variar la intensidad del LED 1 desde apagado (0) hasta la máxima intensidad (1). La intensidad debe cambiar cada milisegundo. Configurar el LED 4
para que se prenda cuando el LED 1 llegue a su máxima intensidad, y se apague cuando la intensidad llegue nuevamente a cero.*/

int main() {
    float x = 0;
    bool up = true;
    while(1) {
        if (x < 1 && up == true){
        myled1.write (x);
        x = x + 0.1;
        wait(0.1);
        }
        else if (x >= 1 && up == true){
        myled1.write (1);
        myled4.write (1);
        up = false;
        wait(0.1);
        }
        else if (x > 0 && up == false){
        myled1.write (x);
        x = x - 0.1;
        wait(0.1);
        }
        else{
         myled1.write (0);
         myled4.write (0);
         up = true; 
         wait(0.1);  
        }
    }
}