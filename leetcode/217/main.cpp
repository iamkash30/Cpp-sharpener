#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        size_t len = nums.size();
        if (len < 2) return false;
        int i,j;

        set<int> s, sd;
        for (auto &i : nums) {
            if (true == s.insert(i).second) {}
            else if (true == sd.insert(i).second)
                return true;
        }
        return false;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
