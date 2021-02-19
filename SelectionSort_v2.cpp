#include <iostream>
using namespace std;

int main() {
	int araEleman, minEleman;
	int dizi[8] = { 2,5,-7,-9,8,-21,23,54 };
	for (int i = 0; i < 7; i++) {
		minEleman = i;
		for (int j = i; j < 7; j++) {
			if (dizi[j] < dizi[minEleman]) {
				minEleman = j;
			}
		}
		araEleman = dizi[i];
		dizi[i] = dizi[minEleman];
		dizi[minEleman] = araEleman;
	}

	for (int a = 0; a < 8; a++) {
		cout << dizi[a] << "\t";
	}
}