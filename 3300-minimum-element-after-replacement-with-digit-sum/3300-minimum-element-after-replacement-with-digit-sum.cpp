class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int sum =0;
            string val = to_string(nums[i]);
            for(int j=0;j<val.size();j++){
                   sum+=(val[j] - '0');
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
        
    }
};