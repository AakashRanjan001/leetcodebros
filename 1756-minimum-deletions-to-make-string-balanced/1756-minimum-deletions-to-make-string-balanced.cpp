class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        int acount =0;
        int ans =0;    //a should be on the left hand side of b
        for(int i=n-1;i>=0;i--){
           if(s[i]=='b' && acount>0){
            acount--;
            ans++;
           }
           else if(s[i]=='a'){
            acount++;
           }
        }
  return ans;
    }
};