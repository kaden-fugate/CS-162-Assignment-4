#include <iostream>
#include "eventheader.h"

// this class is literally nothing - abstract parent class

/*********************************************************************** 
** Function: Event()
** Description: default constructor for event class- does nothing as
** i want event to remain uninitialized until manually declared. 
** (cave.size() ^ 2) - 6 will be the # of uninitialized events
** Parameters: none
** Pre-Conditions: will be called when rooms are initialized
** Post-Conditions: none
************************************************************************/

Event::Event(){}
// 0 lines



/*********************************************************************** 
** Function: percept() - virtual func / parent class
** Description: does nothing in event class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Event::percept(){}
// 0 lines



/*********************************************************************** 
** Function: encounter(bool&, bool&, bool&, int&, int&, int) - virtual func / parent class
** Description: does nothing in event class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Event::encounter(bool &w_dead, bool &p_dead, bool& has_gold, int &x, int &y, int max){}
// 0 lines



/*********************************************************************** 
** Function: display_symbol() - virtual func / parent class
** Description: does nothing in event class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

char Event::display_symbol(){}
// 0 lines



/*********************************************************************** 
** Function: arrow_event(bool&) - virtual func / parent class
** Description: does nothing in event class
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Event::arrow_event(bool &w_dead){}
// 0 lines