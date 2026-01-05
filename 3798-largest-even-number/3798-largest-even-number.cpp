class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int index = 0;
        for(int i=n-1;i>=0;i--){
             if(s[i] == '2'){
                 index = i;
                 break;
             }
        }
        string ans = "";
        for(int i=0;i<=index;i++){
            ans+=s[i]; 
        }
        return ans == "1" ? "" : ans;

    }
};