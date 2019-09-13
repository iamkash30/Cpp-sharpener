#include <iostream>
#include <string>
#include <set>

using namespace std;

string removeDuplicates(const string &str, string &dups) {
	string tmp;
	set<char> s, sd;
	dups.clear();
	for (auto &c : str) {
		if (true == s.insert(c).second)
			tmp += c;
		else if (true == sd.insert(c).second)
			dups += c;
	}
	return tmp;
}

void removeDuplicates(string &str) {
	if (str.empty()) return;
	size_t len = str.length();
	if (len < 2) return;
	int tail = 1;
	int i,j;

	for (i = 1; i < len; ++i) {
		for (j = 0; j < len; ++j) {
			if (str[i] == str[j])
				break;
		}
		if (j == tail) {
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = 0;
}

int main(int argc, char **argv) {
	string str = "hello world";
	string dups, unique;
	unique = removeDuplicates(str, dups);
	cout << "Unique String is: " << unique << endl;
	cout << "Duplicates char are: " << dups << endl;
	return 0;
}
