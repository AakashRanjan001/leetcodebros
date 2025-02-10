class Solution {
public:
    string clearDigits(string s) {
    bool foundDigit = true;
    
    while (foundDigit) {
        foundDigit = false;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                
                int j = i;
                while (j > 0 && !isalpha(s[j - 1])) {
                    --j;
                }
                
                if (j > 0 && isalpha(s[j - 1])) {
                    s.erase(j - 1, 1); 
                    --i;
                }
                
                s.erase(i, 1); 
                foundDigit = true;
                break; 
            }
        }
    }
        return s;
             
    }
};



 
