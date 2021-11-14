#include<iostream>
using namespace std;

const int MAX = 50;

string esEstable(int pi, int di, int pd, int dd);
bool esEstable(int pi, int di, int pd, int dd, int& p);

//MAIN
int main() {

	int pi, di, pd, dd;
	cin >> pi >> di >> pd >> dd;

	while (!(pi == 0 && di == 0 && pd == 0 && dd == 0)) {
		cout << esEstable(pi, di, pd, dd) << endl;
		cin >> pi >> di >> pd >> dd;
	}

	return 0;
}

string esEstable(int pi, int di, int pd, int dd) {
	int foo;
	if (esEstable(pi, di, pd, dd, foo))
		return "SI";
	return "NO";
}

/* { Pre: } */
bool esEstable(int pi, int di, int pd, int dd, int & p) {

	bool i = true, d = true;
	int pi_aux, di_aux, pd_aux, dd_aux;

	if (pi == 0) {
		cin >> pi_aux >> di_aux >> pd_aux >> dd_aux;
		i = esEstable(pi_aux, di_aux, pd_aux, dd_aux, pi);
	}
	if (pd == 0) {
		cin >> pi_aux >> di_aux >> pd_aux >> dd_aux;
		d = esEstable(pi_aux, di_aux, pd_aux, dd_aux, pd);
	}

	p = pi + pd;
	return i && d && (pi * di) == (pd * dd);
}
/* { Pos: } */