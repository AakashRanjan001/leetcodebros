class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>temp;
    //     int cnt_zero =0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]!=0){
    //             temp.push_back(nums[i]);  
    //         }
    //         else{
    //             cnt_zero++;
    //         }
    //     }

    //  while(cnt_zero--){
    //     temp.push_back(0);
    //  }

    int n = nums.size();
    int nonzeropointer =0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
             int temp = nums[i];
             nums[i] = nums[nonzeropointer];
             nums[nonzeropointer] = temp;
             nonzeropointer++;
        }
    }
  
    }
};