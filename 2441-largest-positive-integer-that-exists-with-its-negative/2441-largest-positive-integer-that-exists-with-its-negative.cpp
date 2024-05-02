class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==0){
                   maxi = max(abs(nums[i]),maxi);
                }
            
            }
            
        }
        return maxi;
      

    }
};