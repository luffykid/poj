#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

class PhoneMap {
private:
	static int mapt[26];
	string outstr;
public:
	PhoneMap() {
		int j = 0;
		for (char i = 'A'; i <= 'Z'; i++)
		{
			if (i != 'Q' && i != 'Z') {
				mapt[i - 'A'] = j++;
			}
		}
	}

	string* map(string& str) {
		outstr.clear();
		int j = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (isalpha(str[i])) {
				char ch = ass_map(str[i]);
				outstr.push_back(ch);
				j++;
			}
			if (isdigit(str[i])) {
				outstr.push_back(str[i]);
				j++;
			}
			if (j == 3) {
				outstr.push_back('-');
				j++;
			}
		}
		return &outstr;
	}

private:
	char ass_map(char ch) {
		return ((mapt[ch - 'A'] / 3) + 2) + '0';
	}
};
int PhoneMap::mapt[26];


int main() {
	int mapt[26];
	int count = 0;
	string instr;
	string* outstr;
	map<string, int> mp;


	cin >> count;
	PhoneMap pm;
	for (int i = 0; i < count; i++)
	{
		cin >> instr;
		outstr = pm.map(instr);
		mp[*outstr] = mp[*outstr] == 0 ? 1 : mp[*outstr] + 1;
	}

	map<string, int>::iterator it = mp.begin();
	bool r = true;
	while (it != mp.end()) {
		if (it->second > 1) {
			cout << it->first << " " << it->second << endl;
			r = false;
		}
		it++;
	}
	if (r) {
		cout << "No duplicates." << endl;
	}

	system("pause");
	return 0;
}