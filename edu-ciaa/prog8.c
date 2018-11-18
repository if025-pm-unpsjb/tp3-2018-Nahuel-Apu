/*============================================================================
 * Autor: Nahuel Alamo
 * Licencia:
 * Fecha: 18/11/2018
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
    
    bool_t buttonValue = OFF;
    bool_t ledBValue    = ON;
    bool_t led1Value    = ON;
    bool_t led2Value    = ON;
    bool_t led3Value    = ON; 
    
    gpioConfig( GPIO0, GPIO_INPUT );

    gpioConfig( GPIO1, GPIO_OUTPUT );
             
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
       
      // ON-OFF LEDB
      buttonValue = gpioRead( TEC1 );
           
      if ( buttonValue != ledBValue ) {
            ledBValue = gpioToggle( LEDB );
      }
      
      // ON-OFF LED1
      buttonValue = gpioRead( TEC2 );
            
      if ( buttonValue != led1Value ) {
         led1Value = gpioToggle( LED1 );
      }
     
      // ON-OFF LED2
      buttonValue = gpioRead( TEC3 );
            
      if ( buttonValue != led2Value ) {
         led2Value = gpioToggle( LED2 );
      }
      
      // ON-OFF LED3
      buttonValue = gpioRead( TEC4 );
            
      if ( buttonValue != led3Value ) {
         led3Value = gpioToggle( LED3 );
      }
            
    delay( 250 );
                  
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
