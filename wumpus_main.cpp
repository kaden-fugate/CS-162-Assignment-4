/******************************************************************************* 
** Program Filename: wumpus_main.cpp
** Author: Kaden ("The Kadenator") Fugate
** Date: November 6th, 2022
** Description: This program allows the player to play go fish against a very difficult computer
** Input: Cheat Mode, Requested Rank, Play Again
** Output: Players Hand, Players Book, (Maybe Computer Hand), Computer Books, Drawn Card, Winner
********************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include "gameheader.h"
#include "funcsheader.h"

int main(){

    bool cheat_mode = get_cheat_mode();

    bool play_again = true;

    srand(time(0));

    Game wumpus(check_size());

    while(true){

        if(play_again == false){

            wumpus.game_reinit(check_size());

        }
        
        while(wumpus.game_over(cheat_mode) == false){

            wumpus.print_cave(cheat_mode);

            wumpus.encounter_event(cheat_mode);

            if(wumpus.get_p_dead() == false){

                wumpus.full_percepts();

                wumpus.move_player();

            }

        }

        if(get_play_again() == true){

            play_again = map_again();

            wumpus.reset_vars();

        }
        else{
            
            wumpus.delete_game();

            break;

        }

    }

    return 0;

}
// exactly 15 lines

