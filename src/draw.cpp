#include <iostream>
#include "../includes/crypto.h"
#include <string>
#include <thread>
#include <iomanip>
#include <limits>

using namespace std;

void timer() {
	cout << "\033[8;30H";
    int j = 0;
    while (true) {
        for (int i = 1; i <= 60; i++) {
            cout << "Timer: " << setw(2) << setfill('0') << j << " : " << setw(2) << setfill('0') << i << "\033[0m";
            cout.flush();
            system("sleep 1");
        }
        j++;
    }
}

void drawHeader(){
	int row = getHeight();
	string str = "\033["+ to_string(row-1) + ";1H";
	system("clear");
	cout << str << setw(width) << "" ;
	setPosition(1,paddingX);
	for(int row = 1; row <= 3; row++){

		if(row == 1){
			for(int col=1; col<= width; col++)
				cout << "=";
		}

		else if(row == 2){
			printSpecial("banner ENCRYPTO");
//			system("banner ENCRYPTO");
		}
		else{
			cout << "\033[2A";
			shiftRight(paddingX);
			for(int i=1; i <= width-developerMsg.length(); i++)
				cout <<" ";
			cout << "Developed by MMM" << endl;
			shiftRight(paddingX);
			for(int col=1; col<= width; col++)
				cout << "=";
		}
		cout << endl;
	}
	system("sleep 0.5");
}

void drawHeaderNull(){
        int row = getHeight();
        string str = "\033["+ to_string(row-1) + ";1H";
        system("clear");
        cout << str << setw(width) << "" ;
        setPosition(1,paddingX);
        for(int row = 1; row <= 3; row++){

                if(row == 1){
                        for(int col=1; col<= width; col++)
                                cout << "=";
                }

                else if(row == 2){
                        printSpecial2("banner ENCRYPTO");
//                      system("banner ENCRYPTO");
                }
                else{
                        cout << "\033[2A";
                        shiftRight(paddingX);
                        for(int i=1; i <= width-developerMsg.length(); i++)
                                cout <<" ";
                        cout << "Developed by MMM" << endl;
                        shiftRight(paddingX);
                        for(int col=1; col<= width; col++)
                                cout << "=";
                }
                cout << endl;
        }
        system("sleep 0.5");
}


void drawSubHeader(){
//	thread t1(timer);
//	t1.detach();
//	string tab(8," ");

	system("clear");
	for(int i = 1; i <= 3; i++){
		shiftRight(paddingX);
		string str;
//		if(i == 1)
//			str = " ";
		if(i == 1 || i == 3)
			str = "=";
		else{
			cout << setw(8) << "" << "Level : "<< level << setw(8) << "" << "Scores : " << scores << setw(8) << "" << "Lives : " << lives ;
		}
		for(int j=1; j <= width; j++){
			if(i == 2)
				continue;
			cout << str;
		}
	cout << endl;
	}
}

void menuScreen(){
	variablesInit();
	getName();
	if(level == 1)
		printSpecial("cowsay -f moose \" Welcome to encrypto \n 1. Start Game \n 2. How to play \n  3. Highest Scores \n   4. Random Cryptrography Facts\"");
//		system("cowsay \" Welcome to encrypto \n 1. Start Game \n 2. How to play \n  3. Highest Scores \n   4. Random Cryptrography Facts\"");
	else
		printSpecial("cowsay -f moose \" Welcome to encrypto \n 0. Continue Game \n 1. Start Game \n 2. How to play \n  3. Highest Scores \n  4. Random Cryptrography Facts\"");

	system("PS1=\"-->\"");
}

void navigation(){

	int w = getWidth();
	int opt;

	system("PS1=\"-->\"");
	shiftRight(paddingX);
	cout << endl;

	shiftRight(paddingX);
	cout << "0 takes you home and 99 terminates the game --> ";
again:
	cin >> opt;
	if(cin.fail()){
                cout << "\033[1A" << setw(70) << "" << endl;
		shiftRight(paddingX);
		cout << "\033[1A" << "0 takes you home and 99 teminates the game --> ";


                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                goto again;
        }

	else if(opt == 0)
		startUp();
	else if(opt == 99)
		exit;
	else{
		cout << "\033[1A" << setw(w) << "" << endl;
		shiftRight(paddingX);
		cout << "\033[1a" << "0 takes you home and 99 teminates the game --> ";

                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                goto again;

	}
}

void factHeader(string heading){
//      thread t1(timer);
//      t1.detach();
//      string tab(8," ");

        system("clear");
        for(int i = 1; i <= 3; i++){
		shiftRight(paddingX);
                string str;
//                if(i == 1)
//                        str = " ";
                if(i == 1 || i == 3)
                        str = "=";
                else{
                        cout << setw((width - heading.length())/2) << "" << heading ;
                }
                for(int j=1; j <= width; j++){
                        if(i == 2)
                                continue;
                        cout << str;
                }
        cout << endl;
        }
}

void factNavigation(){

	int w = getWidth();
	string option;
	string optionValidated;
	system("PS1=\"-->\"");
	cout << endl;
	cin.clear();
	cin.sync();

	shiftRight(paddingX);

	while(true){
		cout << " Type 'more' for another one or 'home' to go back --> ";
		getline(cin, option);
		if(option == "home"){
			startUp();
			break;
		}
		else if(option == "more"){
			randomFacts();
			break;
		}
		else{
			cout << "\033[1A" << setw(w) << "" << endl;
			shiftRight(paddingX);
			cout << "\033[1A";
			continue;
		}
	}
}
