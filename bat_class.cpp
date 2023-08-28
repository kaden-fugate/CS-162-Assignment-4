#include <iostream>
#include <cstdlib>
#include "batheader.h"

/*********************************************************************** 
** Function: percept() - bat derived
** Description: this is a function for how the player percepts an event
** that is a bat
** Parameters: none
** Pre-Conditions: an event must be initialized as a bat & player must be within 1 of the event
** Post-Conditions: none
************************************************************************/

void Bat::percept(){

    std::cout << "You hear wings flapping...\n";

}
// 0 lines



/*********************************************************************** 
** Function: encounter(bool&, bool&, bool&, int&, int&, int) - bat derived
** Description: this is how the player encounters an event of bat type.
** the player gets moved to a random x and y coord
** Parameters: w_dead, p_dead, has_gold, x, y, max
** Pre-Conditions: player must be on an event that was initialized as bat type
** Post-Conditions: none
************************************************************************/

void Bat::encounter(bool &w_dead, bool &p_dead, bool &has_gold, int &x, int &y, int max){

    std::cout << "You step in the room and a horde of bats lift you up!\n\nYou are in a place that you dont recognize anymore...\n\n";

    x = rand() % (max), y = rand() % (max); // sets rand within max bounds of cave for each coord

}
// 1 line



/*********************************************************************** 
** Function: display_symbol() - bat derived
** Description: this function displays the bats symbol if the player has
** cheat mode on. It is also used for differentiating events when
** using the shoot arrow function
** Parameters: none
** Pre-Conditions: event must be initialized as a bat
** Post-Conditions: none
************************************************************************/

char Bat::display_symbol(){

    return 'b';
}
// 0 lines



/*********************************************************************** 
** Function: arrow_event(bool&) - bat derived
** Description: function for when an arrow is on an event. bat event
** does not interact with arrow
** Parameters: w_dead
** Pre-Conditions: arrow must be on an event of bat
** Post-Conditions: none
************************************************************************/

void Bat::arrow_event(bool &w_dead){}
// 0 lines