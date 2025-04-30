class Solution {
public:
    int findNumbers(vector<int>& nums) {
          
          int n = nums.size();
          int digits =0;
          int cnt =0;
         
          for(int i=0;i<n;i++){
             while(nums[i]>0){
                 digits++;
                 nums[i]= nums[i]/10;
             }
             if(digits%2 ==0)cnt++;
          }
          return cnt; 

    }
};