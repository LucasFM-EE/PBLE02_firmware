/* 
 * File:   output.h
 * Author: Lucas Ferreira Machado 
 *
 * Created on July 9, 2022, 9:35 PM
 */

#ifndef OUTPUT_H
#define	OUTPUT_H

#define STATE_ALARME_0 0
#define STATE_ALARME_1 1
#define STATE_TEMPO 2
#define STATE_IDIOMA 3
#define STATE_ALARME_BAIXO_0 4
#define STATE_ALARME_ALTO_0 5
#define STATE_ALARME_BAIXO_1 6
#define STATE_ALARME_ALTO_1 7
#define TIME_OUT 8
#define STATE_FIM 8


void outputInit(void);
void outputPrint(int numTela, int idioma); 
#endif	/* OUTPUT_H */

