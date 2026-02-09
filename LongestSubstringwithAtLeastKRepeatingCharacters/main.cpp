#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(const string& s, const int& k) {

        // Current problem size (length of the string segment we're solving for).
        const int stringSize = static_cast<int>(s.size());

        // Base cases:
        // - If k is larger than the segment length, no character can reach k occurrences.
        if (k > stringSize) return 0;

        // - If k <= 1, every substring is valid; the best is the whole segment.
        if (k <= 1) return stringSize;

        // Frequency map for characters in this segment.
        unordered_map<char, int> freq = {};

        // Count each character occurrence.
        for (char c : s) {
            freq[c]++;
        }

        int splitIndex = 0;

        while(splitIndex < stringSize && freq[s[splitIndex]] >= k){
            splitIndex++;
        };
        // If we reached the end, then every character in `s` occurs at least k times,
        // so the whole string segment is valid.
        if (splitIndex == stringSize) {
            return stringSize;
        }


        const int maxLeft = longestSubstring(s.substr(0,splitIndex),k);

        // Skip over consecutive invalid characters (each has count < k in this segment),
        // because none of them can belong to any valid substring here.
        while (splitIndex < stringSize && freq[s[splitIndex]] < k) {
            splitIndex++;
        }

        const int maxRight = (splitIndex < stringSize) ? longestSubstring(s.substr(splitIndex), k) : 0;
        return max(maxRight, maxLeft);
    }
};

int main() {
    Solution solution;
    string s = "aaabb";
    int k = 3;
    const int result = solution.longestSubstring(s,k);
    std::cout << result<< std::endl;
    return 0;
}