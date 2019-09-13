#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it == 0) {
                nums.erase(it);
                count++;
                continue;
            }
            it++;
        }

        for (int i = 0; i < count; i++)
            nums.push_back(0);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    s.moveZeroes(nums);
    for (auto &it : nums)
        cout << it << endl;
    return 0;
}
