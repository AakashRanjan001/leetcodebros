class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,bool>is_present;
        int T_sum = accumulate(nums.begin(),nums.end(),0);

        int res = -1001;
        //int  T_sum = 2*x + y
        for(int elem:nums){
             int outlier = T_sum - 2*elem;
             int sum = (T_sum - elem)/2;

             if(is_present[outlier]){
                 res = max(res,outlier);
             }
             if(2*sum + elem == T_sum && is_present[sum]){
                   res = max(res, elem);
             }
             is_present[elem] = true;
        }
        return res;
    }
};