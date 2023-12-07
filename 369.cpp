#include <iostream>
#include <iomanip>
#include <fstream>


std::string resolver(int n) {
    std::string ret;

    ret.assign(n, '1');

    return ret;
}

bool resuelveCaso() {
    int n;

    std::cin >> n;

    if (n == 0)
        return false;

    std::string sol = resolver(n);

    std::cout << sol << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}