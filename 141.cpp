#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool balanceados(string line);
char apertura(char c);

int main() {

	string line;
	getline(cin,line);
	while (cin) {

		if (balanceados(line))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		getline(cin, line);
	}

	return 0;
}


bool balanceados(string line) {

	stack<char> pila;

	int i = 0;
	bool ret = true;

	while (i < line.length() && ret) {
		
		if (
			line[i] == '(' ||
			line[i] == '{' ||
			line[i] == '['
		) {
			pila.push(line[i]);
		}

		else if (
			line[i] == ')' ||
			line[i] == '}' ||
			line[i] == ']'
		) {
			if (
				!pila.empty() &&
				pila.top() == apertura(line[i])
			) {
				pila.pop();
			}

			else ret = false;
		}

		++i;
	}

	return ret;
}

char apertura(char c) {
	if (c == ')')
		return '(';
	else if (c == '}')
		return '{';
	return '[';
}