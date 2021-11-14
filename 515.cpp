#include <iostream>
using namespace std;

int sol(int n);

int main() {
	int n;
	cin >> n;

	while (n != 0) {
		cout << sol(n) << endl;
		cin >> n;
	}

	return 0;
}

/* { Pre: 0 < n <= 10000 } */ 
int sol(int n) {

	//O(1)
	if (n == 1 || !(n % 2))
		return n;
	return n - 1;
}
/* { Pos: } */