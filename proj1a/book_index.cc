#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "book_index.h"

// Binary search over the BookIndex and populates findee if the search is conclusive
//	  Returns the index word should be at if the index does not contain the word w
int BookIndex::find(std::string w, Word*& findee) {
	// If nothing in the index
	if(indexes.size() == 0) {
	  return 0;
	}

	int low = 0;
	int high = indexes.size();
	int middle;

	while(low <= high) {
		middle = (low+high)/2;

		if(indexes[middle]) {
			if(indexes[middle]->word.compare(w) == 0) {
				// Word is equal to indexes[middle]
				findee = indexes[middle];
				return middle;
			} else if(indexes[middle]->word.compare(w) > 0) {
				// Word goes before indexes[middle]
				high = middle-1;
			} else {
				// Word goes after indexes[middle]
				low = middle+1;
			}
		} else {
			// If getting from the index returns NULL (out of bounds)
			findee = NULL;
			return middle;
		}
	}
	// Once we searched everything, we want to return the low instead of midpoint
	return low;
}

// Calculates the page number based off the line number, then finds the entry in the index.
//	  If the entry exists, increase the count and add the page number if it is different
//	  If the entry doesn't exist, create a new word and add to the location returned by find
void BookIndex::insert(std::string w, int line) {
	int pageNumber = line/(linesPerPage+1) + 1;
	Word* entry = NULL;

	int found = find(w, entry);

	// Entry is populated
	if(entry != NULL && indexes[found]->word == w) {
		entry->count = entry->count + 1;

		// Only add new page if the last one isn't the same
		if( (entry->pages).back() != pageNumber ) {
			entry->pages.push_back(pageNumber);
		}
		return;
	}
	// Entry is not populated
	else {
		entry = new Word();
		entry->word = w;
		entry->count = 1;
		entry->pages.push_back(pageNumber);

		// Insert at place specified by binary search
		indexes.insert(indexes.begin()+found, entry);
		return;
	}
}

// Prints the book index to ostream in order as follows:
//	  word (count) pageNumbers
//
// Page numbers are printed 1,2,3,5,6 appears as 1-3, 5-6, grouping consecutive pages.
void BookIndex::print(std::ostream & fout) {
	std::stringstream ss;

	for(int i = 0;  i < indexes.size(); i++) {
		bool hyphen = false;

		// Add to string stream the word and count
		ss << indexes[i]->word << " (" << indexes[i]->count << ") ";

		// Iterate through pages
		for(int j = 0; j < indexes[i]->pages.size()-1; j++) {
			// If consecutive
			if(indexes[i]->pages[j] + 1 == indexes[i]->pages[j+1]) {
				if(!hyphen) {
					hyphen = true;
					ss << indexes[i]->pages[j] << "-";
				}
			} else {
				hyphen = false;
				ss << indexes[i]->pages[j] << ",";
			}
		}
		// Add the last page
		ss << indexes[i]->pages[indexes[i]->pages.size()-1];
		fout << ss.str() << std::endl;
		// Reset stringstream
		ss.str("");
	}
}
