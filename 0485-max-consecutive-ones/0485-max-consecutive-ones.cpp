class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int n = nums.size();
         int cnt_one = 0;
         int maxi = INT_MIN;
         for(int i=0;i<n;i++){
             if(nums[i] == 1){
                 cnt_one++;
             }
             else{      
                   cnt_one =0;
             }
              maxi = max(cnt_one,maxi);
         }
         return maxi;

    }
};