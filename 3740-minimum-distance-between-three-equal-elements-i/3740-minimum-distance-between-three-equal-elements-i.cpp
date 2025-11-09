// class Solution {
// public:
//    int finddist(vector<int>& nums , int val){
//        vector<pair<int,int>>ind;
//        for(int i=0;i<nums.size();i++){
//            if(nums[i] == val){
//               ind.push_back({i,val});
//            }
//        }
    
//       int dist = abs(ind[0].first - ind[1].first)
//                  + abs(ind[0].first - ind[2].first)
//                  + abs(ind[1].first - ind[2].first);
//        return dist;
//    }
//     int minimumDistance(vector<int>& nums) {
//          unordered_map<int,int>mp;
//          for(auto i:nums){
//              mp[i]++;
//          }
//          int ans = INT_MAX;

//          for(auto it:mp){
//              if(it.second >= 3){
//                 int val = it.first;
//                  int temp = finddist(nums,val);
//                  ans = min(ans,temp);
//              }
//          }
//          return ans  == INT_MAX ? -1 : ans;

//     }
// };

class Solution {
public:
    int minimumDistance(vector<int>& A) {
        int n = A.size(), res = INT_MAX;

        for(int i = 0; i < n; ++i) 
            for(int j = i + 1; j < n; ++j) 
                for(int k = j + 1; k < n; ++k) 
                    if(A[i] == A[j] && A[j] == A[k])
                        res = min(res, (j - i) + (k - j) + (k - i));
                
        return res == INT_MAX ? -1 : res;
    }
};