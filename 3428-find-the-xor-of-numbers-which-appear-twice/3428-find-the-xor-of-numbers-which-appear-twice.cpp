class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;
        int ans =0;
        for(auto it : nums){
            mp[it]++; 
        }
        for(auto i:mp){
            if(i.second==2){
                ans = ans^ i.first;
            }
        }
        return ans;
    }
};