class Solution {
public:
  // Recursively converts a special binary string into its lexicographically largest form
    string solve(const string& s) {
        vector<string> parts;
        int balance = 0, start = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            balance += (s[i] == '1') ? 1 : -1;
            if (balance == 0) {
                // s[start..i] is a special substring: 1 + middle + 0
                // Make the middle largest, then wrap back with 1...0
                string middle = solve(s.substr(start + 1, i - start - 1));
                parts.push_back("1" + middle + "0");
                start = i + 1;
            }
        }

        // Sort parts descending to maximize lexicographic order when concatenated
        sort(parts.begin(), parts.end(), greater<string>());

        string ans;
        for (const auto& p : parts) ans += p;
        return ans;
    }

public:
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};