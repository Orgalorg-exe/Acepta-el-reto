#include <iostream>

using namespace std;

const int MOD = 1000000007;
const double SQRT5 = sqrt(5);
const double PHI = (1 + SQRT5) / 2;
const double UNO_MENOS_PHI = 1 - PHI;

int Bonacci(int n, int x, int y);

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	while (cin) {
		cout << Bonacci(n, x, y) << endl;
		cin >> n >> x >> y;
	}

	return 0;
}

int Bonacci(int n, int x, int y) {

	if (n == 0)
		return x;
	else if (n == 1)
		return y;


	
}

double pow(double n) {
	
}