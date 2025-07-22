class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
         unordered_set<int>st;
         int start =0;
         int sum =0;
         int maxsum =-1;

         for(int end =0;end<n;end++){
             while( st.find(nums[end])!=st.end()){
                  st.erase(nums[start]);
                  sum-=nums[start];
                  start++;
                  
             }
             sum+=nums[end];
             st.insert(nums[end]);
             maxsum = max(maxsum,sum);
         }
         return maxsum;
        
    }
};