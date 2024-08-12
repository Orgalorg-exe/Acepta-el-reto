#include<iostream>
#include<string>

using namespace std;

const int MAX = 100000;

string solBocadillos(int n, int v[]);
int numBocadillos(int n, int v[]);
void lecturaDelVector(const int n, int v[]);

int main() {

	int n, v[MAX];
	int numBocadillos = 0;
	cin >> n;

	while (n != 0) {
		lecturaDelVector(n, v);
		cout << solBocadillos(n, v) << endl;

		cin >> n;
	}

	return 0;
}

string solBocadillos(int n, int v[]) {
	string ret = "NO";
	int numB = numBocadillos(n, v);

	if (numB != n)
		ret = "SI " + to_string(numB);

	return ret;
}


int numBocadillos(int n, int v[]) {

	int i = n - 1;
	long long int suma = 0;
	int ret = n;

	while (i > -1) {
		if (v[i] == suma) {
			ret = i + 1;
		}
		suma += v[i];
		--i;
	}

	return ret;
}

void lecturaDelVector(const int n, int v[]) {
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}
