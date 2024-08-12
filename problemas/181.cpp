#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(std::vector<std::vector <char>> const &grid, int n) {
    std::vector<int> mem(n, 0);
    mem[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X') {
                mem[j] = 0;
            }
            else if (j >= 1) {
                mem[j] += mem[j - 1];
            }
        }
    }

    return mem[n - 1];
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;

    std::vector<std::vector <char>> grid(n, std::vector<char>(n));
    for (int i = n-1; i >=0 ; i--) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    int sol = resolver(grid, n);

    std::cout << sol << "\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
