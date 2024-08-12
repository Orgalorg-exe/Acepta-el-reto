#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#define MOD 1000000007

std::vector<int> resolver(int n, int m) {
    std::vector<int> v(m + 1, 0);
    v[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = std::min(i, m); j > 0; j--) {
            v[j] = (v[j] + v[j - 1]) % MOD;
        }
    }

    return v;
}

bool resuelveCaso() {
    int n, m;
    std::cin >> n >> m;
    if (n == 0)
        return false;

    std::vector<int> resultado = resolver(n, m);

    std::cout << resultado[0];
    for (int i = 1; i <= m; i++) {
        std::cout << ' ' << resultado[i];
    }
    std::cout << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}