#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

int numBarcos;
std::map<int, int> barcos;
int gridLen;
std::vector<std::vector<int>>grid;

bool correcto() {

	for(int i = 0; i < gridLen; i++){
		for (int j = 0; j < gridLen; j++){
			//Cuando encuentra un barco
			if (grid[i][j] == 1){
				grid[i][j] = 0;

				int barcoLen = 1;

				//Puede continuar hacia la derecha o hacia abajo

				//Si continua hacia la derecha
				if (j + 1 < gridLen && grid[i][j + 1] == 1){
					int k = j + 1;
					while(k < gridLen && grid[i][k] == 1){
						grid[i][k] = 0;
						barcoLen++;
						k++;
					}
					
					if (k < gridLen) j = k;
					else {j = 0; i++;} //Check out for loop
				}
				//Si continua hacia abajo
				else if(i+1 < gridLen && grid[i+1][j] == 1){
					int k = i +1;
					while(k  < gridLen && grid[k][j] == 1){
						grid[k][j] = 0;
						barcoLen++;
						k++;
					}
				}

				//Si no era un barco
				if (barcos.count(barcoLen) <= 0) 
					return false;

				barcos[barcoLen]--;
			}
		}
	}

	return true;
}

std::string resolver() {
    if (correcto()) return "SI";
	return "NO";
}

bool resuelveCaso() {
	barcos.clear();
	grid.clear();

	std::cin >> numBarcos;
    if (!numBarcos)
        return false;
    
	 int b;
	for (int i = 0; i < numBarcos; i++){
		std::cin >> b;
		if (barcos.find(b) == barcos.end())
			barcos.insert(std::pair<int, int>(b, 1));
		else
			barcos[b]++;
	}

	std::cin >> gridLen;
	grid = std::vector<std::vector<int>>(gridLen, std::vector<int>(gridLen));
	for (int i = 0; i < gridLen; i++){
		for (int j = 0; j < gridLen; j++){
			std::cin >> grid[i][j];
		}
	}

    std::string sol = resolver();
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
