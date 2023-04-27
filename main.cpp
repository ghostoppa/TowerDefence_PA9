#include <SFML/Graphics.hpp>

#include <iostream>
#include "GameClassWip.hpp"
#include "Test.hpp"
int main()
{
    int choice = 0;
   
    std::cout << "Please Select to 1, play game or 2, do tests" << std::endl;
    std::cin >> choice;
    if (choice == 1) {
        GameWip game(SCREEN_WIDTH, SCREEN_HEIGHT, "Swarm Patrol");
    }
    else
    {
        Test newTest;
    }
       return 0;
}