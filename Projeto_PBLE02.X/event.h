/* 
 * File:   event.h
 * Author: Lucas Ferreira Machado 
 *
 * Created on July 11, 2022, 5:21 PM
 */

#ifndef EVENT_H
#define	EVENT_H

#define EV_NOEVENT 0
#define EV_RIGHT 1
#define EV_LEFT 2
#define EV_ENTER 3

unsigned int eventRead(void); 
void eventInit(void); 

#endif	/* EVENT_H */

