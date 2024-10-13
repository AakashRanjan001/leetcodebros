
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> arr;
        int i = 1;
        for (auto it : nums) {
            for (auto e : it) {
                arr.push_back({e, i});
            }
            i++;
        }
        sort(arr.begin(), arr.end());
        int k = nums.size();
        i = 0;
        int j = 0;
        vector<int> ans(2, 1e5);
        ans[0] = -1e5;
        unordered_map<int, int> mp;
        //sliding window 
        while (i < arr.size()) {
            mp[arr[i].second]++;
            if (mp.size() == k) {
                while (mp[arr[j].second] > 1) {
                    mp[arr[j].second]--;
                    j++;
                }
                int diff = arr[i].first - arr[j].first;

                if (diff < ans[1] - ans[0]) {
                    ans[0] = arr[j].first;
                    ans[1] = arr[i].first;
                }
                mp.erase(arr[j].second);
                j++;
                while (j < i && mp[arr[j].second] > 1) {
                    mp[arr[j].second]--;
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};

//optimization code
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();