class Solution {
public:
    int maxProfit(vector<int>& nums) {
        //  int n = prices.size();
        //  int mini = INT_MAX;
        //  int minInd;
        //  for(int i=0;i<n;i++){
        //      if(prices[i]<mini){
        //          mini = prices[i];
        //          minInd = i;
        //      }
        //  }
        //  if(minInd == n-1)return 0;
        // int maxi =-1;
        //  for(int j = minInd;j<n;j++){
        //      maxi = max(prices[j],maxi);
        //  }
        //  return maxi-mini;


      int n= nums.size();
      int maxi = INT_MIN;
      for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             int diff = nums[j] - nums[i];
             maxi = max(maxi,diff);
         }
      }
      return maxi < 0 ? 0 :maxi;

    }
};