#include <iostream>
#include <vector>

using namespace std;

class Sequence {
private:
	static vector<float> seq;
public:
	Sequence() {
		float val = 1.0 / 2;
		seq.push_back(val);
	}
	int search(float val) {
		int i = 0, j = seq.size() - 1;
		while (i < j)
		{
			int mid = (i + j) / 2;
			if (val <= seq[mid]) j = mid;
			else i = mid + 1;
		}
		return i+1;
	}

	int f(float val) {
		bool r = true;
		while (true) {
			float last = seq[seq.size() - 1];
			if (val <= last) {
				if (r) return search(val);
				else return seq.size();
			}
			float newVal = last + 1.0 / (seq.size() + 2);
			seq.push_back(newVal);
			r = false;
		}
	}
};

vector<float> Sequence::seq;

int main() {
	float val = 0.0;
	Sequence seq;
	while (cin >> val)
	{
		if (val == 0.00) return 0;
		int i = seq.f(val);
		cout << i << " card(s)" << endl;
	}
	//system("pause");
	return 0;
}