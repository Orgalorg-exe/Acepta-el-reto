#include <iostream>

using namespace std;

void hora(float a, float b);

int main() {

	int n;
	float a, b;

	cin >> n;

	for (n; n > 0; --n) {
		cin >> a >> b;
		hora(a, b);
	}

	return 0;
}

void hora(float a, float b) {

	int hora, min;

	if ((a - (30 * (int)(a / 30))) / 30 == b / 360) {
		hora = a / 30;
		min = b / 6;
		if (hora < 10 && min < 10)
			cout << "0" << hora << ":" << "0" << min << endl;
		else if (hora < 10)
			cout << "0" << hora << ":" << min << endl;
		else if (min < 10)
			cout << hora << ":" << "0" << min << endl;
		else
			cout << hora << ":" << min << endl;
	}
	else if ((b - (30 * (int)(b / 30))) / 30 == a / 360) {
		hora = b / 30;
		min = a / 6;
		if (hora < 10 && min < 10)
			cout << "0" << hora << ":" << "0" << min << endl;
		else if (hora < 10)
			cout << "0" << hora << ":" << min << endl;
		else if (min < 10)
			cout << hora << ":" << "0" << min << endl;
		else
			cout << hora << ":" << min << endl;
	}
	else {
		cout << "ERROR\n";
	}
}