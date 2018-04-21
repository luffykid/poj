#include <iostream>

using namespace std;

int main() {
	double sum = 0.0;
	double tmp = 0.0;
	double result = 0.0;
	while (cin >> tmp)
	{
		sum += tmp;
	}
	result = sum / 12;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << '$' << result << endl;
	//system("pause");
	return 0; 
}