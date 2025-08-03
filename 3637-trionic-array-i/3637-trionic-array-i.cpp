class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n = nums.size();
         int cnt =0;
    
         for(int i=0;i<n-1;i++){
             if(i>0 && nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                 cnt++;
           
             }
             else if(i>0 && nums[i]<nums[i+1] && nums[i]<nums[i-1]){
                 cnt++;
                 if(cnt == 1)return false;
             }
             else if(nums[i] == nums[i+1])return false;
         }
         if(cnt == 2 )return true;
         return false;
    }
};