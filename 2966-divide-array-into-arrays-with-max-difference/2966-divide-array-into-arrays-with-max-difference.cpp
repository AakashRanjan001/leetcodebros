class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        
if(nums.size()%3!=0)
   return {};
     
            
        for(int i=0 ;i<n;i=i+3){
            if(nums[i+2]-nums[i]<=k){
                v.push_back({nums[i],nums[i+1],nums[i+2]});
                            }
            else return{};
                            }
                            return v;
    }
};