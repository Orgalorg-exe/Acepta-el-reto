#include<iostream>

using namespace std;

int main() {

	int max, min, num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		//Extra big Oof
		cin >> max;
		getchar();
		getchar();
		getchar();
		cin >> min;
		
		if (max >= min) {
			cout << "BIEN" << endl;
		}
		else { cout << "MAL" << endl; }
	}

	return 0;
}