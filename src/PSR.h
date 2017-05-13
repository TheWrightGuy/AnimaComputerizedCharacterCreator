/*
 * PSR.h
 *
 *  Created on: Apr 28, 2017
 *      Author: Logan
 */

#ifndef PSR_H_
#define PSR_H_
#include <ctime>
#include <fstream>
#include <string>
#include "math.h"
#include "time.h"


long input;
int gah;
int rnd;
int reass;
int rolls[8];
int charValues[8];

std::string charNames[] = {"Agi","Con","Dex","Str","Int","Per","Pow","Wp"};

int rand(long seed);

int PSR(){
	sheet << "CHARACTERISTICS:" << std::endl;
	sheet << "_________________________" << std::endl;
	std::cout << "Rolling..." <<std::endl;

	for(int i = 0; i<8; i++){
		int value;
			do{
				value = rand();
			} while(value < 4);
			std::cout << "Value # " << i+1 << ": " << value << "                  enter a character to continue" << std::endl;

			rolls[i]= value;
			gah++;
	}
	std::cout << "   are you charicteristic scores. Now you will distribute them. Enter any character to continue" << std::endl << std::endl;
	getchar();
	for(int i = 0; i<8; i++){
		std::cout << "Enter the # of the value you want to assign to " + charNames[i] << std::endl;
		std::cin >> reass;
		charValues[i] = rolls[reass-1];
		sheet << charNames[i] << ": " << charValues[i] << std::endl;
	}
	for (int i = 0; i < 8; i++){

	}
	return 0;
}

int rand(long seed)
{
		int getSeed;
		if(!seed){
			ofstream seed;
		}
		seed.open("seed.txt");
		if (seed){
			getline(seed, getSeed);
		} else {
			std::cout << "error in reading seed, please enter a random 4 digit number." << std::endl;
			std::cin >> getSeed;
		}
        static long a = long(/*getSeed???*/seed);
        a = (a * 32719 + 3) % 32749;
        return ((a % 10) + 1);
}




// sheet.open("AnimaCharacterSheet.txt");
#endif /* PSR_H_ */


