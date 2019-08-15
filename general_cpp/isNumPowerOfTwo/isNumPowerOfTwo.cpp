#include <iostream>
using namespace std;

bool isNumPowerOfTwo(int num) {
	if (num <= 0)
		return false;

	while (num % 2 == 0) {
		num = num / 2;
	}
	if (num == 1) {
		return true;
	}

	return false;
}

bool isNumPowerOfTwoUsingBitwise(int num) {
	if (num <= 0) return false;
	int numOfOnes = 0;
	int i;
	for (i=0; i < 32; i++) {
		char bit = static_cast<char>(num & 0x1);
		if (bit == 1)
			numOfOnes += 1;
		num = num >> 1;
	}
	if (numOfOnes == 1)
		return true;
	return false;
}

bool isNumPowerOfTwoUsingBitwise_1(int num) {
	if (0 == (num & (num - 1))) {
		return true;
	}
	return false;
}

int main(int argc, char **argv) {
	isNumPowerOfTwo(0) ? std::cout << "Yes" << std::endl
			: std::cout << "No" << std::endl;

	isNumPowerOfTwoUsingBitwise(1) ? std::cout << "Yes" << std::endl
				: std::cout << "No" << std::endl;

	isNumPowerOfTwoUsingBitwise_1(4) ? std::cout << "Yes" << std::endl
					: std::cout << "No" << std::endl;
	return 0;
}
