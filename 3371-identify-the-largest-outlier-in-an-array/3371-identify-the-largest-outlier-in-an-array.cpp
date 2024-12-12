class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int res = -1001;
        sort(nums.begin(),nums.end());
        int total = accumulate(nums.begin(),nums.end(),0);

        for(int x=0,y=n-1;x<n;x++){
             while(y>0 && 2*nums[x] + nums[y] > total){
                   --y;
             }
             if((x!=y) && 2*nums[x] + nums[y] == total){
                res = max(res,nums[y]);
             }
            
        }
        return res;
    }
};