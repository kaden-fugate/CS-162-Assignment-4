#ifndef ROOMHEADER_H
#define ROOMHEADER_H

#include "eventheader.h"

class Room{

    protected:

        int x, y; // saves location of room
        Event *event;
    
    public:

        Room();
        Room(int, int);
        int get_x();
        int get_y();
        Event* get_event() const;
        void room_percepts();
        void room_encounter(bool&, bool&, bool&, int&, int&, int);
        void set_event(Event*);
        void set_x(int);
        void set_y(int);
        void delete_event();

};

#endif