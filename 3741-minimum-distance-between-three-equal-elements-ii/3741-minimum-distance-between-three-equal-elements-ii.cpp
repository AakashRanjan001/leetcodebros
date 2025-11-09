// class Solution {
// public:
   
//  int finddist(vector<int>& nums, int val) {
//         vector<pair<int,int>> ind;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == val) {
//                 ind.push_back({i, val});
//             }
//         }

       
//         if (ind.size() < 3) return INT_MAX;

//         int minDist = INT_MAX;

//         for (int i = 0; i + 2 < ind.size(); i++) {
//             int dist = abs(ind[i].first - ind[i+1].first)
//                      + abs(ind[i].first - ind[i+2].first)
//                      + abs(ind[i+1].first - ind[i+2].first);
//             minDist = min(minDist, dist);
//         }

//         return minDist;
//     }

//     int minimumDistance(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for (auto i : nums) mp[i]++;

//         int ans = INT_MAX;

//         for (auto it : mp) {
//             if (it.second >= 3) { 
//                 int val = it.first;
//                 int temp = finddist(nums, val);
//                 ans = min(ans, temp);
//             }
//         }

//         return ans == INT_MAX ? -1 : ans;
//     }
// };
class Solution {
public:
    // finddist() now takes pre-stored indices (not the full array again)
    int finddist(vector<int>& idx) {
        int minDist = INT_MAX;
        for (int i = 0; i + 2 < idx.size(); i++) {
            // simplified formula for 3 sorted indices
            // |a-b| + |a-c| + |b-c| = 2 * (c - a)
            int dist = 2 * (idx[i + 2] - idx[i]);
            minDist = min(minDist, dist);
        }
        return minDist;
    }

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;

        // collect all indices for each value in one pass
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // same structure: iterate map, call helper
        for (auto& it : pos) {
            if (it.second.size() >= 3) {
                ans = min(ans, finddist(it.second));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
