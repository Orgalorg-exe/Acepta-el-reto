#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

//automata
std::string resolver(std::string datos) {
    std::string ret = "";
    int coef = 1, exp = 0;
    int max = datos.length(), i = 0;
    int state = 0;

    while (i < max) {
        switch (state) {
            case 0:
                if (isdigit(datos[i])) {
                    coef *= int(datos[i] - '0');
                    state = 1;
                }
                else if (datos[i] == 'x') {
                    state = 2;
                }
                break;

            case 1:
                i++;
                while (i < max && isdigit(datos[i])) {
                    coef = coef * 10 + int(datos[i] - '0');
                    i++;
                }

                if (i >= max) {
                    if (ret.empty()) {
                        ret.append("0");
                    }                    
                }
                else if (datos[i] == 'x') {
                    state = 3;
                }
                break;

            case 2:
                i++;
                if (i >= max || datos[i] == '+') {
                    if (!ret.empty()) {
                        ret.append("+");
                    }
                    ret.append("1");
                    state = 0;
                }
                else if (datos[i] == '^') {
                    state = 4;
                }
                i++;
                break;

            case 3:
                i++;
                if (i >= max) {
                    if (!ret.empty()){
                        ret.append("+");
                    }
                    ret.append(std::to_string(coef));
                }
                else if (datos[i] == '^') {
                    state = 4;
                }
                else if (datos[i] == '+') {
                    state = 0;
                    if (!ret.empty()){
                        ret.append("+");
                    }
                    ret.append(std::to_string(coef));
                    coef = 1;
                }
                i++;
                break;

            case 4:
                exp = int(datos[i] - '0');
                i++;
                while (i < max && isdigit(datos[i])) {
                    exp = exp * 10 + int(datos[i] - '0');
                    i++;
                }
                if (!ret.empty()) {
                    ret.append("+");
                }
                ret.append(std::to_string(coef * exp) + "x");
                if (exp - 1 > 1) ret.append("^" + std::to_string(exp - 1));
                if (i < max && datos[i] == '+') {
                    state = 0;
                    coef = 1;
                    exp = 0;
                }
                i++;
                break;
        }
        
    }

    return  ret;
}


bool resuelveCaso() {
    std::string polinomio;
    std::cin >> polinomio;

    if (!std::cin)
        return false;

    std::string derivada = resolver(polinomio);

    std::cout << derivada << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}