#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

#define BASE 16

/* (n)_10 -> (n)_16 con std::hex
bool optimization(int n) {
    std::stringbuf buffer;
    std::ostream os(&buffer);
    os << std::hex << n;
    std::string s = buffer.str();
    return !(s[s.length()-1] == '0' || s[s.length()-1] == '1' || s[s.length()-1] == '4' || s[s.length()-1] == '9');
}
*/

bool optimization(char n) {
    short num = 0;
    
    while (n != '\n') {
        num = (num * 10) + (short)(n - '0');
        if (num >= BASE) num %= BASE;
        std::cin.get(n);
    }

    return !(num == 0 || num == 1 || num == 4 || num == 9);
}

std::string resolver(char n) {
    bool esImperfecto = optimization(n);
    if (esImperfecto) return "IMPERFECTO";
    return "NO SE";
}

bool resuelveCaso() {
    char n;
    std::cin.get(n);

    if (! std::cin)
        return false;
    
    std::string sol = resolver(n);
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}