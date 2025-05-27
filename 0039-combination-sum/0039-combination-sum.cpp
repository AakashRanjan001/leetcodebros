class Solution {
public:
    void func(int ind, int target,vector<int>&arr,vector<int> &ds ,vector<vector<int>> &ans){
         if(ind == arr.size()){
             if(target == 0){
                    ans.push_back(ds); // takes o(k);
             }
             return;
         }

         // pick conditiomn 
         if(arr[ind]<=target){
             ds.push_back(arr[ind]);
             func(ind,target - arr[ind],arr,ds,ans);
             ds.pop_back(); // while backtracking we use this condition and pop_back 
         }
         //not pick
         func(ind+1,target,arr,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        func(0,target,candidates,ds,ans);
        return ans;
    }
};