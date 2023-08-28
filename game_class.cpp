#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "gameheader.h"

// no default constructor as it is never called so it does not cause an error.

/*********************************************************************** 
** Function: Game(int)
** Description: non default constructor for game. initializes 2D vector,
** creates rooms with no event and sets initial bools/ # arrows.
** Parameters: size of cave
** Pre-Conditions: user must give valid cave size
** Post-Conditions: none
************************************************************************/

Game::Game(int size){

    for(int i = 0; i < size; i++){

        this->cave.push_back(std::vector< Room >(0));

        for(int j = 0; j < size; j++){

            Room temp_room(j, i); // init room with only coords, no event

            this->cave[i].push_back(temp_room); // add room to 2d vector

        }

    }

    shuffle_cave(); // sets 6 events and player start location in random spots

    p_dead = false;
    w_dead = false;
    has_gold = false;
    num_arrow = 3;

}
// 9 lines



/*********************************************************************** 
** Function: delete_game()
** Description: as i manually allocate the events within the game class,
** i found it easiest to manually delete them as well. I tried to make this
** a destructor however that caused some issues with letting the game play
** again with the same cave layout as before.
** Parameters: none
** Pre-Conditions: player must end the game or restart game with new cave
** Post-Conditions: none
************************************************************************/

void Game::delete_game(){

    for(int i = 0; i < cave.size(); i++){ // cycle through every single room in cave

        for(int j = 0; j < cave.size(); j++){

            if(cave[i][j].get_event()){ // check if the room has an event

                cave[i][j].delete_event(); // delete the room

            }

        }

    }

    cave.clear(); // clear the vector

}
// 5 lines



/*********************************************************************** 
** Function: game_reinit(int)
** Description: this function makes a new cave when the player wants to
** play again with new game
** Parameters: size of the new cave
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::game_reinit(int size){

    delete_game(); // deletes the previous game layout
    
    for(int i = 0; i < size; i++){ // reinit the vector using the same method found in the constructor

        this->cave.push_back(std::vector< Room >(0));

        for(int j = 0; j < size; j++){

            Room temp_room(j, i); // init room with only coords, no event

            this->cave[i].push_back(temp_room); // add room to 2d vector

        }

    }

    shuffle_cave(); // shuffle placement of new events and new player start location

}
// 6 lines



/*********************************************************************** 
** Function: init_event(int)
** Description: this function takes in the number of which event to initialize
** and it manually creates a new event of that type.
** Parameters: # that determines which event is chosen
** Pre-Conditions: called only when game starts/ new game is made
** Post-Conditions: none
************************************************************************/

Event* Game::init_event(int i){

    Event* temp_e; // event pointer to be initialized polymorphically

    if(i == 0){

        temp_e = new Wumpus;

    }
    else if(i > 0 && i < 3){

        temp_e = new Pit;

    }
    else if(i > 2 && i < 5){

        temp_e = new Bat;

    }
    else if(i == 5){

        temp_e = new Gold;

    }
    
    return temp_e;

}
// 8 lines



/*********************************************************************** 
** Function: shuffle_cave()
** Description: this function loops through 7 times. for the first 6
** iterations, it chooses a random spot for an event to be initialized.
** if the random spot chosen has an event, a new spot is chosen. for the
** final iteration, it sets the players start location
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::shuffle_cave(){

    int a, b;

    for(int i = 0; i < 7; i++){

        while(true){ // loop to choose a and b repeatedly until (a,b) in cave does not hold an event

            a = rand() % cave.size(), b = rand() % cave.size();

            if(!this->cave[a][b].get_event()){ // if not event, break

                break;

            }

        }

        if(i < 6){

            cave[a][b].set_event(init_event(i)); // if 

        }
        else{

            y = a, x = b;

            rope_x = x, rope_y = y;

        }

    }

}
// 10 lines



/*********************************************************************** 
** Function: print_cave(bool)
** Description: this function prints the cave. player is represented as '*'.
** cave is printed in a different way when cheat mode is activated
** Parameters: cheat mode bool value
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::print_cave(bool c_m){

    for(int i = 0; i < this->cave.size(); i++){ // print rows for # of columns

        std::cout << std::setfill('=') << std::setw((this->cave.size() * 8) + 2) << "\n";

        for(int j = 0; j < 3; j++){ // this for loop prints a room that is 3 tall which is why it iterates 3 times.
        
            for(int k = 0; k < this->cave.size(); k++){

                if( (this->x == k && this->y == i) && j == 1){ // player position overides every other print func

                    std::cout << "|   *   ";

                }
                else if(j == 1 && this->cave[i][k].get_event() && c_m == true){ // if cheat mode is true, display the locations of all events

                    std::cout << "|   " << this->cave[i][k].get_event()->display_symbol() << "   "; // cheat mode display

                }
                else if(k == rope_x && i == rope_y && j == 1 && c_m == true){ // special if else statement for rope

                    std::cout << "|   e   "; // cheat mode rope

                }
                else{ // empty room

                    std::cout << "|       "; 

                }

                if(k == this->cave.size() - 1){ // start new line of cave

                    std::cout << "|\n";

                }

            }

        }

    }

    std::cout << std::setfill('=') << std::setw((this->cave.size() * 8) + 2) << "\n"; // bottom border

    std::cout << "x: " << cave[x][y].get_y() << " y: " << cave[x][y].get_x() << "\n"; // prints players coords

    print_inventory(); // print inventory (not required but makes it easier for the player to see what they've done)

}
// 9 lines



/*********************************************************************** 
** Function: move_player()
** Description: function that lets the player move as long as they as
** desired movement is within allowed bounds. if player chooses to shoot,
** this function will call the shoot arrow function instead
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::move_player(){

    std::string direction;
    std::cout << ">";
    
    getline(std::cin, direction); // getline so it will register a space before the desired char

    if(direction[0] != ' '){ // enters if the player doesnt choose to shoot

        // only enters if the movement is correct input
        if(direction == "w"){

            if(y - 1 > -1){

                y--;

            }

        }
        else if(direction == "s"){

            if(y + 1 < cave.size()){

                y++;

            }

        }
        else if(direction == "a"){

            if(x - 1 > -1){

                x--;

            }

        }
        else if(direction == "d"){

            if(x + 1 < cave.size()){

                x++;

            }

        }

    }
    else{ // call shoot arrow function if ' ' detected

        shoot_arrow(direction);

    }

}
// 14 lines



/*********************************************************************** 
** Function: shoot_arrow(std::string)
** Description: this function shoots the arrow in the correct direction
** for the correct distance
** Parameters: direction of arrow
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::shoot_arrow(std::string direction){

    if(num_arrow > 0){ // only enters if arrow is greater than 0 

        int temp_x = this->y, temp_y = this->x;

        for(int i = 0; i < 3; i++){

            // only shoots if valid direction entered
            
            if(direction[1] == 'w'){

                temp_x--;

            }
            else if(direction[1] == 'a'){

                temp_y--;

            }
            else if(direction[1] == 's'){

                temp_x++;

            }
            else if(direction[1] == 'd'){

                temp_y++;

            }

            if( (temp_x < cave.size() && temp_x > -1) 
            && (temp_y < cave.size() && temp_y > -1) ){

                if(cave[temp_x][temp_y].get_event()){

                    cave[temp_x][temp_y].get_event()->arrow_event(this->w_dead);

                }

            }

            if(i == 2 && w_dead == false){ // if arrow didnt kill wumpus and it has traveled 3 rooms in distance, wumpus moves

                move_wumpus();

            }

        }

        if(direction[1] == 'w' || direction[1] == 'a' || direction[1] =='s' || direction[1] == 'd'){ // exception to make sure player doesnt lose an arrow
        // if they choose an invalid direction to shoot arrow

            num_arrow--;

        }

    }

}
/* 17 lines- it originally was 15 however adding the exception to make it so the player doesnt lose an arrow if they enter an invalid input
tipped me over the edge. it wasnt required but i wanted to make it so that you could move the wumpus if the user enters wrong input for
testing purposes. */



/*********************************************************************** 
** Function: full_percepts()
** Description: runs percepts in each given direction.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::full_percepts(){

    if(y < cave.size() - 1){ // checks if x will be in bounds first as it will cause a seg fault if it does the next if statement on an empty room

        if(this->cave[y + 1][x].get_event()){ // checks if the room has an event

            this->cave[y + 1][x].room_percepts(); // runs percept for room to the east

        }

    }
    // rest of functions are copies for west, north, and south (in that order)
    if(y > 0){

        if(this->cave[y - 1][x].get_event()){

            this->cave[y - 1][x].room_percepts();

        }

    }

    if(x < cave.size() - 1){ 

        if(this->cave[y][x + 1].get_event()){

            this->cave[y][x + 1].room_percepts();

        }

    }

    if(x > 0){

        if(this->cave[y][x - 1].get_event()){

            this->cave[y][x - 1].room_percepts();

        }

    }

}
// 12 lines



/*********************************************************************** 
** Function: encounter_event(bool)
** Description: this lets the player encounter an event, if the players location
** has changed due to the event, it prints the updated cave
** Parameters: cheat mode for printing a new cave
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::encounter_event(bool c_m){

    while(true){ // will loop if bat event happens

        if(this->cave[this->y][this->x].get_event()){

            int temp_x = this->y, temp_y = this->x;

            this->cave[this->y][this->x].room_encounter(this->w_dead, this->p_dead, this->has_gold, this->y, this->x, cave.size());

            if(y != temp_x || x != temp_y){ // if bat moves player, print screen again to show updated position

                print_cave(c_m); 

            }

            if((y != temp_x || x != temp_y)          // if bat moves player and they land on a new event, return to beginning of loop
            && cave[this->y][this->x].get_event()){

                continue;

            }
            else{ // no other scenario requires any other special conditions, break loop

                break;

            }

        }
        else{ // if no event, no encounter

            break;

        }

    }

}
// 11 lines



/*********************************************************************** 
** Function: game_over(bool)
** Description: determines if the game is over. if player wins the game,
** it prints one last updated cave to show the player entering the room with
** the rope
** Parameters: cheat mode for printing cave
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

bool Game::game_over(bool c_m){

    bool over = false;

    if(p_dead == true){ // player dies, they lose

        over = true;

        std::cout << "Game over! You lose!\n";

    }
    else if(this->x == this->rope_x && this->y == this->rope_y && has_gold == true && w_dead == true){ /*player is on the right location, killed the wumpus, 
    and got the gold, they win*/

        print_cave(c_m);

        over = true;

        std::cout << "Game over! You win!\n";

    }

    return over;

}
// 5 lines



/*********************************************************************** 
** Function: get_p_dead()
** Description: getter for p_dead so game does not encounter/percept
** event again after dying
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

bool Game::get_p_dead(){

    return p_dead;

}
// 0 lines



/*********************************************************************** 
** Function: print_inventory()
** Description: not required but prints players inventory so the
** player can better understand what they have done in the cave
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::print_inventory(){

    std::cout << "Inventory:\n\n";

    if(w_dead == true){

        std::cout << "> 1x Wumpus Head\n";

    }

    if(has_gold == true){

        std::cout << "> 1x Pocket Full of Dubloons\n";

    }

    std::cout << "> " << num_arrow << "x Arrows\n\n";

}
// 2 lines



/*********************************************************************** 
** Function: move_wumpus()
** Description: moves the wumpus to a random room in the cave
** Parameters: none
** Pre-Conditions: called when arrow misses wumpy
** Post-Conditions: none
************************************************************************/

void Game::move_wumpus(){

    for(int i = 0; i < this->cave.size(); i++){

        for(int j = 0; j < this->cave.size(); j++){ // check all rooms in cave

            if(this->cave[i][j].get_event()){ // check if room has event

                if(this->cave[i][j].get_event()->display_symbol() == 'w'){ // if room is wumpus event

                    if(rand() % 4 < 3){ // run 3 in 4 probability

                        while(true){

                            int a = rand() % this->cave.size(), b = rand() % this->cave.size();

                            if(!cave[a][b].get_event()){ // set event if no event already in room

                                cave[a][b].set_event(new Wumpus);

                                cave[i][j].delete_event();

                                break;

                            } // thats
                        
                        } // a

                    } // lot

                } // of

            } // curly

        } // braces

    }

}
// 10 lines



/*********************************************************************** 
** Function: reset_vars()
** Description: resets the variables within the game if player would like to replay
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

void Game::reset_vars(){

    this->p_dead = false, this->w_dead = false, this->has_gold = false; // reset event bools

    this->x = this->rope_x, this->y = this->rope_y; // reset player to original pos

    this->num_arrow = 3; // reset arrows

}   
// 3 lines