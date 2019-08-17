#include <iostream>
using namespace std;

static void reverseStr(char *str) {
	char *end = str;
	char tmp;

	if (str) {
		while (*end)
			end++;
		end--;
		while (str < end) {
			tmp = *str;
			*str = *end;
			*end = tmp;
			str++;
			end--;
		}
	}
}


int main(int argc, char **argv) {
	char str[] = {'a','b','c','d','\0'};
	cout << "Before: " << str << endl;
	reverseStr(str);
	cout << "After: " << str << endl;
	return 0;
}
