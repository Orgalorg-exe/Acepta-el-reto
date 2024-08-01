#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>

int v[1000001];

std::string resolver(int i, int j){
    if (v[i] == v[j])
        return "SI";
    return "NO";
}

bool resuelveCaso() {
    std::string s;
    std::getline(std::cin, s,'\n');

    int numIntervalos;
    std::cin >> numIntervalos;

    if (numIntervalos == 0)
        return false;

    int sLen = (int)s.size();
    v[0] = 0;
    for(int c = 1; c < sLen; c++){
        v[c] = (s[c] == s[c - 1]) ? v[c - 1] : v[c-1] + 1;
    }

    for(int n = 0; n < numIntervalos; n++){
        
        int i, j;
        //std::cin >> i >> j;
        scanf("%d%d\n", &i, &j);

        std::string sol = resolver(i, j);

        std::cout << sol << '\n';

    }

    std::cout << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}