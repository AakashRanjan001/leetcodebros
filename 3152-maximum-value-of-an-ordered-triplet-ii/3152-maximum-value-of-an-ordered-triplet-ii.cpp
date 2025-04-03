
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
      vector<int>prefix(n);
      vector<int>suffix(n);

      prefix[0] = nums[0];
      for(int i=1;i<n-1;i++){
         prefix[i] = max(prefix[i-1],nums[i]);
      }

      suffix[n-1] = nums[n-1];

      for(int i=n-2;i>=0;i--){
         suffix[i] = max(suffix[i+1],nums[i]);
      }

      long long ans =0;
      for(int j=1;j<n-1;j++){
         long long val = 1LL*(prefix[j-1] - nums[j])*suffix[j+1];
         ans = max(ans,val);
      }
       return ans;

    }
};