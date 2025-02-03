class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
      int n = nums.size();
      if(n == 1)return 1;

      int strictIncrease =1;
      int strictDecrease =1;
      int increasing_cnt =1;
      int decreasing_cnt =1;

      for(int i=1;i<n;i++){
        if(nums[i-1]<nums[i]){
             //increasing 
             increasing_cnt++;
             decreasing_cnt =1;
        }
        else if(nums[i-1]>nums[i]){
             //decreasing
             decreasing_cnt++;
             increasing_cnt =1; 
        }
        else{
            increasing_cnt =1;
            decreasing_cnt =1;
        }
      strictIncrease = max(increasing_cnt,strictIncrease);
      strictDecrease = max(decreasing_cnt , strictDecrease);
      }
  
      return max(strictIncrease,strictDecrease);

    }
};