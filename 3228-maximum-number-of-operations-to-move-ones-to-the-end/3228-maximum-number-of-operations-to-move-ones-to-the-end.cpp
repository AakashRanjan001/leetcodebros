class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.size();
        int cnt =0;
        int res =0;
        int i= n-1;
        for(int i=n-1;i>0;i--){
           if(s[i]=='0' && s[i-1]=='1'){
            cnt++;
           }
         else if((s[i]=='1'&& s[i-1]=='1') ||(s[i]=='1'&& s[i-1]=='0') ){
            res+=cnt;
           }       
        }
        if(s[i]=='1')res+=cnt;
        return res;

    }
};