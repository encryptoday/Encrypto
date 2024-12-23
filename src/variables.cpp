#include "../includes/crypto.h"
#include <string>
#include <sqlite3.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string ans = " ";
string animal = " ";

//struct winsize size;
//ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
//int width = (size.ws_col <= 70) ? size.ws_col : 63;
//int height = (size.ws_row <= 30) ? size.ws_row : 30;

int level = 1;
int scores = 0;
int lives = 7;
int height = 7;
int width = 63;
int widthX = getWidth();
int widthY = getHeight();
int paddingX = (widthX > width) ? (widthX-width)/2 : 0;
string playerName = "Aura Austin";

string developerMsg = "Developed By MMM";

string getAnimal(){

        ifstream fileHandler;
	fileHandler.open("src/animals.txt");

        static bool seeded = false;
        if (!seeded) {
                srand(static_cast<unsigned>(time(nullptr)));
                seeded = true;
        }

        int random = rand() % 14;

        int i = 0;
	if (!fileHandler.is_open()) {
        	cerr << "Error opening file!" << endl;
        	return "moose"; // Return "moose" if file can't be opened
    	}
        while(getline(fileHandler, animal)){
                if(random == i){
                        return animal;
                }
                i++;
        }
	fileHandler.close();
        return "moose";
}


static int callback(void* data, int argc, char** argv, char** azColName){
			int* values = static_cast<int*>(data);
				for(int i=0; i < argc ; i++){
					if(strcmp(azColName[i],"level") == 0)
						level = atoi(argv[i]);
				}
			return 99;
			};

static int callback0(void* data, int argc, char** argv, char** azColName){

		for(int i = 0; i<= argc; i++){
			if(strcmp(azColName[i],"level") == 0)
				level = argv[i] ? atoi(argv[i]) : 1;
			else if(strcmp(azColName[i],"scores") == 0)
				scores = argv[i] ? atoi(argv[i]) : 0;
			else if(strcmp(azColName[i],"lives") == 0)
				lives = argv[i] ? atoi(argv[i]) : 7;
			else
				continue;
		}
	return 0;
}

static int callbackName(void* data, int argc, char** argv, char** azColName){

                for(int i = 0; i<= argc; i++){
                        if(strcmp(azColName[i],"name") == 0)
                                playerName = argv[i]? argv[i] : "Aura Austin";
                }
        return 0;
}


void variablesInit(){
	sqlite3* db;
	sqlite3_open("variables.db", &db);
	string cmd = "CREATE TABLE IF NOT EXISTS variables(id INTEGER NOT NULL PRIMARY KEY, level INT, scores INT, lives INT);";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	cmd = "SELECT level, scores, lives FROM variables";
	const char* data = " " ;
	sqlite3_exec(db, cmd.c_str(), callback0,nullptr, nullptr);
}


void variablesReset(){

	level = 1;
	scores = 0;
	lives = 7;

	variablesUpdate(level, scores, lives);
}

void variablesUpdate(int level, int scores, int lives){

	sqlite3* db;
	sqlite3_open("variables.db",&db);

//	string cmd = "CREATE TABLE IF NOT EXISTS variables(id INTEGER NOT NULL PRIMARY KEY, level INT, scores INT, lives INT);";
//	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	string cmd = "DELETE FROM variables WHERE TRUE";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	cmd = "INSERT INTO variables(level, scores, lives) VALUES(" + to_string(level) + ", " + to_string(scores) + ", " + to_string(lives) +");";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);

	int values[3] = { level, scores, lives };
	cmd = "SELECT level, scores, lives FROM variables;";
	sqlite3_exec(db,cmd.c_str(),callback,values,nullptr);
}

void updateName(){
	sqlite3* db;
	sqlite3_open("variables.db",&db);
	string cmd = "CREATE TABLE IF NOT EXISTS name(id INTEGER NOT NULL PRIMARY KEY, name text);";
	sqlite3_exec(db, cmd.c_str(), nullptr, nullptr, nullptr);
	cmd = "INSERT INTO name(name) VALUES('" + playerName  + "')";
	sqlite3_exec(db, cmd.c_str(), nullptr, nullptr, nullptr);
}
void getName(){
	sqlite3* db;
        sqlite3_open("variables.db",&db);
	string cmd = "SELECT name FROM name ORDER BY id DESC LIMIT 1;";
	const char* data = " " ;
        sqlite3_exec(db, cmd.c_str(), callbackName,nullptr, nullptr);
}
