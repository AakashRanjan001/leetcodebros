class Solution {
public:
    int singleNumber(vector<int>& nums) {

     // 3 ways 
    //   1. unordered_map wala tareeka
    //   2. sort karke kar lenge
    //   3. XOR wla tareeka best hai ye  
        
       unordered_map<int,int>mp;
       for(auto it:nums){
        mp[it]++;
       }
       for(auto i:mp){
         if(i.second ==1){
             return i.first;
         }
       }
        return 0;
    }
};