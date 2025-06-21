// class Solution {
// public:
//     void func(vector<int> &ds, vector<int>& nums, vector<bool>&hash , vector<vector<int>>&ans){
//          if(ds.size() == nums.size()){
//              ans.push_back(ds);
//              return;
//          }
//          for(int i=0;i<nums.size();i++){
//              if(hash[i] == 0){
//                  ds.push_back(nums[i]);
//                  hash[i] = 1;
//                  func(ds,nums,hash,ans);
//                  ds.pop_back();
//                  hash[i] = 0;
//              }
             
             
//          }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//          int n = nums.size();
//          vector<bool>hash(n);
//          vector<int>ds;
//          vector<vector<int>>ans;
//          for(int i=0;i<n;i++){
//              hash[i] = 0;
//          }
//          func(ds,nums,hash,ans);
//          return ans;

//     }
// };
class Solution {
public:
    void func(int ind , vector<int>& nums,vector<vector<int>>& ans){
         if(ind == nums.size()){
             ans.push_back(nums);
             return;
         }

         for(int i=ind;i<nums.size();i++){
             swap(nums[ind],nums[i]);
             func(ind+1,nums,ans);
             swap(nums[ind],nums[i]);// while coming back make sure to re swap it
             
         }
    }
    vector<vector<int>> permute(vector<int>& nums) {
         int n = nums.size();
         vector<vector<int>>ans;
         func(0,nums,ans);
         return ans;
    }
};