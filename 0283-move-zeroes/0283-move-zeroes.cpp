class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //  int n = nums.size();
        //  vector<int>vec;
        //  int cnt_zero =0;
        //  for(int i=0;i<n;i++){
        //      if(nums[i]!=0){ 
        //         vec.push_back(nums[i]);
        //      }
        //      else{
        //          cnt_zero++;
        //      }
        //  }
        //  while(cnt_zero>0){
        //      vec.push_back(0);
        //  }
        //  return vec;

        int n = nums.size();
        int i=-1;
        for(int j=0;j<n;j++){
             if(nums[j] == 0){ 
                i = j;
                break;
             }
        }
         if (i == -1) return;

        for(int j = i+1;j<n;j++){
             if(nums[j]!=0){
                 swap(nums[i],nums[j]);
                 i++;
             }
        }

    }
};