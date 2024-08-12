#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
std::vector<int> v;


int resolver() {
	if (n < 3) return 0;

	int i = 2;
	bool find = false;

	std::sort(v.begin(), v.end(), std::greater<int>());

	while (i < n && !find) {
		find = v[i - 2] < v[i - 1] + v[i];
		i++;
	}

	if (find) return v[i-1] + v[i - 2] + v[i - 3];
	return 0;
}

void resuelveCaso() {
	int num;
	std::cin >> n;

	v.clear();
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		v.push_back(num);
	}

	int sol = resolver();
	// escribir sol

	if(!sol) cout << "NO HAY NINGUNO\n";
	else cout << sol << '\n';

}

int main() {

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}