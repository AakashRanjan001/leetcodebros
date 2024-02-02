class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mpp;
        
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
           if(it.second==1){
               ans.push_back(it.first);
           } 
            
        }
        int sum =0;
        for(int i=0;i<ans.size();i++){
            sum =sum +ans[i];
        }
        return sum;
    }
};