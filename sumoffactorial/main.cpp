#include "stdafx.h"

int main() {
	int n = 0;
	cin >> n;
	cout << sumOfFact(n, [](int n) { return n % 1000000; }) << endl;
	system("pause");
	return 0;
}

template <typename F>
int sumOfFact(int n, F func) {
	int sum = 0;
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact = func(fact)*i;
		sum = func(sum + fact);
	}
	return func(sum);

}