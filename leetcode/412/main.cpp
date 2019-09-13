#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vStr(n);
        string num;

        for (int i = 1; i <= n; i++) {
            if ((i%15 == 0))
                num = "FizzBuzz";
            else if (i%5 == 0)
                num = "Buzz";
            else if (i%3 == 0)
                num = "Fizz";
            else
                num = std::to_string(i);
            vStr[i-1] = num;
        }
        return vStr;
    }
};

int main()
{
    Solution s;
    vector<string> out;
    int n = 10;
    out = s.fizzBuzz(n);
    return 0;
}
