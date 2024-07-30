class Solution {
public:
    bool checkString(string s) {
        
        int n = s.size();
        for(int i=n-1;i>0;i--){
            if(s[i] =='b' && s[i-1]=='a'){
                continue;
            }
            else if(s[i]=='b' && s[i-1] =='b' || s[i]=='a' && s[i-1]=='a'){
                continue;
            }
            else if(s[i]=='a' && s[i-1]=='b'){
                return false;
            }
        }
        return true;
    }
};