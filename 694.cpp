#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


std::string resolver(std::string s) {
    std::string ret = "";

    if (isupper(s.at(0))) ret.push_back(s.at(0));

    std::size_t found = s.find_first_of(' ');
    while (found != std::string::npos)
    {
        if (isupper(s.at(found+1))) ret.push_back(s.at(found+1));
        found = s.find_first_of(' ', found + 1);
    }

    return ret;
}


void resuelveCaso() {
    std::string input;
    std::getline(std::cin, input);

    std::string sol = resolver(input);

    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::string aux;

    std::cin >> numCasos;
    std::getline(std::cin, aux);
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}