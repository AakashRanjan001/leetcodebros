class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt =1;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]-nums[i]<=k)continue;
            else{
                i=j;
                cnt++;
            }
        }
        return cnt;
    }
};