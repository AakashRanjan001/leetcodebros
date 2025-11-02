class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());

        for(int i=mini;i<=maxi;i++){  
            bool f = 1;       
             for(int j=0;j<n;j++){
                 if(nums[j] == i){
                     f = 0;
                     break;
                 }
             }
             if(f == 1){
                ans.push_back(i);
             }
            
        }
        return ans;
    }
};