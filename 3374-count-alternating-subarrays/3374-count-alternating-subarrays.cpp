class Solution {
public:
#define ll long long
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll ans =0;
        int i =0;
        int j=0;
        for(int j=0;j<n;j++){
            if(j>0 && nums[j]==nums[j-1])
            i=j;

            ans+= j-i+1;
        }
       return ans; 
        
    }

};