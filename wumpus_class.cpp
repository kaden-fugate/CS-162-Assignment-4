#include <iostream>
#include "wumpusheader.h"



/*********************************************************************** 
** Function: percept() - wumpus derived
** Description: outputs percept for wumpus
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Wumpus::percept(){

    std::cout << "You smell a terrible stench...\n";

}
// 0 lines



/*********************************************************************** 
** Function: encounter(bool&, bool&, bool&, int&, int&, int) - wumpus derived
** Description: encounters wumpus, if wump dead, game prints a sad message,
** if wump alive, player dies
** Parameters: w_dead, p_dead, has_gold, x, y, max
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Wumpus::encounter(bool &w_dead, bool &p_dead, bool &has_gold, int &x, int &y, int max){

    if(w_dead == false){ // if encountered and wump not dead, player dies

        std::cout << "You step foot into the dark room and notice you're standing on something fuzzy...\n\nThe wumpus wakes up and eats you!\n\n";

        p_dead = true;

    }
    else if(w_dead == true){

        std::cout << "There's a cute fuzzy creature, it's dead...\n\n";

    }

}
// 3 lines



/*********************************************************************** 
** Function: display_symbol() - wumpus derived
** Description: returns wump symbol
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

char Wumpus::display_symbol(){

    return 'w';

}
// 0 lines



/*********************************************************************** 
** Function: arrow_event(bool&)
** Description: if arrow encounters wumpus, wumpus dies
** Parameters: w_dead
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Wumpus::arrow_event(bool &w_dead){

    std::cout << "You hear a monster cry out in agonizing pain...\nYou kind of feel bad for it.\n";

    w_dead = true;

}