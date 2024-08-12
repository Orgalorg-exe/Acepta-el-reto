#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int resolver(int n, std::vector<int> v) {
    int ret = 0;
    for (int i = 0; i < n-1; i++)
        ret += v[i]-1;
    ret += v[n-1];
    
    return ret;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;
    
    std::vector<int> v(n, 0);
    for(int i = 0; i < n; i++)
        std::cin >> v[i];

    int sol = resolver(n, v);
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
