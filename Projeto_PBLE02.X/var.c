#include "var.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/i2c1.h"
#include "lcd.h"

//variáveis a serem armazenadas
static char state;
static char language;
static unsigned short time;              
static unsigned short alarmLowLevel_0;         
static unsigned short alarmHighLevel_0;        
static unsigned short alarmLowLevel_1;        
static unsigned short alarmHighLevel_1; 
static int sensorValue;

void varInit(void) {
    
    state = 0;
    setLanguage(getLanguage());
    setTime(getTime());
    setAlarmHighLevel_0(getAlarmHighLevel_0());
    setAlarmLowLevel_0(getAlarmLowLevel_0());
    setAlarmHighLevel_1(getAlarmHighLevel_1());
    setAlarmLowLevel_1(getAlarmLowLevel_1());
}


char getState(void) {
    return state;
}


void setState(char newState) {
    state = newState;
}


unsigned short getTime(void) {
    MCHP24LC512_Read(0x51,&time,2);
    
    if(time > 10000)
        return 500;
    else if(time > 800)
        return 800;
    else if(time < 300)
        return 300;
    else
        return time;      
}


void setTime(unsigned short newTime) {
    
    time = newTime;
    writeMem (0x51, &time, 2);
    MSdelay(10);
    
}


unsigned short getAlarmLowLevel_0(void) {
    
    MCHP24LC512_Read(0x58,&alarmLowLevel_0,2);
    
    if(alarmLowLevel_0 > 750)
        return 250;
    else if (alarmLowLevel_0 > 500) 
        return 500;
    else if (alarmLowLevel_0 < 1)
        return 1;
    else 
        return alarmLowLevel_0; 
}


void setAlarmLowLevel_0(unsigned short newAlarmLevel) {
    
    alarmLowLevel_0 = newAlarmLevel;
    writeMem (0x58, &alarmLowLevel_0, 2);
    MSdelay(10);
    
}

unsigned short getAlarmHighLevel_0(void) {
    
    MCHP24LC512_Read(0x7A,&alarmHighLevel_0,2);
    MSdelay(10);
    
    if(alarmHighLevel_0 > 3000)
        return 750;  
    else if (alarmHighLevel_0 > 1000)
        return 1000;
    else if (alarmHighLevel_0 < 500)
        return 500;
    else
        return alarmHighLevel_0;
           
}


void setAlarmHighLevel_0(unsigned short newAlarmLevel) {
    
    alarmHighLevel_0 = newAlarmLevel;
    writeMem (0x7A, &alarmHighLevel_0, 2);
    MSdelay(10);
   
}


unsigned short getAlarmLowLevel_1(void) {
    
    MCHP24LC512_Read(0x7D,&alarmLowLevel_1,2);
    
    if(alarmLowLevel_1 > 3000)
        return 2500;
    else if (alarmLowLevel_1 > 2750) 
        return 2750;
    else if (alarmLowLevel_1 < 2250)
        return 2250;
    else 
        return alarmLowLevel_1; 
}


void setAlarmLowLevel_1(unsigned short newAlarmLevel) {
    
    alarmLowLevel_1 = newAlarmLevel;
    writeMem (0x7D, &alarmLowLevel_1, 2);
    MSdelay(10);
    
}

unsigned short getAlarmHighLevel_1(void) {
    
    MCHP24LC512_Read(0x8B,&alarmHighLevel_1,2);
    MSdelay(10);
    
    if(alarmHighLevel_1 > 5000)
        return 3000;  
    else if (alarmHighLevel_1 > 3250)
        return 3250;
    else if (alarmHighLevel_1 < 2750)
        return 2750;
    else
        return alarmHighLevel_1;
           
}


void setAlarmHighLevel_1(unsigned short newAlarmLevel) {
    
    alarmHighLevel_1 = newAlarmLevel;
    writeMem (0x8B, &alarmHighLevel_1, 2);
    MSdelay(10);
   
}

unsigned short getSensorValue(){
    return ADCRead(channel_pot);
}


char getLanguage(void){
    MCHP24LC512_Read(MHCP24LC512_ADDRESS,&language,2);
    if(language == 0 || language == 1)
        return language;
    else 
        setLanguage(0);
    
    return language;
}


void setLanguage(char newLanguage){
    //só tem 2 linguas
    //resto de divisão: para evitar colocar valor errado
    language = newLanguage%2;
    writeMem (MHCP24LC512_ADDRESS, &language, 1);
}