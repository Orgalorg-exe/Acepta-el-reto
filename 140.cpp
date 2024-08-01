#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(int n) {

	//Caso base
	if (n < 10) {
		std::cout << n;
		return n;
	}

	//LLamada recursiva
	int ret = resolver(n / 10);
	std::cout << " + " << n % 10;
	return ret + (n % 10);
}


bool resuelveCaso() {
	int n;
	std::cin >> n;

    if (n <= -1)
        return false;
    
    std::cout << " = " << resolver(n) << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
