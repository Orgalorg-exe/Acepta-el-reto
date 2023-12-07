#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(int h, int c, int& p) {

	//Caso base
	if (c <= h * 2)
		return 0;

	//Caso recursivo
	int pp = ((c / 3) * 2) + c % 3;
	int pl = c / 3;
	p++;

	resolver(h, pp, p);
	resolver(h, pl, p);
	return p;
}

bool resuelveCaso() {
    int h, c, p = 0;
	std::cin >> h >> c;

    if (h == 0)
        return false;
    
    int sol = resolver(h, c, p);
    
    std::cout << sol << '\n';
    
    return true;
    
}

int main() {

    while (resuelveCaso());

    return 0;
}
