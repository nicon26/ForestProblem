#include <iostream>
#pragma warning(push)
#pragma warning(disable:6385)
using namespace std;

int forest[10][10];

bool isInMatrix(int i, int j) {

	if ((i < 0 || i > 9) || (j < 0 || j > 9))
		return false;

	return true;
}

void removed(int vector[], int &n) { // removes first element of vector

	vector[0] = vector[1];
	
	for (int i = 1; i < n - 1; i++) {
		vector[i] = vector[i + 1];
	}
	n--;

}

void add(int vector[], int &n, int x) { // adds an element at the end of vector
	
	vector[n] = x;
	n++;
}

void print(int vector[], int n) { // prints vector
	int i;
	if (n == 0)
		cout << "Nothing to print." << endl;
	else {
		for (i = 0; i < n; i++)
			cout << vector[i] << " ";
		cout << endl;
	}
}

int main()
{
	int i, j, day = 1, treesi[100]{}, treesj[100]{}, ki = 0, kj = 0, treeBurns = 0;

	cout << "Enter the position of the tree that catches fire.\n";
	cout << "Line: ";
	cin >> i;
	cout << "Column: ";
	cin >> j;
	forest[i][j] = 1; // position of the first tree to be catching fire

	add(treesi, ki, i); // retains position of the tree catching fire -- i
	add(treesj, kj, j); // -- j

	while (ki != 0) {
		i = treesi[0];
		j = treesj[0];

		if (isInMatrix(i - 1, j) == true && forest[i - 1][j] == 0) {
			add(treesi, ki, i - 1);
			add(treesj, kj, j);
			forest[i - 1][j] = forest[i][j] + 1;
		}
		if (isInMatrix(i, j + 1) == true && forest[i][j + 1] == 0) {
			add(treesi, ki, i);
			add(treesj, kj, j + 1);
			forest[i][j + 1] = forest[i][j] + 1;
		}
		if (isInMatrix(i + 1, j) == true && forest[i + 1][j] == 0) {
			add(treesi, ki, i + 1);
			add(treesj, kj, j);
			forest[i + 1][j] = forest[i][j] + 1;
		}
		if (isInMatrix(i, j - 1) == true && forest[i][j - 1] == 0) {
			add(treesi, ki, i);
			add(treesj, kj, j - 1);
			forest[i][j - 1] = forest[i][j] + 1;
		}
		
		removed(treesi, ki);
		removed(treesj, kj);

	}

	for (i = 0; i < 10; i++) { // find out the day when the whole forest burned
		for (j = 0; j < 10; j++)
			if (forest[i][j] > treeBurns)
				treeBurns = forest[i][j];
	}

	for (i = 0; i < 10; i++) { // prints the forest 
		for (j = 0; j < 10; j++) {
			if (forest[i][j] < 10)
				cout << " " << forest[i][j] << " ";
			else cout << forest[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "The forest burned in " << treeBurns << " days !!!"; 

	return 0;
}