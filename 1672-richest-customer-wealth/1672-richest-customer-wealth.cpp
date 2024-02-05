class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
   int n = accounts.size();
   int m = accounts[0].size();
int maxi = INT_MIN;
   for(int i=0;i<n;i++){
       int sum =0;        // matlab ek iteration hone ke baad matlab jab i =1 hua fro 0 tab wapas se sum =0 ho gya
       
       
       for(int j=0;j<m;j++){
           sum = sum +  accounts[i][j];
           maxi= max(sum ,maxi);
       }
   }

  return maxi;


    }
};