class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>left;
        vector<int>center;
        vector<int>right;
        for(int i=0;i<n;i++){
             if(nums[i]<pivot){
                  left.push_back(nums[i]);
             }
             else if(nums[i]>pivot){
                 right.push_back(nums[i]);
             }
             else{
                center.push_back(nums[i]);
             }

        }

        vector<int>ans;
        for(int i=0;i<left.size();i++){
            ans.push_back(left[i]);
        }
        for(int i=0;i<center.size();i++){
            ans.push_back(center[i]);
        }
        for(int i=0;i<right.size();i++){
            ans.push_back(right[i]);
        }
      return ans;
    }
};