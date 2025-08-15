class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  int n = nums.size();
        //  int product = 1;
        //  int maxi = INT_MIN;
        //  for(int i=0;i<n;i++){
        //     product = 1;
        //      for(int j=i;j<n;j++){
        //          product *= nums[j];
                 
        //         maxi = max(product , maxi);
        //      }
        //  }
        //  return maxi;

        // suing the suffix and prefix 
        int n = nums.size();
        int pref = 1;
        int suff = 1;

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
             if(pref == 0)pref = 1;
             if(suff == 0)suff = 1;

             pref*=nums[i];
             suff*=nums[n-i-1];

             ans = max(ans, max(pref,suff));
        }
        return ans;
    }
};