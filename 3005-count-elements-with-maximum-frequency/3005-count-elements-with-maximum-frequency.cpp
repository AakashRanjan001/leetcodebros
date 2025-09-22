class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
         int n= nums.size();
         int maxi = INT_MIN;
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
             mp[nums[i]]++;
             maxi =max(maxi,mp[nums[i]]);
         }
         int sum=0;
         for(auto i:mp){
             if(i.second == maxi){ 
                sum+=i.second;
             }
         }
         return sum;
    }
};