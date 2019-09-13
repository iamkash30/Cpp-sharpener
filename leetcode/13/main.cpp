#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>
using namespace std;

class Solution {
public:
    map<char, int> m;

    int romanToInt(string s) {
        // for (auto it = m.cbegin(); it != m.cend(); it++)
        //     std::cout << it->first << endl;
        m.insert(pair<char,int>('I', 1));
        m.insert(pair<char,int>('V', 5));
        m.insert(pair<char,int>('X', 10));
        m.insert(pair<char,int>('L', 50));
        m.insert(pair<char,int>('C', 100));
        m.insert(pair<char,int>('D', 500));
        m.insert(pair<char,int>('M', 1000));
        int result = 0;
        int p = m[s[0]];
        result = p;
        for (size_t i = 1; i < s.length(); ++i) {
            int c = m.at(s[i]);
            if (p >= c)
                result += c;
            else {
                result -= p;
                result += c - p;
            }
            p = c;
        }
        return result;
    }

};

int main()
{
    Solution s;
    cout << s.romanToInt("XXIV") << endl;
    return 0;
}
