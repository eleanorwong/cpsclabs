#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

const int ASCII_COUNT = 256;

// Node struct for the heap and Huffman tree
// Holds character and its frequency (which we use for heap property)
// Also holds pointer to left and right nodes as a binary tree
struct Node {
    int character;
    int frequency;
    Node* left;
    Node* right;
};

// PriorityQueue class
// Implements the priority queue ADT (public functions) as a min heap
class PriorityQueue {
    public:
        std::vector<Node*> queue;

        void heapify(int freq[]);
        void insert(Node* node);
        Node* removeMin();
        void printQueue();

    private:
        void swapDown(int i);
        void swapUp(int i);
        void printQueueHelper(std::vector<Node*> queue, int i, int d);
};

// CodeTree class
// Generates the Huffman Coding tree using the PriorityQueue class
class CodeTree {
    public:
        PriorityQueue queue;
        Node* tree;

        CodeTree(int freq[]) {
            queue.heapify(freq);
        }

        void generateTree();
        void printTree();
        void printCode();

    private:
        void printTreeHelper(Node* r, std::string pre);
        void printCodeHelper(Node* r, std::string currentPath, int index);
};

// Provided integer to character helper function
void printChar(int character);
