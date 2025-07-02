// class Solution {
// public:
//     int func(vector<int>& weights,int capacity){
//          int day = 1; // currently on day 1 the load is 0
//          int load = 0;

//          for(int i=0;i<weights.size();i++){
//              if(load + weights[i]>capacity){
//                   day = day + 1;
//                   load = weights[i];
//              }
//              else{
//                  load+=weights[i];
//              }
//          }
//          return day;

//     }
//     int shipWithinDays(vector<int>& weights, int days) {
//          int maxi = *max_element(weights.begin(),weights.end());
//          int sum = accumulate(weights.begin(),weights.end(),0);

//          int start = maxi;
//          int  end = sum;
//          // this is the range where wew can get the answer 
//          for(int cap=start;cap<=end;cap++){
//              int daysReq = func(weights,cap);
//              if(daysReq<=days){
//                  return cap;
//              }
//          }
//          return 0;
//     }
// };
class Solution {
public:
        int func(vector<int>& weights,int capacity){
         int day = 1; // currently on day 1 the load is 0
         int load = 0;

         for(int i=0;i<weights.size();i++){
             if(load + weights[i]>capacity){
                  day = day + 1;
                  load = weights[i];
             }
             else{
                 load+=weights[i];
             }
         }
         return day;

    }
    int shipWithinDays(vector<int>& weights, int days) {
         int maxi = *max_element(weights.begin(),weights.end());
         int sum = accumulate(weights.begin(),weights.end(),0);

         int start = maxi;
         int  end = sum;
              int ans;
         while(start<=end){
             int mid = start + (end-start)/2;
          
              int daysReq = func(weights,mid);
              if(daysReq<=days){
                 ans = mid;
                 end = mid-1;
              }
              else{
                 start = mid+1;
              }
         }
         return ans;
    }
};