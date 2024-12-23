#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include "../includes/crypto.h"
#include <fstream>

/*
string getMsg(){
	ifstream file;
	string word;
	string msg;
	file.open("src/wordlist.txt");
	if (!file.is_open()) {
                cerr << "Error opening file!" << endl;
                return "moose"; // Return "moose" if file can't be opened
        }

	static bool seeded = false;

        if (!seeded) {
                srand(static_cast<unsigned>(time(nullptr)));
                seeded = true;
        }

        int random = rand() % 17;

        int i = 0;

	while(getline(file,word)){
		if(i == random){
			return word;
		}
		i++;
	}
	return "helloman";
}
*/

//-------------------------------------- //
//-------------- LEVEL 01 -------------- //
//-------------------------------------- //

string ceaserEnc(){
	string msg = "key is freedom";
	string cipherText;
	string temp;
	int pos;

	for(char& c : msg){

        	if(!isalpha(c))
	        	continue;

        	pos = toupper(c) - 'A' + 3;

        	c = char('A' + pos % 26);

    }
	return msg;
}

string ceaserDec(string cipherText){
	for(char &ch : cipherText){
		if(!isalpha(ch))
			continue;
		ch = char('A' + (toupper(ch) - 'A' - 3 + 26 ) % 26);
	}
	return cipherText;
}


//-------------------------------------- //
//-------------- LEVEL 02 -------------- //
//-------------------------------------- //


string atbashEnc(){
    string str = "Beware of the graveyard";
    for(char& ch: str){
        if(!isspace(ch))
            ch = char('A' + 'Z' - toupper(ch));
    }
    return str;
}
string atbashDec(string cipherText){
    for(char& ch: cipherText){
        if(!isspace(ch))
            ch = char('A' + 'Z' - toupper(ch));
    }
    return cipherText;
}


//-------------------------------------- //
//-------------- LEVEL 05 -------------- //
//-------------------------------------- //


string affineEnc(){
    string str = "in love lies power";
    int x, a = 7, b = 5;

    for(char& ch: str){
        if(isspace(ch))
            continue;
        x = tolower(ch) - 'a';
        ch = toupper(char('a' + (a * x + b) % 26));
    }
    return str;
}

string affineDec(string str){
    int x, a= 7, aInv=15, b = 5;
/*
    while(true){
        if((a*aInv) % 26 == 1)
            break;
        aInv++;
    }
*/
    for(char& ch : str){
        if(isspace(ch))
            continue;
        x = tolower(ch) - 'a';
        ch = char('a' + ((aInv * (x - b + 26) ) % 26));
    }
    return str;
}

//-------------------------------------- //
//-------------- LEVEL 03 -------------- //
//-------------------------------------- //


string bandOfFiveEnc(){

    string str= "numbers follow the truth";
    string temp;
    bool recursing = false;
    int x;
    int counter = 1;

        for(char& ch : str){
            if(isspace(ch))
                continue;

            if(counter <= 5){
                int x = tolower(ch) + counter ;
                int pos = (x - 'a') % 26;
                ch = char('a' + pos);
                counter++;
            }
            else{
                counter = 1;
            }
        }

    return str;
}


string bandOfFiveDec(string cipherText){

    int counter = 1;
    int x, pos;

    for(char& ch : cipherText){
        if(isspace(ch))
                continue;

            if(counter <= 5){
                int x = tolower(ch) - counter ;
                int pos = (x - 'a') % 26;
                ch = char('a' + pos);
                counter++;
            }
            else{
                counter = 1;
            }
    }

    return cipherText;
}


//-------------------------------------- //
//-------------- LEVEL 05 -------------- //
//-------------------------------------- //


string vigenereEnc(){
    string key = "freedom";
    string plainText = "denver doglas hamilton";
    string str;
    int space = 0;

    for(int i =0; i < plainText.length(); i++){
        if(isspace(plainText[i])){
            str += ' ';
            space ++;
            continue;
        }

        if(i - space >= key.length())
            key += key;

        str += char('a' + ((plainText[i] - 'a') + (key[i-space] - 'a')) % 26);

    }

    return str;
}

string vigenereDec(string cipherText){
    string key = "freedom";
    string str;
    int space = 0;

    for(int i =0; i < cipherText.length(); i++){
        if(isspace(cipherText[i])){
            str += ' ';
            space ++;
            continue;
        }

        if(i - space >= key.length())
            key += key;

        str += char('a' + ((cipherText[i] - 'a') - (key[i-space] - 'a') + 26) % 26);

    }
    return str;
}


//-------------------------------------- //
//-------------- LEVEL 06 -------------- //
//-------------------------------------- //


string playFairEnc(){
    string key = "universe";
    string plainText = "buy some roses";
    string plainTextTemp;
    string cipherText;
    string key2;
    bool unique = true;
    int count;
    vector<string> square;
    vector<string> pairs;

    for(char ch: plainText){
        if(isspace(ch))
            continue;
        plainTextTemp += tolower(ch);
    }

    for(char ch : key){
        unique = true;
        count = 0;
        for(char ch2 : key2){
            if(ch == ch2)
                unique = false;
        }
        if(unique)
            key2 += tolower(ch);
    }

    key = key2;

    string temp = key.substr(0,5);
    string temp2 = key.substr(temp.length(),key.length()-temp.length());

    for(int i = 0; i < 26; i++){
        char alpha = char('a' + i);
        unique = true;
        for(char ch : key){
            if(ch == alpha || alpha == 'j')
                unique = false;
        }
        if(unique)
            key += alpha;
    }

//    cout << temp << endl << temp2 << endl;
//    cout << key << key.length() << endl;

    for(int i = 0; i < 5 ; i++)
        square.push_back(key.substr(i*5,5));

//    for(string str: square)
//        cout << str << endl;
//    cout << plainTextTemp << endl;

    string plainText2;
/*
    if(plainTextTemp.length() % 2 != 0){
        plainTextTemp += 'e';
    }
*/
    for(int i = 0; i <= plainTextTemp.length()/2; i++){
            string pairTemp = plainTextTemp.substr(2*i, 2);
            string k ;
            k.clear();
            if(pairTemp[0] == pairTemp[1]){
                k = pairTemp[0];
                pairTemp[1] = 'x';
            }
            for(char& ch: pairTemp){
                if(ch == 'j')
                    ch = 'z';
            }
            plainText2 += pairTemp + k;
    }

    if(plainText2.length() % 2 != 0){
        plainText2 += 'z';
    }

//    cout << plainTextTemp << endl;
//    cout << plainText2 << plainText2.size() << endl;

    int row1, col1, row2, col2;
    int m,n,o,p;
    string encTemp;

    for(int loopIteration = 0; loopIteration < (plainText2.length()/2); loopIteration++){
        string pair = plainText2.substr(loopIteration*2,2);
        for(int i=0; i < square.size(); i++){
            string line = square[i];
            string temp ;
            for(int j=0; j < 5 ; j++){
                if(pair[0] == line[j]){
                    row1 = i;
                    col1 = j;
                }
                if(pair[1] == line[j]){
                    row2 = i;
                    col2 = j;
                }
            }
//            cout << endl;
        }

        if(row1 == row2){
            m = row1;
            o = row2;
            n = (col1 == 4) ? 0 : col1 + 1;
            p = (col2 == 4) ? 0 : col2 + 1;
        }
        else if(col1 == col2){
            n = col1;
            p = col2;
            m = (row1 == 4) ? 0 : row1 + 1;
            o = (row2 == 4) ? 0 : row2 + 1;
        }
        else{
            m = row1;
            n = col2;
            o = row2;
            p = col1;
        }
//        encTemp += square[m][n] + square[o][p];

            for (size_t i = 0; i < square.size(); ++i) {
                for (size_t j = 0; j < square[i].size(); ++j) {
                    if(i == m && j == n){
                        encTemp += square[i][j];
                    }
                }
            }

            for (size_t i = 0; i < square.size(); ++i) {
                for (size_t j = 0; j < square[i].size(); ++j) {
                    if(i == o && j == p){
                        encTemp += square[i][j];
                    }
                }
            }

//        cout << row1 << col1 << row2 << col2;
//        cout << encTemp << m << n << o << p;
    }
	for(char ch : encTemp)
		cipherText += toupper(ch);
	return cipherText;
}

string playFairDec(string cipherText){

    string key = "universe";
    string plainText;
    string plainTextTemp;
    string key2;
    bool unique = true;
    int count;
    vector<string> square;
    vector<string> pairs;

    for(char& ch: cipherText){
        ch = tolower(ch);
    }

    for(char ch : key){
        unique = true;
        count = 0;
        for(char ch2 : key2){
            if(ch == ch2)
                unique = false;
        }
        if(unique)
            key2 += tolower(ch);
    }

    key = key2;

    string temp = key.substr(0,5);
    string temp2 = key.substr(temp.length(),key.length()-temp.length());

    for(int i = 0; i < 26; i++){
        char alpha = char('a' + i);
        unique = true;
        for(char ch : key){
            if(ch == alpha || alpha == 'j')
                unique = false;
        }
        if(unique)
            key += alpha;
    }
//    cout << temp << endl << temp2 << endl;
//    cout << key << key.length() << endl;

    for(int i = 0; i < 5 ; i++)
        square.push_back(key.substr(i*5,5));

//    for(string str: square)
//        cout << str << endl;
//    cout << plainTextTemp << endl;


    int row1, col1, row2, col2;
    int m,n,o,p;
    string encTemp;

    for(int loopIteration = 0; loopIteration < (cipherText.length()/2); loopIteration++){
        string pair = cipherText.substr(loopIteration*2,2);
        for(int i=0; i < square.size(); i++){
            string line = square[i];
            string temp ;
            for(int j=0; j < 5 ; j++){
                if(pair[0] == line[j]){
                    row1 = i;
                    col1 = j;
                }
                if(pair[1] == line[j]){
                    row2 = i;
                    col2 = j;
                }
            }
//            cout << endl;
        }

        if(row1 == row2){
            m = row1;
            o = row2;
            n = (col1 == 0) ? 4 : col1 - 1;
            p = (col2 == 0) ? 4 : col2 - 1;
        }
        else if(col1 == col2){
            n = col1;
            p = col2;
            m = (row1 == 0) ? 4 : row1 - 1;
            o = (row2 == 0) ? 4 : row2 - 1;
        }
        else{
            m = row1;
            n = col2;
            o = row2;
            p = col1;
        }
//        encTemp += square[m][n] + square[o][p];

            for (size_t i = 0; i < square.size(); ++i) {
                for (size_t j = 0; j < square[i].size(); ++j) {
                    if(i == m && j == n){
                        plainText += square[i][j];
                    }
                }
            }

            for (size_t i = 0; i < square.size(); ++i) {
                for (size_t j = 0; j < square[i].size(); ++j) {
                    if(i == o && j == p){
                        plainText += square[i][j];
                    }
                }
            }

//        cout << row1 << col1 << row2 << col2;
//        cout << encTemp << m << n << o << p;
    }
    plainText.insert(3,1,' ');
    plainText.insert(8,1,' ');
    return plainText;

}


//-------------------------------------- //
//-------------- LEVEL 07 -------------- //
//-------------------------------------- //


string hillEnc() {
    string plainText = "enigma";
    string key = "gybnqkurp";
    string cipherText;
    string temp;
    int matrixK[3][3], result[3][1] = {0}, result2[3][1] = {0};
    int matrixM1[3] = {0}, matrixM2[3] = {0};
    int k = 0, l = 0;

    string block1 = plainText.substr(0, 3);
    string block2 = plainText.substr(3, 3);

    for (char ch : block1) {
        matrixM1[l++] = ch - 'a';
    }
    l = 0;
    for (char ch : block2) {
        matrixM2[l++] = ch - 'a';
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrixK[i][j] = key[k++] - 'a';
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrixK[i][k] * matrixM1[k];
                result2[i][j] += matrixK[i][k] * matrixM2[k];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cipherText += char('a' + result[i][0] % 26);
    }
    for (int i = 0; i < 3; i++) {
        cipherText += char('a' + result2[i][0] % 26);
    }

    for (char &ch : cipherText) {
        ch = toupper(ch);
    }

    return cipherText;
}

string hillDec(string cipherText) {
    int kInv[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    int matrixM1[3] = {0}, matrixM2[3] = {0};
    int result[3][1] = {0}, result2[3][1] = {0};
    int l = 0;

    for (char &ch : cipherText) {
        ch = tolower(ch);
    }

    string block1 = cipherText.substr(0, 3);
    string block2 = cipherText.substr(3, 3);
    string plainText;

    for (char ch : block1) {
        matrixM1[l++] = ch - 'a';
    }
    l = 0;
    for (char ch : block2) {
        matrixM2[l++] = ch - 'a';
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += kInv[i][k] * matrixM1[k];
                result2[i][j] += kInv[i][k] * matrixM2[k];
            }
        }
    }


    for (int i = 0; i < 3; i++) {
        plainText += char('a' + result[i][0] % 26);
    }
    for (int i = 0; i < 3; i++) {
        plainText += char('a' + result2[i][0] % 26);
    }

    return plainText;
}

//-------------------------------------- //
//-------------- LEVEL 07 -------------- //
//-------------------------------------- //


string columnarEnc(){

    string key = "cuba";
    string key2 = key;
    string plainText = "the end is near!";
    string cipherText;
    vector<string> grid;

    for(int i = 0; i < plainText.length()/key.length(); ++i){
        string row = plainText.substr(i*key.length(),key.length());
        grid.push_back(row);
    }

    for(string& str: grid){
        for(char& ch : str){
            if(isspace(ch)){
                ch = '_';
            }
        }
    }

    for(int i = 0; i < key2.length() ; i++){
        char shortChar = 'z';
        int pos;
        for(int i = 0; i < key2.length() ; i++){
            if(key2[i] < shortChar){
                shortChar = key2[i];
                pos = i;
            }
        }

        key2[pos] = '~';
        for(string row: grid){
            cipherText += row[pos];
        }
    }

    for(char& ch : cipherText)
        ch = toupper(ch);

    return cipherText;
}

string columnarDec(string cipherText){
    string key = "cuba";
    string key2 = key;
    string plainText;
    vector<string> grid;
    vector<string> temp;

    for(int i = 0; i < cipherText.length()/key.length(); ++i){
        string row = cipherText.substr(i*key.length(),key.length());
        grid.push_back(row);
    }

    temp.push_back(grid[2]);
    temp.push_back(grid[3]);
    temp.push_back(grid[1]);
    temp.push_back(grid[0]);

        for(int i = 0; i < key.length() ; i++){
            for(string str: temp){
                plainText += str[i];
            }
        }
	for(char& ch : plainText){
		ch = tolower(ch);
		if(!isalpha(ch))
			ch = ' ';
	}
	plainText.erase(plainText.length()-1,1);
    	return plainText;
}

//-------------------------------------- //
//-------------- LEVEL 04 -------------- //
//-------------------------------------- //


string polybiusSquareEnc(){
    string plainText = "land of spice";
    char grid[5][5];
    int charCount = 0;
    string cipherText;

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(char('a' + charCount) == 'j')
                charCount++;

            grid[i][j] = char('a' + charCount);
            charCount ++;
        }
    }

    for(char ch: plainText){
        if(isspace(ch))
            continue;
        for(int i=0; i < 5; i++){
            for(int j=0; j < 5; j++){
                if(grid[i][j] == ch || (ch == 'j' && grid[i][j] == ch))
                    cipherText += to_string(i+1) + to_string(j+1);
            }
        }
    }
    return cipherText;
}

string polybiusSquareDec(string cipherText){
    string plainText;
    char grid[5][5];
    int charCount = 0;

    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(char('a' + charCount) == 'j')
                charCount++;

            grid[i][j] = char('a' + charCount);
            charCount ++;
        }
    }

    int counter = 0;

    for(int i = 0; i < cipherText.length() ; i = i + 2){

        if(isspace(cipherText[i]) || isspace(cipherText[i+1])){
            continue;
        }

        int row =  stoi(string(1,cipherText[i])) - 1;
        int col = stoi(string(1,cipherText[i + 1])) - 1;

        for(int i=0; i < 5; i++){
            for(int j=0; j < 5; j++){
                if(i == row && j == col)
                    plainText += grid[row][col];
            }
        }
    }
	plainText.insert(4,1,' ');
	plainText.insert(7,1,' ');
    	return plainText;
}


//-------------------------------------- //
//-------------- LEVEL 6 -------------- //
//-------------------------------------- //


string kamasutraEnc(){
    string plainText = "Long as eyes shall see";
    string temp ;
    string cipherText;
    int fibonacci[13];
    int pairs[13][2];

    memset(pairs,0,sizeof(pairs));
    memset(fibonacci,-1,sizeof(fibonacci));
    for(char ch : plainText){
        if(isspace(ch))
            continue;
        temp += tolower(ch);
    }
    int inserted = 0;
    int a = 0;
    int b = 1;
    fibonacci[0] = 0;
    int iter = 1;
    while(iter != 13){
        int c = a + b;
        int x = c % 26;
        bool duplicate = false;
        for(int i = 0; i < 26; i++){
            if(x == fibonacci[i] ){
                duplicate = true;
                break;
            }
        }
        if(!duplicate){
            fibonacci[iter] = x;
            iter ++;
        }
        a = b;
        b = c;
        inserted ++;
    }

    string alphabets="11111111111111111111111111";

   // memset(alphabets,'1',sizeof(alphabets));

    for(int i = 0; i < 13; i++)
        alphabets[2*i]= char('a' + fibonacci[i]);

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 26; j++){
            if(alphabets.find(string(1, char('a' + j))) == std::string::npos){
                alphabets[2*i + 1] = char('a' + j);
                goto endhere;
            }
        }
endhere: ;
    }

    for(char ch : plainText){
        if(isspace(ch)){
            cipherText += ' ';
        }
        else{
            for(int i=0; i < 26; i++){
                if(tolower(ch) == alphabets[i]){
                    if(i % 2 == 0)
                        cipherText += alphabets[i + 1];
                    else
                        cipherText += alphabets[i - 1];
                    break;
                }
            }
        }
    }
	for(char& ch: cipherText)
		ch = toupper(ch);

    return cipherText;
}

string kamasutraDec(string cipherText){
    string plainText;
    string temp ;
    int fibonacci[13];
    int pairs[13][2];

    memset(pairs,0,sizeof(pairs));
    memset(fibonacci,-1,sizeof(fibonacci));
    for(char ch : plainText){
        if(isspace(ch))
            continue;
        temp += tolower(ch);
    }
    int inserted = 0;
    int a = 0;
    int b = 1;
    fibonacci[0] = 0;
    int iter = 1;
    while(iter != 13){
        int c = a + b;
        int x = c % 26;
        bool duplicate = false;
        for(int i = 0; i < 26; i++){
            if(x == fibonacci[i] ){
                duplicate = true;
                break;
            }
        }
        if(!duplicate){
            fibonacci[iter] = x;
            iter ++;
        }
        a = b;
        b = c;
        inserted ++;
    }

    string alphabets="11111111111111111111111111";

   // memset(alphabets,'1',sizeof(alphabets));

    for(int i = 0; i < 13; i++)
        alphabets[2*i]= char('a' + fibonacci[i]);

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 26; j++){
            if(alphabets.find(string(1, char('a' + j))) == std::string::npos){
                alphabets[2*i + 1] = char('a' + j);
                goto endhere;
            }
        }
endhere: ;
    }
    for(char ch : cipherText){
        if(isspace(ch)){
            plainText += ' ';
        }
        else{
            for(int i=0; i < 26; i++){
                if(tolower(ch) == alphabets[i]){
                    if(i % 2 == 0)
                        plainText += alphabets[i + 1];
                    else
                        plainText += alphabets[i - 1];
                    break;
                }
            }
        }
    }

    return plainText;
}


//-------------------------------------- //
//-------------- LEVEL 11 -------------- //
//-------------------------------------- //


string autokeyEnc(){
    string key = "maths";
    string plainText = "save the world";
    string str;
    string cipherText;
    int space = 0;

    for(char ch: plainText){
        if(isspace(ch))
            continue;
        else
            str += ch;
    }

    key += str.substr(0,str.length()-key.length());

    for(int i=0; i < key.length(); i++){
        cipherText += char('a' + ((key[i] - 'a') + (str[i] - 'a')) % 26);
    }

    for(int i=0; i < plainText.length(); i++){
        if(isspace(plainText[i])){
            cipherText.insert(i,1,' ');
        }
    }
	for(char& ch : cipherText)
		ch = toupper(ch);
    return cipherText;
}

string autokeyDec(string cipherText){
    string key = "maths";
    string plainTextCache = "save the world";
    string plainText;
    string str;
    int space = 0;

    for(char ch: plainTextCache){
        if(isspace(ch))
            continue;
        else
            str += ch;
    }

    key += str.substr(0,str.length()-key.length());

    str.clear();

    for(char ch: cipherText){
        if(isspace(ch))
            continue;
        else
            str += tolower(ch);
    }

    for(int i=0; i < key.length(); i++){
        plainText += char('a' + ((str[i] - 'a') - (key[i] - 'a') + 26) % 26);
    }

    for(int i=0; i < cipherText.length(); i++){
        if(isspace(cipherText[i])){
            plainText.insert(i,1,' ');
        }
    }
    return plainText;
}
