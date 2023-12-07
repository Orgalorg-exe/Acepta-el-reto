#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

std::string resolver(std::string s) {
    std::string ret = std::string(1, s[0]);
	int sum = s[0] - '0';

	for(int i  = 1; i < s.length(); i++){
		sum += (s[i] - '0');
		ret += " + " + std::string(1, s[i]);
	}
    
	ret += " = " + std::to_string(sum);

	return ret;
}

bool resuelveCaso() {
    std::string s;
	std::cin >> s;

	int n = std::stoi(s);

    if (n == -1)
        return false;
    
    std::string sol = resolver(s);
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
