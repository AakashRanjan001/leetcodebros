class Solution {
public:
    int search(vector<int>& nums, int target) {
         // O(N) mei to ye solution bann jayega , normal linear search
         //binary serach se bann jayega ye 
         //chekck if the array is left sorted or right sorted 
         int n = nums.size();
         int l =0;
         int h = n-1;

         while(l<=h){
             int mid  = l+(h-l)/2;
             if(nums[mid] == target)return mid;

              // left sorted 
              if(nums[mid]>=nums[l]){
                 if(target>=nums[l] && target<=nums[mid]){
                     h = mid-1;
                 }
                 else{
                     l = mid+1;
                 }
              }
              
              //right sorted
              else if(nums[mid]<=nums[h]){
                 if(target>=nums[mid] && target<=nums[h]){
                     l = mid+1;
                 }
                 else{
                     h = mid-1;
                 }
              }
         }

        return -1;
    }
};