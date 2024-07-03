class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        sort(nums.rbegin(),nums.rend());
        int oper =0;
        for(int i=0;i<n;i++){
           oper++;
           if(oper<=3){
              nums[i] = nums[n-1];
           }
        }
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        return maxi - mini;
    }
};