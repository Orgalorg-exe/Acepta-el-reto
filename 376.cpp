#include <iostream>
#include <iomanip>
#include <fstream>


int resolver(int n) {

    int a, b;
    std::cin >> a >> b;

    if(n == 2){
        if (a < b || b < a) return 1;
        else return 0;
    }
    // else if (n > 2)

    int first;
    int l = a, c = b, r;
    int ret = 0;

    for (int i = 2;  i < n; i++){
        std::cin >> r;
        if (c > l && c > r) ret++;
        l = c; c = r;
    }
    
    if (c > l && c > a) ret++;
    if (a > r && a > b) ret++;

    return ret;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;
    
    int sol = resolver(n);
    
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
