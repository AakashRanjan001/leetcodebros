
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>Soln;
        sort(nums.begin(),nums.end());
        
        if(nums.size()%3!=0)return {};
        
        for(int i =0;i<nums.size();i+=3){ 
            if(abs(nums[i+2]-nums[i])<=k){
                Soln.push_back({nums[i],nums[i+1],nums[i+2]});
            }
            else return {};
        }
        return Soln;
    }
};