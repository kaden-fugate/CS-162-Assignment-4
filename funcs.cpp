#include <iostream>
#include "funcsheader.h"



/*********************************************************************** 
** Function: check_size()
** Description: this function makes sure the user enters a valid size.
** the cin.clear()/ ignore() is there to make sure the getline() in move_player
** doesnt get jammed up and skip the first iteration.
** Parameters: w_dead
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

int check_size(){

    int size;

    while(true){

        std::cout << "Please input the size of the cave: ";
        std::cin >> size;

        if(size > 3){
            
            std::cin.ignore(); 
            break; // valid input, loop breaks

        }
        else{

            std::cout << "Please enter a size greater than 3!\n";
            std::cin.clear();
            std::cin.ignore(); // invalid input, loop repeats. if char is enters, clear/ignore makes no infinite loops occur

        }

    }

    return size;

}
// 7 lines



/*********************************************************************** 
** Function: get_cheat_mode()
** Description: gets the users desired choice for cheat mode
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

bool get_cheat_mode(){

    std::string c_m_str;
    bool c_m;

    while(true){ // loops while no valid input present

        std::cout << "Cheat mode? (t or f): ";
        std::cin >> c_m_str;

        if(c_m_str == "T" || c_m_str == "t"){ // t or T makes c_m true and breaks loop

            c_m = true;

            std::cin.clear();
            break;

        }
        else if(c_m_str == "F" || c_m_str == "f"){ // f or F makes c_m false and breaks loop

            c_m = false;

            std::cin.clear();
            break;

        }
        else{ // invalid input yells at you

            std::cout << "Please enter a valid input!\n";
            std::cin.clear();

        }
        
    }
    // cin.clear() makes it so getline doesnt skip first iteration

    return c_m;

}
// 11 lines



/*********************************************************************** 
** Function: get_play_again()
** Description: gets if the player would like to play again
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
************************************************************************/

bool get_play_again(){

    bool p_a;
    std::string p_a_str;

    while(true){ // loops while no valid input present

        std::cout << "Would you like to play again? (t or f): ";
        std::cin >> p_a_str;

        if(p_a_str == "T" || p_a_str == "t"){ // t or T makes p_a true

            p_a = true;
            break;

        }
        else if(p_a_str == "F" || p_a_str == "f"){ // f or F makes p_a false

            p_a = false;
            break;

        }
        else{

            std::cout << "Please enter a valid input!\n";

        }

    }
    // no cin.clear needed because another cin.clear will run after this function

    return p_a;

}
// 8 lines



/*********************************************************************** 
** Function: map_again()
** Description: determines if player wants to play on same map or new map
** Parameters: none
** Pre-Conditions: player must choose to play again
** Post-Conditions: none
************************************************************************/

bool map_again(){

    bool m_a;
    std::string m_a_str;

    while(true){ // loops while valid input not present

        std::cout << "Would you like to replay the current map? (t or f): ";
        std::cin >> m_a_str;

        if(m_a_str == "t" || m_a_str == "T"){ // t or T makes m_a true and breaks loop

            m_a = true;
            std::cin.ignore();
            break;

        }
        else if(m_a_str == "f" || m_a_str == "F"){ // f or F makes m_a false and breaks loop

            m_a = false;
            std::cin.ignore();
            break;

        }
        else{

            std::cout << "Please enter a valid input!\n";

        }

    }

    return m_a;

}