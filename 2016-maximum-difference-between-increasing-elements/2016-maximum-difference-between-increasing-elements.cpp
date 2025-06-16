class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        //  int n = nums.size();
        //  int maxi = -1;
        //  for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //          if(nums[i]<nums[j]){
        //              maxi = max(nums[j]-nums[i],maxi);
        //          }
        //     }
        //  }
        //  return maxi;

        //approach 2
         int n = nums.size();
         int maxi = -1;
         int mini = nums[0];
         for(int i=1;i<n;i++){
              mini = min(mini,nums[i]);

             if(nums[i]>mini){
                 maxi = max(maxi , nums[i] - mini);
             }
         }
         return maxi;
    }
};