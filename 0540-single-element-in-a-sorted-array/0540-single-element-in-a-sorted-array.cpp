class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int n = nums.size();
         // O(N)mei toh answer Brute toh pata chal jayega 
        //  if(n == 1)return nums[0];
        //  for(int i=0;i<n;i++){
        //      if(i == 0){
        //          if(nums[i]!=nums[i+1])return nums[i];
        //      }
        //      else if(i == n-1){
        //          if(nums[i]!= nums[i-1])return nums[i];
        //      }
        //      else{
        //          if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1]){
        //              return nums[i];
        //          }
        //      }
        //  }
        //  return 0;
      
      // Sorted hai suing binary search also we can solve the quetsion 
       
       if(n == 1)return nums[0];
       if(nums[0]!=nums[1])return nums[0];
       if(nums[n-1]!=nums[n-2])return nums[n-1];

       int l =1;
       int r =n-2;

       while(l<=r){
         int mid = l+ (r-l)/2;
         if(nums[mid-1]!=nums[mid] && nums[mid]!= nums[mid+1]){
             return nums[mid]; // matlab ye hi hai unique elemnt
         }
          if(mid%2!=0 && nums[mid]==nums[mid-1] 
                || mid%2 ==0 && nums[mid] == nums[mid+1]){
                     l = mid+1;
           }
           else{
             r = mid-1;
           }
       }
            return -1;

    }
};