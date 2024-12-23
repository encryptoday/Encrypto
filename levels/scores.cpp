#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sqlite3.h>
#include <algorithm>
#include "../includes/crypto.h"

using namespace std;

vector<int> hScores = {0,0,0,0,0};

static int callback(void* data, int argc, char** argv, char** azColName){
	for(int i=0; i<argc; i++)
		hScores.push_back(atoi(argv[i]));
	return 0;
}

void displayScores(){
	sqlite3* db;
	if(sqlite3_open("variables.db", &db))
		cout << "not opened";

	string cmd = ("CREATE TABLE IF NOT EXISTS scores(score INT NOT NULL PRIMARY KEY);");
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr, nullptr);

//	cmd = "	DELETE FROM scores WHERE TRUE";
//	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr, nullptr);

//	cmd = "INSERT INTO scores(score) VALUES (0),(0),(0),(0),(0);";
//	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr, nullptr);

	cmd = "SELECT score FROM scores ORDER BY score DESC LIMIT 5;";
	const char* data = "";
	sqlite3_exec(db,cmd.c_str(),callback,(void*) data,nullptr );
	sort(hScores.begin(), hScores.end(),greater<int>());
	string cow = "cowsay -f fox \"Highest Scores \n 1st\t:\t" + to_string(hScores[0]) + "\n 2nd\t:\t " + to_string(hScores[1]) +"\n 3rd\t:\t"+to_string(hScores[2]) + "\n 4th\t:\t"+to_string(hScores[3])+"\n 5th\t:\t"+to_string(hScores[4])+ "\n \"";
	printSpecial(cow);
//	system(cow.c_str());
}

void highestScores(){

	drawSubHeader();
	system("sleep 0.5");
	displayScores();
	navigation();
}

void addScore(int newScore){
	sqlite3* db;
	sqlite3_open("variables.db",&db);

	string cmd = "INSERT INTO scores(score) VALUES (" + to_string(newScore) + ");";
	sqlite3_exec(db, cmd.c_str(),nullptr,nullptr,nullptr);
}
