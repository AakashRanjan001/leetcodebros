class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int a = nums[0];
        int b = nums[1];

        int c = nums[nums.size()-1];
        return a+b-c;
    }
};