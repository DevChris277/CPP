#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> TwoSum(vector<int> &nums, int target) {
    unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.contains(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    int target = 17;
    vector<int> nums = {2,7,11,15};

    vector<int> result = solution.TwoSum(nums, target);

     if (!result.empty()) {
         cout << result[0] << " " << result[1] << endl;
     }
    return 0;
}