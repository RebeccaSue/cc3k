





#include<iostream>
#include<string>

#include "Floor.h"
#include "Player.h"

class Game {

	string map; 
	string main_character; 
	string action; 

	public: 
		Game(string map, string status);
		~Game();

		// start() generates the map 
		void start(); 

		// print() print the map to the screen
		void print(); 

		// move_main_character(string) consumes a command string and move the main character
		void move_main_character(string); 
		
		// use_potion(string) consumes a potion string and reflects the effects on the main character
		void use_potion(string);

		// attack_enemy(string) consumes a genre of monster and change the main_character
		void attack_enemy(string);
		void freeze();
		void restart();
		void quit();
	
};