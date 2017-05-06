// main.cpp
// 	Created on: Apr 26, 2017
//    Author: Logan

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "math.h"
#include "time.h"
#include "PSR.h"

std::string characterName;

int chars[8];
std::string characterFile = characterName + ".txt";

int charaDecide();
int PSR();

int charaDecide(){ //switch is broken(?)  :(
	int input;
	std::cout << "type the number of the method you'd like for characteristic rolls." << std::endl;
	std::cout << "1) Psudo-random generator" << std::endl;
	std::cin >> input;
	switch (input){
		default: PSR();
	}
	return 0;
}

int deetz(){
	return 0;
}

int printer(std::string textInput, int caseNumber){
	sheet.open("AnimaCharacterSheet.txt");
		if (! sheet){
				std::cout << "Error: File Stream Error. Reboot Program and try again." << std::endl;
				return 1;
			}
	switch(caseNumber){
	case 1: { //Character sheet Basics
		sheet << "Computer Generated ANIMA Character-Sheet (cGac)." << std::endl;
		sheet << "___________________________________________________" << std::endl << std::endl;
		sheet << "Character name: " + textInput << std::endl;
		break;
	}
	case 2: { //Characteristics

		break;
	}
	case 3: {break;}
	case 4: {break;}
	case 5: {break;}
	case 6: {break;}
	case 7: {break;}
	case 8: {break;}
	case 9: {break;}
	case 10:{break;}
	case 11:{break;}
	default: {}
	}
	sheet.close();
	return 0;
}



int main(){
	sheet.open("AnimaCharacterSheet.txt");
	std::cout << "Welcome to the Anima Charcter Creator." << std::endl;
	std::cout << "Your Character sheet will be called 'AnimaChracterSheet.txt'; "
			"plese rename it after it is complete" << std::endl;
	std::cout << "Please enter the name of your character" <<std::endl;
	std::cin >> characterName;
	printer(characterName, 1);
	std::cout << characterName << std::endl;

		/* okay, now i need to list the things that need to be in character creation
		 *
		 * Characteristics (method: chara)
		 * Details, LP, fatigue, movement speet (method: deetz)
		 * Advantages/Disadvantages (method: vantage)
		 * Class & development points (method: dp)
		 * if ki, ki skills (method: ki)
		 * if mage, then spells, (method: magic)
		 * if summ, then summ stuffs (method: summ)
		 * if psy, then psy skills (method: psy)
		 * inititve and resistances (method: resist)
		 * background (method: back)
		 *
		 * */
	charaDecide();
	sheet.close();
	return 0;
	}



