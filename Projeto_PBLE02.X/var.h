/* 
 * File:   var.h
 * Author: Lucas Ferreira Machado 
 *
 * Created on 9 de Julho de 2022, 20:37
 */

#ifndef VAR_H
#define	VAR_H

void varInit(void);

char getState(void);
void setState(char newState);

unsigned short getTime(void);
void setTime(unsigned short newTime);

unsigned short getAlarmLowLevel_0(void);
unsigned short getAlarmHighLevel_0(void);
unsigned short getAlarmLowLevel_1(void);
unsigned short getAlarmHighLevel_1(void);

void setAlarmLowLevel_0(unsigned short newAlarmLevel);
void setAlarmHighLevel_0(unsigned short newAlarmLevel);
void setAlarmLowLevel_1(unsigned short newAlarmLevel);
void setAlarmHighLevel_1(unsigned short newAlarmLevel);

unsigned short getSensorValue();

char getLanguage(void);
void setLanguage(char newLanguage);
#endif	/* VAR_H */
