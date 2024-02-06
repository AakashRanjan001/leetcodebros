class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        int n= nums.size();
      int count =0;
        for(int i=0;i<n;i++){
            count =0;  // ye important point tha jab wapas se ek iteration start hone wala hai toh phirse count =0;
         for(int j=0;j<n;j++){
             if(nums[i]>nums[j] && j!=i){
                 count++;
             }
         }
         ans.push_back(count);
        }
        return ans;
    }
};