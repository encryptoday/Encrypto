#include <iostream>
#include <string>
#include <unordered_set>
#include <sqlite3.h>

#include "../includes/crypto.h"

using namespace std;

//string playerName;

void newGame(int level){
	if(level == 1){
start:
		string blank;
		system("clear");
		drawHeaderNull();
		string str= "In the near future, privacy is on the verge of extinction. One day, a whistleblower from a major tech company leaks information about Project Epsilon, a classified program to intercept and decrypt all communications.";
		string str2 = "You're a young cryptographer with a passion for digital rights, receive an encrypted message from an anonymous source. Decrypting this message will change your live forever!";

		str = textAlignJustify(str);
		str2 = textAlignJustify(str2);

		cout << endl << endl;
		shiftRight(paddingX);
		typingAnimation(str,40);

		cout << endl << endl;
		shiftRight(paddingX);
		typingAnimation(str2,40);

		cout << endl << endl << endl;
		shiftRight(paddingX);
		textAnimate("Type in your name to continue --> ");
		cin.ignore();
		getline(cin,playerName);

		bool capitalise = false;
		int charCount = 0;

	        for(char& ch: playerName){
                	if(charCount == 0 || capitalise){
				ch = toupper(ch);
				capitalise = false;
			}
			else
				ch = tolower(ch);
			if(isspace(ch))
				capitalise = true;
        		charCount++;
		}

		if(playerName.empty())
			goto start;
		else
			updateName();
	}
	if(level == 12)
		enormousSuccess();
	system("cmatrix & sleep 2.5; kill $!");
//	levels(level);
	storyLine();

//	levels(level);
//	loadLevel(level);
}

void levelUp(int score){
	scores += score;
	level++;
	lives += 3;
	variablesUpdate(level, scores, lives);
	addScore(scores);
	system("./includes/sl");
	newGame(level);
}
