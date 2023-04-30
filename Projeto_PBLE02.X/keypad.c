#include "keypad.h"
#include "mcc_generated_files/adc1.h"
#include "lcd.h"


static unsigned short valor;


unsigned char kpRead(void) {
    if(valor < 2100)
        return left;
    else if(valor < 2850)
        return up;
    else if(valor < 3150)
        return enter;
    else if(valor < 3350)
        return down;
     else if(valor < 3500)
        return right;
    else if(valor < 4500)
        return nothing;
}



void kpDebounce(void) {
    unsigned char i, j;
    static unsigned short tempo ;
    static unsigned short valorNovo = 0;
    static unsigned short valorAntigo = 0;
    
    
    tempo = 1;
    valorNovo = 0;
    valorAntigo = 0;
    
    
    while(tempo != 0)
    {   
        valorNovo = ADCRead(channel_keypad) ;
        if ( (abs(valorNovo - valorAntigo) < 50) ) 
            tempo--;
        else {
            tempo = 20; // tempo ajustado 
            valorAntigo = valorNovo;
        }
        if (tempo == 0) 
            valor = valorAntigo;       
    }
    
}
