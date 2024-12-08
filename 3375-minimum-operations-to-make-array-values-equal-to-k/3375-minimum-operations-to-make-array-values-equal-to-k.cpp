class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      
           int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int oper =0;

        for(int i=0;i<n;i++){
            if(nums[i]<k)return -1;
        }

       while(nums[0]!=k){
           int max_val = nums[0];
           
           for(int i=0;i<n;i++){
               if(nums[i] == max_val){
                   nums[i] = k;
               }
           }
           oper++;
           sort(nums.rbegin(),nums.rend());     
       }
        return oper;
    }
};