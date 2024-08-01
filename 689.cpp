#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>    

std::vector<std::set<int>> enemigos, amigos;
std::vector<bool> vis;

int dfs(int v) {

    int tam = 1; vis[v] = true;
    for (int w : amigos[v]) {
        if (!vis[w])
            tam += dfs(w);
    }

    return tam;
}


bool resuelveCaso() {
    int V, P, A;
    std::cin >> V >> P >> A;

    if (!std::cin)
        return false;

    enemigos.assign(V, {});
    amigos.assign(V, {});
    vis.assign(V, false);



    int a, b;
    std::set<int> izq, der;

    //Las peleas
    for (int i = 0; i < P; i++) {
        std::cin >> a >> b;
        a--; b--;
        enemigos[a].insert(b);
        enemigos[b].insert(a);
    }

    // Las amistades
    for (int i = 0; i < V; i++) {
        for (int e : enemigos[i]) {
            for (int ee : enemigos[e]) {
                amigos[i].insert(ee);
            }
        }
    }


    // Los grupitos
    std::vector<std::pair<int, int>> grupitos;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            int a = 0, b = 0;
            a = dfs(i);
            if (!enemigos[i].empty()) {
                b = dfs(*enemigos[i].begin());
            }
            grupitos.push_back(std::make_pair(a, b));
        }
    }

    //Dinámica
    std::vector<bool> mem(A+1, false);
    mem[0] = true;
    for (auto g : grupitos) {
        for (int i = A; i > 0; i--) {
            bool no_considerar_g = mem[i];
            bool considerar_gFirst = (i - g.first >= 0) ? mem[i - g.first] : false;
            bool considerar_gSecond = (i - g.second >= 0) ? mem[i - g.second] : false;
            mem[i] = no_considerar_g || considerar_gFirst || considerar_gSecond;
        }
    }

    //Recuperar la solución
    int i = A;
    while (!mem[i] && i >= 0) i--;

    std::cout << i << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}