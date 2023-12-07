#include <iostream>
using namespace std;

const int MAX = 10;

bool gana(int v1[], int v2[]);

int main() {
	int v1[MAX], v2[MAX];
	char c;
	int numCasos;
	cin >> numCasos;
	for (; numCasos > 0; --numCasos) {

		for (int j = 0; j < MAX; ++j) {
			v1[j] = 0; v2[j] = 0;
		}

		for (int j = 0; j < 7; ++j) {
			cin >> c;
			v1[(int)(c -'0')] += 1;
		}
		for (int j = 0; j < 7; ++j) {
			cin >> c;
			v2[(int)(c - '0')] += 1;
		}

		if (gana(v1, v2))
			cout << "GANA\n";
		else
			cout << "PIERDE\n";
	}

	return 0;
}

bool gana(int v1[], int v2[]) {
	int i = 0;
	while (i < MAX && v1[i] == v2[i]) {
		++i;
	}
	return i == MAX;
}


/*
bool gana(string num1, string num2) {

	int j = 0;
	bool ret = false;

	while (j < 7 && !ret) {
		if (num1[0] == num2[j]) {
			//Num2 a la derecha
			if (num1[1] == num2[(j + 1) % 7]) {
				int k = 2;
				bool aux = true;
				while (k < 7 && aux) {
					aux &= num1[k] == num2[(j + k)%7];
					++k;
				}
				ret |= aux;
			}

			//Num2 a la izquierda
			if (num1[1] == num2[((j - 1) +7) % 7]) {
				int k = 2;
				bool aux = true;
				while (k < 7 && aux) {
					aux &= num1[k] == num2[((j - k)+7)% 7];
					++k;
				}
				ret |= aux;
			}
		}
		++j;
	}

	return ret;
}
*/
