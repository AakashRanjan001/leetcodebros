class Solution {
public:
    int maximumDifference(vector<int>& nums) {
    int val = nums[0];
    int diff = -1;
    int maxdiff =-1;
    for(int j=1;j<nums.size();j++){
        if(val<nums[j]){
            diff = nums[j]-val;
            maxdiff = max(diff ,maxdiff);
        } 
    else{
        val = min(val,nums[j]);
    }
     
    }
   return maxdiff;

    }
};