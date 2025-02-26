class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        //brute ho jayega 
        //saare subarrays nikalke abs max check kar lena 
        int n = nums.size();
        int sum =0;
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++){
             for(int j=i;j<n;j++){
                sum =0;
                 for(int k=i;k<=j;k++){
                     sum+=nums[k];
                 }
                 maxSum = max(maxSum,abs(sum));
             }
        }
        return maxSum;
    }
};