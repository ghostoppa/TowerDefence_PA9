#pragma once
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define LEVEL1 1


//Assets
//Textures
constexpr auto Map1File = "assets/img/map1.png";
constexpr auto MENU_BG = "assets/img/bg.png";
constexpr auto PLAY_BTN = "assets/img/startbtn.png";
constexpr auto LOAD_BTN = "assets/img/loadbtn.png";
constexpr auto SPLASH = "assets/img/splogo.png";
constexpr auto SPLASHBG = "assets/img/SplashBackground.png";
constexpr auto MENUBACKGROUND = "assets/img/testMenu.png";

constexpr auto TOWER_ONE = "assets/img/sprayer.png";
constexpr auto TOWER_TWO = "assets/img/particleCannon.png";
constexpr auto TOWER_THREE = "assets/img/flamethrower.png";
constexpr auto TOWER_FOUR = "assets/img/zapper.png";
constexpr auto TOWER_FIVE = "assets/img/particleCannon.png";
constexpr auto TOWER_SIX = "assets/img/particleCannon.png";

constexpr auto PROJECTILE_ONE = "assets/img/mist.png";
constexpr auto PROJECTILE_TWO = "assets/img/particleBeam.png";
constexpr auto PROJECTILE_THREE = "assets/img/firebolt.png";
constexpr auto PROJECTILE_FOUR = "assets/img/firebolt.png";

//Sounds
constexpr auto menuSound = "assets/Sounds/SneakyAdventure.ogg";
constexpr auto gameSound = "assets/Sounds/KevinMacLeodGrooveGrove.flac";
//Fonts
constexpr auto MythologyFont = "assets/fonts/Mythology.ttf";
constexpr auto RobotoNormal = "assets/fonts/Roboto-Regular.ttf";
constexpr auto RobotoRegular = "assets/font/Roboto-Bold.ttf";


////Stats////
//Towers
constexpr auto sprayerPrice = 250;
constexpr auto pCanPrice = 150;
constexpr auto fThrowPrice = 200;
constexpr auto zapPrice = 100;
//Enemies
#define GREEN_HEALTH 5
#define GREEN_SPEED 2.0f
#define YELLOW_HEALTH 10
#define YELLOW_SPEED 3.0f
#define RED_HEALTH 20
#define RED_SPEED 5.0f