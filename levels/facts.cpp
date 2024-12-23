#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <thread>
#include <chrono>

#include "../includes/crypto.h"

void randomFacts(){

    string str;

    ifstream file;
    file.open("src/facts.txt");
    if(!file.is_open())
        cout << "file opening failed" << endl;

    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 30;
    int headingNumber = 0;

    string headingText, bodyText;

    while(getline(file,str)){
        if(headingNumber == random + 1 && str[0] != '#')
            bodyText += str;

        if(str[0] == '#'){

            if(headingNumber == random){
                int pos = 0;
                int length = 0;
                for(char ch : str){
                    if(pos >= 5)
                        headingText += ch;
                    pos ++;
                }
            }

            if(headingNumber == random + 1)
                break;
            headingNumber ++;
        }

    }
//cout << headingText << bodyText;

	factHeader(headingText);
	system("sleep 0.3");
	int charCount = 0, i = 0;
	bool paragraphing = false, done = false, space=false;
	cout << endl;
/*	for(char ch : bodyText){
		if(ch == '\n')
			continue;
		if(paragraphing && !done){
			cout << endl << endl;
			shiftRight(paddingX);
			paragraphing = false;
			done = true;
			charCount = 0;
			i = 0;
		}

		if(charCount > 360 && ch == '.' && !paragraphing && !done)
			paragraphing = true;

		if(charCount == i*(width-1)){
			cout << endl;
			shiftRight(paddingX);
			if(isspace(ch))
				space = true;
			i++;
		}
//		if(!space){
	    		cout << ch << flush;
//			space = false;
//		}
		this_thread::sleep_for(chrono::milliseconds(30));
		charCount ++;
	}
*/
	int x;
//        bodyText = textAlignJustify(bodyText);
/*	for(char& ch : bodyText){
		if(x == 100){
			ch = '\n';
			x = 101;
		}
		if(paragraphing && !done){
                        ch = '\n';
                        paragraphing = false;
                        done = true;
			x = 100;
                }
		if(charCount > 360 && ch == '.' && !paragraphing)
                        paragraphing = true;
		charCount ++;
	}
*/
	charCount = 0;
	string temp;
	for(char ch:bodyText){
		if(ch == '.' && charCount >= 300){
			temp = bodyText.substr(0,charCount+1);
			break;
		}
	charCount ++;
	}
	string temp2 = bodyText.substr(charCount+2, bodyText.length()-(charCount+2));

   	shiftRight(paddingX);
        typingAnimation(textAlignJustify(temp), 30);
	cout << endl << endl;

	shiftRight(paddingX);
	typingAnimation(textAlignJustify(temp2),30);

	cout << endl << endl << endl;
	system("sleep 0.3");
	factNavigation();
}
