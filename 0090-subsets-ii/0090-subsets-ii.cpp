
class Solution {
public:
    void solve(int i, vector<int>& ds, vector<int>& nums, set<vector<int>>& st, int n) {
        if (i == n) {
            // sort(ds.begin(),ds.end());
            st.insert(ds);
            return;
        }
         // Not picking the element
        solve(i + 1, ds, nums, st, n);
        // Picking the element
        ds.push_back(nums[i]);
        solve(i + 1, ds, nums, st, n);
        ds.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        solve(0, ds, nums, st, n);
        // Convert set to vector

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
