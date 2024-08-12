#include <iostream>
#include <iomanip>
#include <fstream>
#include <bitset>
#include <vector>
#include <string>

#define MAX 1024

int diag1, diag2;
int corn, cntr, sides;
std::vector<int> col(MAX), fil(MAX);
std::bitset<MAX*MAX> b;

std::string resolver(int n) {
    int num;
    bool par = ((n % 2)== 0);
    bool diabolico = false;
    bool esoterico = false;

    for (int i = 0; i < n; i++) { // Fila
        for (int j = 0; j < n; j++) { // Columna
            std::cin >> num;

            fil[i] += num;
            col[j] += num;
            
            // Si es diag1
            if (i == j) diag1 += num;

            // Si es diag2
            if (i + j == n - 1) diag2 += num;

            //Si es esquina
            if ((i == 0 && j == 0) || 
                (i == 0 && j == n - 1) || 
                (i == n - 1 && j == 0) || 
                (i == n - 1 && j == n - 1)) 
                corn += num;
      
            // Si es lado central
            if ((i == 0 && ((j == n / 2) || ((j == n / 2 - 1) && par))) ||// N
                (i == n - 1 && ((j == n / 2) || ((j == n / 2 - 1) && par ))) || // S
                (j == 0 && ((i == n / 2) || ((i == n / 2 - 1) && par ))) || // E
                (j == n - 1 && ((i == n / 2) || ((i == n / 2 - 1) && par ))))//W
                sides += num;
            
            // Si es centro
            if ((i == n / 2 && j == n / 2) ||
                (par && ((i == n / 2 && j == n / 2 - 1) ||
                    (i == n / 2 - 1 && j == n / 2) ||
                    (i == n / 2 - 1 && j == n / 2 - 1))))
                cntr += num;

            if (num <= MAX * MAX) b[num - 1] = false;
        }
    }

    // Finished reading matrix

    // Check diabolico
    diabolico = diag1 == diag2;
    if (!diabolico) return "NO\n";

    for (int i = 0; i < n; i++) {
        diabolico &= diag1 == fil[i];
        diabolico &= diag1 == col[i];
        if (!diabolico) return "NO\n";
    }

    // Check esoterico
    b <<= MAX * MAX - n;
    esoterico = diabolico && b.none();
    if (!esoterico) return "DIABOLICO\n";

    esoterico &= (float)corn == 4.0 * diag1 / n;
    if (!esoterico) return "DIABOLICO\n";

    if (par) esoterico &= (float)sides == 8.0 * diag1 / n && (float)cntr == 4.0 * diag1 / n;
    else esoterico &= (float)sides == 4.0 * diag1 / n && (float)cntr == (float)diag1 / n;
    if (!esoterico) return "DIABOLICO\n";

    return "ESOTERICO\n";
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!n)
        return false;

    diag1 = 0;
    diag2 = 0;
    corn = 0;
    cntr = 0;
    sides = 0;
    col.clear(); col.resize(n);
    fil.clear(); fil.resize(n);
    b.reset(); b.flip();

    std::string sol = resolver(n);

    // escribir sol
    std::cout << sol;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
