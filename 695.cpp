#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void count_digits(std::vector<int> &v, int n) {
    while (n) {
        int r = n % 10;
        n /= 10;

        v[r]++;
    }
}

int max_num(std::vector<int> v) {
    long long ret = 0, i = 9;
    while (i >= 0) {
        if (v[i]) { ret += i; ret *= 10; v[i]--; }
        else i--;
    }
    return ret / 10;
}

int min_num(std::vector<int> v) {
    long long ret = 0, i = 1;
    while (i < 10) {
        if (v[i]) { ret += i; ret *= 10; v[i]--; }
        else i++;
    }
    return ret / 10;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    std::vector<int>d_count(10, 0);
    count_digits(d_count, n);

    int max = max_num(d_count);
    int min = min_num(d_count);
    int diff = max - min;
    int div = diff / 9;

    std::cout << max << " - " << min << " = " << diff << " = " << div << " x 9\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}