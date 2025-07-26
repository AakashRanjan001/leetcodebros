class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int n = nums.size();
         unordered_map<int,int>mp;
         for(auto i: nums){
             mp[i]++;
         }
         for(auto i:mp){
             if(i.second == 1){
                return i.first;
                break;
             }
         }
         return 0;
    }
};