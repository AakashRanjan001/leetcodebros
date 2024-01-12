class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int>ans;
        
        for(auto it:mpp){
            if(it.second>nums.size()/3){
                 ans.push_back(it.first);
            }
        }
        return ans;
    }
};