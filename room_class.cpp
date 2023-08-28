#include <iostream>
#include "roomheader.h"

/* despite there being a pointer within this class, i did not use a single member of the big 3.
the reason for this is because i found it much easier to deal with the events from the game class.
using a destructor to delete the events provided a lot of bugs. and i also never really found an
opportunity to use the CC or AOO in a way that would use less lines of code/ be more efficient. */




/*********************************************************************** 
** Function: Room()
** Description: doesnt do anything
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Room::Room(){}
// 0 lines



/*********************************************************************** 
** Function: Room(int, int)
** Description: intializes event with default constructor, initializes room coords
** Parameters: x, y
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Room::Room(int x, int y) : event(){

    this->x = x, this->y = y;

    this->event = NULL;

}
// 0 lines



/*********************************************************************** 
** Function: get_x()
** Description: getter for x, not sure if i even ever use this
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

int Room::get_x(){

    return this->x;

}
// 0 lines



/*********************************************************************** 
** Function: get_y()
** Description: getter for y, not sure if i ever even use this
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

int Room::get_y(){

    return this->y;

}
// 0 lines



/*********************************************************************** 
** Function: get_event()
** Description: getter for event
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

Event* Room::get_event() const{ // marked as const because i tried to use it in a AOO

    return *&event;

}
// 0 lines



/*********************************************************************** 
** Function: room_percepts()
** Description: runs the percept for the event contained in the room
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Room::room_percepts(){

    this->event->percept();

}
// 1 line



/*********************************************************************** 
** Function: room_encounter(bool&, bool&, bool&, int&, int&, int)
** Description: encounters the event contained within the room
** Parameters: w_dead, p_dead, has_gold, x, y, max
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Room::room_encounter(bool&w_dead, bool& p_dead, bool &has_gold, int &x, int &y, int max){

    this->event->encounter(w_dead, p_dead, has_gold, x, y, max);

}
// 1 line



/*********************************************************************** 
** Function: set_event(Event*)
** Description: sets the event within the room to the event given within the parameters
** Parameters: event pointer
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Room::set_event(Event *e){

    this->event = e;

}
// 1 line



/*********************************************************************** 
** Function: set_x(int)
** Description: sets x
** Parameters: new x
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Room::set_x(int x){

    this->x = x;

}
// 1 line



/*********************************************************************** 
** Function: set_y(int)
** Description: sets y
** Parameters: new y
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Room::set_y(int y){

    this->y = y;

}
// 1 line



/*********************************************************************** 
** Function: delete_event()
** Description: deletes the event within the room and sets it to null
** Parameters: none
** Pre-Conditions: will only be called when an event within the room exists
** Post-Conditions: none
************************************************************************/

void Room::delete_event(){

    delete this->event;

    this->event = NULL;

}
// 2 lines