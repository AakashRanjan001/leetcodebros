
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> parity_intervals;
        int n = nums.size(),l = 0,r;
        for(r=1;r<n;r++){
            if((nums[r-1]+nums[r])&1^1){
                // if both elements are of same parity
                parity_intervals.push_back({l,r-1});
                l = r;
            }
        }
        parity_intervals.push_back({l,r-1});
        int m = parity_intervals.size();
        vector<bool> ans(queries.size(),0);
        int c = 0;
        for(auto &it:queries){
            int l = 0,r = m-1;
            int ind = -1;
            while(l<=r){
                int mid = l+((r-l)>>1);
                if(parity_intervals[mid][0] > it[0]){
                    r = mid-1;
                }
                else if(parity_intervals[mid][1] < it[0]){
                    l = mid + 1;
                }
                else{
                    ind = mid;
                    break;
                }
            }
            if(ind != -1){
                ans[c] = (it[1]<=parity_intervals[ind][1])?1:0;
            }
            c++;
        }
        return ans;
    }
};