#include <iostream>
using namespace std;

const int MAX = 5;

bool exCombOp(int result, int nums[], int solParcial, int k);

int main() {
	int result;
	int nums[MAX]{};

	cin >> result;
	while (cin) {
		for (int i = 0; i < MAX; ++i) cin >> nums[i];

		if (exCombOp(result, nums, nums[0], 1))
			cout << "SI" << endl;
		else
			cout << "NO" << endl;

		cin >> result;
	}

	return 0;
}

bool exCombOp(
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
			exComb |= exCombOp(result, nums, solParcial + nums[k], k + 1);
			break;

		case 1:
			exComb |= exCombOp(result, nums, solParcial - nums[k], k + 1);
			break;

		case 2:
			exComb |= exCombOp(result, nums, solParcial * nums[k], k + 1);
			break;

		case 3:
			if (solParcial != 0 && solParcial % nums[k] == 0)
				exComb |= exCombOp(result, nums, solParcial / nums[k], k + 1);
			break;

		default:
			break;
		}

		++i;
	}

	return exComb;
}