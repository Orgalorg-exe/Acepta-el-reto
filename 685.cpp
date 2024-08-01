#include <iostream>
#include <iomanip>
#include <fstream>

std::string resolver(int Tx, int Ty, int Ix, int Iy) {
    //mismo eje x
    if (Tx == Ix) return "SI";

    //mismo eje y
    if (Ty == Iy) return "SI";

    //en angulo de 45º
    // (Tx, Ty) y (Ix, Iy) las esquinas de la diagonal de un cuadrado
    if (std::abs(Tx - Ix) == std::abs(Ty - Iy)) return "SI";

    return "NO";
}


bool resuelveCaso() {
    int Tx, Ty, Ix, Iy;
    std::cin >> Tx >> Ty >> Ix >> Iy;

    if (!Tx && !Ty && !Ix && !Iy)
        return false;


    std::string sol = resolver(Tx, Ty, Ix, Iy);

    std::cout << sol << "\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}