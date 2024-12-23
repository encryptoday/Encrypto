#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "../includes/crypto.h"

using namespace std;

void beautifyText(string str){

	int charCount = 0, i = 0;
	bool addSingleBreak = false;
	bool addDoubleBreak = false;

	for(char ch : str){
		if(addSingleBreak){
                	cout << endl;
			shiftRight(paddingX);
			cout << setw(4) << "";
			addSingleBreak = false;
		}
		if(addDoubleBreak){
			cout << endl << endl;
			shiftRight(paddingX);
			cout << " ";
			addDoubleBreak = false;
		}

                if(charCount >= (width-4) && isspace(ch)){
			addSingleBreak = true;
                        charCount = 0;
                }
		if(ch == '.'){
			addDoubleBreak = true;
			charCount = 0;
		}
		if(charCount  == 0){
			shiftRight(paddingX);
			cout << " ";
		}
		if(ch != '.')
	                cout << ch << flush;
		this_thread::sleep_for(chrono::milliseconds(20));
                charCount ++;
        }

}

void instructions(){
	string heading = "How to play encrypto";
	factHeader(heading);
	ifstream file;
	string str, bodyText;

	file.open("src/instructions.txt");
	if(!file.is_open())
		cout << "Could not open file ! " << endl;

	int line = 1;
	while(getline(file,str)){
		if(line == 1)
			bodyText += str;
		line++;
	}
	file.close();
/*	bool paragraphing = false;
	bool done = false;
	int charCount = 0, i = 1;

	for(char ch : bodyText){
		if(charCount == 0){
			cout << endl << endl;
			shiftRight(paddingX);
			cout << " ";
		}
                if(charCount >= i*(width-2) && isspace(ch)){
                        cout << endl;
			shiftRight(paddingX);
                        if(!isspace(ch))
                                cout << " ";
                        i++;
                }
                cout << ch << flush;
		this_thread::sleep_for(chrono::milliseconds(20));
                charCount ++;
        }

        cout << endl << endl << endl;
*/
	shiftRight(paddingX);
	bodyText = textAlignJustify(bodyText);
	cout << endl;
	shiftRight(paddingX);
	typingAnimation(bodyText, 30);

	file.open("src/instructions.txt");
	line = 1;
	string newText;
	while(getline(file,str)){
		if(line != 1)
			newText = newText + str;
		line++;
	}

//	cout << newText;
//	file.close();
	cout << endl << endl << endl;
//	shiftRight(paddingX);
	beautifyText(newText);
/*	string temp;
	newText = textAlignJustify(newText);
	cout << endl << endl << endl;
	for(char ch: newText){
		if(ch == '.')
			temp += "\n\n";
		else
			temp += ch;
	}
	newText = temp;
	shiftRight(paddingX);
        typingAnimation(newText, 30);
*/
        system("sleep 0.3");
	cout << endl << endl << endl;
	navigation();
}
