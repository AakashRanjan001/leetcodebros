class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int length = words.size();
        vector<string> answer;
        vector<string> temp(words); // Keep the original order

        // Sort characters of each word to identify anagrams
        for (int i = 0; i < length; i++) {
            sort(words[i].begin(), words[i].end());
        }

        // Always include the first word
        answer.push_back(temp[0]);

        // For each subsequent word, compare with previous sorted word
        for (int i = 1; i < length; i++) {
            if (words[i] != words[i - 1]) // If not an anagram of previous
                answer.push_back(temp[i]); // Include original
        }
        return answer;
    }
};