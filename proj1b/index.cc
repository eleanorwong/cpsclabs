#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       // provides string class
#include <cctype>       // provides isalpha() and tolower()
#include <ctime>                // for time()
#include <cstdlib>              // for rand(), srand(), and RAND_MAX
#include <ctime> // for time()
#include <cstdlib> // for rand(), srand(), and RAND_MAX
#include "skip_book_index.h"

using namespace std;

// Remove all characters except letters (A-Z,a-z) from line,
// except keep '-' or '\'' if they are between letters.
void lowercaseWords(string & line) {
    for (string::iterator it = line.begin(); it != line.end(); ++it) {
        if (!isalpha(*it)) {
            if ((*it != '-' && *it != '\'') ||
                it == line.begin() || it + 1 == line.end() ||
                !isalpha(*(it - 1)) || !isalpha(*(it + 1))) {
                *it = ' ';
            }
        }
        else {
            *it = tolower(*it);
        }
    }
}

void print(ostream & output, string & word) {
    output << word << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " book.txt index.txt" << endl;
        exit(1);
    }

    ifstream fin;
    fin.open(argv[1]);
    if (!fin.is_open()) {
        cerr << "Unable to open " << argv[1] << endl;
        exit(2);
    }

    ofstream fout;
    fout.open(argv[2]);
    if (!fout.is_open()) {
        cerr << "Unable to open " << argv[2] << endl;
        exit(3);
    }

    srand(time(0)); // Seed for random number generator
    SkipBookIndex b; // Initialize the book

    string line, word;
    int lineNumber = 1;
    while (!fin.eof()) {
        getline(fin, line);
        lowercaseWords(line);
        istringstream iss(line, istringstream::in);
        while (iss >> word) {
            b.insert(word, lineNumber);
        }
        lineNumber++;
    }
    // Print words
    b.print(fout);
}
