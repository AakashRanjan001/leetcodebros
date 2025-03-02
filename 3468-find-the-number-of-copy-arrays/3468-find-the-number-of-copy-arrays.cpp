class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
         
         int n = original.size();
         int lower = bounds[0][0];
         int upper = bounds[0][1];
         int prevdiff =0;

         for(int i=1;i<n;i++){ 
            int diff = original[i]-original[i-1];
            diff+=prevdiff;

             lower = max(lower, bounds[i][0] - diff);
             upper = min(upper, bounds[i][1] - diff);

             prevdiff = diff;
         }
         int res = upper-lower +1;
         return res<0 ? 0 : res;
    }
};


