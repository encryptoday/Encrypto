#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>

using namespace std;

void installPackages();
void drawHeader();
void drawHeaderNull();
void drawSubHeader();
void randomFacts();
void factNavigation();
void instructions();
void factHeader(string heading);
void menuScreen();
void newGame(int level);
void loadLevel(int level);
void levels(int level);
void levelUp(int score);
void variablesReset();
void variablesInit();
void variablesUpdate(int level, int scores, int lives);
void highestScores();
void addScore(int newScore);
void navigation();
void startUp();
void timer();
void gameOver();
int getHeight();
int getWidth();
void setPosition(int x, int y);
void shiftRight(int x);
void printSpecial(const string command);
void printSpecial2(const string command);
void textAnimate(string str);
void storyLine();
void typingAnimation(const string& str, int delay);
void updateName();
void getName();
void enormousSuccess();

string getAnimal();
string ceaserEnc();
string ceaserDec(string cipherText);
string atbashEnc();
string atbashDec(string cipherText);
string affineEnc();
string affineDec(string cipherText);
string bandOfFiveEnc();
string bandOfFiveDec(string cipherText);
string vigenereEnc();
string vigenereDec(string cipherText);
string playFairEnc();
string playFairDec(string cipherText);
string hillEnc();
string hillDec(string cipherText);
string columnarEnc();
string columnarDec(string cipherText);
string polybiusSquareEnc();
string polybiusSquareDec(string cipherText);
string kamasutraEnc();
string kamasutraDec(string cipherText);
string autokeyEnc();
string autokeyDec(string cipherText);
string alignCenter(const string& text);
string textAlignJustify(string str);

extern int paddingX;
extern int level;
extern int scores;
extern int lives;
extern int width;
extern int height;
extern int widthX;
extern int widthY;
extern int gameType;
extern string ans;
extern string developerMsg;
extern string animal;
extern string playerName;

#endif
