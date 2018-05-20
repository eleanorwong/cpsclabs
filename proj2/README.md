# CPSC 221 - Eleanor Wong 32507121 k1w8 | Programming Project 2
To compile this project, run `make` and then `./huftree testfile.txt`

Time to complete: 3 hours

This project is an implementation of the Huffman coding algorithm. The goal of this code is to generate the prefix codes for a given test file.

This program works by implementing two classes, a priority queue used by the Huffman Algorithm, and a CodeTree, which generates the Huffman algorithm code tree.

The priority queue implementation implements the priority queue ADT functions: insert and removeMin. I have also implemented heapify for an unheaped array input and print queue for debugging. This priority queue is a min heap, so the minimum value is at the root of the heap. The code from the lecture notes on Priority Queues aided in the implementation of this data structure. The priority queue's underlying structure is using a std::vector.

The code tree implementation implements Huffman's algorithm to generate prefix codes for all the ASCII characters in the input text file. Functions implemented as part of this class include generating the tree based off a heap of the frequencies of characters as well as printing the Huffman tree as specced and also printing out the codes for every unique character in the input.


## Relevant Files
* codetree.cc - Implementation of the codetree.h functions for both the Priority Queue and the Code Tree
* codetree.h - Header file for the codetree functions, including the PriorityQueue class, Codetree class and Node* structss
* huftree.cc - Contains the main function of the program that takes in a single input file. Prints to the console the Huffman coding tree and codes generated for all the unique ASCII characters in the input file
* moveover.txt - Sample input (moveover moveover) as supplied by the lab
* Makefile - contains build information to run make
