class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int n = nums.size();
        
         int maxi = -1;
         int cnt =1;
         for(int i=0;i<n-1;i++){
             if(nums[i] == 1 && nums[i+1] == 1){
               
                 cnt++;          
             }
             else{
              
                 cnt =1;
             }
             maxi = max(cnt,maxi);
         }
         return n == 1 ? nums[0] : maxi;
    }  
};