#include <LiquidCrystal.h>


/** \brief  Se invoca una sola vez cuando el programa empieza. 
 *          Se utiliza para inicializar los modos de trabajo 
 *          de los pines, el puerto serie, etc... 
 * \param void
 * \return void
 */
void setup(void)
{
  setup_reloj(); // inicializo el reloj
  lcd.begin(16, 2); // inicializo la biblioteca indicando 16 caracteres por 2 lineas
}


/** \brief  Contiene el programa que se ejecutará cíclicamente
 *          
 * \param void
 * \return void
 */
void loop(void)
{
    loop_reloj();
}
   
  
  
  