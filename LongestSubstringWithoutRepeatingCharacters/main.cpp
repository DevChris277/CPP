#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubString(string s) {
        const long stringSize = s.size();
        unordered_map<char,int> freq = {};
        int left = 0;
        int maxSum = 0, windowSum = 0;

        for (int right = 0; right < stringSize; right++) {
            windowSum++;
            freq[s[right]]++;

            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                windowSum--;
                left++;
            }

            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    const string s = "abcabcbb";
    int result = solution.longestSubString(s);

    std::cout << result << std::endl;
    return 0;
}