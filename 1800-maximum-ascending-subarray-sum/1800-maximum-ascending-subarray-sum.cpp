class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        // int n = nums.size();
        // int sum =0;
        // int maxSum =0;
        // for(int i=0;i<n;i++){
        //     sum =0;
        //     for(int j=i;j<n;j++){
        //          if(nums[j]>=nums[i]){
        //              sum+=nums[j];                
        //          }
        //          else{
        //             break;
        //          }            
        //     }
        //      maxSum = max(maxSum,sum);
        // }
        // return maxSum;

        int n = nums.size();
        int maxSum =0;
        int sum =nums[0];

        for(int i=1;i<n;i++){
             if(nums[i]>nums[i-1]){
                 sum+=nums[i];
             }
             else{
                   maxSum = max(maxSum,sum);
                   sum = nums[i];
             }
           
        }
        return max(maxSum,sum);


    }
};