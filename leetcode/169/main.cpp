#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i : nums) {
            m[i]++;
        }

        for (auto it = m.cbegin(); it != m.cend(); it++) {
            if ( it->second > nums.size()/2)
                return it->first;
        }
    }
};

int main()
{
    Solution s;
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(2);

    cout << s.majorityElement(num) << endl;


    return 0;
}
