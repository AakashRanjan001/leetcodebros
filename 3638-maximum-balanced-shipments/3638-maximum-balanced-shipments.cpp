class Solution {
public:
    int maxBalancedShipments(vector<int>& nums) {
         int n = nums.size();
         int i=0,j=0;

         int maxi = INT_MIN;
         int cnt =0;
         while(j<n){
             maxi = max(maxi, nums[i]);
             int last_parcel = nums[j];

             if(last_parcel<maxi){
                 cnt++;
                 maxi = INT_MIN;
             }
              i++;
             j++;
         }
         return cnt;

        
    }
};