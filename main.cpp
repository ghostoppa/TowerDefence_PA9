#include <SFML/Graphics.hpp>

#include <iostream>
#include "GameClassWip.hpp"
#include "Test.hpp"
int main()
{
<<<<<<< HEAD
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
=======
    Test newTest;
    GameWip game(SCREEN_WIDTH, SCREEN_HEIGHT, "Swarm Patrol");

    //newTest.AssetManagerTest();
    return 0;
>>>>>>> d2b00e7bd8b995a0387b43a35bbb024563876b61
}