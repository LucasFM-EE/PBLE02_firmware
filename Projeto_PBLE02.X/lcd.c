#include "lcd.h"
#include "mcc_generated_files/pin_manager.h"

#define dados LATC

#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define BitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define BitTst(arg,bit) ((arg) & (1<<bit)) 

void pulseEnablePin(void)
{
    EN_SetHigh();                           
	EN_SetLow();
}

void pushNibble(int value, int rs) 
{
    if (BitTst(value, 4)) DB4 = 1;
    else DB4 = 0;
    if (BitTst(value, 5)) DB5 = 1;
    else DB5 = 0;
    if (BitTst(value, 6)) DB6 = 1;
    else DB6 = 0;
    if (BitTst(value, 7)) DB7 = 1;
    else DB7 = 0;
    
    if (rs) RS_SetHigh();
    else RS_SetLow();
    pulseEnablePin();
}

void pushByte(int value, int rs) 
{
    int val_lower = (value << 4) &0xf0;
    int val_upper = value & 0xF0;
    pushNibble(val_upper, rs);
    pushNibble(val_lower, rs);
}

void LCD_Init() {
    
    EN_SetDigitalOutput();
    RS_SetDigitalOutput();
    DB4_SetDigitalOutput();
    DB5_SetDigitalOutput();
    DB6_SetDigitalOutput();
    DB7_SetDigitalOutput();
    RW_SetLow();

    MSdelay(15); 

    
    lcdCommand(0x03);
    MSdelay(1);
    lcdCommand(0x03);
    MSdelay(1); 
    lcdCommand(0x03);
    MSdelay(5);

    lcdCommand(0x02);
    MSdelay(1);

    //configura o display
    lcdCommand(0x28); //4bits, 2 linhas, 5x8
    lcdCommand(0x06); //modo incremental
    lcdCommand(0x0c); //display e cursor on, com blink
    lcdCommand(0x03); //zera tudo
    lcdCommand(0x80); //posição inicial
    lcdCommand(0x01); //limpar display
}


void lcdCommand(int value)
{ 
    pushByte(value, 0);
    MSdelay(1);
    if (value == 0x01){
        MSdelay(2);
    }	
}

void LCD_Char(unsigned char value)
{
	pushByte(value, 1);
    MSdelay(1);	
}


void lcdInt(unsigned short val)   //máx: 5 digitos
{
    if (val < 0) {
        val = val * (-1);
        LCD_Char('-');
    }
    LCD_Char((val / 10000) % 10 + 48);
    LCD_Char((val / 1000) % 10 + 48);
    LCD_Char((val / 100) % 10 + 48);
    LCD_Char((val / 10) % 10 + 48);
    LCD_Char((val / 1) % 10 + 48);

}


void LCD_String(const char *msg)
{
	while((*msg)!=0)
	{		
	  LCD_Char(*msg);
	  msg++;	
    }
}

void LCD_String_xy(char row,char pos,const char *msg)
{
    char location=0;
    if(row<=1)
    {
        location=(0x80) | ((pos) & 0x0f);      //Imprimir mensagem na 1ª linha e local desejado
        lcdCommand(location);
    }
    else
    {
        location=(0xC0) | ((pos) & 0x0f);      //Imprimir mensagem na 2ª linha e local desejado
        lcdCommand(location);    
    }  
    

    LCD_String(msg);

}
void LCD_Clear()
{
   	lcdCommand(0x01);              //Comando para limpar tela
}

void MSdelay(unsigned int val)     //Função para gerar atraso 
{
 unsigned int i,j;
 for(i=0;i<=val;i++)
     for(j=0;j<81;j++);             
 }

