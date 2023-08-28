#ifndef WUMPUSHEADER_H
#define WUMPUSHEADER_H

#include "eventheader.h"

class Wumpus : public Event{

    public:

        void percept();

        void encounter(bool&, bool&, bool&, int&, int&, int);

        char display_symbol();

        void arrow_event(bool&);

};

#endif