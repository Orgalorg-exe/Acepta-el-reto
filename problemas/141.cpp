#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>


bool resolver(std::string line) {

	std::stack<char> pila;

	int i = 0;

	for (char c : line) {
		
		if (c == '(') pila.push(')');
		else if (c == '{') pila.push('}');
		else if (c == '[') pila.push(']');

		else if (c == ')' || c == '}' || c == ']') {
			if (pila.empty() || pila.top() != c) {
				return false;
			}
			pila.pop();
		}
	}

	return pila.empty();
}

bool resuelveCaso() {
	// leer los datos de la entrada
	std::string line;
	std::getline(std::cin, line);

	if (!std::cin)
		return false;

	bool sol = resolver(line);

	// escribir sol
	if (sol) std::cout << "YES\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}