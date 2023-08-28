#ifndef BATHEADER_H
#define BATHEADER_H

#include "eventheader.h"

class Bat : public Event{

    public:

        void percept();

        void encounter(bool&, bool&, bool&, int&, int&, int);

        char display_symbol(); 

        void arrow_event(bool&);

};

#endif