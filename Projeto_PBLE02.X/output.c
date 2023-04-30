#include "output.h"
#include "lcd.h"
#include "var.h"

#define NUM_IDIOMAS 2

//msgs com 16 caracteres
//1 msg por estado (apenas linha de cima)
static char * msgs[STATE_FIM+3][NUM_IDIOMAS] = {
    {"Alterar alarme 0 ", "Change alarm 0  "},
    {"Alterar alarme 1 ", "Change alarm 1  "},
    {"Alterar tempo   ", "Change time      "},
    {"Alterar idioma  ", "Change language  "},
    {"Alarme Baixo 0  ", "Lo Level Alarm 0"},
    {"Alarme Alto 0   ", "Hi Level Alarm 0"},
    {"Alarme Baixo 1  ", "Lo Level Alarm 1"},
    {"Alarme Alto 1   ", "Hi Level Alarm 1"},
    {"Sensor 0: ", "Sensor 0: "},
    {"Sensor 1: ", "Sensor 1: "},
    {"Nivel <<B / A>>", "Level <<L / H>>"}
};

void outputInit(void) {
    LCD_Init();
}

void outputPrint(int numTela, int idioma) {

     if (numTela == STATE_ALARME_0) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        LCD_String(msgs[10][idioma]);
        LCD_String("           ");//para apagar os textos depois do numero
    }
     
    if (numTela == STATE_ALARME_1) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        LCD_String(msgs[10][idioma]);
        LCD_String("           ");//para apagar os textos depois do numero
    }
    
    if (numTela == STATE_TEMPO) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        lcdInt(getTime());
        LCD_String("           ");//para apagar os textos depois do numero
    }
    
    if (numTela == STATE_IDIOMA) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        if (getLanguage() == 0) {
            LCD_String("Portugues       ");
        }
        if (getLanguage() == 1) {
            LCD_String("English         ");
        }

    }
    if (numTela == STATE_ALARME_BAIXO_0) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        lcdInt(getAlarmLowLevel_0());
        LCD_String("           ");//para apagar os textos depois do numero
    }
    if (numTela == STATE_ALARME_ALTO_0) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        lcdInt(getAlarmHighLevel_0());
        LCD_String("           ");//para apagar os textos depois do numero
    }
     
    if (numTela == STATE_ALARME_BAIXO_1) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        lcdInt(getAlarmLowLevel_1());
        LCD_String("           ");//para apagar os textos depois do numero
    }
     
    if (numTela == STATE_ALARME_ALTO_1) {
        lcdCommand(0x80);
        LCD_String(msgs[numTela][idioma]);
        lcdCommand(0xC0);
        lcdInt(getAlarmHighLevel_1());
        LCD_String("           ");//para apagar os textos depois do numero
    }
    
}

