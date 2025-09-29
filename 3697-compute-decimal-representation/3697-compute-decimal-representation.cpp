class Solution {
public:
    vector<int> decimalRepresentation(int n) {
         
         int prod = 1;
         vector<int>ans;

         while(n>0){
             int dig = n%10;
             dig = dig*prod;
             if(dig!=0){
             ans.push_back(dig);
             }
             prod = 1LL*prod*10;
             n = n/10;
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};