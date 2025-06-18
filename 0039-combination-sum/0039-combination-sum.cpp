// class Solution {
// public:
//     void func(int ind,vector<int>& ds,int varsum,vector<int>&candidates,int target,vector<vector<int>>&ans){
          
//           if(ind>=candidates.size()){
//              if(varsum == target){
//                  ans.push_back(ds);
//              }
//              return;
//           }
//           //include 
//           ds.push_back(candidates[ind]);
//           varsum+=candidates[ind];
//           func(ind+1,ds,varsum,candidates,target,ans);
//           ds.pop_back();

//           //exclude
//           varsum-=candidates[ind];
//           func(ind+1,ds,varsum,candidates,target,ans);


//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//          //whos esum is k 
//          vector<vector<int>>ans;
//          vector<int>ds;
//          func(0,ds,0,candidates,target,ans);
//          return ans;
//     }
// };

class Solution {
public:
    void func(int ind, vector<int> ds, int varsum, vector<int> candidates, int target, vector<vector<int>>& ans) {
        if (ind >= candidates.size()) {
            if (varsum == target) {
                ans.push_back(ds);
            }
            return;
        }

        // include
        if (varsum + candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            func(ind, ds, varsum + candidates[ind], candidates, target, ans);
            ds.pop_back(); // not necessary due to pass-by-value, but kept for symmetry
        }

        // exclude
        func(ind + 1, ds, varsum, candidates, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, ds, 0, candidates, target, ans);
        return ans;
    }
};
