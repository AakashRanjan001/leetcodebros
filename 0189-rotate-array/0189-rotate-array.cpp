class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
         int n = nums.size();
         k = k%n;
         vector<int>concatenate(2*n);
         for(int i=0;i<n;i++){
             concatenate[i] = nums[i];
             concatenate[i+n] = nums[i];
         }
        //  for(int i=0;i<2*n;i++){
        // cout<<concatenate[i]<<"";
        //  }

       for(int i=0;i<n;i++){
           nums[i] = concatenate[n-k +i];
       }
        
    }
};