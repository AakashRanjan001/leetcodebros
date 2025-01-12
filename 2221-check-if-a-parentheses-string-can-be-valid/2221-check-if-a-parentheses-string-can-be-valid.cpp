class Solution {
public:
    bool canBeValid(string s, string locked) {

        if (s.size() % 2 != 0) return false;
        int balance = 0;

        // Left-to-right traversal.
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                balance++;
            } else {
                if (s[i] == '(') {
                    balance++;
                } else {
                    balance--;
                }
            }
            if (balance < 0) return false;
        }

        balance = 0; 

        // Right-to-left traversal.
        for (int i = s.size() - 1; i >= 0; i--) {

            if (locked[i] == '0') {
                balance++;
            } else {
                if (s[i] == ')') {
                    balance++;
                } else {
                    balance--;
                }
            }
            if (balance < 0) return false;
        }

        return true;
    }
};