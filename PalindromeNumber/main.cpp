#include <iostream>

using namespace std;

class Solution {
public:
    static bool isPalindrome(int n) {
        // Negative numbers are not palindromes due to the '-' sign.
        if (n < 0) return false;

        // Work on a copy so we can still compare against the original n later.
        int x = n;

        // rev will store the reversed digits of x.
        int rev = 0;

        // the remainder stores the last digit extracted from x each loop iteration.
        int remainder = 0;

        // Reverse x digit-by-digit until all digits are consumed.
        while (x != 0) {
            // Take the last digit (e.g., 123 % 10 == 3).
            remainder = x % 10;

            // Shift current reversed number left and append the last digit.
            // Example: rev=12, remainder=3 -> rev becomes 123.
            rev = rev * 10 + remainder;

            // Drop the last digit from x (e.g., 123 / 10 == 12).
            x /= 10;
        }

        // If the reversed number equals the original, it's a palindrome.
        if (rev == n) return true;

        // Otherwise, it's not a palindrome.
        return false;
    }
};

int main() {
    // Example input.
    int n = 121;

    // Create a Solution object and print a result (1 for true, 0 for false).
    cout << Solution::isPalindrome(n);

    return 0;
}