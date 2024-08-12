#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 50;

bool esEstable(int pi, int di, int pd, int dd, int & p) {

	bool i = true, d = true;
	int pi_aux, di_aux, pd_aux, dd_aux;

	if (pi == 0) {
		std::cin >> pi_aux >> di_aux >> pd_aux >> dd_aux;
		i = esEstable(pi_aux, di_aux, pd_aux, dd_aux, pi);
	}
	if (pd == 0) {
		std::cin >> pi_aux >> di_aux >> pd_aux >> dd_aux;
		d = esEstable(pi_aux, di_aux, pd_aux, dd_aux, pd);
	}

	p = pi + pd;
	return i && d && (pi * di) == (pd * dd);
}


std::string resolver(int pi, int di, int pd, int dd) {
	int foo;
	if (esEstable(pi, di, pd, dd, foo))
		return "SI";
	return "NO";
}

bool resuelveCaso() {
	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;
    
    if (pi == 0 && di == 0 && pd == 0 && dd == 0)
        return false;
    
    std::string sol = resolver(pi, di, pd, dd);
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
