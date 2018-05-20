#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <fstream>

const int maxHeight = 16;
const int linesPerPage = 40;

// Word struct
// Holds the word, count and list of pages
struct Word {
    std::string word;
    int count;
    std::vector<int> pages;
};

// Node of a skip list struct
// Holds a entry, nextList, and height
struct SkipListNode {
    Word* entry;
    SkipListNode* next[maxHeight];
    int height;
};

// SkipBookIndex class
// Supports three functions: find, insert and print
class SkipBookIndex {
    public:

        SkipListNode* indexHead;
        SkipListNode* update[maxHeight];

        // Public Functions
        int find(std::string word, Word*& findee);
        void insert(std::string word, int line);
        void print(std::ostream& fout);

        SkipBookIndex() {
            indexHead = NULL;
        }

    private:
        int randomNodeHeight(void);
        int randBit(void);
};
