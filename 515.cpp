//  DATOS PREVIOS

#include <iostream>

using namespace std;

int sol(int n);



//  MAIN
int main() {
	int n;
	cin >> n;

	while (n != 0) {
		cout << sol(n) << endl;
		cin >> n;
	}

	return 0;
}



//  IMPLEMENTACIÓN DE FUNCIONES

/* { Pre: 0 < n <= 10000 } */ 
int sol(int n) { // Return ret

	int ret;
	//I:

	//O(1)
	if (n == 1 || !(n % 2))
		ret = n;
	else
		ret = n - 1;

	return ret;
}
/* { Pos: } */