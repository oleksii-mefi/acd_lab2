#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void buldMatrix(int matrix[7][7]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void Sort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	setlocale(LC_ALL, "Ukrainian");
	srand(time(0));
	int matrix[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
	cout << "Наявна матриця:" << endl;
	buldMatrix(matrix);

	int diagonal[7];
	for (int i = 0; i < 7; i++) {
		diagonal[i] = matrix[i][6 - i];
	}
	Sort(diagonal, 7);
	for (int i = 0; i < 7; i++) {
		matrix[i][6 - i] = diagonal[i];
	}
	cout << "Посортована матриця:" << endl;
	buldMatrix(matrix);
	return 0;
}
