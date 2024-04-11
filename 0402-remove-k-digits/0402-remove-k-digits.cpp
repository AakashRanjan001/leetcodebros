class Solution {
public:
    string removeKdigits(string num, int k) {
        // Use a string to store the result directly
        string result;

        // Iterate through each character (digit) in num
        for (char digit : num) {
            // While the result is not empty, k > 0, and the last character in result
            // is greater than the current digit, remove the last character from result
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            // Append the current digit to the result if it's not a leading zero or the result is not empty
            if (!result.empty() || digit != '0') {
                result += digit;
            }
        }

        // If there are remaining removals, remove the required amount from the end
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Return the result, if empty return "0"
        return result.empty() ? "0" : result;
    }
};
