class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int ones =0;
        int len =0;
        int maxlne = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){ 
                 ones++;
                 len++;
                 maxlne = max(maxlne,len);

            }
            else if(nums[i] == 0){
                ones =0;
                len =0;
            }
        }
        return maxlne;
    }
};