// class Solution {
// public:
//      int n;
//      int Q;

//     bool checkWithDiffArrayTech(vector<int> &nums ,vector<vector<int>>& queries , int k ){
//          vector<int>diff(n,0);
//          // here K ka value maximum Q queries tak jaa skata hai 
//          // hence O(Q ) tak bhi jaa sakta hai 
//          for(int i=0;i<=k;i++){ // means mujhe kth query tak dekhna hai 
//               int l = queries[i][0];
//               int r = queries[i][1];
//               int x = 1;
             
//              diff[l]+=x;
//              if(r+1<n){
//                  diff[r+1]-=x;
//              }
//          }
//              int cumSum =0;
//              // o(N);
//              for(int i=0;i<n;i++){
//                  cumSum+=diff[i];
//                  diff[i] = cumSum;

//                  if(nums[i] - diff[i] > 0){ // nums[i] after decrement with diff[i] 0 nhi bann paa rha jo hame chahiye tha 
//                      return false;
//                  }
//              }
//                 return true;

//          }
       
//     bool checkAlreadyZero(vector<int>& nums){
//          for(int i=0;i<nums.size();i++){
//              if(nums[i]!=0)return false;
//          }
//          return true;
//     }
//     int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
//          n = nums.size();
//          Q = queries.size();
//          //agar pehle se nums 0 hai saare elements then no oper req
//          if(checkAlreadyZero(nums)){
//              return 0;
//          }


//          //check after processing each query whther the array becomes zero or not 
//          int l =0,r= Q-1;
//          int k = -1;
//          while(l<=r){
//              int mid = (l+(r-l)/2);
//              // agar zero index of query se mid index tak mil jaata hai then store teh ans and find more smaller ans exists
//              if(checkWithDiffArrayTech(nums,queries,mid) == true){
//                   k = mid +1; // store teh count of the queries jisse zero bann gya 
//                   r = mid-1;
//              }
//              else{
//                  l = mid+1;
//              }
//          }
       
//         if(k == -1)return -1;
//         else return Q-k;
         
//     }
// };


class Solution {
public:
    int n;
    int Q;

    bool checkWithDiffArrayTech(vector<int> &nums , vector<vector<int>>& queries , int k) {
        vector<int> diff(n + 1, 0); // diff array of size n+1 to avoid out-of-bound
        
        // Apply queries from index k to end (not from 0 to k)
        for (int i = k; i < Q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            diff[l] += 1;
            if (r + 1 < n) {
                diff[r + 1] -= 1;
            }
        }

        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            if (nums[i] - cumSum > 0) {
                return false; // Can't make nums[i] zero
            }
        }
        return true;
    }

    bool checkAlreadyZero(vector<int>& nums) {
        for (int val : nums) {
            if (val != 0) return false;
        }
        return true;
    }

    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        if (checkAlreadyZero(nums)) {
            return Q; // Can remove all queries
        }

        int l = 0, r = Q - 1;
        int k = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (checkWithDiffArrayTech(nums, queries, mid)) {
                k = mid;      // Try removing more
                l = mid + 1;
            } else {
                r = mid - 1;  // Try fewer removals
            }
        }

        if(k == -1)return -1;  // Max number of queries you can remove from the beginning
        else return k+1;
    }
};
