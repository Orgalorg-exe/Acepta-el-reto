#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

bool resolver(std::string n) {
    int l = n.length();
    int i = (n[0] - '0')%l;
    int cnt = 1;

    while (i != 0 && cnt <= l) {
        i = ((n[i] - '0') + i) % l;
        cnt++;
    }

    return i == 0 && cnt == l;
}

void resuelveCaso() {
    // leer los datos de la entrada
	std::string n;
	std::cin >> n;

    bool sol = resolver(n);
   
    if (sol) std::cout << "SALTARINES\n";
    else std::cout << "NORMALES\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}