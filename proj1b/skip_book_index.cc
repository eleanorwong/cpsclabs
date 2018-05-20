#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime> // for time()
#include <cstdlib> // for rand(), srand(), and RAND_MAX
#include "skip_book_index.h"

// Binary search over the BookIndex and populates findee if the search is conclusive
// If search is inconclusive, the global update array is populated with which indexes to update
int SkipBookIndex::find(std::string w, Word*& findee) {
    // First item we need to create the SkipBookIndex
    if(indexHead == NULL) {
        SkipListNode* node = new SkipListNode();
        node->height = maxHeight;
        indexHead = node;

        // Populate update with head
        for(int i = 0; i < maxHeight; i++) {
            update[i] = indexHead;
        }

        return -1; // Not found
    }

    // Find algorithm as described by the project description
    int height = indexHead->height - 1;
    SkipListNode* node = indexHead;

    for(int i = height; i >= 0; i--) {
        while(node->next[i] != NULL && node->next[i]->entry->word.compare(w) < 1) {

            if(node->next[i]->entry->word.compare(w) == 0) {
                findee = node->next[i]->entry;
                return i;
            }

            node = node->next[i];

            if(node->next[i] == NULL) break; // Need to break so we don't go out of bounds
        }
        update[i] = node;
    }

	return -1;
}

// Calculates the page number based off the line number, then finds the entry in the index.
//	  If the entry exists, increase the count and add the page number if it is different
//	  If the entry doesn't exist, create a new word and add to the location returned by find
void SkipBookIndex::insert(std::string w, int line) {
    int pageNumber = line/(linesPerPage+1) + 1;
    Word* entry = NULL;

    int found = find(w, entry);

    if (found == -1) {
        entry = new Word();
        entry->word = w;
        entry->count = 1;
        entry->pages.push_back(pageNumber);

        SkipListNode* node = new SkipListNode();
        node->entry = entry;
        node->height = randomNodeHeight();

        // Insert algorithm as described by project description
        for(int h = 0; h < node->height; ++h) {
            if(update[h] != NULL) {
                // Sometimes code fails here
                node->next[h] = update[h]->next[h];
                update[h]->next[h] = node;
            }
        }

        // Reset Update
        for(int i = 0; i < 16; i++) {
            update[i] = indexHead;
        }
    } else {
        entry->count = entry->count + 1;

        // Only add new page if the last one isn't the same
        if( (entry->pages).back() != pageNumber ) {
            entry->pages.push_back(pageNumber);
        }
        return;
    }

	return;
}

// Prints the book index to ostream in order as follows:
//	  word (count) pageNumbers
//
// Page numbers are printed 1,2,3,5,6 appears as 1-3, 5-6, grouping consecutive pages.
void SkipBookIndex::print(std::ostream & fout) {
    std::stringstream ss;

    SkipListNode* list = indexHead;

	while(list->next[0] != NULL) {
		bool hyphen = false;

		// Add to string stream the word and count
		ss << list->next[0]->entry->word << " (" <<  list->next[0]->entry->count << ") ";

		// Iterate through pages
		for(int j = 0; j <  list->next[0]->entry->pages.size()-1; j++) {
			// If consecutive
			if( list->next[0]->entry->pages[j] + 1 ==  list->next[0]->entry->pages[j+1]) {
				if(!hyphen) {
					hyphen = true;
					ss <<  list->next[0]->entry->pages[j] << "-";
				}
			} else {
				hyphen = false;
				ss <<  list->next[0]->entry->pages[j] << ",";
			}
		}
		// Add the last page
		ss <<  list->next[0]->entry->pages[ list->next[0]->entry->pages.size()-1];
		fout << ss.str() << std::endl;
		// Reset stringstream
		ss.str("");
        list = list->next[0];
	}
}

// Random Functions
// Gets a random node height
int SkipBookIndex::randomNodeHeight(void) {
    int height;
    for( int i=1; i<maxHeight; ++i ) {
        height = i;
        if( randBit() == 1 ) break;
    }
    return height;
}

// Gets a random bit
int SkipBookIndex::randBit(void) {
    static int bitsUpperBd=0;
    static int bits; // store bits returned by rand()
    if( bitsUpperBd == 0 ) { // refresh store when empty
        bitsUpperBd = RAND_MAX;
        bits = rand();
    }
    int b = bits & 1;
    bits >>= 1;
    bitsUpperBd >>= 1;
    return b;
}
