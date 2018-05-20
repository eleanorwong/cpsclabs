#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

// Word struct
// Holds the word, count and list of pages
struct Word {
    std::string word;
    int count;
    std::vector<int> pages;
};

// BookIndex class
// Supports three functions: find, insert and print
class BookIndex {
    public:
        int linesPerPage = 40;
        std::vector<Word*> indexes;

        // Public Functions
        int find(std::string word, Word*& findee);
        void insert(std::string word, int line);
        void print(std::ostream& fout);
};
