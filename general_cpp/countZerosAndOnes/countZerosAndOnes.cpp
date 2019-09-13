#include <iostream>
using namespace std;

#define INT_SIZE	sizeof(int) * 8

static void countOnes(int num, int &ones, int &zeros) {
	int i;

	for (i = 0; i < INT_SIZE; i++) {
		ones += (num >> i) & 1;
	}
	zeros = INT_SIZE - ones;
}

int main(int argc, char **argv) {
	int num, zeros, ones;
	cout << "Input num: ";
	cin >> num;
	countOnes(num, ones, zeros);
	cout << "Ones: " << ones << endl;
	cout << "Zeros: " << zeros << endl;

	return 0;
}
