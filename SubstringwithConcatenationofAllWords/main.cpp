#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(const string& s, const vector<string>& words) {
        vector<int> result = {};
        // look if the list or string is empty
        if (s.empty() || words.empty()) return result;

        //get wordLength and windowSize
        int wordLength = words[0].size();
        int windowLength = wordLength * words.size();

        //look if string is too short
        if (s.size()< windowLength) return result;

        // needed[word] = how many times this word must appear
        unordered_map<string,int> needed = {};
        for (string word : words) {
            needed[word]++;
        }

        for (int offset = 0; offset < wordLength; offset++) {
            int left = offset; // start of current window
            int usedWords = 0; // how many word-chunks are currently in the window

            // freq[word] = how many times this word appears in current window
            unordered_map<string, int> freq = {};

            // We must check all starting alignments: 0 .. wordLength-1
            for (int right = offset; right + wordLength <= s.size(); right += wordLength) {
                string currentWord = s.substr(right, wordLength);

                // If currentWord is not needed at all, reset the window
                if (!needed.contains(currentWord)) {
                    freq.clear();
                    usedWords = 0;
                    left = right + wordLength;
                    continue;
                }

                // add currentWord into window
                freq[currentWord]++;
                usedWords++;

                // If we have too many of currentWord, shrink from the left
                while (freq[currentWord] > needed[currentWord]) {
                    string leftWord = s.substr(left,wordLength);
                    freq[leftWord]--;
                    usedWords--;
                    left += wordLength;
                }

                // If window contains exactly wordCount words, record answer
                if (usedWords == words.size()) {
                    result.push_back(left);

                    // Move left forward by one word to look for next match
                    string leftWord = s.substr(left, wordLength);
                    usedWords--;
                    freq[leftWord]--;
                    left += wordLength;
                }
            }
        }

        return result;

    }
};

int main() {
    Solution solution;
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    vector<int> results = solution.findSubstring(s,words);

    for (int i : results) {
        cout << i << " ";
    }

    return 0;
}