#include <iostream>
#include <vector>
using namespace std;

bool findDuplicates(const vector<int> &in, int num) {
	size_t size = in.size();
	if (0 == size)
		return false;
	size_t i;
	for (i = 0; i < size; i++) {
		if (num == in[i]) {
			return true;
		}
	}
	return false;
}

void removeDuplicates(const vector<int> &in, vector<int> &out) {
	size_t size = in.size();
	if (0 == size)
		return;
	size_t i;
	bool isDuplicate = false;
	for (i = 0; i < size; i++) {
		isDuplicate = findDuplicates(out, in[i]);
		if (false == isDuplicate) {
			out.push_back(in[i]);
		}
	}
}

void printVector(const vector<int> &v) {
	size_t size = v.size();
	if (0 == size) {
		return;
	}
	size_t i;
	for (i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(int argc, char **argv) {
	vector<int> in, out;
	in.push_back(1);
	in.push_back(2);
	in.push_back(3);
	in.push_back(2);
	in.push_back(1);
	printVector(in);
	removeDuplicates(in, out);
	printVector(out);
	return 0;
}
