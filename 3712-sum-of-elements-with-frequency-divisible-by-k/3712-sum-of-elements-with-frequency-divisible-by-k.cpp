class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
         int n = nums.size();
         int maxi = *max_element(nums.begin(),nums.end());
         vector<int>hash(maxi+1,0);
         for(int i=0;i<n;i++){
             hash[nums[i]]++;
         }
         int sum =0;
         for(int i=1;i<hash.size();i++){
             if(hash[i]%k == 0){
                 sum+=(i*hash[i]);
             }
         }
         return sum;
    }
};