class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int cnt =0;
       for(int i=0;i<n-1;i++){
          if(s[i] == '1' && s[i+1] =='0'){
              swap(s[i],s[i+1]);
              cnt++;
          }
       }
       return cnt;
    
    }
};