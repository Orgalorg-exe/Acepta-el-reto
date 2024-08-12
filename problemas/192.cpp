#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::vector<bool> mem(20001);

void innit_mem() {
    mem[0] = false;
    mem[1] = true;
    mem[2] = false;
    mem[3] = true;
    mem[4] = false;
    for (int i = 5; i <= 20000; i++) {
        bool minus5 = mem[i - 5];
        bool div3 = (i % 3 == 0) ? mem[i / 3] : false;
        mem[i] = minus5 || div3;
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    if (mem[n])
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

    return true;

}

int main() {

    innit_mem();
    while (resuelveCaso());

    return 0;
}
