#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    int L, H;
    std::cin >> L >> H;

    if (!L && !H)
        return false;

    int sol = 0;
    bool dentro = false;
    char c;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < H; j++) {
            std::cin >> c;
            if (c == '.' && dentro) {
                sol += 2;
            }
            else if (c == '/' || c == '\\') {
                sol++;
                dentro = !dentro;
            }
        }
    }


    std::cout << sol/2 << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}