class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int cnt =1;
        for(int i=1;i<n;i++){
              if(nums[i]  == nums[i-1]){
                  cnt++;

                  if(cnt == 2)ans.push_back(nums[i]);
              }
              else{
                 cnt = 1;
              }
        }
        return ans;
    }
};