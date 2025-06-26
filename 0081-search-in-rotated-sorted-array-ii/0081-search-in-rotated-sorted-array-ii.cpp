class Solution {
public: 
    int indexPresent(vector<int>& nums, int target, int n){
          int l = 0;
          int h = n-1;

          while(l<=h){
             int mid = l + (h-l)/2;
             if(nums[mid] == target)return mid;
             if(nums[mid] == nums[l] && nums[mid] == nums[h]){
                 l = mid+1; // to avoid the duplicates we can shrink it 
                 h = mid-1;
                 continue;
             }
             //left Sorted 
             if(nums[mid]>=nums[l]){
                 if(target>=nums[l] && target<nums[mid]){
                     h = mid-1;
                 }
                 else{
                     l = mid+1;
                 }
             }
             else if(nums[mid]<=nums[h]){
                 if(target>nums[mid] && target<=nums[h]){
                     l = mid+1;
                 }
                 else{
                     h = mid-1;
                 }
             }
          }
          return -1;
    }
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
         int ans = indexPresent(nums,target,n);
         
         bool result = (ans == -1)? false:true;
         return result;
    }
};