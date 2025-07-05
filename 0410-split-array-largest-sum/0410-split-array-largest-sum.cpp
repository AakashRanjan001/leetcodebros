class Solution {
public: 
     int partition(vector<int>&nums,int maxsum){
            int subarray = 1, sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum + nums[i] > maxsum) {
                subarray++;
                sum = nums[i];
            } else
                sum += nums[i];
        }
        return subarray;
     }
    int splitArray(vector<int>& nums, int k) {
         // book allocation wala template lag rha hai
         // the template 
         int maxelement = *max_element(nums.begin(),nums.end());
         int sum = accumulate(nums.begin(),nums.end(),0);
         int low = maxelement;
         int high = sum;
         int ans = -1;
         while(low<=high){
             int mid = low+(high-low)/2;
             if(partition(nums,mid)<=k){
                   ans = mid;
                   high = mid-1;
             }
             else{
                 low = mid+1;
             }
             
         } 
         return ans;
    }
};   