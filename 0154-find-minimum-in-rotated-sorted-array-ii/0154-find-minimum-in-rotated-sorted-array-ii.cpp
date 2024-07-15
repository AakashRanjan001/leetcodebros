class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int s =0;
        int e = n-1;
        int ans = INT_MAX;
        if(n==1){
            return nums[0];
        }

        while(s<=e){
               int mid = s+(e-s)/2;

               if(nums[s] == nums[mid]  && nums[e]== nums[mid]){
                s++;
                e--;
                ans=min(ans,nums[mid]);
                continue;
               }

               //right sorted part 
              else if(nums[e]>=nums[mid]){
                  ans = min(ans , nums[mid]);
                  e = mid-1;
               }
               else{
                ans=min(ans,nums[s]);
                s=mid+1;
               }
        }
        return ans;
    }
};