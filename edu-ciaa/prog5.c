/*============================================================================
 * Autor: Nahuel Alamo
 * Licencia : 
 * Fecha: 17/11/2018.
 *===========================================================================*/

// DEPENDENCIAS

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   uartConfig(UART_USB,9600);
   
   int8_t num; 
   bool_t ok;
      
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
     ok = uartReadByte(UART_USB, &num);
              
     switch (num) {
            case '1':
                gpioWrite(LED1, ON);
                delay (250);
                gpioWrite(LED1, OFF);
                delay (250);
                break;
            case '2':
                gpioWrite(LED2, ON);
                delay (250);
                gpioWrite(LED2, OFF);
                delay (250);
                break;
            case '3':
                gpioWrite(LED3, ON);
                delay (250);
                gpioWrite(LED3, OFF);
                delay (250);
                break;
            case '4':
                gpioWrite(LEDB, ON);
                delay (250);
                gpioWrite(LEDB, OFF);
                delay (250);
                break;
     }
         
      /* Retardo bloqueante durante 250 ms */
      delay( 250 );
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}