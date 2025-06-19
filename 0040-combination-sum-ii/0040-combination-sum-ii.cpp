// class Solution {
// public:
//     void func(int i,vector<int>&ds, int varsum,set<vector<int>>&ans,int target,vector<int>& candidates){
//         int n = candidates.size();
//           if(i>=n){
//               if(varsum == target){
//                   ans.insert(ds);
//               }
//               return;
//           }
//            // include
//          if(candidates[i] + varsum<=target){  
//           ds.push_back(candidates[i]);
//           varsum+=candidates[i];
//           func(i+1,ds,varsum,ans,target,candidates);

//           ds.pop_back();
//           varsum-=candidates[i];
//          }
//           func(i+1,ds,varsum,ans,target,candidates);

//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//          int n = candidates.size();
//          set<vector<int>>ans;
//          vector<int>ds;
//          func(0,ds,0,ans,target,candidates);

//          // convert the set to vector<int>
//          vector<vector<int>>val;
//          for(auto i:ans){
//              val.push_back(i);
//          }
//          return val;
//     }
// };



class Solution {
public:
    void func(int i, vector<int>& ds, int varsum, set<vector<int>>& ans, int target, vector<int>& candidates) {
        int n = candidates.size();
        if (i >= n) {
            if (varsum == target) {
                ans.insert(ds);
            }
            return;
        }

        // INCLUDE current element only if it's not a duplicate at this level
        if (i == 0 || candidates[i] != candidates[i - 1] || (i > 0 && taken[i - 1])) {
            ds.push_back(candidates[i]);
            taken[i] = true;
            func(i + 1, ds, varsum + candidates[i], ans, target, candidates);
            taken[i] = false;
            ds.pop_back();
        }

        // EXCLUDE current element
        func(i + 1, ds, varsum, ans, target, candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Required to skip duplicates
        set<vector<int>> ans;
        vector<int> ds;
        taken.assign(candidates.size(), false);     // Track usage for duplicate logic
        func(0, ds, 0, ans, target, candidates);
        return vector<vector<int>>(ans.begin(), ans.end());
    }

private:
    vector<bool> taken; // To track if previous duplicate was included
};
