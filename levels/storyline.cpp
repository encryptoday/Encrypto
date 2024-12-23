#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include "../includes/crypto.h"

using namespace std;


void storyLine(){

	system("clear");

        unordered_map<string,string> story;
	string heading = "LEVEL 1 - THE GIRL IN RED SKIRT";
	string press;
	string firstName;

	story["from"] = "The keeper";
	story["to"] = playerName;

	for(char ch: playerName){
		if(isspace(ch))
			break;
		firstName += ch;
	}

        switch(level){
		case 1:
												story["heading"] = "Level 1 : Eyes in the Dark";
												story["mission"] = "Decode to confirm your loyalty";
												story["msg1"] 	 = "The world is not as it seems, "+ firstName  +". Those who hold power are watching, listening, controlling. You’ve been chosen because of your skills, but you’re not the only one interested in this knowledge.";
												story["msg2"]	 	 = "Decode this message to stay hidden, and make no mistake—there’s more at stake than you realize.";
												story["tagline"] = "Remember, every solution you find leads to new risks.";
												break;
		case 2:
												story["heading"] = "Level 2: The Mirror’s Edge";
												story["mission"] = "Uncover the truth beneath the surface";
												story["msg1"]	 = "Welcome to the team, " + firstName  + ". Trust is a luxury you cannot afford. This message will give you the coordinates to your next clue, but the Gunda is closing in. They’re well-funded, relentless, and they won’t stop until they have everything.";
												story["msg2"] 	 = "Reverse everything you think you know to understand the true meaning here. What you decode might be your only chance to stay a step ahead.";
												story["tagline"] = "Don’t let them catch you unaware.";
												break;
		case 3:
                        story["heading"] = "Level 3: Band of Five";
                        story["mission"] = "Whats' bothering the old man?";
                        story["msg1"]    = "Let me tell you a tale of five brothers bound by a powerful secret. They wielded the art of ciphers with their loyalty unbreakable. They held the unbreakable algorithm that could replace any other. But one dark night, they were gone—gone into the wind.";
                        story["msg2"]    = "Your last clue led us to the forgotten cemetery where their gravestones lie, each one engraved with cryptic messages no one has ever deciphered. Why were these riddles left behind? What secrets do they guard?";
                        story["tagline"] = "Rumor whispers of a consortium behind it all, but only you have the skill to uncover the truth.";
                        break;
    case 4:
                        story["heading"] = "Level 4: Echoes of Time";
                        story["mission"] = "Unmask the true power";
                        story["msg1"]    = "Your journey has been remarkable, " + firstName + ". The text you uncovered has unveiled the enigmatic truth behind a formidable power. Now, the next cipher beckons you to an ancient temple, the very birthplace of the secred algorithm.";
                        story["msg2"]    = "The answer to this cipher will reveal your next step, but only if you can calculate it. They think only numbers can protect them, but we’ll prove them wrong. Stay sharp, and don’t look back. ";
                        story["tagline"] = "The truth lies in the shadows; shine your light upon it.";
                        break;
    case 5:
												story["heading"] = "Level 5: Path of the Chosen";
												story["mission"] = "Break through their calculations";
												story["msg1"]	 	 = "We’ve uncovered the ancient temple deep within Bangladesh, but 7 of its gate is guarded by 5 symettric—a final test for those who seek entry. This is no ordinary lock; the temple seems alive, sensing intentions.";
												story["msg2"]	   = "Perhaps there’s a clue, something only the worthy can see. We believe you may be able to solve this cipher and unlock the path forward without awakening what lies within.";
												story["tagline"] = "Remember, every word holds significance.";
												break;
		case 6:
                        story["heading"] = "Level 6: The Enigmatic Embrace";
                        story["mission"] = "Unlock the secrets they hide";
                        story["msg1"]    = "You’re nearing a crucial juncture, " + firstName + ". The Gunda is growing restless, and they believe their secrets are impenetrable. This message is found in a old book from the temple that holds the key to your next location, but you’ll need to decipher their obfuscations.";
                        story["msg2"]    = "Trust in your instincts and break their code to reveal what lies ahead. With each message, you’re inching closer to the heart of their operation.";
                        story["tagline"] = "Remember the things you have learnt.";
                        break;
		case 7:
                        story["heading"] = "Level 7: High Wind Havana";
                        story["mission"] = "Reveal the truth of their intentions";
                        story["msg1"]    = "Something is going on in Cuba, " + firstName + ", Something big. We’re seeing a surge in encrypted traffic from the area. The consortium knows what we are trying to do and they have shifted their communication to an even more secure form of encryption.";
                        story["msg2"]    = "Decipher this shifting text to find the message they think is hidden. The key to unraveling this lies in how you piece the words back together. ";
                        story["tagline"] = "Uncover the truth before it’s too late.";
                        break;
		case 8:
												story["heading"] = "Level 8: Shifting Shadows";
												story["mission"] = "Unmask the true enemies";
												story["msg1"]    = "Nothing in this world is straightforward. Freedom is the key behind symbols and secrets, and it’s up to you to reveal the truth. They’re relying on complex substitutions to keep their secrets safe, but we know the game.";
												story["msg2"]    = "Each letter has been shifted—find the pattern and break it. The decoded message will point you towards the next step.";
												story["tagline"] = "Remember, what you find may put you closer to the Gunda’s radar.";
												break;
		case 9:
										    story["heading"] = "Level 9: Web of Lies";
										    story["mission"] = "Untangle the web of deception";
										    story["msg1"]    = "You have found the person behind the Gunda, " + firstName + ". But this person is a ghost. They think they can bury the truth beneath layers of complexity, but the key is in the Universe. This cipher relies on grid patterns and hidden messages.";
										    story["msg2"]    = "Decipher it, and you’ll unveil their plan to keep you at bay. Each step forward brings you closer to unveiling their intricate web of lies.";
										    story["tagline"] = "Stand tall in the rising tide.";
										    break;
		case 10:
                        story["heading"] = "Level 10: Echoes of the Protocol";
                        story["mission"] = "Unlock the gateway to freedom";
                        story["msg1"]    = "The time has come to confront the echoes of the past. This message is layered with multiple encryptions, but hidden within is the Gunda’s ultimate objective.";
                        story["msg2"]    = "Decoding this is paramount; it will expose their final plan. Your instincts must guide you as you navigate through the chaos.";
                        story["tagline"] = "Trust in the maths skills you’ve honed so far.";
                        break;
		case 11:
										    story["heading"] = "Level 11: The Matrix Trap";
										    story["mission"] = "Trust in yourself";
										    story["msg1"]    = "Gathering in the moonlight, the villagers whispered tales of the old forest. Young hearts raced as they ventured deeper, drawn by the legends of hidden treasures. Beneath the ancient trees, shadows danced, and the air buzzed with anticipation. Nightfall brought secrets to life, revealing paths unknown to the untrained eye.";
										    story["msg2"]    = "Questing through the darkness, they stumbled upon a clearing lit by fireflies. Kneeling to examine an ornate stone, they discovered carvings of forgotten lore. Unraveling the mystery of the markings, they realized they held the key to untold riches. Reveling in their find, they vowed to protect the forest's secrets. Pledging their loyalty, they became guardians of the magic that lingered in the night.";
										    story["tagline"] = "Break the matrix, and save the world.";
										    break;

        }

//	string temp;
//	for(int i=0; i<= story["msg1"].length() ; i+=63){
//		temp += story["msg1"].substr(i,63) + "\n" + "\033[" + to_string(paddingX) + "C";
//	}
//	story["msg1"] = temp;
//	temp = "";
//
//	for(int i=0; i<= story["msg2"].length() ; i+=63){
//                temp += story["msg2"].substr(i,63) + "\n" + "\033[" + to_string(paddingX) + "C";
//        }
//        story["msg2"] = temp;
start:
	factHeader(story["heading"]);
	cout << endl << endl;

	shiftRight(paddingX);
	textAnimate("From   \t:  " + story["from"]);
	cout << endl;
	shiftRight(paddingX);
	textAnimate("To\t\t:  " + story["to"]);
	cout << endl << endl;
	shiftRight(paddingX);
	textAnimate("Mission\t:  " + story["mission"]);
	cout << endl << endl << endl;

	shiftRight(paddingX);
	story["msg1"] = textAlignJustify(story["msg1"]);
	typingAnimation(story["msg1"],47);
	cout << endl << endl;

	shiftRight(paddingX);
	story["msg2"] = textAlignJustify(story["msg2"]);
	typingAnimation(story["msg2"],47);
	cout << endl << endl << endl;

	shiftRight(paddingX);
	story["tagline"] = textAlignJustify(story["tagline"]);
	typingAnimation(story["tagline"],47);
	cout << endl << endl << endl;

	shiftRight(paddingX);
	textAnimate("Press enter to continue -->");

	if (gameType == 0)
        	cin.ignore();

	getline(cin, press);
	if(press.empty()){
		levels(level);
	}
	else{
		system("clear");
		goto start;
	}
}
