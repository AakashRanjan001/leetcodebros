class Solution {
public:
    int solveUsingRec(vector<int>& arr,map<pair<int,int>,int> &maxi,int left , int right){
         // base case
         if(left == right)return 0; // means jab aise hi agar ek hi node bacha matlab toh woh pakka ek leaf node hai kyunki array mei saare leaf nodes hai aur hame sum chahiye non leaf nodes ka hence we retunr 0

         int ans = INT_MAX;
         for(int i=left;i<right;i++){
              ans = min(ans , maxi[{left,i}]*maxi[{i+1,right}] +solveUsingRec(arr,maxi,left,i) + solveUsingRec(arr,maxi,i+1,right));
         }
       return ans;

    }
    int solveUsingMem(vector<int>& arr, map<pair<int,int>,int> &maxi, int left , int right,  vector<vector<int>>&dp){
    if(left == right)return 0; // means jab aise hi agar ek hi node bacha matlab toh woh pakka ek leaf node hai kyunki array mei saare leaf nodes hai aur hame sum chahiye non leaf nodes ka hence we retunr 0

//step 3: jaust after the bse case write if answer already exits
        if(dp[left][right]!=-1){
             return dp[left][right];
        }

         int ans = INT_MAX;
         //step 2: ans wer mei dp array ka use karo
         for(int i=left;i<right;i++){
              ans = min(ans , maxi[{left,i}]*maxi[{i+1,right}] +solveUsingMem(arr,maxi,left,i,dp) + solveUsingMem(arr,maxi,i+1,right,dp));
         }
       dp[left][right] =  ans;
       return dp[left][right];
    }
    
    int mctFromLeafValues(vector<int>& arr) {
 
// unordered_map<pair<int,int>,int>maxi;
// unordered map se pair nhi bana sakte hai 
        // //precomputation to store the maximum values of all the ranges 
        // // o(1 ) mei ek ekement ko map mei store kar liya
         map< pair<int,int> , int> maxi;
        //pre-computation   
        for(int i=0;i<arr.size(); i++) {
            // pair<int,int> p;
            // p.first = i;
            // p.second=i;
            // maxi[p] = arr[i];     //{0,0} index tak ki kya range hogi wahi jo arr ki answer hogi

            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<arr.size(); j++) {
                maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
         // // ek range pass karnege ki kaha se kaha lie karenge 
        // //0 ->starting index
        // // n-1 ->ending index
        //  int ans = solveUsingRec(arr, maxi, 0, n-1);
        // return ans;


        //MEMOIZATION
        //step 1 : Create  a DP array // left and right dono change ho rha hai 
        vector<vector<int>>dp(n , vector<int>(n,-1));
        int ans = solveUsingMem(arr,maxi,0,n-1,dp);
        return ans;
    }
};