#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    static bool func(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char,int> map1, map2 = {};

        for (int i = 0; i <= s.size(); i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        if (map1 != map2) return false;
        return true;
    }
};

int main() {
    const string s = "anagram";
    const string t = "nagaram";
    bool result = Solution::func(s, t);

    cout << result;

    return 0;
}