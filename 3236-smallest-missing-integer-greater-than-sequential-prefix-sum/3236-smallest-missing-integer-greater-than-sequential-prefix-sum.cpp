class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                sum=sum+nums[i];
            }
            if(nums[i]!=nums[i-1]+1)
            {
                break;
            }
        }
        sum+=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(sum==nums[i])
            {
                i=0;
                sum++;
            }
        } 
        return sum;
    }
};
