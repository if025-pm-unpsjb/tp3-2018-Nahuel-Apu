/*============================================================================
 * Autor: Nahuel Alamo
 * Licencia:
 * Fecha:17/11/2018
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

    /* Configurar PWM */
    pwmConfig( 0, PWM_ENABLE );
    pwmConfig(PWM7, PWM_ENABLE_OUTPUT); 
        
    uint8_t x = 0; 
    bool_t up = true;
         
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
                
     if (x < 255 && up == true){
            x = x + 15;
            pwmWrite(PWM7, x);
        }
        else if (x == 255 && up == true){
            pwmWrite(PWM7, x);
            gpioWrite(LEDB,ON);
            up = false;
        }
        else if (x > 0 && up == false){
            x = x - 15;
            pwmWrite(PWM7, x);
        }
        else{
            pwmWrite(PWM7, 0);
            gpioWrite(LEDB,OFF);
            up = true; 
        }
      
        delay( 250 );
        
   }
   
   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
