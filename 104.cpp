#include <iostream>
using namespace std;

bool esEstable(int pi, int di, int pd, int dd, int & p);

int main() {

	int pi, di, pd, dd, p;

	cin >> pi >> di >> pd >> dd;

	while (!(di == 0 && pd == 0)) {

		if (esEstable(pi, di, pd, dd, p))
			cout << "SI" << endl;
		else 
			cout << "NO" << endl;

		cin >> pi >> di >> pd >> dd;
	}
	
	return 0;
}

bool esEstable(int pi, int di, int pd, int dd, int & p) {

	bool i = true, d = true;

	int pii, dii, pdi, ddi;
	int pid, did, pdd, ddd;

	if (pi == 0) {
		cin >> pii >> dii >> pdi >> ddi;
		i = esEstable(pii, dii, pdi, ddi, pi);
	}
	if (pd == 0) {
		cin >> pid >> did >> pdd >> ddd;
		d = esEstable(pid, did, pdd, ddd, pd);
	}

	p = pi + pd;
	return i && d && (pi * di) == (pd * dd);
}