#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "../includes/crypto.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <thread>
#include <iomanip>

int getHeight(){
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	return(size.ws_row);
}

int getWidth(){
        struct winsize size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
        return(size.ws_col);
}

void clearScreen(){

	int row = getHeight();
	int col = getWidth();

	cout << "\033["+to_string(row-2)+";1H";
	for(int l = 1; l <= 2; l++){
	        for(int i=0;i<col; i++)
        	        cout << " ";
	}
//	if(str == nullptr)
//	else{
//	        str = str + "\033[" + to_string(row-1) + ";" + to_string(paddingX) + "H" + str +  " --> ";
//		textAnimate(str);
//	}
}

int rows;
int hintCount = 0;


//string displayHints1(int i){
//	return hints[i];
//}

string getFeedback(){
	vector<string> feedbacks={"Oops! That’s a nutty answer. Try again!","Close, but no banana! Give it another shot!","Well, that answer took a wrong turn! Try again!","That’s surprising! Want to try another?","Hmm, that’s a wobbly answer. Let’s balance it!"};
	srand(time(0));
	int random = rand() % 5;
	return feedbacks[random];
}

void levels(int level){

	drawSubHeader();
	system("sleep 1");

	int row = getHeight();
	int col = getWidth();
	int above = 8;
	hintCount = 0;
	string cowsay;
	string cowsayAnimal;
	string intro = " Decode the following cipher ";
	string cipherText;
	string plainText;
	vector<string> hints;

	switch(level){
		case 1:
			cowsayAnimal = "gnu";
			cipherText= ceaserEnc();
			plainText = ceaserDec(cipherText);
			hints = {"This cipher shifts each letter by a fixed number","The simplest way to ‘move’ letters in the alphabet.", "Shift each letter back by three positions."};
			break;
		case 2:
			cowsayAnimal = "ghostbusters";
			cipherText = atbashEnc();
			plainText = atbashDec(cipherText);
			hints = {"Think of the alphabet as a reflection","This cipher works by mirroring the alphabet","Change each letter to its opposite alphabet (A=Z, B=Y)"};
			break;
		case 3:
			cowsayAnimal = "stimpy";
			cipherText = bandOfFiveEnc();
			plainText = bandOfFiveDec(cipherText);
			hints = {"letters are substituted with a repeating pattern of shifts","Shifts restart after every five letters","Shift the first letter by 1, second by 2 and Repeat."};
			break;
		case 4:
				cowsayAnimal = "stegosaurus";
				cipherText = polybiusSquareEnc();
				plainText = polybiusSquareDec(cipherText);
				hints = {"Each letter has a unique coordinate in grid system.","Assign each letter a pair of numbers based on its position.","Match each pair of numbers to letters on the 5x5 grid."};
				break;
		case 5:
					cowsayAnimal = "ren";
					cipherText = affineEnc();
					plainText = affineDec(cipherText);
					hints = {"Remember, multiplication and addition can change letters","Encripted with E(x) = (a * x + b) mod 26. Find key(a, b)","Decrypt with D(x) = (a^-1 * (x - b)) mod 26"};
					break;
		case 6:
					cowsayAnimal = "kiss";
					cipherText = kamasutraEnc();
					plainText = kamasutraDec(cipherText);
					hints = {"Characters swap positions in pairs.","Use Fibonacci series to create fist 13 elements of pairs","Assign remaining alphabets in ordered sequence."};
					break;
		case 7:
						cowsayAnimal = "turtle";
						cipherText = columnarEnc();
						plainText = columnarDec(cipherText);
						hints = {"This encryption uses grids to cipher letters","Look for clues that might indicate the length of the keyword","Experiment with different column orders"};
						break;
		case 8:
			cowsayAnimal = "kangaroo";
			cipherText = vigenereEnc();
			plainText  = vigenereDec(cipherText);
			hints = {"This cipher uses a keyword for substitution","Try to decipher using frequency analysis","The key was delivered to you in last message"};
			break;
		case 9:
			cowsayAnimal = "snowman";
			cipherText = playFairEnc();
			plainText = playFairDec(cipherText);
			hints = {"This cipher encrypts letters in pairs using a grid system","Find key and change their positions in the 5x5 grid.","For same row, shift left. Column, shift up. Rectangle, swap corners"};
			break;
		case 10:
				cowsayAnimal = "turkey";
				cipherText = autokeyEnc();
				plainText = autokeyDec(cipherText);
				hints = {"This is a modification of a previous cipher with extended key","The key has same length as the message","Shift the letters according to the key"};
				break;

		case 11:
			cowsayAnimal = "dragon";
			cipherText = hillEnc();
			plainText = hillDec(cipherText);
			hints = {"Identify 3x3 key matrix","The letters are transformed using matrix multiplication","Key is of length 9, given in the instruction."};
			break;




	}

	for(char& ch: cipherText)
		ch = toupper(ch);

	cowsay = "cowsay -f " + cowsayAnimal + " \""+intro+ " \n  \033[1m "+ std::string(((intro.length()-cipherText.length())/2)-2, '*') +"  " + cipherText + "  " + std::string(((intro.length()-cipherText.length())/2)-2,'*') + " \033[0m \n  \"";
	cout << endl;
	printSpecial(cowsay);
//	system(cowsay.c_str());

//	thread t1(timer);
//	t1.detach();
//	cin.ignore();
	string hintFirst = "\033[" + to_string(row-above) + ";" + to_string(paddingX) + "H" +  "Hint " + to_string(hintCount+1) + " : " + hints[hintCount];
	shiftRight(paddingX);
	textAnimate(hintFirst);
//	cout << "\033[" +to_string(row-above)+";2H" << "Hint " << hintCount+1 << " : "<< displayHints1(hintCount) << endl;

	string input = "\033[" + to_string(row) + ";" + to_string(paddingX) + "H";
	string instruction = "\033[" + to_string(row-1) + ";" + to_string(paddingX)  + "H";
	cout << instruction;
//	cout << "Instruction : "  << "Type hint for another hint" << endl;
//	cout << input;

	cout << "Type 'hint' for another clue --> ";
last:

	getline(cin,ans);
	gameType = 1;
	for(char& ch : ans)
		ch = toupper(ch);
	for(char& ch : plainText)
		ch = toupper(ch);

	if(ans == plainText)
		levelUp(100-25*hintCount);
	else if(ans == "HINT"){
		if(hintCount == 2){
			string temp = "\033[" + to_string(row-4) + ";"+to_string(paddingX)+"H";
			cout << temp << "Warning : No more hints remaining ";
			string feedback = "You are on your own now";
			clearScreen();
		        feedback = "\033["+to_string(row-1)+";" + to_string(paddingX)  + "H" + feedback + " --> ";
			textAnimate(feedback);
			goto last;
		}
		else{
			hintCount ++;
			above --;
			string temp = "\033[" + to_string(row-above) + ";"+to_string(paddingX)+"H";
			temp = temp + "Hint " + to_string(hintCount+1) + " : " + hints[hintCount];

			clearScreen();
			textAnimate(temp);
		        cout << "\033["+to_string(row-1)+";" + to_string(paddingX)  + "H" << "Type 'hint' for another clue --> ";
	                goto last;

		}
	}
	else{
		lives --;
		cout << "\033[2;" + to_string(paddingX + 53) + "H" << setw(6) << "" << "\033[5D" << lives;

		string feedback = getFeedback();

		if(lives == 1)
			feedback = "This is your last chance. Decipher or Die";
		clearScreen();
	        feedback += " --> ";
		cout << "\033["+to_string(row-1)+";" + to_string(paddingX) + "H";

		if(lives == 0)
			gameOver();

		for(char ch: feedback){
			cout << ch << flush;
			this_thread::sleep_for(chrono::milliseconds(45));
		}

/*		cout << "\033["+to_string(row-1)+";2H";
                for(int i=0;i<width; i++)
                     cout << " ";
                cout << "\033["+to_string(row-1)+";2H" << feedback << " --> ";
*/
		if(lives > 0)
	              goto last;
	}
}
