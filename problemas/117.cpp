#include <iostream>
#include <iomanip>
#include <fstream>

std::string resolver(std::string s) {
    std::string ret = "Hola, " + s + ".";
	return ret;
}

void resuelveCaso() {
    std::string s;
	std::cin >> s >> s;
    
    std::string sol = resolver(s);
    
    std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}