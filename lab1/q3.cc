#include <iostream>
#include <string>
#include <fstream>

#define ARRAY_SIZE 10

using namespace std;

// FUNCTION PROTOTYPES
void fill_array(void);
void fill_array(int first_value, int increment);

int fillee[ARRAY_SIZE] = {};

int main(void) {
	fill_array();

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << fillee[i] << " ";
	}

	cout << endl;

	fill_array(4, 2);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << fillee[i] << " ";
	}

	cout << endl;
}

// PART A
void fill_array(void) {
	for (int i = 1; i <= ARRAY_SIZE; i++) {
		fillee[i - 1] = i;
	}
}

// PART B
void fill_array(int first_value, int increment) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		fillee[i] = first_value + i*increment;
	}
}
