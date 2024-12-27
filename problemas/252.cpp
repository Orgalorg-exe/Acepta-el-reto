#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>

bool resolver(std::string str, int a, int b) {
    if (a >= b ) return true;
    
    while (!isalpha(str[a])) a++;
    while (!isalpha(str[b])) b--;

    if (tolower(str[a]) == tolower(str[b])) return resolver(str, a+1, b-1);
    return false;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    std::string str;

    std::getline(std::cin, str);

    if (str == "XXX")
        return false;

    bool sol = resolver(str, 0, str.length()-1);

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
