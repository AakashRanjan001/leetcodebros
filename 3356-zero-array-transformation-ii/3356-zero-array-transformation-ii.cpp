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
//               int x = queries[i][2];
             
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
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         
//          n = nums.size();
//          Q = queries.size();
//          //agar pehle se nums 0 hai saare elements then no oper req
//          if(checkAlreadyZero(nums)){
//              return 0;
//          }


//          //check after processing each query whther the array becomes zero or not 
//          for(int i=0;i<Q;i++){ // O(Q) time lag rha  
//               if(checkWithDiffArrayTech(nums,queries,i) == true){
//                  return i+1;
//               }
//               else{
//                  continue;
//               }
//          }
//          // harr ek query ke liye upar o(Q+N) lag rha and hence 
//         //  there are maximum Q queies 
//         //  tehrefore ----> O(Q * (Q + N)) time complexity ho rha still gives us the TLE 

//          return -1;
//     }
// };

// MORE OPTIMISED BY BINARY SEARCH
class Solution {
public:
     int n;
     int Q;

    bool checkWithDiffArrayTech(vector<int> &nums ,vector<vector<int>>& queries , int k ){
         vector<int>diff(n,0);
         // here K ka value maximum Q queries tak jaa skata hai 
         // hence O(Q ) tak bhi jaa sakta hai 
         for(int i=0;i<=k;i++){ // means mujhe kth query tak dekhna hai 
              int l = queries[i][0];
              int r = queries[i][1];
              int x = queries[i][2];
             
             diff[l]+=x;
             if(r+1<n){
                 diff[r+1]-=x;
             }
         }
             int cumSum =0;
             // o(N);
             for(int i=0;i<n;i++){
                 cumSum+=diff[i];
                 diff[i] = cumSum;

                 if(nums[i] - diff[i] > 0){ // nums[i] after decrement with diff[i] 0 nhi bann paa rha jo hame chahiye tha 
                     return false;
                 }
             }
                return true;

         }
       
    bool checkAlreadyZero(vector<int>& nums){
         for(int i=0;i<nums.size();i++){
             if(nums[i]!=0)return false;
         }
         return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         
         n = nums.size();
         Q = queries.size();
         //agar pehle se nums 0 hai saare elements then no oper req
         if(checkAlreadyZero(nums)){
             return 0;
         }


         //check after processing each query whther the array becomes zero or not 
         int l =0,r= Q-1;
         int k = -1;
         while(l<=r){
             int mid = (l+(r-l)/2);
             // agar zero index of query se mid index tak mil jaata hai then store teh ans and find more smaller ans exists
             if(checkWithDiffArrayTech(nums,queries,mid) == true){
                  k = mid+1; // store teh count of the queries jisse zero bann gya 
                  r = mid-1;
             }
             else{
                 l = mid+1;
             }
         }
       

         return k;
    }
};