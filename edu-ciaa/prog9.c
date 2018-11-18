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
    
    bool_t buttonValue  = OFF;
    bool_t ledBValue    = ON;
    bool_t ledRValue    = ON;
    bool_t ledGValue    = ON;
    bool_t led_ON_OFF   = ON; 
    
    gpioConfig( GPIO0, GPIO_INPUT );

    gpioConfig( GPIO1, GPIO_OUTPUT );     
             
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
       
      // ON-OFF LEDR
      buttonValue = gpioRead( TEC1 );
           
      if ( buttonValue != ledRValue ) {
            ledRValue = gpioToggle( LEDR );
      }
      
      // ON-OFF LEDG
      buttonValue = gpioRead( TEC2 );
            
      if ( buttonValue != ledGValue ) {
         ledGValue = gpioToggle( LEDG );
      }
     
      // ON-OFF LEDB
      buttonValue = gpioRead( TEC3 );
            
      if ( buttonValue != ledBValue ) {
         ledBValue = gpioToggle( LEDB );
      }
    
      // ON-OFF LEDRGB
      buttonValue = gpioRead( TEC4 );
            
      if ( buttonValue != led_ON_OFF ) {
         //Falta prender y apagar el LED
      }
      
      /* Retardo bloqueante durante 100ms */
      delay( 250 );
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
