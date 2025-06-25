class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         
         int first = -1;
         int last = -1;

         // in O(N) solution
         for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                 if(first == -1)first = i;
                 last = i;
            }
         }
           return {first,last};
    }
};