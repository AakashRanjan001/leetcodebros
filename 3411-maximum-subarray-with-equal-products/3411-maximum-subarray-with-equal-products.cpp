class Solution {
public:
    int maxLength(vector<int>& nums) {
         
          long long n = nums.size();
           int  ans = INT_MIN;
         for(int i=0;i<n;i++){
         unsigned long long prod = 1;
            unsigned  long long gcd_val = nums[i];
           unsigned   long long lcm_val = nums[i];

             for(int j=i;j<n;j++){
                  prod = prod*nums[j];
                  gcd_val = gcd(gcd_val,nums[j]);
                  lcm_val = lcm(lcm_val,nums[j]);
                  if(prod == gcd_val*lcm_val){
                     ans = max(ans,j-i+1);
                  }
             }
         }
         return ans;
    }
};