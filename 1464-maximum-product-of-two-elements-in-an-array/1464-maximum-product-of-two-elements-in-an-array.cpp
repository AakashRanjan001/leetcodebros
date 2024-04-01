class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=n-1;i>=n-2;i--){
            int val = (nums[n-1]-1)*(nums[n-2]-1);
            return val;
        }
        return 0;
    }
};