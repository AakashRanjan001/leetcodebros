class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int q = queries.size();

        vector<int> prefixSum(n, 0);
        int sum = 0;

        // Fill prefix sum based on words starting and ending with vowels
        for (int i = 0; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                sum++;
            }
            prefixSum[i] = sum;
        }

        vector<int> result(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            result[i] = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
        }

        return result;
    }
};