```
				===============================================================
				# # # #  #    #   ####   #####     #   #  #####   #####   #####
				#        ##   #  #    #  #    #    #   #  #    #    #    #    #
				#####    # #  #  #       #    #      #    #    #    #    #    #
				#        #  # #  #       #####       #    #####     #    #    #
				#        #   ##  #    #  #    #      #    #         #    #    #
				#######  #    #   ####   #    #      #    #         #    ## # #   
						      A Terminal-Based Cryptography Puzzle Game    
				===============================================================
				      
				
				
				
				 _______________________________________________
				/ Developer: Md. Masum Miah                     \
				| Programming Language: C++, Bash Scripting      |
				| Operating System: Linux 		         |
				\ Database: SQLite3                      	 /
				 -----------------------------------------------
				   \
				    \                                  ___-------___
				     \                             _-~~             ~~-_
				      \                         _-~                    /~-_
					     /^\__/^\         /~  \                   /    \
					   /|  O|| O|        /      \_______________/        \
					  | |___||__|      /       /                \          \
					  |          \    /      /                    \          \
					  |   (_______) /______/                        \_________ \
					  |         / /         \                      /            \
					   \         \^\\         \                  /               \     /
					     \         ||           \______________/      _-_       //\__//
					       \       ||------_-~~-_ ------------- \ --/~   ~\    || __/
						 ~-----||====/~     |==================|       |/~~~~~
						  (_(__/  ./     /                    \_\      \.
							 (_(___/                         \_____)_)


```



# 1. Introduction

Encrypto is a cryptography-based puzzle game designed to engage users in learning about classical encryption techniques. Built in C++ for high performance and optimized for Linux, Encrypto provides an immersive, educational experience where players attempt to solve puzzles by deciphering encoded messages. The game utilizes a series of historical cryptographic methods, presenting players with an interactive storyline that introduces cryptography with challenges that grow progressively more difficult.

## Motivation

C++ was chosen for this project due to its speed and object-oriented capabilities, making it ideal for a game requiring rapid data processing, real-time feedback, and a smooth user experience. Linux was selected as the platform because it aligns with the open-source ethos and as a global knowledge sharing platform. Having used Linux for over eight years, this project also serves as a personal contribution to the Linux community, reflecting both expertise and support for the open-source movement.


# 2. Game Structure and User Interface

After launching Encrypto, players are presented with a main menu featuring following options:

0. Continue Game 
1. New Game
2. How to Play
3. Highest Scores
4. Random Cryptographic Facts 



## 2.1 Game Flow and Progression

New Game: The player begins with a storyline introduction (visible only at level one), entering their name to personalize the experience. Encrypto remembers the player’s name by inserting into a database, creating a tailored interaction throughout gameplay.

Continue Game: This option becomes available only after completing the first level, allowing players to resume from their previous level.  
  
Highest Scores: Displays the player’s best scores stored in an SQLite3 database, fostering a competitive element and tracking progress.
```
                              _______________________________
                             /  Welcome to encrypto          \
                             |                               |
                             | 0. Continue Game              |
                             |                               |
                             | 1. Start Game                 |
                             |                               |
                             | 2. How to play                |
                             |                               |
                             | 3. Highest Scores             |
                             |                               |
                             \ 4. Random Cryptrography Facts /
                              -------------------------------
                               \
                                \   \_\_    _/_/
                                 \      \__/
                                        (oo)\_______
                                        (__)\       )\/\
                                             ||----w |
                                             ||     ||

```
Random Cryptographic Facts: Displays cryptographic from a local text file, providing educational snippets about cryptography's history and real-world applications.

How to Play: Details the game rules and objectives, instructing players on gameplay mechanics. This information is fetched from a text file within the game directory.


# 3. Gameplay Mechanics and Scoring

In Encrypto, each level challenges the player to decrypt a cipher text using hints, logical deduction, and knowledge of cryptographic methods. The core mechanics include:

Hints: Three hints are available per level to help players in deciphering the code. However, each hint incurs a 25% deduction from the total score for that level (out of 100 points).

Feedback Mechanism: Incorrect answers prompt feedback to guide the player. After submitting the correct answer, the game displays a celebratory animation with ASCII art, adding a dynamic touch to the experience.

Lives System: Players have seven attempts to decode each level’s cipher. Upon exhausting their lives, the game ends, and the player returns to the main menu.

## 3.1 Levels and Encryption Algorithms

Encrypto includes 11 levels, each employing a different encryption algorithm, ordered by difficulty:

1. Caesar Cipher  
2. Atbash Cipher  
3. Band of Five  
4. Polybius Square Cipher  
5. Affine Cipher  
6. Kamasutra Cipher  
7. Columnar Transposition Cipher  
8. Playfair Cipher  
9. Autokey Cipher  
10. Hill Cipher  
11. Final Custom Cipher Challenge

Each cipher’s encryption and decryption processes are implemented in unique functions, totaling 22 encryption/decryption functions for the game. Players advance through increasingly complex encryption schemes, deepening their understanding of classical cryptography concepts.

				===============================================================
				Level : 3        Scores : 150        Lives : 9
				===============================================================
				                                             
				       / Highest Scores  \
				       |                 |
				       | 1st : 1075      |
				       |                 |
				       | 2nd : 975       |
				       |                 |
				       | 3rd : 950       |
				       |                 |
				       | 4th : 900       |
				       |                 |
				       \ 5th : 875       /
				        -----------------
				        \     ,-.      .-,
				         \    |-.\ __ /.-|
				          \   \  `    `  /
				               /_     _ \
				             <  _`q  p _  >
				             <.._=/  \=_. >
				                {`\()/`}`\
				                {      }  \
				                |{    }    \
				                \ '--'   .- \
				                |-      /    \
				                | | | | |     ;
				                | | |.;.,..__ |
				              .-"";`         `|
				             /    |           /
				            `-../____,..---'`
# 4. Database Integration

Encrypto utilizes SQLite3 for data storage, specifically to manage player scores and progress. This allows the game to retain high scores and continue-game data, enhancing the user experience by providing a sense of achievement and continuity. The database structure is minimalistic, focusing solely on essential information to maintain fast, lightweight interactions.

# 5. ASCII arts and animation

All the ASCII arts in this game is created using a linux program, Cowsay, which is written in Perl. It was created by Tony Monroe in 2002. It is an open source program and falls under GNU General Public License (GPL).

The steam locomotive that runs after successful completion of a level is another linux program developed by Masashi Toyoda in 1993. Originally this program was built as a joke for mistyping ls, which shows a list of files and directories in linux machines. It is also copyrighted under GNU General Public License (GPL). 

The loading matrix animation is created using another open source program, Cmatrix, originally created by Chris Allegretta and maintained by Abishek V. Menon. This program also falls under GNU General Public License (GPL).  

# 6. Storyline and Educational Value

## 6.1 Storyline

The narrative of Encrypto introduces an antagonist organization, the Gunda, which threatens global privacy by possessing powerful decryption technology. The player, guided by a character known as The Keeper, must prevent the Gunda from abusing their knowledge by solving encrypted messages and uncovering clues to reveal their secrets. Each level unveils new insights and heightens the importance of the mission, with the ultimate goal of safeguarding personal privacy and freedom.

## 6.2 Educational Elements

Each level’s encryption challenge is rooted in classical cryptography, immersing players in historical ciphers used for secure communication. The Random Cryptographic Facts section and contextual hints provide players with background knowledge, combining education with entertainment.





# 7. Conclusion and Future Work

Encrypto demonstrates the power of games in education, especially within the field of cybersecurity and cryptography. By presenting cryptographic concepts through interactive puzzles and a compelling storyline, this game has the potential to raise awareness and understanding of information security among players.

## Future Enhancements

Expanded Storyline: Further narrative development to enrich player engagement.
Additional Levels and Ciphers: Incorporating more advanced ciphers, including modern techniques like RSA and Diffie-Hellman.
Multiplayer Mode: Introducing a collaborative mode where players can compete or cooperate to solve encryption challenges.
Visual Interface: Potentially developing a GUI to broaden the game's accessibility and appeal.


# Appendices

## Appendix A: Encryption and Decryption functions for Caesar Cipher
```C++
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
```


## Appendix B: Database Schema for SQLite3 Integration.
```C++

void variablesInit(){
	sqlite3# db;
	sqlite3_open("variables.db", &db);
	string cmd = "CREATE TABLE IF NOT EXISTS variables(id INTEGER NOT NULL PRIMARY KEY, level INT, scores INT, lives INT);";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	cmd = "SELECT level, scores, lives FROM variables";
	const char# data = " " ;
	sqlite3_exec(db, cmd.c_str(), callback0,nullptr, nullptr);
}
void variablesReset(){
	level = 1;
	scores = 0;
	lives = 7;
	variablesUpdate(level, scores, lives);
}
void variablesUpdate(int level, int scores, int lives){
	sqlite3# db;
	sqlite3_open("variables.db",&db);
	string cmd = "DELETE FROM variables WHERE TRUE";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	cmd = "INSERT INTO variables(level, scores, lives) VALUES(" + to_string(level) + ", " + to_string(scores) + ", " + to_string(lives) +");";
	sqlite3_exec(db,cmd.c_str(),nullptr,nullptr,nullptr);
	int values[3] = { level, scores, lives };
	cmd = "SELECT level, scores, lives FROM variables;";
	sqlite3_exec(db,cmd.c_str(),callback,values,nullptr);
}
static int callback(void# data, int argc, char## argv, char## azColName){
			int# values = static_cast<int#>(data);
				for(int i=0; i < argc ; i++){
					if(strcmp(azColName[i],"level") == 0)
						level = atoi(argv[i]);
				}
			return 99;
			};

static int callback0(void# data, int argc, char## argv, char## azColName){

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

```

## Appendix C: Excerpts from "How to Play" and "Random Cryptographic Facts."

```c++

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
	shiftRight(paddingX);
	bodyText = textAlignJustify(bodyText);
	cout << endl;
	shiftRight(paddingX);
	typingAnimation(bodyText, 30);

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

```
