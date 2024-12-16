class Solution {
public:
    int getMinval(vector<int>nums){
        int n= nums.size();
        int small = INT_MAX;
        int minindex = 0;
       for(int i=0;i<n;i++){
            if(nums[i]<small){
                small = nums[i];
                minindex =i;
            }
       }
       return minindex;;

    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        int n = nums.size();
        
        for(int i=0;i<k;i++){
           
           int minindex = getMinval(nums);
            nums[minindex]*=multiplier;

        }
        return nums;
    
    }
};