#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using vii = std::vector<std::vector<int>>;
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };

bool ok(int i, int j, int n) {
    return 0 <= i && i < n && 0 <= j && j < n;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    vii matriz(n, std::vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            std::cin >> matriz[i][j];
        }
    }

    long long sol = matriz[n/2][n/2];
    int i = n / 2, j = n / 2;

    for (int step = 1, dir = 0; step <= n; step++, dir = (dir + 1)%4) {
        for (int s = 0; s < step; s++) {
                i += y[dir];
                j += x[dir];
            if (ok(i, j, n)) {
                sol += matriz[i][j];
            }
            else break;
        }
    }

    std::cout << sol << "\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}