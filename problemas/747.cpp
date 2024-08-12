#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 50;

int f, c;
char matriz[MAX][MAX];

int despX[4] = { 0, 1, 0, -1 };
int despY[4] = { -1, 0, 1, 0 };

bool isInside(int x, int y) {
    return 0 <= x && x < c && 0 <= y && y < f;
}

bool resolver(int x, int y) {
    if (x == c - 1 && y == f - 1) return true;

    matriz[y][x] = 'v';
    

    bool ret = false;
    for (int i = 0; i < 4; i++) {
        if (isInside(x + despX[i], y + despY[i])) {
            if (matriz[y + despY[i]][x + despX[i]] == '.') {
                ret |= resolver(x + despX[i], y + despY[i]);
                if (ret) return true;
            }
        }
    }

    return false;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    std::cin >> f >> c;

    if (!f || !c)
        return false;

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> matriz[i][j];
        }
    }

    bool sol = resolver(0, 0);

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
