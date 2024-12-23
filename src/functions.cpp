#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <sys/ioctl.h>
#include <chrono>
#include <thread>

#include "../includes/crypto.h"

using namespace std;

void setPosition(int x, int y){
        string str = "\033[" + to_string(x) + ";" + to_string(y+1) + "H";
        cout << str;
}

void shiftRight(int x){
	string str = "\033[" + to_string(x) + "C";
	cout << str;
}


string alignCenter(const string& text){
	return string(paddingX,' ') + text;
}

void textAnimate(string str){
	for(char ch: str){
		cout << ch << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

vector<string> getOutput(const std::string& message) {
    vector<string> output;
    string command = message;

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "popen() failed!" << std::endl;
        return output;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        output.emplace_back(buffer);
    }

    pclose(pipe);
    return output;
}

std::string centerText(const std::string& text, int width) {
    int len = text.length();
    int padding = (widthX - width) / 2;
    return string(padding > 0 ? padding : 0, ' ') + text;
}

void printSpecial(string command) {

	auto output = getOutput(command);

	size_t maxLength = 0;
   	 for (const auto& line : output) {
        	if (line.length() > maxLength) {
            	maxLength = line.length();
        	}
    	}


    for (const auto& line : output) {
        std::cout << centerText(line,maxLength) << flush;
	this_thread::sleep_for(chrono::milliseconds(77));
    }

}

void printSpecial2(string command) {

        auto output = getOutput(command);

        size_t maxLength = 0;
         for (const auto& line : output) {
                if (line.length() > maxLength) {
                maxLength = line.length();
                }
        }


    for (const auto& line : output) {
        std::cout << centerText(line,maxLength) << flush;
//        this_thread::sleep_for(chrono::milliseconds(77));
    }

}


void typingAnimation(const string& str, int delay){
	for(char ch : str){
		cout << ch << flush;
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

string textAlignJustify(string str){

	istringstream words(str);
	string word;
	string line;
	string output;
	int wordCount = 0;

	while(words >> word){
		if(line.length() + word.length() + 1 > width){
			output += line + "\n" + "\033[" + to_string(paddingX) + "C";
//			shiftRight(paddingX);
			line = word;
		}
		else{
			if(!line.empty())
				line += " ";
			line += word;
		}
		wordCount ++;
	}

	if(!line.empty()){
		output += line;
	}

	return output;
}
void enormousSuccess(){
  system("clear");
  system("toilet -f mono12 -F gay Huge");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay Success");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay You");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay are");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay a gem");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay game");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("toilet -f mono12 -F gay over!");
  this_thread::sleep_for(chrono::milliseconds(700));
  system("cmatrix & sleep 2.5; kill $!");
  variablesReset();
  startUp();
}
void gameOver(){
//	cout << "\033[10;2H";
//	lives = lives -3;
//	variablesUpdate(level, scores, lives);
	system("clear");
	system("toilet -f mono12 -F gay Game");
	this_thread::sleep_for(chrono::milliseconds(700));
	system("toilet -f mono12 -F gay Over");
	this_thread::sleep_for(chrono::milliseconds(700));
	system("toilet -f mono12 -F gay Bye!");
	this_thread::sleep_for(chrono::milliseconds(700));
	startUp();
}
