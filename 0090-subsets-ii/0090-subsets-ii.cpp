class Solution {
public:
    void func(int ind , vector<int>& ds, vector<int> &nums, vector<vector<int>>& ans , int n){
           
             ans.push_back(ds);
             
           for(int i=ind;i<nums.size();i++){
             if(i>ind && nums[i] ==nums[i-1])continue;
             ds.push_back(nums[i]);
             func(i+1,ds,nums,ans,n);
             ds.pop_back();
           }
          
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         int n =nums.size();
         sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
         vector<int>ds;
         func(0,ds,nums,ans,n);
         return ans;
    }
};