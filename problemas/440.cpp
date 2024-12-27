#include <iostream>
#include <iomanip>
#include <fstream>

void resolver(int n, int& numGrupos, int& minGrupo, int& maxGrupo) {
    int aux = 1;
    int c, p;

    std::cin >> c;

    for (int i = 1; i < n; i++) {
        std::cin >> p;

        if (p < c) {
            numGrupos++;
            minGrupo = (aux < minGrupo) ? aux : minGrupo;
            maxGrupo = (aux > maxGrupo) ? aux : maxGrupo;
            c = p;
            aux = 1;
        }
        else {
            aux++;
        }
    }

    minGrupo = (aux < minGrupo) ? aux : minGrupo;
    maxGrupo = (aux > maxGrupo) ? aux : maxGrupo;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n) return false;

    int num=1, min=10000, max=0;
    resolver(n, num, min, max);

    std::cout << num << ' ' << min << ' ' << max << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
