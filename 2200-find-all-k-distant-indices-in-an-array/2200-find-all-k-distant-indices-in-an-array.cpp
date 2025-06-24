class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
         map<int,vector<int>>mp;
         for(int i=0;i<nums.size();i++){
              if(nums[i] == key){
                 mp[key].push_back(i);
              }
         }
         vector<int>ans;
        for(int i=0;i<nums.size();i++){
             for(auto j:mp[key]){
                 if(abs(i-j)<=k){
                     ans.push_back(i);
                     break;
                 }
             }
        }
        return ans;
    }
};