# CPSC 221 - Eleanor Wong 32507121 k1w8 | Programming Project 1B
To compile this project, run `make` and then `./index infile.txt outfile.txt`

This project is an implementation of a book index. The goal of this code is to print the words of the book in sorted order, how many times they appear in the book and what pages they occur at.

This program works by reading each line at a time, removing punctuation and normalizing the words. For each word, we check if it is already added in the index, if it doesn't exist, we add a new entry, otherwise, we add a count and the page number to the existing entry.

The book index is composed in a class called 'SkipBookIndex', which has three functions: find, insert, and print. Unlike project 1A, 1B is implements the book index as a Skip list instead of a regular list. If the word does not exist in the index, find will return the index it should be at. The insert function finds the word in the index, then if the entry pointer exists, increases the count and page numbers. If the pointer does not exist, a new word is created and inserted into the index at the place specified by the binary search. This results in SkipBookIndex::insert inserting in order. Finally, since we insert each word in order, we just iterate through the book index to print the index in order as entries were inputted in order. The algorithms for the skip list are implemented based off interpretations of the project guidelines.

The underlying data structure used for SkipBookIndex is a vector of Word struct pointers. A word struct contains the fields: word, count and pageNumbers. I chose to do binary search to find the entries because it requires the BookIndex to be in order, and is faster to search through than using linear search. Binary search also returns the index the entry is supposed to be in if the entry doesn't exist so this made it easy to insert entries in order. By not needing to sort in the end, printing the index in order is very simple.

## Relevant Files
* skip_book_index.cc - Implementation of the SkipBookIndex class functions
* skip_book_index.h - Header file for the SkipBookIndex, defining the class and the Word struct as well as a single SkipListNode
* index.cc - Contains the main function of the program that takes in two files, an input file and output file, and prints the book index to the output file.
* ch1.txt - Sample input (Ch.1 of Alice in Wonderland) as supplied by the lab
* index.txt - Sample output (Index for Ch.1 of Alice in Wonderland)
* Makefile - contains build information to run make
