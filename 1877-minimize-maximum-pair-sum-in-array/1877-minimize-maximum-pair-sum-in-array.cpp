class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n/2;i++){
             maxi = max((nums[i]+ nums[n-i-1]), maxi);
        }
        return maxi;
    }
};