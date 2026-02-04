#include <iostream>
#include <vector>



using namespace std;

class Solution {
public:
    static vector<int> func(vector<int> nums) {
        vector<int> ans = {};
        for ( int j = 0; j < 2; j++) {
            for (int i : nums) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};


int main() {
    const vector<int> x = {1,542,1};
    vector<int> result = Solution::func(x);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
