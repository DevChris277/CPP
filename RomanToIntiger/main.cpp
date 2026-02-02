#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        static int RomanToInt( const string& s) {
            int result = 0;
            auto romanValue = [](char c) -> int {
                switch (c) {
                        case 'I': return 1;
                        case 'V': return 5;
                        case 'X': return 10;
                        case 'L': return 50;
                        case 'C': return 100;
                        case 'D': return 500;
                        case 'M': return 1000;
                        default: return 0;
                }
            };

            for (size_t i = 0; i < s.size(); ++i) {
                int currentValue = romanValue(s[i]);
                bool hasNext = i + 1 < s.size();

                int nextValue = hasNext ? romanValue(s[i+1]) : 0;
                if ( currentValue >= nextValue ) {
                    result += currentValue;
                } else {
                    result -= currentValue;
                };
            }
            return result;
        }
};

int main() {
    const string romanNumeral = "XXIV";
    cout << Solution::RomanToInt(romanNumeral);
    return 0;
}