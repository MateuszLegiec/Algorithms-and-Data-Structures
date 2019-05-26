#include <iostream>

using namespace std;

void mound(int tab[], int n, int i){

	int largest = i;
	int left = 2*i+1;
	int right = 2*i + 2;

	if (left < n && tab[left] > tab[largest])
		largest = left;
	if (right < n && tab[right] > tab[largest])
		largest = right;
	if (largest != i){
		swap(tab[i], tab[largest]);
		mound(tab, n, largest);
	}

}

void sort(int tab[], int n){

	for (int i = n / 2 - 1; i >= 0; i--)
		mound(tab, n, i);

	for (int i=n-1; i>=0; i--){
		swap(tab[0], tab[i]);
		mound(tab, i, 0);
	}
}

void displayMound(int tab[], int n){
	for (int i=0; i<n; ++i)
		cout << tab[i] << " ";
	cout << "\n";
}
