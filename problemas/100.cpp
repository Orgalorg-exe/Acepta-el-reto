#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

const int CONST = 6174, MAX_TAM = 4;

int resolver(int n) {
	int ret = 1;
	int v[MAX_TAM];
	bool dif = false;

	if (n == CONST)
		return  0;

	for (int i = 0; i < MAX_TAM; i++) {
		v[i] = n % 10;
		n /= 10;
		if (i > 0 && !dif)
			dif = v[i] != v[i - 1];
	}

	if (!dif) 
		return 8;

	std::sort(v, v+MAX_TAM);

	int asc = 0, des = 0;
	for (int i = 0; i < MAX_TAM; i++) {
		asc = asc * 10 + v[i];
		des = des * 10 + v[MAX_TAM - (i+1)];
	}

	ret += resolver(des - asc);

	return ret;
}

void resuelveCaso() {
    int n;
	std::cin >> n;
    
    int sol = resolver(n);
    
    std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}