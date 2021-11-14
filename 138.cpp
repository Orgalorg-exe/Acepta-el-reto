#include <iostream>
using namespace std;

int cuantosCeros(long long n);

int main() {
	int numCasos;
	long long n;
	cin >> numCasos;
	
	for (numCasos; numCasos > 0; --numCasos) {
		cin >> n;
		cout << cuantosCeros(n) << endl;
	}

	return 0;
}

// { Pre: 0 <= n }
int cuantosCeros(long long n) {
	int ret = n / 5;
	// { I : ( ret = max i: 0 <= i : n! mod 10^i == 0 )
	// }

	//O()
	if (ret > 0) {
		ret += cuantosCeros(ret);
	}

	return ret;
}
// { Pos : ret = max i: 0 <= i : n! mod 10^i == 0 }