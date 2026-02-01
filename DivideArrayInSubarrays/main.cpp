#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int DivideArray(vector<int> nums) {
        int fixedValue = nums[0];
        vector<int> remainder(nums.begin() + 1, nums.end());
        sort(remainder.begin(), remainder.end());
        return fixedValue + remainder[0] + remainder[1];
    };
};

int main() {
    Solution sol;
    vector<int> myNumbers = {10, 5, 5, 8, 3};

    int result = sol.DivideArray(myNumbers);
    cout << "Result: " << result << endl;

    return 0;
}