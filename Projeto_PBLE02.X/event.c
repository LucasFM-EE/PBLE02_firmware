#include "keypad.h"
#include "event.h"


static unsigned char key_ant;

int ev = EV_NOEVENT;

void eventInit(void) {
    key_ant = nothing;
}

unsigned int eventRead(void) {
    unsigned char key;
    key = kpRead();
    
    if (key != key_ant) {
        if (key == right) 
            ev = EV_RIGHT;
        
        if (key == left) 
            ev = EV_LEFT;
        
        if (key == enter) 
            ev = EV_ENTER;  
        
         if (key == nothing) 
            ev = EV_NOEVENT;        
    }
    
    key_ant = key;
    
    return ev;
}
