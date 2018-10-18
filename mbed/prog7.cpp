#include "mbed.h"

BusOut Bits(LED1,LED2,LED3,LED4); 
Serial pc (USBTX, USBRX);

/*Implementar un contador binario de 0 a 15, utilizando los cuatro LEDs de la
placa. El intervalo de incremento es leído desde la interface serial (expresado en
milisegundos). Debe ser posible cambiar el intervalo en tiempo de ejecución.*/

int num = 1000;
char bin_val = 0x00;

void callback() {
    pc.scanf("%d", &num);
    pc.printf("%d\n", num);
}


int main() {       
    
    pc.baud (9600);
    pc.attach(&callback);
    
    while(1){
                
        bin_val++;
        if(bin_val > 0x0F){
            bin_val = 0;
        }
        
        Bits = bin_val;
        wait_ms(num);
        
        }
}