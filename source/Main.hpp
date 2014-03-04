#ifndef __MAIN_HPP
#define __MAIN_HPP

#define DEFAULT_WIDTH 1680
#define DEFAULT_HEIGHT 1050
#define FRAMETIME 17 // Delay between updates (FPS = 1/FRAMETIME)
#define RADDEG 57.29577951308232088 // 180/PI

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#include <cstdlib> 
#include "Player.hpp"
#include "GameMap.hpp"
#include "map/MapFileParser.hpp"
#include "Game.hpp"
#include "Window.hpp"

using namespace glPortal::engine;

// Main functions
void update(int);
void respawn();
void nextLevel();
void draw();
void registerCallbacks();
void setup(int *, char **);
// Callback functions
void mouse_moved(int, int);
void mouse_pressed(int, int, int, int);
void key_down(unsigned char, int, int);
void key_up(unsigned char, int , int);
void resize(int, int);
void window_status(int state);
void resetKeyStates();
int width, height;	
int mousex, mousey; 
bool keystates[256];
bool nmap_enabled = true;

Player player;
GameMap gameMap;
Game game;
Window window;
int current_level;

#endif
