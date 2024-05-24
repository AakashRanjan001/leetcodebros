#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    int solve(vector<string>& words, vector<int>& ch, vector<int>& score, int i) {
        if (i == words.size())
            return 0;

        // Skip the current word
        int skip = solve(words, ch, score, i + 1);

        // Calculate the score for the current word and check if it can be formed
        int currentWordScore = 0;
        bool canForm = true;
        vector<int> temp(26);

        for (char c : words[i]) {
            int index = c - 'a';
            temp[index]++;
            if (temp[index] > ch[index]) {
                canForm = false;
                break;
            }
            currentWordScore += score[index];
        }

        int use = 0;
        if (canForm) {
            // Use the current word
            for (char c : words[i]) 
                ch[c - 'a']--;
            
            use = currentWordScore + solve(words, ch, score, i + 1);

            // Restore the letter counts
            for (char c : words[i]) 
                ch[c - 'a']++;
        }

        return max(skip, use);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> ch(26, 0);
        for (char c : letters) {
            ch[c - 'a']++;
        }

        return solve(words, ch, score, 0);
    }
};
