class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int i=0;
        int j=0;
        string ans ="";

        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && i == spaces[j]){
                  ans = ans + ' ';
                  j++;
            }
            ans = ans + s[i];
             
        }
        return ans;
    }
};