#include "codetree.h"

/**
 * Implementations of functions in codetree.h
 */

// Given a map of characters to frequencies, generates the heap for all characters in the frequency
//      map that have at least a frequency of one
void PriorityQueue::heapify(int freq[]) {
    for(int i = 0; i < ASCII_COUNT; i++) {
        // Only code characters that appear
        if(freq[i] > 0) {
            Node* charNode = new Node();
            charNode->character = i;
            charNode->frequency = freq[i];
            insert(charNode); // insert into heap
        }
    }
}

// Implementation of the heap ADT, removes the minimum element of the heap then restores heap property
Node* PriorityQueue::removeMin() {
    if(queue.size() == 0) return NULL; // Nothing to remove
    Node* returnVal = queue[0];
    queue[0] = queue[queue.size()-1]; // Copy last element to root
    queue.pop_back(); // Remove last element
    swapDown(0);
    return returnVal;
}

// Implementation of the heap ADT, adds an element to the heap then restores heap property
void PriorityQueue::insert(Node* node) {
    queue.push_back(node); // Insert to end
    swapUp(queue.size()-1);
}

// Helper function for heap ADT to swap newly inserted elements to maintain heap property
void PriorityQueue::swapUp(int index) {
    if(index == 0) return;
    int p = (index)/2;
    if(queue[index]->frequency < queue[p]->frequency) {
        Node* tmp = queue[index];
        queue[index] = queue[p];
        queue[p] = tmp;
        swapUp(p);
    }
}

// Helper function for heap ADT to swap elements to maintain heap property (used in remove)
void PriorityQueue::swapDown(int index) {
    int s = index;
    int left = index*2+1;
    int right = index*2 + 2;
    if(left < queue.size() && queue[left]->frequency <= queue[s]->frequency ) {
        s = left;
    }
    if(right < queue.size() && queue[right]->frequency <= queue[s]->frequency ) {
        s = right;
    }
    if ( s != index ) {
        Node* tmp = queue[index];
        queue[index] = queue[s];
        queue[s] = tmp;
        swapDown(s);
    }
}

// Prints the priority queue as a tree
void PriorityQueue::printQueue() {
    printQueueHelper(queue, 0, 0);
}

// Helper function to print the priority queue
void PriorityQueue::printQueueHelper(std::vector<Node*> queue, int node = 0, int d = 0) {
    if(node >= queue.size()) {
        return;
    }
    printQueueHelper(queue, 2*node+2, d+1);
    std::cout << std::string(d, '\t');
    printChar(queue[node]->character);
    std::cout << ": " << queue[node]->frequency << std::endl;
    printQueueHelper(queue, 2*node+1, d+1);
}

// Generates the Huffman code tree by merging pairs of nodes and readding them to heap until there
//      is only one node left, which is the root of the Huffman code tree.
void CodeTree::generateTree() {
    while(queue.queue.size() > 1) {
        // Remove two smallest nodes
        Node* one = queue.removeMin();
        Node* two = queue.removeMin();

        // Give common parent
        Node* parent = new Node();
        parent->frequency = 0 + one->frequency + two->frequency;
        parent->left = one;
        parent->right = two;

        // Re insert into heap
        queue.insert(parent);
    }
    tree = queue.removeMin();
}

// Prints the Huffman Code tree and the codes for the characters derived from the tree
void CodeTree::printTree() {
    printTreeHelper(tree, "");
}

void CodeTree::printCode() {
    printCodeHelper(tree, "", 0);
}

// Helper function to print the Huffman Code tree
void CodeTree::printTreeHelper(Node* r, std::string pre) {
    if( r == NULL ) return;
    if(r->right == NULL) {
        printChar(r->character);
        std::cout<< std::endl;
    } else {
        std::cout << "." << std::endl;
        std::cout << pre << "|`1-";
        printTreeHelper(r->right, pre + "|   ");
        std::cout << pre + "|   " << std::endl;
        std::cout << pre << "`-0-";
        printTreeHelper(r->left, pre + "    ");
    }
}

// Helper function to print the codes for all the characters. Implemented through recursively
//      traversing the tree till it reaches a leaf, then prints the leaf character and path code.
void CodeTree::printCodeHelper(Node* node, std::string currentPath, int index) {
    if(node == NULL) {
        return;
    }
    if(node->left == NULL && node->right == NULL) {
        printChar(node->character);
        std::cout << ": " << currentPath << std::endl;
        currentPath = "";
    }
    printCodeHelper(node->left, currentPath+="0", index);
    currentPath = currentPath.substr(0, currentPath.size()-1); // Need to reduce size by one
    printCodeHelper(node->right, currentPath+="1", index);

}

// Provided function to print the ASCII integer characters as a char
void printChar( int ch ) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
    }
}
