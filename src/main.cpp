// main.cpp
// 	Created on: Apr 26, 2017
//    Author: Logan

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "math.h"
#include "time.h"
//#include "PSR.h"    I put all the stuff in there into main.cpp

using namespace std; //Becasue why the fuck not?

ofstream sheet;

string characterName;
string charNames[] = { "Agi", "Con", "Dex", "Str", "Int", "Per", "Pow", "Wp" };

long input;
int reass;
int rolls[8];
int charValues[8];
int charScores[8];

int PSR();

int dpClass() { //nothing yet

	return 0;
}

int deetz() {   //nothing yet
	cout << "Okay, now we have to take care of some details." << endl;
	return 0;
}

int charRNG(){
	int seed;
	cout << "please enter 4 digit seed code" << endl;
	cin >> seed;
	/*if(!seed){
		cout << "UH OH, DIS BROKE TOO!" << endl;
		return -1;
	}
	seed.open("seed.txt");
	if (seed){
	} else {
		std::cout << "error in reading seed, please enter a random 4 digit number." << std::endl;
		std::cin >> getSeed;
	}
	*/
    static long a = long(/*getSeed???*/seed);
    a = (a * 32719 + 3) % 32749;
    return ((a % 10) + 1);
}

int charaDecide() {
	int input;
	cout << "type the number of the method you'd like for characteristic rolls."
			<< endl;
	cout << "1) Psudo-random generator" << endl;
	cin >> input;
	switch (input) {
	default:
		PSR();
	}
	cout << "Your characterisitics have been decided" << endl;
	return 0;
}

int printer(string textInput, int caseNumber) {
	if (!sheet) {
		ofstream sheet;
	}
	sheet.open("AnimaCharacterSheet.txt");
	if (!sheet) {
		cout << "Error: File Stream Error. Reboot Program and try again."
				<< endl;
		return 1;
	}
	switch (caseNumber) {
	case 1: { //Character sheet Basics
		sheet << "Computer Generated ANIMA Character-Sheet (cGac)." << endl;
		sheet << "___________________________________________________" << endl
				<< endl;
		sheet << "Character name: " + textInput << endl;
		break;
	}
	case 2: { //Characteristics

		break;
	}
	case 3: {
		break;
	}
	case 4: {
		break;
	}
	case 5: {
		break;
	}
	case 6: {
		break;
	}
	case 7: {
		break;
	}
	case 8: {
		break;
	}
	case 9: {
		break;
	}
	case 10: {
		break;
	}
	case 11: {
		break;
	}
	default: {
	}
	}
	sheet.close();
	return 0;
}

int PSR() {
	sheet << "CHARACTERISTICS:" << std::endl;
	sheet << "_________________________" << std::endl;
	std::cout << "Rolling..." << std::endl;

	for (int i = 0; i < 8; i++) {
		int value;
		do {
			value = charRNG();
		} while (value < 4);
		std::cout << "Value # " << i + 1 << ": " << value << "." << std::endl;
		rolls[i] = value;
	}
	std::cout
			<< "   are you charicteristic scores. Now you will distribute them. Enter any character to continue"
			<< std::endl << std::endl;
	getchar();
	for (int i = 0; i < 8; i++) {
		std::cout
				<< "Enter the # of the value you want to assign to "
						+ charNames[i] << std::endl;
		std::cin >> reass;
		charValues[i] = rolls[reass - 1];
		sheet << charNames[i] << ": " << charValues[i] << std::endl;
	}
	for (int i = 0; i < 8; i++) {
		switch (charValues[i]) {
		case 10: {
			charScores[i] = 15;
			sheet << charNames[i] << ": +15 (base: 10)" << endl;
			cout << "Wow! You have a high " << charNames[i] << " modifier of +"
					<< charValues[i] << endl;
			break;
		}
		case 9: {
			charScores[i] = 10;
			sheet << charNames[i] << ": +10 (base: 9)" << endl;
			cout << "Wow! Your " << charNames[i] << " modifier is a +"
					<< charValues[i] << endl;
			break;
		}
		case 8: {
			charScores[i] = 10;
			sheet << charNames[i] << ": +10 (base: 8)" << endl;
			cout << "Wow! Your " << charNames[i] << " modifier is a +"
					<< charValues[i] << endl;
			break;
		}
		case 7: {
			charScores[i] = 5;
			sheet << charNames[i] << ": +5 (base: 7)" << endl;
			break;
		}
		case 6: {
			charScores[i] = 5;
			sheet << charNames[i] << ": +5 (base: 6)" << endl;
			break;
		}
		case 5: {
			charScores[i] = 0;
			sheet << charNames[i] << ": +0 (base: 5)" << endl;
			break;
		}
		case 4: {
			charScores[i] = -5;
			sheet << charNames[i] << ": -5 (base: 4)" << endl;
			cout << "Uh-oh, you have a below average " << charNames[i]
					<< " score!" << endl;
			break;
		}
		}
	}
	return 0;
}

int main() {
	sheet.open("AnimaCharacterSheet.txt");
	cout << "Welcome to the Anima Charcter Creator." << endl;
	cout << "Your Character sheet will be called 'AnimaChracterSheet.txt'; "
			"plese rename it after it is complete" << endl;
	cout << "Please enter the name of your character" << endl;
	cin >> characterName;
	printer(characterName, 1);
	cout << characterName << endl;

	/* okay, now i need to list the things that need to be in character creation
	 *
	 * Characteristics (method: chara)
	 * Class & development points (method: dpClass)
	 * Details, LP, fatigue, movement speed (method: deetz)
	 * Advantages/Disadvantages (method: vantage)
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

