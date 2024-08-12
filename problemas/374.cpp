#include <iostream>
#include <iomanip>
#include <fstream>

struct  t_sol {
    unsigned long long tempMin;
    unsigned long long tempMax;
    unsigned long long tempMinF;
    unsigned long long tempMaxF; 
};

void resolver(t_sol * sol) {
    unsigned long long n;
    std::cin >> n;

    while(n){
        if(n == sol->tempMin){
            sol->tempMinF++;
        } else if (n < sol->tempMin){
            sol->tempMin = n;
            sol->tempMinF = 1;
        }

        if(n == sol->tempMax){
            sol->tempMaxF++;
        } else if (n > sol->tempMax){
            sol->tempMax = n;
            sol->tempMaxF = 1;
        }


        std::cin >> n;
    }
}

void resuelveCaso() {
    t_sol sol;
    sol.tempMin = 1000000000000000000;
    sol.tempMinF = 0;
    sol.tempMax = 0;
    sol.tempMaxF = 0;
    
    resolver(&sol);
    
    std::cout << sol.tempMin << " " << sol.tempMinF << " " << sol.tempMax << " " << sol.tempMaxF << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}