/* 
 * File:   main.c
 * Author: Lucas Ferreira Machado 
 *
 * Created on 17 de Abril de 2022, 18:33
 */

#include <stdio.h>
#include <stdlib.h>
#include "mcc_generated_files/mcc.h"

void main(void) 
{   
    SYSTEM_Initialize();
    MSdelay(10);  // delay para garantir que a memória foi inicializada
    varInit();
    
    for(;;)
    {
            
        kpDebounce();
       
        MSdelay(2);
      
        fsmLoop();
        
        MSdelay(500);
             
    }
 
}




