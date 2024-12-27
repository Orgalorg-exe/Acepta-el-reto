#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 5;

bool resolver(
	//Datos del problema
	int result,
	int nums[],

	//Sol Parcial
	int solParcial,
	int k

) {
	//Caso base
	if (k == MAX)
		return result == solParcial;

	//Caso recursivo
	bool exComb = false;

	int i = 0;
	while (i < 4 && !exComb) {
		switch (i) {
		case 0:
			exComb |= resolver(result, nums, solParcial + nums[k], k + 1);
			break;

		case 1:
			exComb |= resolver(result, nums, solParcial - nums[k], k + 1);
			break;

		case 2:
			exComb |= resolver(result, nums, solParcial * nums[k], k + 1);
			break;

		case 3:
			if (nums[k] != 0 && solParcial % nums[k] == 0)
				exComb |= resolver(result, nums, solParcial / nums[k], k + 1);
			break;

		default:
			break;
		}

		++i;
	}

	return exComb;
}

bool resuelveCaso() {
	int result;
	int nums[MAX]{};

	std::cin >> result;

	if (!std::cin)
		return false;

	for (int i = 0; i < MAX; ++i) std::cin >> nums[i];

	bool sol = resolver(result, nums, nums[0], 1);

	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}