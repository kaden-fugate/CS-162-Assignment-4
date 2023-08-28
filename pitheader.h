#ifndef PITHEADER_H
#define PITHEADER_H

#include "eventheader.h"

class Pit : public Event{

    public:

        void percept();

        void encounter(bool&, bool&, bool&, int&, int&, int);

        char display_symbol();

        void arrow_event(bool&);

};

#endif