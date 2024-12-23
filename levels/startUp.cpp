#include <iostream>
#include <limits>
#include "../includes/crypto.h"
#include <iomanip>

void installPackages(){
	cout << "Checking Requirements..." << endl;
	system("bash ./includes/build.sh");
	system("sleep 0.5");
}

int gameType;

void startUp(){
	int option;
	int w = getWidth();
//	installPackages();
//	system("sleep 1");
	system("clear");
	system("PS1=-->");

	drawHeader();
	cout << endl;
	menuScreen();

	cout << endl << endl;
	shiftRight(paddingX);
	cout << "--> ";
in:
	cin >> option;
	gameType = option;
//	cin.ignore();
checkV:
	if(cin.fail()){
//		shiftRight(paddingX);
		cout << "\033[1A"  << setw(w) << "" << endl;
		shiftRight(paddingX);
		cout << "\033[1A" << "Select any of the option given --> ";

		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		goto in;
	}
	else{
		switch(option){
			case 0:
				newGame(level);
				break;
			case 1:
				variablesReset();
//				system("cmatrix & sleep 2 ; kill $!");
				newGame(level);
				break;
			case 2:
				instructions();
				break;
			case 3:
				highestScores();
				break;
			case 4:
				cin.ignore();
				randomFacts();
				break;
			default:
				cout << "\033[1A" << setw(w) << "" << endl;
				shiftRight(paddingX);
                		cout << " \033[1A" << "Select any of the option given --> "; 
		//		cin.ignore();
		                cin.clear();
                		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                		goto in;

				break;
		}
	}
}
