#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "Question 5 Guessing Game!" << endl << 
		"Type a number between 1 and 100 to guess or 0 or not an integer to quit" << endl;

	srand(0); // 84

	int number = rand() % 100 + 1;
	int guess;

	char buffer[256];

	do {
		fgets(buffer, 256, stdin);
		guess = atoi(buffer);

		if (guess == 0) {
			cout << "Quitting Game :(" << endl;
			return 0;
		}

		if (guess != number) {
			cout << "You have guessed incorrectly :(" << endl;
		}
	} while (guess != number);

	cout << "You have guessed correctly! Congratulations!" << endl;
	
	return 0;
}