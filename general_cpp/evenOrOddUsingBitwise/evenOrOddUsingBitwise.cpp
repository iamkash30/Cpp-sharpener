#include <iostream>
using namespace std;

static bool isEven(int num) {
	if ((num & 0x0001)) {
		return false;
	}
	return true;
}

int main(int argc, char **argv) {
	int num = 6;
	isEven(num) ? cout << num << " is even" << endl :
			cout << num << " is odd" << endl;
	return 0;
}
