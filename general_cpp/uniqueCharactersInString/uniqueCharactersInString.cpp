#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * Using ascii table
 */
static bool isUnique_v1(string str) {
	bool ascii_table[256] = {false};
	for (int i = 0; i < str.length(); ++i) {
		int val = str[i];
		if (true == ascii_table[val])
			return false;
		ascii_table[val] = true;
	}
	return true;
}

/**
 * Using bit vector and considering string has just lower case
 * from 'a' to 'z'
 */
static bool isUnique_v2(string str) {
	int checker = 0;
	for (int i = 0; i < str.length(); ++i) {
		int val = str[i] - 'a';
		if (0 < (checker & (1 << val)))
			return false;
		checker = checker | (1 << val);
	}
	return true;
}

int main(int argc, char **argv) {
	string str = "abcdefg";
	bool isUnique = isUnique_v1(str);
	isUnique ? cout << str << " is unique" << endl :
			cout << str << " is not unique" << endl;

	isUnique = isUnique_v2(str);
	isUnique ? cout << str << " is unique" << endl :
				cout << str << " is not unique" << endl;
	return 0;
}
