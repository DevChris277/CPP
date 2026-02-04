#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
    static bool func(vector<int> nums) {
        unordered_set<int> set = {};

        for (int i : nums) {
            if (set.contains(i)) {
                return true;
            }else {
                set.insert(i);
            }
        }
        return false;
    }
};


int main() {
    const vector<int> x = {1,2,5,6,1};
    bool result = Solution::func(x);

    cout << result;

    return 0;
}
