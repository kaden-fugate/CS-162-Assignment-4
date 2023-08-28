#ifndef GAMEHEADER_H
#define GAMEHEADER_H

#include "roomheader.h"
#include "wumpusheader.h"
#include "pitheader.h"
#include "batheader.h"
#include "goldheader.h"

class Game{

    private:

        std::vector< std::vector< Room > > cave; // vector for cave
        int x, y; // position of player
        int rope_x, rope_y;
        bool p_dead; // whether or not player is dead
        bool w_dead; // whether or not wumpus is dead
        bool has_gold; // if player has gold
        int num_arrow; // # of arrows user has

    public:

        Game(int);
        void delete_game();
        void game_reinit(int);
        void print_cave(bool);
        Event* init_event(int);
        void shuffle_cave();
        void move_player();
        void full_percepts();
        void encounter_event(bool);
        bool game_over(bool);
        bool get_p_dead();
        void shoot_arrow(std::string);
        void print_inventory();
        void move_wumpus();
        void reset_vars();
        // mo' functions, mo' problems

};



#endif