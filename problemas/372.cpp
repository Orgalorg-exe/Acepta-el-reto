#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

std::string resolver(std::string datos) {
    std::string ret = "";
    int l = datos.size();

    if (isupper(datos[0])) {
        datos[0] = tolower(datos[0]);
        datos[l - 1] = toupper(datos[l - 1]);
    }

    for (int i = l-1; i >= 0; --i) {
        ret.push_back(datos[i]);
    }

    return ret;
}

void resuelveCaso() {
    std::string s;
    std::cin >> s;

    std::string sol = resolver(s);
    
    std::cout << sol << std::endl;;
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}