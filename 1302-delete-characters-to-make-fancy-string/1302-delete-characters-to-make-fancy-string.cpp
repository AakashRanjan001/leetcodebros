class Solution {
public:
    string makeFancyString(string s) {
 
    int n = s.size();
        if(n <= 2) return s;
        int cnt = 1;
        string res = "";
        res.push_back(s[0]);
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                cnt++;
                if(cnt<=2){
                    res.push_back(s[i]);
                }
            }
            else{
                res.push_back(s[i]);
                cnt = 1;
            }
        }
        return res;

    }
};