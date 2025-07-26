class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n = nums.size();
         bool f = false;
         for(int i=0;i<=n;i++){
            f = false;
             for(int j=0;j<n;j++){
                 if(i == nums[j]){
                     f = true;
                     break;
                 }
             }
             if(f == false)return i;
         }
         return 0;
    }
};