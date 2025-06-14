class Solution {
public:
   void permutation(vector<int>&nums , vector<int>&ds , vector<vector<int>>&ans , vector<int>&freq){
        
        //base case 
        if(ds.size() == nums.size() ){
             ans.push_back(ds);
             return;
        }
        for(int i=0;i<nums.size();i++){
             if(freq[i] == 0){
                 freq[i] = 1;
                 ds.push_back(nums[i]);
                 permutation(nums,ds,ans,freq);
                 freq[i] = 0;
                 ds.pop_back();
             }
        }
   }
 
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>>ans;
         vector<int>ds;
         vector<int>freq(nums.size(),0);
         

         permutation(nums,ds,ans,freq);
         return ans;
    }
};