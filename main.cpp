#include <SFML/Graphics.hpp>

#include <iostream>
#include <time.h>

#include "LinearPath.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "AssetManager.hpp"
#include "Definitions.hpp"
//#include "Game.hpp"
//
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH , SCREEN_HEIGHT), "Game");
//    //Set framerate to MAX 60fps
//    window.setFramerateLimit(60);
//    
//    system("echo %cd%");
//
//    /////Implementation of game class
//    /////Game class unfinished, need to implement accurate damage, enemy progression
//    /////and tower placement, along with many other things lol
#include "GameClassWip.hpp"
int main()
{
    GameWip(SCREEN_WIDTH, SCREEN_HEIGHT, "TEST NAME");
    //Game newGame;
   // newGame.startGame(LEVEL1, window);
    
    return 0;
}