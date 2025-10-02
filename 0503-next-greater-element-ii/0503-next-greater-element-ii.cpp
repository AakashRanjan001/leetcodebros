class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         int n = nums.size();
         vector<int>nge;
         for(int i=0;i<n;i++){
            bool f = 0;
             for(int j=i+1;j<=i+n-1;j++){
                 int ind = j%n;
                 if(nums[ind]>nums[i]){
                     nge.push_back(nums[ind]);
                     f = 1;
                     break;
                 }
             
             }
             if(f == 0)nge.push_back(-1);
         }
         return nge;
    }
};
