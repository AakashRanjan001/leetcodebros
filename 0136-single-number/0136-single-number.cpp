class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=num.size();
         int val = -1;
        for(int i=0;i<n;i++){
            bool f = false;
             int val = nums[i];
             for(int j=0;j<n;j++){
                 if(i!=j && nums[i] == nums[j]){
                      f = true;
                     break;
                 } 
             }
             if(f  == 0)return val;
        }
        return 0;
    }
};