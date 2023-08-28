#include <iostream>
#include "pitheader.h"



/*********************************************************************** 
** Function: percept() - pit derived
** Description: percepts for a pit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Pit::percept(){

    std::cout << "You feel a breeze...\n";

}
// 0 lines



/*********************************************************************** 
** Function: encounter(bool&, bool&, bool&, int&, int&, int) - pit derived
** Description: kills the player so hard
** Parameters: w_dead, p_dead, has_gold, x, y, max
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Pit::encounter(bool &w_dead, bool &p_dead, bool &has_gold, int &x, int &y, int max){

    std::cout << "You try to step into the room but you quickly notice there is no floor...\n\nYou fall to your death!\n\n";

    p_dead = true;

}
// 1 line



/*********************************************************************** 
** Function: display_symbol() - pit derived
** Description: gives the pit character
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

char Pit::display_symbol(){

    return 'p';

}
// 0 lines



/*********************************************************************** 
** Function: arrow_event - pit derived
** Description: arrow does not interact with pit
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Pit::arrow_event(bool &w_dead){}
// 0 lines