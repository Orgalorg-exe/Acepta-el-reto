#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>

std::string line, a, b;
char c;

void resuelveCaso() {

    std::getline(std::cin, line);
    for (char c : line) {
        if (isalpha(c)) {
            a.push_back(tolower(c));
        }
    }

    std::getline(std::cin, line);
    for (char c : line) {
        if (isalpha(c)) {
            b.push_back(tolower(c));
        }
    }

    if (a == b) {
        std::cout << "SI\n";
    }
    else {
        std::cout << "NO\n";
    }

    a = "";
    b = "";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    std::getline(std::cin, line);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}