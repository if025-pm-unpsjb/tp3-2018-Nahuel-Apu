/*============================================================================
 * Autor: Nahuel Alamo
 * Licencia:
 * Fecha:25/11/2018
 *===========================================================================*/

// DEPENDENCIAS

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI
#include <stdlib.h>

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   gpioConfig( GPIO1, GPIO_OUTPUT );
   
   uartConfig(UART_USB, 9600); 
   int32_t espera = 1000; 
   int8_t numero = 0;
   int8_t valorLED1 = 0;
   int8_t valorLED2 = 0;
   int8_t valorLED3 = 0;
   int8_t valorLEDB = 0;
  
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
           
      valorLEDB = numero & 0x0001; 
      valorLED1 = (numero >> 1) & 0x0001;
      valorLED2 = (numero >> 2) & 0x0001;
      valorLED3 = (numero >> 3) & 0x0001;
      
      gpioWrite( LED1, valorLED1 );
      gpioWrite( LED2, valorLED2 );
      gpioWrite( LED3, valorLED3 );
      gpioWrite( LEDB, valorLEDB ); 
       
      /* Retardo bloqueante durante 100ms */
      delay( espera);
       
      numero++;
     
      if (numero > 15){
        numero = 0;
      } 

   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
