/*
 * PSR.h
 *
 *  Created on: Apr 28, 2017
 *      Author: Logan
 */

#ifndef PSR_H_
#define PSR_H_
#include <ctime>
#include <string>
#include "math.h"
#include "time.h"


long input;
int gah;
int rnd;
int reass;
int rolls[8];
int charValues[8];
std::ofstream sheet;
std::string charNames[] = {"Agi","Con","Dex","Str","Int","Per","Pow","Wp"};

int rand(long seed);

int PSR(){
	sheet << "CHARACTERISTICS:" << std::endl;
	sheet << "_________________________" << std::endl;
	std::cout << "Please enter 4 digit seed number" << std::endl;
	std::cin >> input;
	gah = input;
	std::cout << "Rolling..." <<std::endl;

	for(int i = 0; i<8; i++){
		int value;
			do{
				value = rand(gah);
				gah++;
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
	return 0;
}

int rand(long seed)
{
        static long a = long(seed);
        a = (a * 32719 + 3) % 32749;
        return ((a % 10) + 1);
}




// sheet.open("AnimaCharacterSheet.txt");
#endif /* PSR_H_ */


