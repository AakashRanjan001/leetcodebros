class Solution {
public:
    int missingNumber(vector<int>& nums) {


        //BRUTE force
        int n = nums.size();
        bool flag =0;
        for(int i=1;i<=n;i++){
            flag =0;
            for(int j=0;j<n;j++){
                 if(nums[j] == i){
                     flag = 1;
                     break;
                 }
            }
            if(flag == 0)return i;
        }
        return 0;


        //sum wala tareeka 
        // int sum =0;
        // int sum2 =0;
        // for(int i=0;i<=nums.size();i++){
        //      sum+=i;
        // }
        // for(int i=0;i<nums.size();i++){
        //     sum2+=nums[i];
        // }
        // return sum - sum2;

        //XOR wla tareeka 
        // int XOR =0;
        // int XOR1 =0;
        // for(int i=0;i<=nums.size();i++){
        //      XOR^=i;
        // }
        // for(int i=0;i<nums.size();i++){
        //      XOR1^=nums[i];
        // }
        // return XOR ^ XOR1;
    }
};