class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l= k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]==nums[l]&& i<j<k<l){
                            vector<int>temp ={i,j,k,l};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans.size();
    }
};