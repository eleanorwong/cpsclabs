#include <iostream>
#include <cstdlib> 

using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cerr << "Wrong number of arguments!" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    // First insert n elements
    for(int i = 1; i <= n/3; i++) {
        cout << "I " << i << endl;
    }
    for(int i = 1; i <= n/3; i++) {
        cout << "F " << i << endl;
    }   
    // Then remove all n elements
    for(int i = 1; i <= n/3; i++) {
        cout << "R " << i << endl;
    }
    return 0;
}
