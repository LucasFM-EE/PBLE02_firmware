/* 
 * File:   lcd.h
 * Author: Lucas Ferreira Machado 
 *
 * Created on 12 de Junho de 2022, 15:37
 */

#ifndef LCD_H
#define	LCD_H

void MSdelay(unsigned int);                      
void LCD_Init();                                
void lcdCommand(int value );                   
void LCD_Char(unsigned char value);                        
void lcdInt(unsigned short val);                           
void LCD_String(const char *);                   
void LCD_String_xy(char, char , const char *);
void LCD_Clear();                                
void pushNibble(int value, int rs);
void pushByte(int value, int rs);


#endif	/* LCD_H */

