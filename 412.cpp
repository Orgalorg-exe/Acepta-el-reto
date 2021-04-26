#include <iostream>

using namespace std;

const int MAX_TAM = 50;
const char BLANCO = '.', NEGRO = 'X';
char v[MAX_TAM][MAX_TAM];
int f, c;

void FloodFill(int x, int y, char new_color);
bool hayOvejaBlanca();

int main() {

	cin >> c >> f;

	while (cin) {

		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> v[i][j];
			}
		}

		FloodFill(0, 0, NEGRO);
	
		if (hayOvejaBlanca())
			cout << "SI\n";
		else
			cout << "NO\n";

		cin >> c >> f;
	}

	return 0;
}

void FloodFill(int x, int y, char new_color) {
	if ((x < 0  || x >= c )||(y < 0 || y >= f)) {
		return;
	}
	else if ( v[y][x] == new_color) {
		return;
	}

	v[y][x] = new_color;
	FloodFill(x - 1, y, new_color);
	FloodFill(x, y - 1, new_color);
	FloodFill(x + 1, y, new_color);
	FloodFill(x, y + 1, new_color);
}
bool hayOvejaBlanca() {

	bool hayBlanca = false;
	int x = 2, y = 2;

	while (y < f - 2 && v[y][x] != BLANCO) {
		x++;
		if (x >= c - 2) {
			x = 2;
			y++;
		}
	}

	if (y < f - 2)
		hayBlanca = true;

	return hayBlanca;
}