#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const& v, int n) {
    if (n == 0) return 0;
    else if (n == 1) return v[0];

    int sol = 0;
    for (int i = n - 1; i > 0; i--) {
        if (v[i] - v[i - 1] > sol) {
            sol = v[i] - v[i - 1];
        }
        else if (v[i] - v[i - 1] == sol) {
            sol++;
        }
    }

    if (v[0] > sol) {
        sol = v[0];
    }
    else if (v[0] == sol) {
        sol++;
    }

    return sol;
}

void resuelveCaso() {
    int n; // n <= 100.000
    std::cin >> n;

    std::vector<int> v(n);
    // V i , 0 <= i < n; v[i] <= 1.000.000.000
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int sol = resolver(v, n);

    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}