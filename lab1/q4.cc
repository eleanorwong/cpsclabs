#include <cstdlib> // for atoi
#include <iostream>

using namespace std;

// prototype 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " number_of_disks" << endl;
		return -1;
	}
	int n = atoi(argv[1]);
	moveDisks(n, "peg A", "peg B", "peg C");

	return 0;
}


// let n be the number of disks on peg a
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO) {
	// BASE CASE if n = 1
	if (n == 1) {
		cout << "Move disk from " << FROM << " to " << TO << endl;
	}
	else {
		// Recursively move n-1 disks from A to B
		moveDisks(n - 1, FROM, TO, VIA);
		// Remove disk n from A to C
		cout << "Move disk from " << FROM << " to " << TO << endl;
		// Recursively move n-1 disks from B to C so they sit on disk n
		moveDisks(n - 1, VIA, FROM, TO);
	}
}