#ifndef GOLDHEADER_H
#define GOLDHEADER_H

#include "eventheader.h"

class Gold : public Event{

    public:

        void percept();

        void encounter(bool&, bool&, bool&, int&, int&, int);

        char display_symbol(); 

        void arrow_event(bool&);

};

#endif