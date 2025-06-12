class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans;
        int maxi = INT_MIN;
        for(int i=1;i<n;i++){
             ans = abs(nums[i] - nums[i-1]);
             maxi = max(ans,maxi);
        }
        maxi = max(maxi,abs(nums[n-1] - nums[0]));
        return maxi;
    }
};