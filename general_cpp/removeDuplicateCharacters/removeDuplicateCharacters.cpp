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

int main(int argc, char **argv) {
	string str = "hello world";
	string dups, unique;
	unique = removeDuplicates(str, dups);
	cout << "Unique String is: " << unique << endl;
	cout << "Duplicates char are: " << dups << endl;
	return 0;
}
