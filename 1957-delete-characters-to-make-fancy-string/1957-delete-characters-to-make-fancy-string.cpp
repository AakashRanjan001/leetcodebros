class Solution {
public:
    string makeFancyString(string s) {
        
        int cnt =1;
        int n = s.size();
        string res ="";
        res.push_back(s[0]);
        for(int i=1;i<n;i++){
             if(i>0 && s[i] == s[i-1]){
                cnt++;
             }
             else{
                 cnt =1;
             }
             if(cnt<3)res+=s[i];
        }
        return res;
    }
};