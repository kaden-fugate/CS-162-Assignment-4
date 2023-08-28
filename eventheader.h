#ifndef EVENTHEADER_H
#define EVENTHEADER_H

class Event{

    public:

        Event();

        // pure virtual functions
        virtual void percept() = 0;
        virtual void encounter(bool&, bool&, bool&, int&, int&, int) = 0;
        virtual char display_symbol() = 0;
        virtual void arrow_event(bool&) = 0;

};

#endif