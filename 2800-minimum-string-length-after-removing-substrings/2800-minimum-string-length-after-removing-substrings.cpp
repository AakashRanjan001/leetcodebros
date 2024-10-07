class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        //Approach 1 by creating a vector 
        vector<char>ans;
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(s[i]);
            }
            else{
                char ch = ans.back();
                if((ch == 'A' && s[i] =='B') || (ch == 'C' && s[i] =='D') ){
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
        }
        return ans.size();
    }
};