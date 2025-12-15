class Solution {
public:
    int binary(int n){
          string reversestr = "";
          while(n>0){
             int dig = n%2;
             reversestr+=dig;
             n = n/2;
          }
      string temp = reversestr;
      reverse(temp.begin(),temp.end());
      int cnt =0;
      for(int i=0;i<temp.size();i++){
           if(temp[i]!=reversestr[i]){
               cnt++;
           }
      }
      return cnt;
      
    }
    int minimumFlips(int n) {
         int ans = binary(n);
         return ans;
    }
};