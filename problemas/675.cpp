#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

#define MAX 10000

bool esBinario(int n){

    while(n != 0){
        int r = n%10;
        if(r != 1 && r != 0) return false;
        n /=10;
    }

    return true;
}

void rellenarMem(std::vector<int> & mem){
    for(int i = 0; i < mem.capacity(); i++){
        if (esBinario(i)) mem[i] = 0;
        else{
            for(int j = 1; j <= i/2; j++){
                mem[i] = std::min(mem[j] + mem[i-j] + 1, mem[i]);
            }

            for(int j = 2; j <i/2; j++){
                if(i % j == 0) 
                    mem[i] = std::min(mem[j] + mem[i/j] + 1, mem[i]);
            }
        }
    }
}


bool resuelveCaso(std::vector<int> const & mem) {
   int n;
    std::cin >> n;

   if (n == 0)
      return false;
   
   std::cout << mem[n] << "\n";
   
   return true;
}

int main() {

    std::vector<int> mem(MAX +1, INT16_MAX);
    rellenarMem(mem);

    while (resuelveCaso(mem));

   return 0;
}
