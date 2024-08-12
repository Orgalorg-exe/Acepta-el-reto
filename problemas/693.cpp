#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>


long long resolver(
    std::map<int, int> const& map_pos_indx,
    std::vector<int> const& v_indx_pos,
    std::vector<int> const& beneficios,
    int N, int K
) {
    std::vector<long long> mem(N, 0);
    mem[0] = beneficios[0];

    for (int i = 1; i < N; i++) {
        //Considerar
        long long considerar = beneficios[i];
        std::map<int, int>::const_iterator itlow;
        int key = v_indx_pos[i] - K;
        itlow = map_pos_indx.lower_bound(key);
        // Si lower_bound > clave y lower_bound != begin
        //   entonces añadir lower_bound--;
        if (itlow->first > key && itlow != map_pos_indx.begin()) {
            itlow--;
            considerar += mem[itlow->second];
        }
        // Si lower_bound == clave
        //   entonces añadir lower_bound
        else if (itlow->first == key) {
            considerar += mem[itlow->second];
        }

        //No considerar
        long long no_considerar = mem[i - 1];

        mem[i] = std::max(considerar, no_considerar);
    }

    return mem[N - 1];
}

bool resuelveCaso() {
    int N, K;
    std::cin >> N >> K;
    if (!std::cin)
        return false;

    std::map<int, int> mapa_posiciones_indx;
    std::vector<int> vector_indx_posiciones;
    int aux;
    for (int i = 0; i < N; i++) {
        std::cin >> aux;
        mapa_posiciones_indx.insert({aux, i});
        vector_indx_posiciones.push_back(aux);
    }

    std::vector<int> beneficios;
    for (int i = 0; i < N; i++) {
        std::cin >> aux;
        beneficios.push_back(aux);
    }

    long long sol = resolver(mapa_posiciones_indx, vector_indx_posiciones, beneficios, N, K);

    std::cout << sol << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}