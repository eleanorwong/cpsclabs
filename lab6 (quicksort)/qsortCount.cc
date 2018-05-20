#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a]) {
			swap(x[++m], x[i]);
		}
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

int qc(int n) {
	if( n >= 1 ) {
		int p = randint(0,n);
		return n-1 + qc(n-p) + qc(p-1);
	}
}

#define NN 1000
#define REPS 100

int main(int argc, char *argv[]) {
	srand(time(0));

	for(int i = 0; i < REPS; i++) {
		// change the following code
		x = new int[NN];
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}

		quicksort(0, NN-1);
		// for (int i=0; i<NN; ++i) {
		// 	std::cout << x[i] << " ";
		// }
		//std::cout << std::endl << "Number of Comparisons: " << comps << std::endl;
		delete[] x;
	}
	std::cout << std::endl << "Average Comparisons: " << comps/REPS << std::endl;

	comps = qc(1000);

	std::cout << std::endl << "Comparisons Recursive: " << comps << std::endl;

	return 0;
}

// quicksort
// average case - O(nlogn)
// worst case - O(n^2)
// Worst case doesn't occur often because we randomly choose our pivot. The worst
//		case occurs when say we always choose the minimum pivot in an already sorted
//		list!
