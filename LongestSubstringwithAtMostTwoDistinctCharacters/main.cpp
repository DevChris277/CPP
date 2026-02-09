#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int getMaxLength(const string& s) {
        int maxSum = 0, left = 0;
        unordered_map<char,int> freq = {};

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            while (freq.size() > 2) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            maxSum = max(maxSum,right - left + 1);
        }
        return maxSum;
    };
};

int main() {
    string s = "ababacccccc";
    Solution solution;
    int result = solution.getMaxLength(s);

    cout << result;

    return 0;
}