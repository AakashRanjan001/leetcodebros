class Solution {
public:
    int findMin(vector<int>& nums) {
         // Brute toh o(N) mei pata chal jayega 
         int n = nums.size();
         int l =0;
         int h = n-1;
         int ans = INT_MAX;
         while(l<=h){
             int mid = l + ( h-l)/2;

             //left soretd 
             if(nums[mid]>=nums[l]){
                 //means minimum elemnt must be right part
                 ans = min(ans,nums[l]);
                 l = mid+1;
                 
             }
             else{
                 ans = min(ans,nums[mid]);
                 h = mid-1;
             }
            
         }
         return ans;
    }
};