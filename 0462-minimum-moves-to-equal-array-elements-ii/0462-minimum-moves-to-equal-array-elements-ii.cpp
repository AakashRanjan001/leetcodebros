typedef long long ll;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        ll oper =0;
        ll median = nums[n/2];
        for(auto i:nums){
             oper+=abs(i-median);
        }
       return oper;
    }
};