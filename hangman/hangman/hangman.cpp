#include <iostream>
#include <ctime>
using namespace std;
int tries = 3;
string massage = "You have 3 chances";
void hang_man(char);
int checkGuess(char, string, string&);

int main()
{
	char letter;
	string month;
	string months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
	srand(time(NULL));
	int month_number = rand() % 12;
	month = months[month_number];

	string hide_month(month.length(), 'X');

	system("cls");

	while (tries != 0)
	{
		hang_man('n');
		cout << "\t\t\t\tLife: " << tries << endl;
		cout << hide_month << endl;
		cout << "\t\t\t\t Guess a latter: ";
			cin >> letter;
			system("cls");

			if (checkGuess(letter, month, hide_month) == 0) {
				massage = "wrong";
				tries--;
			} else{
				massage = "right";
			}

			if (hide_month == month) {
				massage = "You won";
				hang_man('f');
				cout << "\t\t\t\tLife: " << tries << endl;
				cout << "\t\t\t\tMonth is: " << month << endl;
				break;
			}
	}

	if (tries == 0) {
		massage = "You are dead";
		hang_man('h');
		cout << "\t\t\t\tLife: " << tries << endl;
		cout << "\t\t\t\tMonth is: " << month << endl;

	}
	return 0;
}
int checkGuess(char guess, string real_month, string& hidden_month) {
	int matches = 0;
	int len = real_month.length();
	for (int i = 0; i < len; i++) {
		if (guess == hidden_month[i]) {
			return 0;
		}
		if (guess == real_month[i]) {
			hidden_month[i] = guess;
			matches++;
		}
	}
	return matches;
}

void hang_man(char state) {
	string head_string = "|";
	string stage = "=";
	if (state == 'f') {
		head_string = " ";
	}
	else if (state == 'h') { stage = " "; }
	cout << "\t\t\t\t______________" << endl;
	cout << "\t\t\t\t     "<< head_string<<"      |" << endl;
	cout << "\t\t\t\t     O      |" << endl;
	cout << "\t\t\t\t    / \\     |            " <<massage<< endl;
	cout << "\t\t\t\t     |      |            /" << endl;
	cout << "\t\t\t\t    / \\     |           O" << endl;
	cout << "\t\t\t\t  =="<<stage<< stage << stage << stage << stage << "=  |          / \\" << endl;
	cout << "\t\t\t\t  |      |  |           | " << endl;
	cout << "\t\t\t\t  |      |  |          / \\ " << endl;
	cout << "\t\t\t\t================================|" << endl;
}