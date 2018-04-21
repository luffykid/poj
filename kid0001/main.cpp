#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SteelBar
{
public:
	SteelBar();

	int yield(int len);
	int solution(int len);

private:
	static vector<int> p;
	int r[11];
	int seq[11];
};
vector<int> SteelBar::p;

SteelBar::SteelBar() {
	int tmp[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	p.insert(p.end(), tmp, tmp + sizeof(tmp) / sizeof(int));
	for (int i = 0; i < 11; i++)
	{
		r[i] = 0;
	}
}

int SteelBar::yield(int len) {
	for (int i = 1; i <= len; i++) {
		int max = 0;
		for (int j = i; j >= 0; j--) {
			int tmp = r[i - j] + p[j];
			if (tmp > max) {
				max = tmp;
				seq[i] = i - j;
			}
			cout << i << "---" << max << endl;
		}
		r[i] = max;
	}
	return r[len];
}

int SteelBar::solution(int len)
{
	for (int i = len; i > 0; i = seq[i])
	{
		cout << i - seq[i] << " ";
	}
	return 0;
}

int main() {
	SteelBar *sb = new SteelBar();
	int r = sb->yield(7);
	cout << "max yield: " << r << endl;
	sb->solution(7);
	system("pause");
	return 0;
}