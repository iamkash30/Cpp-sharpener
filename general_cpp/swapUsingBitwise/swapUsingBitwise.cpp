#include <iostream>
using namespace std;

static void swap(int &num1, int &num2) {
	//num1 = 5->0101
	//num2 = 6->0110

	num1 = num1 ^ num2; // num1 = 0101 ^ 0110 = 0011
	num2 = num2 ^ num1; // num2 = 0110 ^ 0011 = 0101
	num1 = num1 ^ num2;	// num1 = 0011 ^ 0101 = 0110
}

int main(int argc, char **argv) {
	int n1 = 5;
	int n2 = 6;
	cout << "Before swapping, " << "n1 = " << n1 << ", " << "n2 = " << n2 << endl;
	swap(n1, n2);
	cout << "After swapping, " << "n1 = " << n1 << ", " << "n2 = " << n2 << endl;
	return 0;
}
