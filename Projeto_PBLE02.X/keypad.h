/* 
 * File:   keypad.h
 * Author: Lucas Ferreira Machado 
 *
 * Created on 10 de Julho de 2022, 20:15
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define left 1
#define up 2
#define enter 3
#define down 4
#define right 5
#define nothing 6

unsigned char kpRead(void);
void kpDebounce(void);

#endif	/* KEYPAD_H */

