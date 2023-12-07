#include <iostream>
#include <iomanip>
#include <fstream>


TipoSolucion resolver(TipoDatos datos) {
    
    
}

bool resuelveCaso() {
    // leer los datos de la entrada
    
    if (! std::cin)
        return false;
    
    TipoSolucion sol = resolver(datos);
    
    // escribir sol
    
    
    return true;
    
}

int main() {

    while (resuelveCaso());

    return 0;
}