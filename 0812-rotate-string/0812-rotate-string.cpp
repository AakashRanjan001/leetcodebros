class Solution {
public:
    bool rotateString(string s, string goal) {
            if (s.length() != goal.length()) {
        return false;
    }
    
    // Step 2: Concatenate s with itself
    string double_s = s + s;
    
    // Step 3: Check if goal is a substring of double_s
    return double_s.find(goal) != std::string::npos;
    }
};