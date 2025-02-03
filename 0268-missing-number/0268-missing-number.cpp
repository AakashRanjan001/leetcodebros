class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //sum wala tareeka 
        int sum =0;
        int sum2 =0;
        for(int i=0;i<=nums.size();i++){
             sum+=i;
        }
        for(int i=0;i<nums.size();i++){
            sum2+=nums[i];
        }
        return sum - sum2;
    }
};