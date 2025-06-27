class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         // Brute toh O(n) solution toh ho jayega
        //  int n = nums.size();
        //  for(int i=0;i<n;i++){
        //      if((i == 0 || nums[i]>nums[i-1]) && (i == n-1 || nums[i]>nums[i+1])){
        //          return i;
        //      }
        //  }
        //  return 0;

        // By applying teh Binary Search approach 
        int n = nums.size();
        if(n == 1)return 0;
        if(nums[0]>nums[1])return nums[0];
        if(nums[n-1]>nums[n-2])return nums[n-1];

        int l = 1, r = n-2;
        while(l<=r){
             int mid = l+ (r-l)/2;
             if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                 return mid;
             }
             else if( nums[mid]>nums[mid-1]){
                 l = mid+1;
             }
             else{
                 r = mid-1;
             }
        }
        return 0;
    }
};