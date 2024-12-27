#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resolver(
    // Datos del problema
    int N,
    const std::vector<std::pair<int, int>>& canciones,

    // Sol parcial
    int k,
    int solActual,
    int & mejorSol,
    
    // Marcaje
    int dur_a,
    int dur_b,
    std::vector<int>& punts_acum,
    std::vector<int>& durs_min
) {
    // Caso Base
    if (k == N) {
        if (solActual > mejorSol) {
            mejorSol = solActual;
        }
        return;
    }

    // Caso Recursivo

    // Pruebo a meter la cancion en un lado de la cinta
    if (dur_a >= canciones[k].first) {
        // Si puedo mejorar la puntuación
        if (solActual + canciones[k].second + punts_acum[k+1] > mejorSol){
            resolver(N, canciones, k+1, solActual+canciones[k].second, mejorSol, dur_a - canciones[k].first, dur_b, punts_acum, durs_min);
        }
    }

    // Si las cintas tienen duraciones distintas,
    // pruebo a meter la cancion en la otra cara
    // Evito repetir ramas
    if (dur_a != dur_b){
        // Si la cancion entra
        if (dur_b >= canciones[k].first) {
            // Si mejoro la solucion
            if (solActual + canciones[k].second + punts_acum[k + 1] > mejorSol) {
                resolver(N, canciones, k + 1, solActual + canciones[k].second, mejorSol, dur_a, dur_b - canciones[k].first, punts_acum, durs_min);
            }
        }
    }

    // Pruebo a no meter la cancion
    if (k == N-1 || // Si ya completé la solución 
       (dur_a >= durs_min[k+1] || dur_b >= durs_min[k+1]) || // O queda alguna canción que puedo meter
       (solActual > mejorSol) // O si ya no puedo meter más canciones pero mi solución actual mejora mi mejor solución
    ) {
        resolver(N, canciones, k + 1, solActual, mejorSol, dur_a, dur_b, punts_acum, durs_min);
    }
}

bool resuelveCaso() {
    int N;
    std::cin >> N;

    if (!N)
        return false;

    int dur;
    std::cin >> dur;

    std::vector<std::pair<int, int>> canciones(N);
    std::vector<int> punts_acum(N+1, 0);
    std::vector<int> durs_min(N+1, 1001);

    int d, p;
    for (int i = 0; i < N; i++) {
        std::cin >> d >> p;
        canciones[i] = std::make_pair(d, p);
        punts_acum[i] = p;
        durs_min[i] = d;
    }

    for (int i = N - 2; i > 0; i--) {
        punts_acum[i] += punts_acum[i + 1];
        durs_min[i] = (durs_min[i] < durs_min[i + 1]) ? durs_min[i] : durs_min[i + 1];
    }

    int sol = 0;
    resolver(N,canciones, 0, 0, sol, dur, dur, punts_acum, durs_min);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
