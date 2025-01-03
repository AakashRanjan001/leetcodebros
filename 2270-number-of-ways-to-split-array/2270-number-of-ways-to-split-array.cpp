class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int n = nums.size();
        long long int total_sum =0;
        for(int i=0;i<n;i++){
             total_sum+=nums[i];
        }
        long long int leftSum =0;
        long long int cnt =0;
        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
           long long int RightSum = total_sum - leftSum;

            if(leftSum >= RightSum){
                cnt++;
            }
        }
        return cnt;
     
    }
};