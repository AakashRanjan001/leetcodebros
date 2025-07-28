class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //  int n = nums.size(); // O(N^3)
        //  //brute force generate all the subarrays 
        //  int sum =0;
        //  int maxi = INT_MIN;
        //  for(int i=0;i<n;i++){
        //      for(int j=i;j<n;j++){ 
        //        sum =0;
        //         for(int k=i;k<=j;k++){
        //              sum+=nums[k];
        //         }
        //         maxi = max(sum, maxi);
        //      }
        //  }
        //  return maxi;
         

        //  int n = nums.size();
        //  int maxi = INT_MIN;
        //  for(int i=0;i<n;i++){
        //     int sum =0;
        //      for(int j=i;j<n;j++){
        //          sum+=nums[j];
        //          maxi = max(maxi,sum);
        //      }
        //  }
        //  return maxi;
        
        // KADANE'S Algo 
        int sum = 0, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
              sum+=nums[i];
              maxi = max(maxi,sum);

              if(sum<0)sum =0;
              else if(sum>maxi){
                 maxi = sum;
              }
        }
        return maxi;

    }
};