class Solution {
public:
    int alternatingSum(vector<int>& nums) {
         int n = nums.size();
         int even_sum =0,odd_sum =0;
         for(int i=0;i<n;i++){
             if(i%2 == 0){
                 even_sum+=nums[i];
             }  
             else{
                 odd_sum+=nums[i];
             }
         }
         return even_sum - odd_sum;
    }
};