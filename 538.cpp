#include <iostream>

std::string sol(int a, int b);

int main() {

	int a, b;
	std::cin >> a >> b;
	while (a != 0 || b != 0) {
		std::cout << sol(a, b) << std::endl;
		std::cin >> a >> b;
	}

	return 0;
}

std::string sol(int a, int b) {
	if (a >= b) return "CUERDO";
	return "SENIL";
}