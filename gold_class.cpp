#include <iostream>
#include "goldheader.h"



/*********************************************************************** 
** Function: percept() - gold derived
** Description: percept() for event of gold type
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Gold::percept(){

    std::cout << "You see a glimmer nearby...\n";

}
// 0 lines



/*********************************************************************** 
** Function: encounter(bool&, bool&, bool&, int&, int&, int) - gold derived
** Description: tells the player that theyre on the gold and sets has_gold to true
** Parameters: w_dead, p_dead, has_gold, x, y, max
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Gold::encounter(bool&, bool&, bool &has_gold, int&, int&, int){

    std::cout << "The room is filled with gold!\n\nYou take as much time as possible filling your pockets full of shiny dubloons!\n\n";

    has_gold = true;

}
// 1 lines



/*********************************************************************** 
** Function: display_symbol() - gold derived
** Description: displays symbol in cave if cheat_mode = true
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

char Gold::display_symbol(){

    return 'g';

}
// 0 lines



/*********************************************************************** 
** Function: arrow_event(bool&) - gold derived
** Description: arrow doesnt interact with gold
** Parameters: w_dead
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Gold::arrow_event(bool &w_dead){}