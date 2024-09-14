class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxVal =0;
        int maxCnt =0;
        int n = nums.size();
        int res =0;
        int cnt =0;

        for(int i=0;i<n;i++){
            maxVal = max(nums[i], maxVal);
        }

        for(int i=0;i<n;i++){
            if(nums[i] == maxVal){
                cnt++;
            }
            else{
                cnt =0;
            }
            res = max(cnt , res);     

        }
        return res;

    }
};