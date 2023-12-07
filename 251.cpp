#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


TipoSolucion resolver(TipoDatos datos) {


}

void resuelveCaso() {
    short tiposMonedas, maxProcesable;
    std::cin >> tiposMonedas >> maxProcesable;

    std::vector<int> monedas(tiposMonedas);
    for (int i = 0; i < tiposMonedas; i++) {
        std::cin >> monedas[i];
    }

    int sol = resolver(datos);
    
    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}