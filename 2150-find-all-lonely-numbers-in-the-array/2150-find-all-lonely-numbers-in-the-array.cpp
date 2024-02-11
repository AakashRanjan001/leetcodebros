class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int>mpp;
        vector<int>ans;
int n = nums.size();
for(int i=0;i<n;i++){
    mpp[nums[i]]++;
}
for(int i =0;i<n;i++){
    if(mpp[nums[i]]==1){
    if(mpp.find(nums[i]+1)==mpp.end()){
        
        if(mpp.find(nums[i]-1)==mpp.end()){
            ans.push_back(nums[i]);
        }
    }
}
}

return ans;

    }
};