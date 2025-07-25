class Solution {
public:
    int maxSum(vector<int>& nums) {
         int n = nums.size();
         map<int,int>m;
         int maxi = INT_MIN;
         for(auto i:nums){
             m[i]++;
             maxi = max(i,maxi);
         }

         int sum =0;
         for(auto j:m){
             if(j.first>0){
                 sum+=j.first;
             }
         }
         if(maxi<=0)return maxi;
         return sum;
    }
};