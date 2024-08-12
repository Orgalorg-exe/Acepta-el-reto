#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const char* days[6] = { "MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO" };

std::string resolver(double num) {
    std::string ret = "";

    double min = num, max= num, acum = num;
    int day_min = 0, day_max = 0;

    for (int i = 1; i < 6; i++) {
        std::cin >> num;
        
        acum += num;
        
        if (min > num) {
            min = num;
            day_min = i;
        }
        else if (min == num) {
            day_min = -1;
        }

        if (max < num) {
            max = num;
            day_max = i;
        }
        else if (min == num) {
            day_max = -1;
        }
    }

    if (day_max < 0) ret += "EMPATE";
    else ret += days[day_max];

    ret += " ";

    if (day_min < 0) ret += "EMPATE";
    else ret += days[day_min];

    ret += " ";

    if (acum / 6 < num) ret += "SI\n";
    else ret += "NO\n";

    return ret;
}

bool resuelveCaso() {
    double num;

    std::cin >> num;
    if (num == -1)
        return false;

    std::string sol = resolver(num);

    // escribir sol
    std::cout << sol;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
