class Solution {
public:
    int longestSubsequence(string s, int k) {
          int n = s.size();
          bool f = false;
           int sum =0;
          int ans =0;
          for(int i=n-1;i>=0;i--){
              if(s[i] == '0'){
                 ans++;
              }
              else if(f == false && n-i-1<31){
                  sum+=pow(2,n-i-1);
                  if(sum>k){
                     f = true;
                     sum-=pow(2,n-i-1);
                  }
                  else{
                     ans++;
                  }
              }
          }
          return ans;
    }
};