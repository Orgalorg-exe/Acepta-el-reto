#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 25000;

int moda(int n, int v[]);

int main() {
	int n;
	int* v = new int[MAX];
	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }
		sort(v, v + n);
		cout << moda(n, v) << endl;
		cin >> n;
	}

	delete[] v;

	return 0;
}

// { Pre: 0 < n <= longitud(v) ^ ord(v, n)
//   donde ord(v, n) = P.t. i : 0 <= i < n - 1 : v[i] <= v[i + 1] }
int moda(int n, int v[]) {
	int ret = v[0];
	int countAct = 1, countMax = 1;
	int i = 1;
	// { I : ( ret = j : 0 <= j < i : v[j]) ^
	// 	     ( countAct = j, k : 0 <= j <= k < i : ())^
	// 	     ( countMax = max countAct)^
	// 	     ( 0 <= i <= n)
	// }

	// O(n)
	// c = n - i
	while (i < n) {
		if (v[i] != v[i - 1]) { 
			countAct = 1;
		}
		else {
			++countAct;
			if (countAct > countMax) {
				ret = v[i];
				countMax = countAct;
			}
		}
		++i;
	}

	return ret;
}
// { Pos: max i : 0 <= i < n ^ (P.t. k : i <= k <= j : v[i] = v[k]): v[i]}
