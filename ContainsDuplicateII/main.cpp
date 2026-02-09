#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int containsDup(const string& s) {
        int left = 0, maxValue = 0;
        unordered_map<char,int> freqFound = {};

        for (int right = 0; right < s.size(); right++) {
            freqFound[s[right]]++;

            //cout << s[right] << "|" << freqFound[s[right]] << endl;
            while (freqFound[s[right]] > 1) {
                freqFound[s[left]]--;
                left++;
            }

            maxValue = max(maxValue, right - left + 1);
        }
        return maxValue;
    }

};

int main() {
    Solution solution;
    string s = "pwwkew";

    int result = solution.containsDup(s);

    cout << result << std::endl;
    return 0;
}