class Solution {
public:
    bool canJump(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i+1]>=nums[i]){
                return true;
            }
            else{
                return false;
            }
        }
        return true;
    }
};