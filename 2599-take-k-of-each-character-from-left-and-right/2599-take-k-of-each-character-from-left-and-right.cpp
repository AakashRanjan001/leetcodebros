
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        if (count['a'] < k || count['b'] < k || count['c'] < k) {
            return -1;
        }

        int requiredA = count['a'] - k;
        int requiredB = count['b'] - k;
        int requiredC = count['c'] - k;

        int left = 0, maxWindow = 0;
        unordered_map<char, int> windowCount;

        for (int right = 0; right < n; ++right) {
            windowCount[s[right]]++;

            while (windowCount['a'] > requiredA || 
                windowCount['b'] > requiredB || 
                windowCount['c'] > requiredC) {
                windowCount[s[left]]--;
                left++;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};