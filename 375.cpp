#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

std::string resolver(std::string s) {
    std::string ret = "";
    
    short n = (s[0] - '0')*10 + (s[1] -'0');
    int comp = (n + 18)%36;
    if (comp == 0) comp = 36;
    if (comp <10) ret = "0";
    ret += std::to_string(comp);
    if(s.length() == 3){
        if (s[2] == 'L') ret += "R";
        else if (s[2] == 'R') ret += "L";
        else ret += "C";
    }

    return ret;
}

bool resuelveCaso() {
    std::string s;
    std::getline(std::cin, s, '\n');

    if (! std::cin)
        return false;
    
    std::string sol = resolver(s);
    
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}