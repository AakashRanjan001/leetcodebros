class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return 0;
        }
        int oper = 0;
        for(int i=1;i<n;i++){
           if(nums[i]<=nums[i-1]){
            oper+=abs(nums[i]-nums[i-1])+1;
            nums[i]=nums[i-1]+1;
           }
        }
        return oper;
    }
};