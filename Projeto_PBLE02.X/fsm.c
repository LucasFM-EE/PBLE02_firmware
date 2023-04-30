#include "mcc_generated_files/mcc.h"


void fsmInit(void) {
    setState(STATE_ALARME_0);
}


void fsmLoop(void) {
    
    unsigned char evento;
    
    //máquina de estados
    evento = eventRead();
    
    switch (getState()) {
        case STATE_ALARME_0:
            //execução de atividade
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_ALTO_0);
            }
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_BAIXO_0);
            }

            //gestão da maquina de estado
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_1);
            }
            break;
            
        case STATE_ALARME_1:
            //execução de atividade
            if (evento == EV_RIGHT) {
                setState(STATE_ALARME_ALTO_1);
            }
            if (evento == EV_LEFT) {
                setState(STATE_ALARME_BAIXO_1);
            }

            //gestão da maquina de estado
            if (evento == EV_ENTER) {
                setState(STATE_TEMPO);
            }
            break;

        case STATE_ALARME_BAIXO_0:
            //execução de atividade
            if(evento == EV_RIGHT){
                int tmp = (getAlarmLowLevel_0() + 1);
                setAlarmLowLevel_0((tmp < 1024) ? tmp : 1024);
            }
            if(evento == EV_LEFT){
                int tmp = (getAlarmLowLevel_0() - 1);
                setAlarmLowLevel_0((tmp > 0) ? tmp : 0);
            }
            
            //gestão da maquina de estado
            if(evento == EV_ENTER){
              setState(STATE_ALARME_1);
            }
            break;

       case STATE_ALARME_ALTO_0:
            //execução de atividade
            if(evento == EV_RIGHT){
                int tmp = (getAlarmHighLevel_0() + 1);
                setAlarmHighLevel_0((tmp < 1024) ? tmp : 1024);
            }
            if(evento == EV_LEFT){
                int tmp = (getAlarmHighLevel_0() - 1);
                setAlarmHighLevel_0((tmp > 0) ? tmp : 0);
            }
            
            //gestão da maquina de estado
            if(evento == EV_ENTER){
              setState(STATE_ALARME_1);
            }
            break;
        
        case STATE_ALARME_BAIXO_1:
            //execução de atividade
            if(evento == EV_RIGHT){
                int tmp = (getAlarmLowLevel_1() + 1);
                setAlarmLowLevel_1((tmp < 2750) ? tmp : 2750);
            }
            if(evento == EV_LEFT){
                int tmp = (getAlarmLowLevel_1() - 1);
                setAlarmLowLevel_1((tmp > 2250) ? tmp : 2250);
            }
            
            //gestão da maquina de estado
            if(evento == EV_ENTER){
              setState(STATE_TEMPO);
            }
            break;

       case STATE_ALARME_ALTO_1:
            //execução de atividade
            if(evento == EV_RIGHT){
                int tmp = (getAlarmHighLevel_1() + 1);
                setAlarmHighLevel_1((tmp < 3250) ? tmp : 3250);
            }
            if(evento == EV_LEFT){
                int tmp = (getAlarmHighLevel_1() - 1);
                setAlarmHighLevel_1((tmp > 2750) ? tmp : 2750);
            }
            
            //gestão da maquina de estado
            if(evento == EV_ENTER){
              setState(STATE_TEMPO);
            }
            break;
                
        case STATE_TEMPO:
            //execução de atividade
            if (evento == EV_RIGHT) {
                setTime(getTime() + 1);
            }
            if (evento == EV_LEFT) {
                int tmp = (getTime() - 1);
                setTime((tmp > 0) ? tmp : 0);
            }

            //gestão da maquina de estado
            if (evento == EV_ENTER) {
                setState(STATE_IDIOMA);
            }
            break;

        case STATE_IDIOMA:
            //execução de atividade
            if (evento == EV_RIGHT) {
                setLanguage(getLanguage() + 1);
            }
            if (evento == EV_LEFT) {
                setLanguage(getLanguage() - 1);
            }

            //gestão da maquina de estado
            if (evento == EV_ENTER) {
                setState(STATE_ALARME_0);
            }
            break;
    }
    outputPrint(getState(), getLanguage());
}

