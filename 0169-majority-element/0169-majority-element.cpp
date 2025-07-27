class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n = nums.size();
         int val = (int)n/2; // by default floor value hoga 

         unordered_map<int,int>mp;
         for(auto i:nums){
             mp[i]++;
         }
       
         for(auto it:mp){
             if(it.second>val){
                 return it.first;
                 break;
             }
         }
         return 0;
        
    }
};