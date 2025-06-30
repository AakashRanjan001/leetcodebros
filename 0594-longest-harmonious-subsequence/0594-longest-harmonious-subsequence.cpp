class Solution {
public:
    int findLHS(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int n = nums.size();
         int i=0,j=0;
         int maxlen =0;
         while(i<n && j<n){
             if(nums[j]-nums[i]<1){
                 j++;
             }
             else if(nums[j] - nums[i] == 1){
                 maxlen = max(maxlen,j-i+1);
                 j++;
             }
             else{
                 i++;
             }
         }
         return maxlen;
    }
};