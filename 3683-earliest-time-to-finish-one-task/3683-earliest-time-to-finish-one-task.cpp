class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
         int n = tasks.size();
         int maxi = INT_MAX;
         for(int i=0;i<n;i++){
             int s = tasks[i][0];
             int e = tasks[i][1];

             int sum = s+e;
             maxi = min(sum,maxi);
         }
         return maxi;
    }
};