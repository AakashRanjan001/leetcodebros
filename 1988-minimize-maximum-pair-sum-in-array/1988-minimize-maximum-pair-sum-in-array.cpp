class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
    int n = nums.size();
    int i=0;
    int j = n-1;
    int max_sum =0;
sort(nums.begin(),nums.end());
int current_sum = INT_MIN;
    while(i<j){
      current_sum = nums[i]+nums[j];
       max_sum = max(current_sum,max_sum);
       i++;
       j--;
    }

return max_sum;


    }
};