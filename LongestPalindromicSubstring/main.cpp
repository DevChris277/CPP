#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    static int getMax(const vector<int>& nums, const int& k) {
        int best = 0;
        int windowSum = 0;
        unordered_map<int,int> freq = {};

        if (nums.size() < k) {
            return 0;
        }

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            windowSum += nums[right];
            freq[nums[right]]++;

            // Ensure window size <= k
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                windowSum -= nums[left];
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                ++left;
            }

            // Ensure all elements are distinct (no frequency > 1)
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                windowSum -= nums[left];
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }

            // Now: distinct and size <= k. If exactly k, it's a valid subarray.
            if (right - left + 1 == k) {
                best = max(best, windowSum);
            }
        }
        return best;
    }
};

int main() {
    vector<int> nums = {1,5,4,5,9,9,9};
    int k = 3;

    int result = Solution::getMax(nums, k);

    cout << result;
};