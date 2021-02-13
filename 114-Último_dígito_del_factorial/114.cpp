#include<iostream>

using namespace std;

int ultDigFactorial(int n);

int main() {
	int num, n;
	cin >> num;
	
	for (int i = 0; i < num; ++i) {
		cin >> n;
		cout << ultDigFactorial(n) << endl;
	}

	return 0;
}

int ultDigFactorial(int n) {
	
	int ret;

	if (n == 0 || n == 1) { ret = 1; }
	else if (n == 2) { ret = 2; }
	else if (n == 3) { ret = 6; }
	else if (n == 4) { ret = 4; }
	else { ret = 0; }

	return ret;
}