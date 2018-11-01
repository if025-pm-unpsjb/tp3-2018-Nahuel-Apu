/*============================================================================
 * Autor: Nahuel Alamo
 * Licencia:
 * Fecha: 25/10/2018
 *===========================================================================*/

// DEPENDENCIAS

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
    uint8_t entrada;
   
    // ---------- CONFIGURACIONES ------------------------------
   
   // Inicializar y configurar la plataforma
   
    boardConfig();
    
    uartConfig(UART_USB,9600);
  
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
    
        entrada = 0;
                
        uartReadByte(UART_USB, &entrada);
       
        if (entrada ==  'h' ) {
            uartWriteString(UART_USB, "Hola!!!");
        }         
      
    /* Retardo bloqueante durante 100 ms*/
      delay( 1000 );
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
