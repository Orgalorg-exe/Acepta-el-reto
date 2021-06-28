//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes
const int MAX = 50;
const char BLANCO = '.', NEGRO = 'X';

//Declaración de funciones
void lecturaDeDatos(int x, int y, char v[][MAX]);
void FloodFill(int x, int maxX, int y, int maxY, char v[][MAX], char new_color);
string ovejaBlanca(int x, int y, char v[][MAX]);
bool hayOvejaBlanca(int x, int y, char v[][MAX]);


//MAIN
int main() {
	char v[MAX][MAX];
	int x, y;

	cin >> x >> y;

	while (cin) {
		lecturaDeDatos(x, y, v);
		FloodFill(0, x, 0, y, v, NEGRO);
		cout << ovejaBlanca(x, y, v) << endl;
		cin >> x >> y;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

void lecturaDeDatos(int x, int y, char v[][MAX]) {
	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			cin >> v[i][j];
		}
	}
}


void FloodFill(int x, int maxX, int y, int maxY, char v[][MAX], char new_color) {
	
	if ((x < 0  || x >= maxX )||(y < 0 || y >= maxY)) {
		return;
	}
	else if ( v[y][x] == new_color) {
		return;
	}

	v[y][x] = new_color;
	FloodFill(x - 1, maxX, y, maxY, v, new_color);
	FloodFill(x, maxX, y - 1, maxY, v, new_color);
	FloodFill(x + 1, maxX, y, maxY, v, new_color);
	FloodFill(x, maxX, y + 1, maxY, v, new_color);
}

string ovejaBlanca(int x, int y, char v[][MAX]) {
	if (hayOvejaBlanca(x, y, v))
		return "SI";
	return "NO";
}

/* { Pre: } */
bool hayOvejaBlanca(int x, int y, char v[][MAX]) {

	int i = 2, j = 2;

	while (i < y - 2 && v[i][j] != BLANCO) {
		j++;
		if (j >= x - 2) {
			j = 2;
			i++;
		}
	}

	return i < y - 2;
}
/* { Pos: } */