#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::string resolver(std::vector<int> & v, int i, int j) {

    if (v[i] == v[j]) return "SI";

    return "NO";
}

bool resuelveCaso() {
    std::string s;
    std::cin >> s;

    int numIntervalos;
    std::cin >> numIntervalos;

    if (!numIntervalos)
        return false;

    std::vector<int> v(s.length());
    v[0] = 0;
    for(int c = 1; c < s.length(); c++){
        v[c] = v[c-1];
        if (s[c] != s[c-1]) v[c]++;
    }

    for(int n = 0; n < numIntervalos; n++){
        
        int i, j;
        std::cin >> i >> j;

        std::string sol = resolver(v, i, j);

        std::cout << sol << '\n';
    }

    std::cout << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}