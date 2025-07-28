class Solution {
public:
    void func(int i,vector<int>& nums, vector<int>&ds, vector<int> &ans){
         if(i>=nums.size()){
             int bitwiseOr = 0;
             for(int i=0;i<ds.size();i++){
                 bitwiseOr |=ds[i];
             }
             ans.push_back(bitwiseOr);
             return;
         }

         //pick 
         ds.push_back(nums[i]);
         func(i+1,nums,ds,ans);
         ds.pop_back();

         //not pick 
         func(i+1,nums,ds,ans);
    }
    int countMaxOrSubsets(vector<int>& nums) {
         // brute is count the no.of subsets and then solve 
         vector<int>ans;
         vector<int>ds;
         func(0,nums,ds,ans);
         
         int cnt =0;
         int maxi = *max_element(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
             if(ans[i] == maxi)cnt++;
         }
         return cnt;

         
    }
};