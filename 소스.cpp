#include "std_lib_facilities.h"

void Dictionary_menu(void);
void game_menu(void);
void Wordle_game(void);

int main(void){
	int put_num;
	cout << "<<< WORDLE >>> \n1.Dictionary\n2.Game\n3.Exit \n\n";
	do {
		cout << "Choose an option(1 - 3) : ";
		cin >> put_num;
		
		if (put_num == 1){
			Dictionary_menu();
		}
		else if (put_num == 2) {
			game_menu();
		}
		else if (put_num == 3) {
			cout << "\nGood bye!!!\n";
			return 0;
		}
	} while (put_num < 1 || put_num>3);
}
void Dictionary_menu(void){
	int put_num1;
	cout << "\n[DICTIONARY] \n1. Print\n2. Return\n\n";

	do{
		cout << "Choose an option(1 - 2) : ";
		cin >> put_num1;
		if (put_num1 == 1)
		{
			fstream file{ "words.txt" };
			if (!file) error("can't open output file", "words.txt");

			string s;
			vector<string> words;

			while (file >> s){
				words.push_back(s);
			}
			sort(words);
			cout << "\n";
			for (string w :words){
				cout << w << "\n";
			}
			cout << "\nA total of " << words.size() << " words are available.\n";
			file.close();

			Dictionary_menu();
		}
		else if (put_num1 == 2){
			cout << "\n";
			main();
		}
	} while (put_num1 < 1 || put_num1>2);
}
void game_menu(void){
	cout << "\n[ GAME ]\n1. Play\n2. Return: \n";
	int put_num;
	do{
		cout << "Choose an option (1-2): ";
		cin >> put_num;

		if (put_num == 1){
			Wordle_game();
		}
		if (put_num == 2){
			cout << "\n";
			main();
		}
	} while (put_num < 1 || put_num>2);
 }
void Wordle_game(void){
	fstream file{ "words.txt" };
	if (!file) error("can't open output file", "words.txt");

	string file_word;
	vector<string> words;

	while (file >> file_word){
		words.push_back(file_word);
	}
	
	string random_word;
	random_word = words[randint((words.size()) - 1)];

	cout << "\nA new 5-letter word has been chosen randomly from the dictionary.\n";
	
	for (int Number = 1;Number < 7;Number++){
		string guess_word;
		string symbol[5];
		do{
			cout << "\n[" << Number << "/6] Guess the word: ";
			cin >> guess_word;
		} while (guess_word.size() != 5);
		
		for (int i = 0;i < 5;i++){
			for (int j = 0;j < 5;j++){
				if (guess_word[i] == random_word[i]){
					symbol[i] = "*";
					break;	
				}
				else if (guess_word[i] == random_word[j] && i != j){
					symbol[i] = "#";
					break;
				}
				else 
					symbol[i] = "@";
			}
		}
		cout << "==> ";
		for(int i=0;i<5;i++)
		 cout<<symbol[i];
		cout << "\n";
		if (guess_word == random_word){
			file.close();
			cout << "\nCongratulation!!! Your guess is correct.\n";
			game_menu();
		}
	}
	file.close();
	cout << "\nOoops!!! You lost all your chances. The correct answer is \""<<random_word<<"\".\n";
	game_menu();
}