#include <iostream>

using namespace std;

int calculadoraPolaca();

int main() {

	int c;
	cin >> c;

	for (c; c > 0; --c) {
		cout << calculadoraPolaca() << endl;
	}

	return 0;
}
/* mi solución
int calculadoraPolaca(char op) {

	char op1, op2;
	int num1, num2;

	cin >> op1;
	if (isdigit(op1)) {

		num1 = op1 - '0';

		cin >> op2;
		if (isdigit(op2))
			num2 = op2 - '0';
		else
			num2 = calculadoraPolaca(op2);
	}
	else {

		num1 = calculadoraPolaca(op1);

		cin >> op2;
		if (isdigit(op2))
			num2 = op2 - '0';
		else
			num2 = calculadoraPolaca(op2);
	}


	if (op == '+')
		return num1 + num2;
	else if (op == '*')
		return num1 * num2;
	else if (op == '-')
		return num1 - num2;
	else if (op == '/')
		return num1 / num2;
}*/

int calculadoraPolaca() {

	char c;
	cin >> c;

	if (c == '0') return 0;
	if (c == '1') return 1;
	if (c == '2') return 2;
	if (c == '3') return 3;
	if (c == '4') return 4;
	if (c == '5') return 5;
	if (c == '6') return 6;
	if (c == '7') return 7;
	if (c == '8') return 8;
	if (c == '9') return 9;

	if (c == '+') return calculadoraPolaca() + calculadoraPolaca();
	if (c == '*') return calculadoraPolaca() * calculadoraPolaca();
	if (c == '-') return calculadoraPolaca() - calculadoraPolaca();
	if (c == '/') return calculadoraPolaca() / calculadoraPolaca();
}